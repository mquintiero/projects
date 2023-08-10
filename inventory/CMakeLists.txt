cmake_minimum_required(VERSION 3.18)
project(inventory)

set(CMAKE_CXX_STANDARD 14)

add_executable(inventory main.cpp Inventory.cpp Inventory.h Trie.cpp Trie.h)
