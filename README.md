## Data Structure

### This repository should contain the main data structure written in C language.

#### CMake is used to build
1 - How to build and run: \
`$ cd desired_data_structure/`\
`$ mkdir build`\
`$ cd build/`\
`$ cmake .S ../ -B .`\
`$ make`\
`$ ./desired_data_structure`

#### Valgring may be used to check memory leaks
2 - How to use valgrind: \
`$ sudo apt install valgrind`\
`$ valgrind --leak-check=full ./executable`
