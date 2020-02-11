cmake_minimum_required(VERSION 3.15)
project(game)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
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
# ecs lib
#add_subdirectory(external/entt)
set(ENTT_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/external/entt/single_include")
#target_link_libraries(${PROJECT_NAME} EnTT) #creates the runtime resources

# adding resources
message("SYSTEM IS:" "${CMAKE_SYSTEM_NAME}")
add_custom_command(
    TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
    #COMMAND ${CMAKE_COMMAND} -E copy ${source} ${destination}
    DEPENDS ${destination}
    COMMENT "symbolic link resources folder from ${source} => ${destination}")

if (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")

    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    target_link_libraries(${PROJECT_NAME} "-s WASM=1") #web assembly FTW
    target_link_libraries(${PROJECT_NAME} "-s USE_SDL=2")
    target_link_libraries(${PROJECT_NAME} "-s USE_SDL_IMAGE=2")
    target_link_libraries(${PROJECT_NAME} "-s SDL2_IMAGE_FORMATS='[png]'")
    target_link_libraries(${PROJECT_NAME} "--preload-file resources")
    target_link_libraries(${PROJECT_NAME} "-o gameSdl2.html")
    target_link_libraries(${PROJECT_NAME} "-s DEMANGLE_SUPPORT=1")
    target_compile_options(${PROJECT_NAME} PUBLIC "-O2") #creates the runtime resources
    target_link_libraries(${PROJECT_NAME} "-O2") #creates the runtime resources
    target_include_directories(${PROJECT_NAME} PUBLIC ${ENTT_INCLUDE_DIR})
else ()
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    #find_package(SDL2_ttf REQUIRED)

    target_include_directories(${PROJECT_NAME} PUBLIC
        ${ENTT_INCLUDE_DIR}
        ${EMSCRIPTEN_INCLUDE_DIRS}
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS})
    #${SDL2_TTF_INCLUDE_DIR})

    #message("sdfasd" ${SDL2_TTF_INCLUDE_DIRS})

    target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

    set(CMAKE_CXX17_COMPILE_FEATURES "cxx_std_17")
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
    #${SDL2_TTF_LIBRARY})

endif ()

