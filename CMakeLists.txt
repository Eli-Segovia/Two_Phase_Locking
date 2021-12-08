cmake_minimum_required(VERSION 3.17)
project(Two_Phase_Locking)

set(CMAKE_CXX_STANDARD 14)


add_executable(Two_Phase_Locking main.cpp LockManager.cpp Transaction.cpp Database.cpp)