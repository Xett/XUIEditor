# Projects Settings
cmake_minimum_required (VERSION 3.18)

include(ExternalProject)

project (TemplateApplication)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(json)

add_subdirectory(wxWidgets)

add_custom_command(OUTPUT "${CMAKE_SOURCE_DIR}/src/View/view.h" "${CMAKE_SOURCE_DIR}/src/View/view.cpp"
	DEPENDS wxrc
	COMMAND wxrc ${CMAKE_SOURCE_DIR}/TemplateApplication.xrc -c -e -o ${CMAKE_SOURCE_DIR}/src/View/view.cpp)

set(INPUT_FILES
	src/main.cpp
	src/Application.cpp
	src/Config.cpp
	src/View/XRC/MainFrame.cpp
	src/View/XRC/About.cpp
	src/View/XRC/SettingsFrame.cpp
	src/View/view.cpp
	src/Commands/CommandProcessor.cpp)

set(PCH_FILES
	src/View/XRC/MainFrame.hpp
	src/View/XRC/About.hpp
	src/View/XRC/SettingsFrame.hpp)

if (WIN32)
	add_executable(TemplateApplication WIN32 ${INPUT_FILES})
endif (WIN32)

if (UNIX)
	add_executable(TemplateApplication ${INPUT_FILES})
endif (UNIX)

target_link_libraries(TemplateApplication wx::net wx::core wx::base wx::xrc nlohmann_json::nlohmann_json)
target_precompile_headers(TemplateApplication PUBLIC src/View/XRC/pch.hpp PRIVATE ${PCH_HEADERS})
