project(a-kuradio)
cmake_minimum_required(VERSION 3.17)

set(TEST_APP a-kura-test) 

add_executable(${TEST_APP}
  tests/app.cpp
  )

set_target_properties(${TEST_APP}
    PROPERTIES CXX_STANDARD 17
    )

target_compile_options(${TEST_APP} PUBLIC
    -Wall
    -Wextra
    -Werror
    -Wshadow
    -Wundef
    -Wpointer-arith
    -Wcast-align
    -Wwrite-strings
    -Wformat-security
    -Wreturn-type
    )

target_include_directories(${TEST_APP} PRIVATE
  includes
  third-party/catch2
  )
