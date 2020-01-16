cmake_minimum_required(VERSION 3.15)
project(FoodShop C)

set(CMAKE_C_STANDARD 99)

add_executable(FoodShop main.c Functions.h User.c AdditionalItems.c Cutlery.c StringFunctions.c StringFunctions.h Buyer_Struct_Functions.h Buyer_Struct_Functions.c Drinks_Struct_Functions.c Drinks_Struct_Functions.h SpecificFood_Struct_Functions.c SpecificFood_Struct_Functions.h)