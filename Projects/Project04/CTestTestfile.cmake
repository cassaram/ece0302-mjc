# CMake generated Testfile for 
# Source directory: /home/user/Desktop/ece0302-mjc/Projects/Project04
# Build directory: /home/user/Desktop/ece0302-mjc/Projects/Project04
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(student-tests "student-tests")
set_tests_properties(student-tests PROPERTIES  _BACKTRACE_TRIPLES "/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;36;add_test;/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;0;")
add_test(test00 "pathfinder" "/home/user/Desktop/ece0302-mjc/Projects/Project04/tests/maze00.png" "output00.png")
set_tests_properties(test00 PROPERTIES  _BACKTRACE_TRIPLES "/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;37;add_test;/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;0;")
add_test(test00-compare "compare" "/home/user/Desktop/ece0302-mjc/Projects/Project04/tests/output00.png" "output00.png")
set_tests_properties(test00-compare PROPERTIES  _BACKTRACE_TRIPLES "/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;38;add_test;/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;0;")
add_test(test01 "pathfinder" "/home/user/Desktop/ece0302-mjc/Projects/Project04/tests/maze01.png" "output01.png")
set_tests_properties(test01 PROPERTIES  _BACKTRACE_TRIPLES "/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;39;add_test;/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;0;")
add_test(test01-compare "compare" "/home/user/Desktop/ece0302-mjc/Projects/Project04/tests/output01.png" "output01.png")
set_tests_properties(test01-compare PROPERTIES  _BACKTRACE_TRIPLES "/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;40;add_test;/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;0;")
add_test(test02 "pathfinder" "/home/user/Desktop/ece0302-mjc/Projects/Project04/tests/maze02.png" "output02.png")
set_tests_properties(test02 PROPERTIES  _BACKTRACE_TRIPLES "/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;41;add_test;/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;0;")
add_test(test02-compare "compare" "/home/user/Desktop/ece0302-mjc/Projects/Project04/tests/output02.png" "output02.png")
set_tests_properties(test02-compare PROPERTIES  _BACKTRACE_TRIPLES "/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;42;add_test;/home/user/Desktop/ece0302-mjc/Projects/Project04/CMakeLists.txt;0;")
subdirs("lib")
