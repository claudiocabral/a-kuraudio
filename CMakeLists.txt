project(a-kuradio)
cmake_minimum_required(VERSION 3.17)


set(TEST_APP a-kura-test) 

add_executable(${TEST_APP}
  tests/app.cpp
  )

target_include_directories(${TEST_APP} PRIVATE
  a-kuraudio
  third-party/catch2
  )
