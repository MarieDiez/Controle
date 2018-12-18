cmake_minimum_required(VERSION 3.0)

project(Polygon C)

# Précision pour cmake: forcer l'ajout des chemins d'installation pour l'exécution
# voir https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_RPATH_USE_LINK_PATH.html
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

# Pour relier à libpolygon.so
link_directories("${CMAKE_SOURCE_DIR}")

enable_testing()

find_program(VALGRIND "valgrind")

# Récupération dans la variable FILES des fichiers de test
file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/test-*.c")

# Pour tous les fichiers de test
foreach(FILENAME ${FILES})
	# Récupération dans la variable SRC du nom sans le préfixe du dossier
	get_filename_component(SRC ${FILENAME} NAME)
	# Récupération dans la variable TEST du nom sans le préfixe du dossier
	# et sans le suffixe
	get_filename_component(TEST ${FILENAME} NAME_WE)
	# Ajout d'un exécutable dépendant également de polygon.c, polygon.h et polygon.inc
	add_executable(${TEST} ${SRC} polygon.c polygon.h polygon.inc)
	# Assemblage du programme de test avec la librairie polygon déjà fournie
	target_link_libraries(${TEST} polygon)
	if(VALGRIND)
		# Ajout d'un test en utilisant valgrind
		add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./${TEST})
		# Ajout d'un test normal
    	add_test("${TEST}[normal]" ./${TEST})
    else()
    	# Ajout d'un test simple
    	add_test("${TEST}" ./${TEST})
	endif()
endforeach()

set(CPACK_SOURCE_GENERATOR "ZIP")
set(CPACK_SOURCE_IGNORE_FILES "~$;${CPACK_SOURCE_IGNORE_FILES}")
include(CPack)

