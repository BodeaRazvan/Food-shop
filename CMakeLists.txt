cmake_minimum_required(VERSION 3.15)
project(FoodShop C)

set(CMAKE_C_STANDARD 99)

add_executable(FoodShop main.c Functions.h User.c AdditionalItems.c Food.c StringFunctions.c StringFunctions.h FreeMemory.c)