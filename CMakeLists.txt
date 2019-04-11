cmake_minimum_required(VERSION 3.13)
project(Labo4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")

set(CMAKE_CXX_STANDARD 11)

add_executable(Labo4 main.cpp Vecteur.h Vecteur.cpp.h Matrice.h Matrice.cpp.h Arithmetic.h)