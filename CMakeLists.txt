#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.8)
# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(snake-game)

# Set version information in a config.h file
set(snake-game_VERSION_MAJOR 1)
set(snake-game_VERSION_MINOR 0)
configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
	)
include_directories("includes")

# Define sources and executable
file(GLOB SOURCES src/*.cpp includes/*)
set(EXECUTABLE_NAME "snake-game")
add_executable(${EXECUTABLE_NAME} WIN32 ${SOURCES} )


# Detect and add SFML
if(WIN32)
	file(COPY "${SFML_ROOT}/cmake" DESTINATION ${PROJECT_SOURCE_DIR})
	set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/" ${CMAKE_MODULE_PATH})
endif(WIN32)
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics audio)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# copy dependencies
file(COPY textures sounds data DESTINATION ${PROJECT_BINARY_DIR})
if(WIN32)
	file(COPY "${SFML_ROOT}/bin/" DESTINATION ${PROJECT_BINARY_DIR})
endif(WIN32)

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
install(DIRECTORY textures sounds data DESTINATION bin)
if(WIN32)	
	install(DIRECTORY "${SFML_ROOT}/bin/" DESTINATION bin)
endif(WIN32)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${snake-game_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${snake-game_VERSION_MINOR}")
include(CPack)