cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)
project("LearnOpenGL")

list(APPEND SOURCE_FILES
    src/main.cpp
    src/Shader.hpp
    src/Shader.cpp
    "Shader Files/shader.fs"
    "Shader Files/shader.vs"
    vendors/glfw/include/GLFW/glfw3.h
    vendors/glfw/include/GLFW/glfw3native.h
    vendors/glad/src/glad.c
    vendors/stb/stb_image.cpp
)

source_group(Shaders FILES
	"Shader Files/shader.fs"
	"Shader Files/shader.vs"
)

source_group(vendors/stb FILES
	vendors/stb/stb_image.cpp
)

add_executable(LearnOpenGL ${SOURCE_FILES})

set_target_properties(LearnOpenGL PROPERTIES
	XCODE_GENERATE_SCHEME TRUE
	XCODE_SCHEME_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/src
)

target_include_directories(LearnOpenGL PRIVATE 
	vendors/glfw/include
	vendors/glad/include
	vendors/stb
	vendors/glm
)

add_library(libglfw3 SHARED IMPORTED)
set_target_properties(libglfw3 PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/vendors/glfw/libglfw3.a)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})

find_library(COCOA_LIBRARY Cocoa REQUIRED)
find_library(IOKIT_LIBRARY IOKit REQUIRED)
find_library(COREVID_LIBRARY CoreVideo REQUIRED)
message(${COCOA_LIBRARY})
message(${IOKIT_LIBRARY})
message(${COREVID_LIBRARY})

target_link_libraries(LearnOpenGL PRIVATE
	libglfw3
	${OPENGL_LIBRARIES}
	${COCOA_LIBRARY} ${COREVID_LIBRARY} ${IOKIT_LIBRARY}
)
