# CMake generated Testfile for 
# Source directory: /home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6
# Build directory: /home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_run "demo6.out" "5" "2")
set_tests_properties(test_run PROPERTIES  _BACKTRACE_TRIPLES "/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;43;add_test;/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;0;")
add_test(test_usage "demo6.out")
set_tests_properties(test_usage PROPERTIES  PASS_REGULAR_EXPRESSION "Usage: .* base exponent" _BACKTRACE_TRIPLES "/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;46;add_test;/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;0;")
add_test(test_5_2 "Demo" "5" "2")
set_tests_properties(test_5_2 PROPERTIES  PASS_REGULAR_EXPRESSION "is 25" _BACKTRACE_TRIPLES "/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;70;add_test;/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;76;do_test;/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;0;")
add_test(test_10_5 "Demo" "10" "5")
set_tests_properties(test_10_5 PROPERTIES  PASS_REGULAR_EXPRESSION "is 100000" _BACKTRACE_TRIPLES "/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;70;add_test;/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;77;do_test;/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;0;")
add_test(test_2_10 "Demo" "2" "10")
set_tests_properties(test_2_10 PROPERTIES  PASS_REGULAR_EXPRESSION "is 1024" _BACKTRACE_TRIPLES "/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;70;add_test;/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;78;do_test;/home/murongyuyue/Desktop/sundry/tool-use-demo/cmake-demo/cmake-demo6/CMakeLists.txt;0;")
subdirs("math")
