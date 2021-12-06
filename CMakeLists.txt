cmake_minimum_required(VERSION 3.15)
project(Two_Phase_Locking)

set(CMAKE_CXX_STANDARD 14)

add_executable(Two_Phase_Locking main.cpp Database.cpp Database.h LockManager.cpp LockManager.h Transaction.cpp Transaction.h)