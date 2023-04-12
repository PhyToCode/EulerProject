# Macro to add quickly simple executables
function(add_programs_exe)
    if(ARGC LESS_EQUAL 0)
        message(FATAL_ERROR "Macro add_programs_exe requires arguments")
    endif()
    set(file ${ARGV0})
    if (ARGC GREATER_EQUAL 2)
        set(src_exe ${ARGV})
        list(REMOVE_AT src_exe 0)
    elseif(ARGC EQUAL 1)
        set(src_exe ${file}.cpp)
    endif()
    add_executable(${file} ${src_exe})
    target_link_libraries(${file} PUBLIC ${EXTRA_LIBS} euler_compiler_flags)
    target_include_directories(${file} PUBLIC "${PROJECT_BINARY_DIR}")
endfunction(add_programs_exe)

# Programs executables (one exercice = one executable)
set(programs_exe
    001_multiples_of_3_or_5
    002_even_fibonacci_numbers
    003_largest_prime_factor
    004_largest_palindrome_product
    005_smallest_multiple
    006_sum_square_difference
    007_10001st_prime
    008_largest_product_in_a_series
    009_special_pythagorean_triplet
    010_summation_of_primes
    011_largest_product_in_a_grid
    060_prime_pair_sets
)

# Generic target
foreach(target ${programs_exe})
    add_programs_exe(${target})
endforeach()