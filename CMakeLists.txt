cmake_minimum_required(VERSION 3.0.0)
project(beast_demo VERSION 0.1.0)


set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost 1.69 REQUIRED COMPONENTS system)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

add_executable(beast_demo websocket_client_async_ssl.cpp)
target_include_directories(beast_demo PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(beast_demo 
    ${Boost_SYSTEM_LIBRARY}
    ${OPENSSL_LIBRARIES}
    Threads::Threads
)