cmake_minimum_required(VERSION 3.21)
project(app_ChainedList C)

set(CMAKE_C_STANDARD 17)

include(FetchContent)

#cmake_policy(SET CMP01)
FetchContent_Declare(
        libprg
        #GIT_REPOSITORY https://github.com/emersonmello/libprg.git
        #GIT_TAG 0.0.1
        # You can reference a local directory instead
        URL file:///${CMAKE_CURRENT_SOURCE_DIR}/../../libprg
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(libprg)

add_executable(app_ChainedList main.c)
target_link_libraries(app_ChainedList PUBLIC libprg)