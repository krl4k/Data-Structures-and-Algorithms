cmake_minimum_required(VERSION 3.17)

project(test)
set(CMAKE_C_STANDARD 99)

include_directories(./Algorithms ./Strcutures/ ./Strcutures/LinkedList) #ПУТЬ К ДИРЕКТОРИИ
link_directories(./Algorithms ./Strcutures/ ./Strcutures/LinkedList)
add_executable(test
        Algorithms/Quick_sort.cpp
        )#СОЗДАНИЕ ИСПОЛЬНЯЕМОГО ФАИЛА
