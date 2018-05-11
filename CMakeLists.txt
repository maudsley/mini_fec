cmake_minimum_required(VERSION 3.0)

# enable C++11 and warnings
set(CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-Wall ${CMAKE_CXX_FLAGS}")

include_directories(.)

set(Sources
  main.cpp
  detail.cpp
  codeword.cpp
  encoder.cpp
  decoder.cpp
  channel.cpp
)

set(Libraries
)

add_executable(mini_fec ${Sources})
target_link_libraries(mini_fec ${Libraries})
