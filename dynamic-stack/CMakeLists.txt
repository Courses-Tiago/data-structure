cmake_minimum_required(VERSION 3.18)

project(stack)

add_executable(stack main.c
               stack/stack.h
               stack/stack.c
)

target_include_directories(stack PRIVATE stack/)