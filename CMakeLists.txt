cmake_minimum_required(VERSION 3.15)
project(game)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

set(EMSCRIPTEN_INCLUDE_DIRS "/home/vushu/coding/repos/emsdk/upstream/emscripten/system/include")


if (NOT APPLE)
    find_package(Threads)
endif()

file(GLOB_RECURSE SOURCE_LIST
    "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

file(GLOB_RECURSE HEADER_LIST
    "${CMAKE_CURRENT_LIST_DIR}/src/*.h")

set (source "${CMAKE_SOURCE_DIR}/resources")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/resources")

add_executable(${PROJECT_NAME} ${HEADER_LIST} ${SOURCE_LIST})

# adding resources
add_custom_command(
    TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
    #COMMAND ${CMAKE_COMMAND} -E copy ${source} ${destination}
    DEPENDS ${destination}
    COMMENT "symbolic link resources folder from ${source} => ${destination}")


if (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
    # TODO(amitp): I don't know how to set this properly with add_compile_options
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_SDL=2")
    # adding resources
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --preload-file resources")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${EMSCRIPTEN_INCLUDE_DIRS}")

    # adding image types
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s SDL2_IMAGE_FORMATS='[png, bmp]'")

    set(SDL2_LIBRARIES "-s USE_SDL=2")
    set(SDL2_IMAGE_LIBRARIES "-s USE_SDL_IMAGE=2")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
else ()
    include(FindPkgConfig)
    pkg_search_module(SDL2 REQUIRED sdl2)
    pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
endif ()

#set(SDL2_LIBRARIES "-s USE_SDL=2")

#include(${EMSCRIPTEN_INCLUDE_CMAKE})
#include_directories(${EMSCRIPTEN_INCLUDE_DIRS})

#target_include_directories(${PROJECT_NAME} PUBLIC
#${EMSCRIPTEN_INCLUDE_DIRS})
#target_include_directories(${PROJECT_NAME} PUBLIC
#${SDL2_INCLUDE_DIRS})
#file (GLOB_RECURSE RESOURCES "resources/*.*")
target_include_directories(${PROJECT_NAME} PUBLIC
    ${EMSCRIPTEN_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC
    ${SDL2_INCLUDE_DIRS})

#target_include_directories(${PROJECT_NAME}
#$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#$<INSTALL_INTERFACE:include>
#PRIVATE src)

#set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set(CMAKE_CXX17_COMPILE_FEATURES "cxx_std_17")

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
