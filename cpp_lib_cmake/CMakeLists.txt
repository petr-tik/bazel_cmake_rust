cmake_minimum_required(VERSION 3.18.1)

project(cmake_with_target_example)
find_package (Python COMPONENTS Interpreter)

set(LIB_SRC lib.cpp lib.hpp)

add_library(working_a STATIC ${LIB_SRC})

add_custom_command(TARGET working_a
  POST_BUILD
  COMMAND bash -c "${Python_Interpreter} ${CMAKE_SOURCE_DIR}/post_build_ninja_summary.py -C ${CMAKE_BINARY_DIR} > ${CMAKE_BINARY_DIR}/working_a_$(date +'%Y_%m_%dT%H_%M_%S')_ninja_log_analysis"
  VERBATIM
  COMMENT "Analysing ninja logfile"
)


install(TARGETS working_a COMPONENT working ARCHIVE DESTINATION lib)
install(FILES lib.hpp DESTINATION include)
