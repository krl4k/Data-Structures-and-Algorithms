cmake_minimum_required(VERSION 3.17)

project(test)
set(CMAKE_C_STANDARD 99)

include_directories(./Algorithms ./Structures/ Structures/LinkedList ./tests) #ПУТЬ К ДИРЕКТОРИИ
link_directories(./Algorithms ./Structures/ Structures/LinkedList ./tests)

file(GLOB SOURCE_LABA1 "Labaratory Work/Part1/Topic2/ex01/*cpp") #ПРОХОДИТ ПО ПАПКЕ СОБИРАЯ ВСЕ ФАИЛЫ
add_executable(laba1
        ${SOURCE_LABA1}
#        tests/test.cpp
#        tests/stack.cpp
        )#СОЗДАНИЕ ИСПОЛНЯЕМОГО ФАИЛА
