#!/usr/bin/python

# Copyright 2003, 2004, 2005, 2006 Vladimir Prus 
# Distributed under the Boost Software License, Version 1.0. 
# (See accompanying file LICENSE_1_0.txt or http://www.boost.org/LICENSE_1_0.txt) 

#  Test that a chain of libraries work ok, not matter if we use static or
#  shared linking.
from BoostBuild import Tester, List, get_toolset
import string
import os

t = Tester()

t.write("Jamfile", """
# Stage the binary, so that it will be relinked
# without hardcode-dll-paths. That will chech that
# we pass correct -rpath-link, even if not passing
# -rpath.
stage dist : main ;
exe main : main.cpp b ; 
""")

t.write("main.cpp", """ 
void foo();

int main() { foo(); return 0; }

""")

t.write("project-root.jam", """ 
""")

t.write("a/a.cpp", """
void
#if defined(_WIN32)
__declspec(dllexport)
#endif
gee() {}
void
#if defined(_WIN32)
__declspec(dllexport)
#endif
geek() {} 
""")

t.write("a/Jamfile", """ 
lib a : a.cpp ; 
""")

t.write("b/b.cpp", """ 
void geek();

void 
#if defined(_WIN32)
__declspec(dllexport)
#endif
foo() { geek(); }

""")

t.write("b/Jamfile", """ 
lib b : b.cpp ../a//a ; 
""")

t.run_build_system(stderr=None)
t.expect_addition("bin/$toolset/debug/main.exe")
t.rm(["bin", "a/bin", "b/bin"])

t.run_build_system("link=static")
t.expect_addition("bin/$toolset/debug/link-static/main.exe")
t.rm(["bin", "a/bin", "b/bin"])

# Check that <library> works for static linking.

t.write("b/Jamfile", """ 
lib b : b.cpp : <library>../a//a ; 
""")
t.run_build_system("link=static")
t.expect_addition("bin/$toolset/debug/link-static/main.exe")

t.rm(["bin", "a/bin", "b/bin"])
t.write("b/Jamfile", """ 
lib b : b.cpp ../a//a/<link>shared : <link>static ; 
""")

t.run_build_system()
t.expect_addition("bin/$toolset/debug/main.exe")
t.rm(["bin", "a/bin", "b/bin"])

# Test that putting library in sources of a searched library
# works.
t.write("Jamfile", """
exe main : main.cpp png ;
lib png : z : <name>png ;
lib z : : <name>zzz ;
""")
t.run_build_system("-a -d+2", status=None, stderr=None)
# Try to find the "zzz" string either in response file
# (for Windows compilers), or in standard output.
rsp = t.adjust_names("bin/$toolset/debug/main.exe.rsp")[0]
if os.path.exists(rsp) and string.find(open(rsp).read(), "zzz") != -1:
    pass
elif string.find(t.stdout(), "zzz") != -1:
    pass
else:
    t.fail_test(1)

#
# Test main -> libb -> liba chain
# in the case where liba is a file, not a Boost.Build target.
#
t.rm(".")
t.write("Jamroot", "")
t.write("a/Jamfile", """
lib a : a.cpp ;
install dist : a ;
""")
t.write("a/a.cpp", """
#if defined(_WIN32)
__declspec(dllexport)
#endif
void a() {}
""")
t.run_build_system(subdir="a")
t.expect_addition("a/dist/a.dll")

if (os.name == 'nt' or os.uname()[0].lower().startswith('cygwin')) and get_toolset() != 'gcc':
    file = t.adjust_names(["a/dist/a.lib"])[0]
else:
    file = t.adjust_names(["a/dist/a.dll"])[0]

t.write("b/Jamfile", """
lib b : b.cpp ../%s ;
""" % file)
t.write("b/b.cpp", """
#if defined(_WIN32)
__declspec(dllimport)
#endif
void a();

#if defined(_WIN32)
__declspec(dllexport)
#endif
void b() { a(); }
""")

t.write("Jamroot", """
exe main : main.cpp b//b ;
""")
t.write("main.cpp", """
#if defined(_WIN32)
__declspec(dllimport)
#endif
void b();
int main() { b(); }
""")

t.run_build_system()
t.expect_addition("bin/$toolset/debug/main.exe")



t.cleanup()
