cmake_minimum_required(VERSION 3.18)

project(queue)

add_executable(queue main.c
               queue/queue.h
               queue/queue.c
)

target_include_directories(queue PRIVATE queue/)