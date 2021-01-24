
# cmake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 工程名
project(cmakedemo)

# 设定工程名和版本号
project(cmakedemo VERSION 1.0)

# 显式定义一个变量
set(CPP_STANDARD 11)

# 编译源码生成目标。
add_executable(min.out main.c)

# 指定额外的include 头文件；
# PROJECT_BINARY_DIR 类似于环境变量 make 的目录；
# PROJECT_SOURCE_DIR 源文件所在目录； 
target_include_directories(cmakedemo PUBLIC_HEADER "${PROJECT_BINARY_DIR}")

# 添加库文件
add_library(target source)

# 