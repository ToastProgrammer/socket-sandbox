cmake_minimum_required(VERSION 3.5.0)
project(socket-sandbox VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

find_library(WS2_32_LIBRARY WS2_32)

add_executable(socket-client socket_client.c socket_utils.c)
add_executable(socket-server socket_server.c socket_utils.c)

target_link_libraries(socket-client WS2_32)
target_link_libraries(socket-server WS2_32)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)