cmake_minimum_required(VERSION 3.18)

project(ordered_list C)

add_executable(ordered_list main.c
               ord_list/ordered_list.h
               ord_list/ordered_list.c
)

target_include_directories(ordered_list PRIVATE ord_list/)