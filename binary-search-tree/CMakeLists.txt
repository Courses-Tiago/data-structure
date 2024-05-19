cmake_minimum_required(VERSION 3.18)

project(bst C)

add_executable(bst main.c
               tree/binary_search_tree.h
               tree/binary_search_tree.c
)

target_include_directories(bst PRIVATE tree/)