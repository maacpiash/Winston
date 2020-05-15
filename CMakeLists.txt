cmake_minimum_required(VERSION 3.15)
project(Winston C)

set(CMAKE_C_STANDARD 11)

add_library(Winston SHARED lib/list.h lib/list.c)
