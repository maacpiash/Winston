cmake_minimum_required(VERSION 3.21)
project(Winston C)

set(CMAKE_C_STANDARD 23)

add_library(Winston SHARED lib/list.c)
