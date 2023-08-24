cmake_minimum_required(VERSION 3.21)
project(hash)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

add_executable(hash
        include/AVL.h
        include/hashtable.h
        include/linklist.h
        include/loading.h
        include/node.h
        include/queu.h
        include/treeNode.h
        src/AVL.cpp
        src/hashtable.cpp
        src/linklist.cpp
        src/loading.cpp
        src/node.cpp
        src/queu.cpp
        src/treeNode.cpp
        main.cpp)
