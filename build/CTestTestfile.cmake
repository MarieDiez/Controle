# CMake generated Testfile for 
# Source directory: /win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/Controle/src
# Build directory: /win/Users/LoïcetMarie/Documents/Marie/Cours/Fac/L2/S3/Programmation C/Controle/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test-append[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-append")
add_test(test-append[normal] "./test-append")
add_test(test-copy_clone[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-copy_clone")
add_test(test-copy_clone[normal] "./test-copy_clone")
add_test(test-create_destroy[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-create_destroy")
add_test(test-create_destroy[normal] "./test-create_destroy")
add_test(test-init_finish[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-init_finish")
add_test(test-init_finish[normal] "./test-init_finish")
add_test(test-prepend[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-prepend")
add_test(test-prepend[normal] "./test-prepend")
add_test(test-remove[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-remove")
add_test(test-remove[normal] "./test-remove")
add_test(test-to-string[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-to-string")
add_test(test-to-string[normal] "./test-to-string")
add_test(test-toString[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-toString")
add_test(test-toString[normal] "./test-toString")
add_test(test-write[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-write")
add_test(test-write[normal] "./test-write")
