cmake_minimum_required(VERSION 3.0)

project(PrimeFactors C)

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

add_library(prime-factors SHARED prime-factors.c prime-factors.h prime-factors.inc)

target_link_libraries(prime-factors m)

#install(
#	TARGETS prime-factors
#	LIBRARY DESTINATION lib
#	ARCHIVE DESTINATION lib
#	RUNTIME DESTINATION bin
#)

#install(
#	FILES prime-factors.h
#	DESTINATION include
#)

#include(CMakePackageConfigHelpers)
#configure_package_config_file(
#	${CMAKE_CURRENT_SOURCE_DIR}/PrimeFactorsConfig.cmake.in
#	${CMAKE_CURRENT_BINARY_DIR}/PrimeFactorsConfig.cmake
#	INSTALL_DESTINATION cmake
#)
#install(
#	FILES ${CMAKE_CURRENT_BINARY_DIR}/PrimeFactorsConfig.cmake
#	DESTINATION cmake
#)

enable_testing()

find_program(VALGRIND "valgrind")

file(GLOB FILES "${CMAKE_CURRENT_SOURCE_DIR}/test-*.c")

foreach(FILENAME ${FILES})
	get_filename_component(SRC ${FILENAME} NAME)
	get_filename_component(TEST ${FILENAME} NAME_WE)
	add_executable(${TEST} ${SRC} prime-factors.h prime-factors.inc)
	add_dependencies(${TEST} prime-factors)
	target_link_libraries(${TEST} prime-factors)
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

