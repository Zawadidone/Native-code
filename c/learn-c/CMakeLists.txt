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

add_executable(pointer pointer.c)

add_executable(struct struct.c)

add_executable(function_arg function_arg.c)

add_executable(function_arg_by_reference function_arg_by_reference.c)

add_executable(dynamic_allocation dynamic_allocation.c)

add_executable(dynamic dynamic.c)

add_executable(point_array point_array.c)

add_executable(recursion recursion.c)

add_executable(recursion-fact recursion-fact.c)

add_executable(test test.c)

add_executable(linked_lists linked_lists.c)

add_executable(binary_trees binary_trees.c)

add_executable(unions unions.c)

add_executable(pointer_arithmetics pointer_arithmetics.c)

add_executable(function_pointers function_pointers.c)
