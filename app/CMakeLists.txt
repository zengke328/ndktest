cmake_minimum_required(VERSION 3.4.1)


add_library(jni-test
            SHARED
            # 提供了一个相对路径你的源文件
            src/main/jni/jni-test.cpp)

find_library(log-lib log)

target_link_libraries(jni-test
                      ${log-lib})