
/*
 * TestExt is mostly deprecated.
 *
 * Please don't add new extension tests here if they are possible to
 * write in php.
 *
 * The tests below still remain in C++ generally because they start
 * temporary servers, which is easier from C++.
 */

#ifdef HAVE_CUSTOM_LIBEVENT
RUN_TESTSUITE(TestExtCurl);
#endif
RUN_TESTSUITE(TestExtServer);
