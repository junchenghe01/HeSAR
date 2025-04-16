# 添加 test_exec 可执行文件
add_executable(test_exec test.c)

# 链接 bsw 模块的库
target_link_libraries(test_exec PRIVATE 
                        os_lib 
                        # dio_lib 
                        # det_lib
                        )

# 包含 bsw 的头文件
target_include_directories(test_exec PRIVATE 
                        ../bsw/os 
                        # ../bsw/dio 
                        # ../bsw/det
                        )
