# EulerProject  
Repository to create a personnal library to solve various problems presented in the EulerProject.  
The goal is not only to solve each problem with the values given in the statements but with as many values as possible in order to have functional and efficient algorithms for any value and thus generalize each problem.

# Compilation with CMake  
To configure all the relevant Makefiles, please type the following commands from the top-level directory:

%prompt% mkdir build  
%prompt% cd build  
%prompt% cmake  ..  
%prompt% make  

To erase all files of sub-directory /build to recompile all with cmake, use the following command in the folder /build:  
%prompt% rm * -rfv