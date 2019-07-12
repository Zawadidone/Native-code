cmake_minimum_required(VERSION 3.14)
project(learn_c C)

set(CMAKE_C_STANDARD 99)


add_executable(hello-world hello-world.c)

add_executable(var-types var-types.c)

add_executable(arrays arrays.c)

add_executable(multi-arrays multi-arrays.c)

add_executable(condition condition.c)

add_executable(strings strings.c)

add_executable(for-loops for-loops.c)

add_executable(while while.c)

add_executable(functions functions.c)

add_executable(static static.c)
