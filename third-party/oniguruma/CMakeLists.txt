add_library(onig INTERFACE)

find_package(ONIGURUMA)
set(CMAKE_REQUIRED_INCLUDES ${ONIGURUMA_INCLUDE_DIRS})
CHECK_CXX_SOURCE_COMPILES(
"#include <onigposix.h>
int main() {
  return 0;
}"
  HAVE_ONIGPOSIX_H
)
set(CMAKE_REQUIRED_INCLUDES)

if(HAVE_ONIGPOSIX_H)
  message(STATUS "Using system oniguruma")
  target_link_libraries(onig INTERFACE ${ONIGURUMA_LIBRARIES})
  target_include_directories(onig INTERFACE ${ONIGURUMA_INCLUDE_DIRS})
  if (ONIGURUMA_STATIC)
    target_compile_definitions(onig INTERFACE "-DONIG_EXTERN=extern")
  endif()

  return()
endif()
message(STATUS "Building oniguruma from third-party/")

include(ExternalProject)
include(HPHPFunctions)

SET_HHVM_THIRD_PARTY_SOURCE_ARGS(
  ONIG_SOURCE_ARGS
  SOURCE_URL
  "https://github.com/kkos/oniguruma/releases/download/v6.9.5/onig-6.9.5.tar.gz"
  SOURCE_HASH
  "SHA512=2bdb24914e7069c6df9ab8a3d0190ddb58440d94b13860cdc36d259062ae0bc2aa85d564a4209ec596fc7ee47b0823d1b817d4f7ffcc3ea60e9870da84491dc1"
)

ExternalProject_add(
  bundled_onig
  ${ONIG_SOURCE_ARGS}
  EXCLUDE_FROM_ALL
  CONFIGURE_COMMAND
  "<SOURCE_DIR>/configure"
    "--prefix=<INSTALL_DIR>"
    --enable-posix-api=yes
    # Oniguruma requires absolute paths for these. This is a bit unusual.
    "--libdir=<INSTALL_DIR>/lib"
    "--includedir=<INSTALL_DIR>/include"
    --disable-dependency-tracking
    --disable-shared
    --enable-static
)

ExternalProject_Get_Property(bundled_onig INSTALL_DIR)

add_dependencies(onig bundled_onig)
target_include_directories(onig INTERFACE "${INSTALL_DIR}/include")
target_link_libraries(onig INTERFACE
  "${INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}onig${CMAKE_STATIC_LIBRARY_SUFFIX}"
)
target_compile_definitions(onig INTERFACE "-DONIG_EXTERN=extern")
