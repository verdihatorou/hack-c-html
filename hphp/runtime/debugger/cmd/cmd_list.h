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

#pragma once

#include "hphp/runtime/base/type-variant.h"
#include "hphp/runtime/base/req-root.h"
#include "hphp/runtime/debugger/debugger_command.h"

namespace HPHP::Eval {
///////////////////////////////////////////////////////////////////////////////

struct CmdList : DebuggerCommand {
  static Variant GetSourceFile(DebuggerClient& client, const std::string& file);

  CmdList() : DebuggerCommand(KindOfList) {}

  void list(DebuggerClient&) override;
  void help(DebuggerClient&) override;
  bool onServer(DebuggerProxy&) override;
  void onClient(DebuggerClient&) override;

protected:
  void sendImpl(DebuggerThriftBuffer&) override;
  void recvImpl(DebuggerThriftBuffer&) override;

private:
  void getListLocation(DebuggerClient &client, int &line,
                       int &charFocus0, int &lineFocus1,
                       int &charFocus1);
  void listEvalCode(DebuggerClient &client);
  bool listFileRange(DebuggerClient &client, int line,
                     int charFocus0, int lineFocus1,
                     int charFocus1);
  bool listFunctionOrClass(DebuggerClient &client);

  // A path to a source file. If relative this is relative to url
  // loaded into the server (if any).
  std::string m_file;

  // The first line of the range of source lines to be listed.
  int32_t m_line1;

  //The last line of the range of source lines to be listed.
  int32_t m_line2;

  // If null, this is uninitialized. If false, there is no such range/file.
  // Otherwise, this contains an HPHP::String instance representing the
  // range of source text to be listed by this command.
  req::root<Variant> m_code;
};

///////////////////////////////////////////////////////////////////////////////
}

