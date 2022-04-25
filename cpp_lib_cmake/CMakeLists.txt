cmake_minimum_required(VERSION 3.18.1)

project(cmake_with_target_example)

set(LIB_SRC lib.cpp lib.hpp)

add_library(working_a STATIC ${LIB_SRC})

install(TARGETS working_a COMPONENT working ARCHIVE DESTINATION lib)
install(FILES lib.hpp DESTINATION include)
