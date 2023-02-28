set(EULERMATHS_CXX_SOURCES
eulermaths.h
prime_factor.cpp
prime_factor.h)

add_library(EulerMaths ${EULERMATHS_CXX_SOURCES})

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(EulerMaths INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
          
# link to eulerproject_compiler_flags
target_link_libraries(EulerMaths euler_compiler_flags)

set_target_properties(EulerMaths PROPERTIES LINKER_LANGUAGE CXX)