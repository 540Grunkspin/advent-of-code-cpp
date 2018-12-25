file(COPY input.txt DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
include_directories(include)
add_executable(day2 src/main.cpp src/box_id.cpp include/box_id.h src/checksum.cpp include/checksum.h)