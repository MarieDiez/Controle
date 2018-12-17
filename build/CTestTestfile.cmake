# CMake generated Testfile for 
# Source directory: /win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/Controle/src
# Build directory: /win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/Controle/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test-nom[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-nom")
add_test(test-nom[normal] "./test-nom")
