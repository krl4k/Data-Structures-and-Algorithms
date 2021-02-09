cmake_minimum_required(VERSION 3.17)

project(test)
set(CMAKE_C_STANDARD 99)

include_directories(./LabaratoryWork/ ./Algorithms ./Structures/ Structures/LinkedList ./tests) #ПУТЬ К ДИРЕКТОРИИ
link_directories(./Algorithms ./Structures/ Structures/LinkedList ./tests)

#file(GLOB SOURCE_LABA1 "LabaratoryWork/Part1/Topic2/ex03/*cpp") #ПРОХОДИТ ПО ПАПКЕ СОБИРАЯ ВСЕ ФАИЛЫ
#set(GLOB SOURCE_LABA1 LabaratoryWork/Part1/Topic2/ex02/ex02.cpp LabaratoryWork/Part1/Topic2/ex04(laba1)/ex04.cpp)
add_executable(laba1
#        ${SOURCE_LABA1}
        LabaratoryWork/Part1/Topic2/ex02/dynamic_stack.cpp
        LabaratoryWork/Part1/Topic2/ex04\(laba1\)/ex04.cpp

#        tests/test.cpp
#        tests/stack.cpp
        )#СОЗДАНИЕ ИСПОЛНЯЕМОГО ФАИЛА
