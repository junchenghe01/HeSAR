# 设置最低 CMake 版本
cmake_minimum_required(VERSION 3.16)

# 定义项目名称
project(HeSAR)

# 设置 C 标准
set(CMAKE_C_STANDARD 99)

# 添加 bsw 和 test 子目录
add_subdirectory(bsw)
add_subdirectory(test)
