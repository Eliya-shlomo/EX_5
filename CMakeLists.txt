cmake_minimum_required(VERSION 3.25)
project(EX_5)

set(CMAKE_CXX_STANDARD 17)

add_executable(EX_5 main.cpp Demo.cpp doctest.h TestCounter.cpp sources/MagicalContainer.cpp Test.cpp sources/AscendingIterator.cpp sources/PrimeIterator.cpp sources/SideCrossIterator.cpp)
