cmake_minimum_required(VERSION 3.21)
project(appprg C)

set(CMAKE_C_STANDARD 17)

include(FetchContent)

#cmake_policy(SET CMP01)

FetchContent_Declare(
        libprg
        #GIT_REPOSITORY https://github.com/emersonmello/libprg.git
        #GIT_TAG 0.0.1
        # You can reference a local directory instead
        URL file:///${CMAKE_CURRENT_SOURCE_DIR}/../../libprg
)
FetchContent_MakeAvailable(libprg)

add_executable(appprg main.c)
target_link_libraries(appprg PUBLIC libprg)