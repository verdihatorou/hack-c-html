/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef HPHP_STREAM_WRAPPER_H
#define HPHP_STREAM_WRAPPER_H

#include <string>

#include "hphp/runtime/base/directory.h"
#include "hphp/runtime/base/file.h"
#include "hphp/runtime/base/req-ptr.h"

struct stat;

namespace HPHP {
struct StreamContext;

namespace Stream {
///////////////////////////////////////////////////////////////////////////////

struct Wrapper {
  Wrapper() : m_isLocal(true) { }

  Wrapper(const Wrapper&) = delete;
  Wrapper& operator=(const Wrapper&) = delete;

  void registerAs(const std::string &scheme);

  virtual req::ptr<File> open(const String& filename,
                              const String& mode,
                              int options,
                              const req::ptr<StreamContext>& context) = 0;
  virtual int access(const String& /*path*/, int /*mode*/) {
    errno = ENOSYS;
    return -1;
  }
  virtual int lstat(const String& /*path*/, struct stat* /*buf*/) {
    errno = ENOSYS;
    return -1;
  }
  virtual int stat(const String& /*path*/, struct stat* /*buf*/) {
    errno = ENOSYS;
    return -1;
  }
  virtual int unlink(const String& /*path*/) {
    errno = ENOSYS;
    return -1;
  }
  virtual int rename(const String& /*oldname*/, const String& /*newname*/) {
    errno = ENOSYS;
    return -1;
  }
  virtual int mkdir(const String& /*path*/, int /*mode*/, int /*options*/) {
    errno = ENOSYS;
    return -1;
  }
  virtual int rmdir(const String& /*path*/, int /*options*/) {
    errno = ENOSYS;
    return -1;
  }
  virtual req::ptr<Directory> opendir(const String& /*path*/) {
    errno = ENOSYS;
    return nullptr;
  }
  virtual String realpath(const String& /*path*/) { return null_string; }

  virtual Optional<std::string> getxattr(const char* /*path*/,
                                         const char* /*xattr*/) {
    return std::nullopt;
  }

  // Normal file streams represent local files and must support all of the
  // stream operations.
  virtual bool isNormalFileStream() const { return false; }

  virtual ~Wrapper() {}

  /**
   * Is there a chance that open() could return a file that is local?
   */
  bool m_isLocal;
};

/*
 * ExtendedWrapper allows a Stream::Wrapper to override various other POSIX
 * functions for manipulating the FileSystem. This is particularly useful for
 * user-defined wrappers which may wish to override these operations. It is
 * also required when proxying through a client in remote unix server mode.
 */
struct ExtendedWrapper : Wrapper {
  virtual bool touch(const String& path, int64_t mtime, int64_t atime) = 0;
  virtual bool chmod(const String& path, int64_t mode) = 0;
  virtual bool chown(const String& path, int64_t uid) = 0;
  virtual bool chown(const String& path, const String& uid) = 0;
  virtual bool chgrp(const String& path, int64_t gid) = 0;
  virtual bool chgrp(const String& path, const String& gid) = 0;
};

///////////////////////////////////////////////////////////////////////////////
}
}

#endif // HPHP_STREAM_WRAPPER_REGISTRY_H
