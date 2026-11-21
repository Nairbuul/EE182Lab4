cmake_minimum_required(VERSION 3.5)
project(lab_8)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 11)
enable_testing()

set(INCLUDES_FOLDER includes)
FILE(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}   "${INCLUDES_FOLDER}/*.cpp" )

ADD_EXECUTABLE(main
    main.cpp
    ${SOURCE_FILES}
)

TARGET_LINK_LIBRARIES(main gtest)