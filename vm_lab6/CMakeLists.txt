cmake_minimum_required(VERSION 3.21)
project(vm6)

set(CMAKE_CXX_STANDARD 14)
set(SOURCES methods/EulerMethod.cpp methods/EulerModified.cpp methods/AdamsMethod.cpp functions/CDifferentialFunctionManager.cpp functions/CDifferentialFunction.cpp)

add_executable(vm_lab main.cpp ${SOURCES})
