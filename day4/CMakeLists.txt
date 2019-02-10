file(COPY input.txt DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
include_directories(include)
add_executable(day4 src/main.cpp)