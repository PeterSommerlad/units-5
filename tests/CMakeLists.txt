#  =============================================================
# Executable
#  =============================================================

MESSAGE("--->  ${units_SOURCE_DIR}")

include_directories(${units_SOURCE_DIR}/externals/Catch/single_include)
include_directories(${units_SOURCE_DIR}/include)

# IMPORTANT this must include only the main cpp file
add_executable (testunit
  ${units_SOURCE_DIR}/tests/main.cpp
  ${units_SOURCE_DIR}/tests/unit_test.cpp
)

target_link_libraries (testunit
  
)

