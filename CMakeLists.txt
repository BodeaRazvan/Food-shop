cmake_minimum_required(VERSION 3.15)
project(FoodShop C)

set(CMAKE_C_STANDARD 99)

add_executable(FoodShop main.c Functions.h Food.c AdditionalItems.c User.c)
