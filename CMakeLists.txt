cmake_minimum_required(VERSION 4.1)
project(linux_basic C)

set(CMAKE_C_STANDARD 11)

#section01
add_executable(section01-ex1 section01/ex1/main.c)
add_executable(section01-ex2 section01/ex2/main.c)
add_executable(section01-ex3 section01/ex3/main.c)

#section02
add_executable(section02-ex1 section02/ex1/main.c)
add_executable(section02-ex2 section02/ex2/main.c)
add_executable(section02-ex3 section02/ex3/main.c)
add_executable(section02-ex4 section02/ex4/main.c)

#section03
add_executable(section03-ex1 section03/ex1/main.c)
add_executable(section03-ex2 section03/ex2/main.c)
add_executable(section03-ex3 section03/ex3/main.c)