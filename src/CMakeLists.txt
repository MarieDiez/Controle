cmake_minimum_required(VERSION 3.0)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
project(Nom C)


#find_package(Fraction REQUIRED)
#include_directories(${FRACTION_INCLUDE_DIRS})
#link_directories(${FRACTION_LIB_DIRS})


add_library(nom SHARED nom.c nom.h nom.inc)
target_link_libraries(nom ${FRACTION_LIBRARIES})
install(
	TARGETS nom
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
)
install(
	FILES nom.h
	DESTINATION include
)
include(CMakePackageConfigHelpers)
configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/NomConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/NomConfig.cmake
	INSTALL_DESTINATION cmake
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/NomConfig.cmake
	DESTINATION cmake
)
enable_testing()
find_program(VALGRIND "valgrind")
file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/test-*.c")
foreach(FILENAME ${FILES})
	get_filename_component(SRC ${FILENAME} NAME)
	get_filename_component(TEST ${FILENAME} NAME_WE)
	add_executable(${TEST} ${SRC} nom.h nom.inc)
	add_dependencies(${TEST} nom)
	target_link_libraries(${TEST} nom)
	if(VALGRIND)
		add_test("${TEST}[valgrind]" ${VALGRIND} --leak-check=full --quiet --error-exitcode=1 ./${TEST})
	add_test("${TEST}[normal]" ./${TEST})
	else()
	add_test("${TEST}" ./${TEST})
		endif()
	endforeach()
		set(CPACK_SOURCE_GENERATOR "ZIP")
	set(CPACK_SOURCE_IGNORE_FILES "~$;${CPACK_SOURCE_IGNORE_FILES}")
	include(CPack)

