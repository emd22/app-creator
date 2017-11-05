cmake_minimum_required(VERSION 3.5)

file (GLOB_RECURSE SOURCES "*.c")
file (GLOB_RECURSE HEADERS "../include/cpl/*.h")

SET(GCC_COVERAGE_COMPILE_FLAGS "-g")

find_package(GTK2)

foreach(f IN LISTS SOURCES)
  get_filename_component(b ${f} NAME)
  set_source_files_properties(${f} PROPERTIES
    COMPILE_DEFINITIONS "__FILENAME__=${b}")
endforeach()
foreach(f IN LISTS HEADERS)
  get_filename_component(b ${f} NAME)
  set_source_files_properties(${f} PROPERTIES
    COMPILE_DEFINITIONS "__FILENAME__=${b}")
endforeach()

include_directories(
  ${CMAKE_CURRENT_LIST_DIR}/../include/cpl
)
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})


if(GTK2_FOUND)
  include_directories(${GTK2_INCLUDE_DIRS})
  add_executable(cpl ${SOURCES} ${HEADERS})
  target_link_libraries(cpl ${GTK2_LIBRARIES})
endif()