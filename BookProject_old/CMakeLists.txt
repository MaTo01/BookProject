cmake_minimum_required(VERSION 2.8)
project(book VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(Header)

add_executable(book 
    main.cpp
)

add_library(Date
    Headers/Date.hpp
    Source/Date.cpp
)

add_library(Isbn
    Headers/Isbn.hpp
    Source/Isbn.cpp
)

add_library(Book
    Headers/Book.hpp
    Source/Book.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
