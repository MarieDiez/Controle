# CMake generated Testfile for 
# Source directory: /disk/win/Mes Dossiers/Cours/Licence/S3/C/CC_nbPremier/cc/src
# Build directory: /disk/win/Mes Dossiers/Cours/Licence/S3/C/CC_nbPremier/cc/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test-create_destroy[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-create_destroy")
add_test(test-create_destroy[normal] "./test-create_destroy")
add_test(test-init-finish[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-init-finish")
add_test(test-init-finish[normal] "./test-init-finish")
add_test(test-prime_factores_get_number[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-prime_factores_get_number")
add_test(test-prime_factores_get_number[normal] "./test-prime_factores_get_number")
add_test(test-toString[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-toString")
add_test(test-toString[normal] "./test-toString")
add_test(test-write[valgrind] "/usr/bin/valgrind" "--leak-check=full" "--quiet" "--error-exitcode=1" "./test-write")
add_test(test-write[normal] "./test-write")
