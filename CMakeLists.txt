cmake_minimum_required(VERSION 3.8)
project(democode)

set(CMAKE_CXX_STANDARD 11)
INCLUDE_DIRECTORIES(/usr/local/include/SDL2/)
set(SOURCE_FILES main.cpp infun.cpp insinglemain.cpp)
add_executable(democode ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(democode /usr/local/lib/libSDL2.so )