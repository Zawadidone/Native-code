cmake_minimum_required(VERSION 3.14)
project(the-c-programming-language-2 C)

set(CMAKE_C_STANDARD 99)

add_executable(hello-world hello-world.c)

add_executable(temperature while.c)

add_executable(temperature-for for.c)

add_executable(define define.c)

add_executable(char char.c)

add_executable(getchar getchar.c)

add_executable(wc wc.c)
