file(COPY input.txt DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
include_directories(include)
add_executable(day3 src/main.cpp include/claim.hpp src/claim.cpp)