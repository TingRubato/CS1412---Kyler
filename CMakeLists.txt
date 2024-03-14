cmake_minimum_required(VERSION 3.27)
project(CS1412 C)

set(CMAKE_C_STANDARD 11)

add_library(CS1412 STATIC
        wirelessBill.c
        lab3_q1.c
        lab3_q2.c)
