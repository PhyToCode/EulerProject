# Macro to add quickly simple executables
function(add_programs_exe)
    if(ARGC LESS_EQUAL 0)
        message(FATAL_ERROR "Macro add_scotch_exe requires arguments")
    endif()
    set(file ${ARGV0})
    if (ARGC GREATER_EQUAL 2)
        set(src_exe ${ARGV})
        list(REMOVE_AT src_exe 0)
    elseif(ARGC EQUAL 1)
        set(src_exe ${file}.cpp)
    endif()
    add_executable(${file} ${src_exe})
endfunction(add_programs_exe)

# Programs executables (one exercice = one executable)
set(programs_exe
    001_multiples_of_3_or_5
    002_even_fibonacci_numbers
    003_largest_prime_factor
)

# Generic target
foreach(target ${programs_exe})
    add_programs_exe(${target})
endforeach()