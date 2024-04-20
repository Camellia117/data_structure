cmake_minimum_required(VERSION 3.10)
project(start)

file(GLOB SOURCES "*.cpp")

add_executable(My_Program ${SOURCES})
