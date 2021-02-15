cmake_minimum_required(VERSION 3.17)

project(test)
set(CMAKE_C_STANDARD 99)

include_directories(
        ./LabaratoryWork/Part1/Topic2/ex02
        ./LabaratoryWork/Part1/Topic2/ex06
        ./LabaratoryWork/Part1/Topic2/ex07(laba3)

                    )
link_directories(
        ./LabaratoryWork/Part1/Topic2/ex02
        ./LabaratoryWork/Part1/Topic2/ex06
        ./LabaratoryWork/Part1/Topic2/ex07(laba3)
        )

#file(GLOB SOURCE_LABA1 "LabaratoryWork/Part1/Topic2/ex03/*cpp") #ПРОХОДИТ ПО ПАПКЕ СОБИРАЯ ВСЕ ФАИЛЫ
#set(GLOB SOURCE_LABA1 LabaratoryWork/Part1/Topic2/ex02/ex02.cpp LabaratoryWork/Part1/Topic2/ex04(laba1)/ex04.cpp)
#add_executable(laba1
#        LabaratoryWork/Part1/Topic2/ex02/dynamic_stack.cpp
#        LabaratoryWork/Part1/Topic2/ex04\(laba1\)/ex04.cpp
#        )


#include_directories(LabaratoryWork/)
#link_directories(LabaratoryWork/)
#LABA2
#add_executable(laba2
#        LabaratoryWork/Part1/Topic2/ex05(laba2)/

#        )

#LABA 3
add_executable(laba3
        LabaratoryWork/Part1/Topic2/ex06/dynamic_queue.cpp
#        LabaratoryWork/Part1/Topic2/ex07\(laba3\)/ex07.cpp
        )

