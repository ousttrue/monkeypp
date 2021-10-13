project(monkeypp)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)

subdirs(_external src tests)
