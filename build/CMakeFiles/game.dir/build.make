# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/252/bin/cmake

# The command to remove a file.
RM = /snap/cmake/252/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vushu/Desktop/emscripten_game_blob

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vushu/Desktop/emscripten_game_blob/build

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/src/Collision_corners.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Collision_corners.cpp.o: ../src/Collision_corners.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/src/Collision_corners.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/Collision_corners.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/Collision_corners.cpp

CMakeFiles/game.dir/src/Collision_corners.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Collision_corners.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/Collision_corners.cpp > CMakeFiles/game.dir/src/Collision_corners.cpp.i

CMakeFiles/game.dir/src/Collision_corners.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Collision_corners.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/Collision_corners.cpp -o CMakeFiles/game.dir/src/Collision_corners.cpp.s

CMakeFiles/game.dir/src/animated_sprite.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/animated_sprite.cpp.o: ../src/animated_sprite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/src/animated_sprite.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/animated_sprite.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/animated_sprite.cpp

CMakeFiles/game.dir/src/animated_sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/animated_sprite.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/animated_sprite.cpp > CMakeFiles/game.dir/src/animated_sprite.cpp.i

CMakeFiles/game.dir/src/animated_sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/animated_sprite.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/animated_sprite.cpp -o CMakeFiles/game.dir/src/animated_sprite.cpp.s

CMakeFiles/game.dir/src/collision_system.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/collision_system.cpp.o: ../src/collision_system.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/src/collision_system.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/collision_system.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/collision_system.cpp

CMakeFiles/game.dir/src/collision_system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/collision_system.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/collision_system.cpp > CMakeFiles/game.dir/src/collision_system.cpp.i

CMakeFiles/game.dir/src/collision_system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/collision_system.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/collision_system.cpp -o CMakeFiles/game.dir/src/collision_system.cpp.s

CMakeFiles/game.dir/src/consumable_system.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/consumable_system.cpp.o: ../src/consumable_system.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/src/consumable_system.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/consumable_system.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/consumable_system.cpp

CMakeFiles/game.dir/src/consumable_system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/consumable_system.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/consumable_system.cpp > CMakeFiles/game.dir/src/consumable_system.cpp.i

CMakeFiles/game.dir/src/consumable_system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/consumable_system.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/consumable_system.cpp -o CMakeFiles/game.dir/src/consumable_system.cpp.s

CMakeFiles/game.dir/src/factories.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/factories.cpp.o: ../src/factories.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/src/factories.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/factories.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/factories.cpp

CMakeFiles/game.dir/src/factories.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/factories.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/factories.cpp > CMakeFiles/game.dir/src/factories.cpp.i

CMakeFiles/game.dir/src/factories.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/factories.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/factories.cpp -o CMakeFiles/game.dir/src/factories.cpp.s

CMakeFiles/game.dir/src/game.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.dir/src/game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/game.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/game.cpp

CMakeFiles/game.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/game.cpp > CMakeFiles/game.dir/src/game.cpp.i

CMakeFiles/game.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/game.cpp -o CMakeFiles/game.dir/src/game.cpp.s

CMakeFiles/game.dir/src/gravity_system.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/gravity_system.cpp.o: ../src/gravity_system.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/game.dir/src/gravity_system.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/gravity_system.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/gravity_system.cpp

CMakeFiles/game.dir/src/gravity_system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/gravity_system.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/gravity_system.cpp > CMakeFiles/game.dir/src/gravity_system.cpp.i

CMakeFiles/game.dir/src/gravity_system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/gravity_system.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/gravity_system.cpp -o CMakeFiles/game.dir/src/gravity_system.cpp.s

CMakeFiles/game.dir/src/items/apple.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/items/apple.cpp.o: ../src/items/apple.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/game.dir/src/items/apple.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/items/apple.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/items/apple.cpp

CMakeFiles/game.dir/src/items/apple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/items/apple.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/items/apple.cpp > CMakeFiles/game.dir/src/items/apple.cpp.i

CMakeFiles/game.dir/src/items/apple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/items/apple.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/items/apple.cpp -o CMakeFiles/game.dir/src/items/apple.cpp.s

CMakeFiles/game.dir/src/main.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/game.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/main.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/main.cpp

CMakeFiles/game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/main.cpp > CMakeFiles/game.dir/src/main.cpp.i

CMakeFiles/game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/main.cpp -o CMakeFiles/game.dir/src/main.cpp.s

CMakeFiles/game.dir/src/move_system.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/move_system.cpp.o: ../src/move_system.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/game.dir/src/move_system.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/move_system.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/move_system.cpp

CMakeFiles/game.dir/src/move_system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/move_system.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/move_system.cpp > CMakeFiles/game.dir/src/move_system.cpp.i

CMakeFiles/game.dir/src/move_system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/move_system.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/move_system.cpp -o CMakeFiles/game.dir/src/move_system.cpp.s

CMakeFiles/game.dir/src/player_system.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/player_system.cpp.o: ../src/player_system.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/game.dir/src/player_system.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/player_system.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/player_system.cpp

CMakeFiles/game.dir/src/player_system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/player_system.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/player_system.cpp > CMakeFiles/game.dir/src/player_system.cpp.i

CMakeFiles/game.dir/src/player_system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/player_system.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/player_system.cpp -o CMakeFiles/game.dir/src/player_system.cpp.s

CMakeFiles/game.dir/src/render_system.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/render_system.cpp.o: ../src/render_system.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/game.dir/src/render_system.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/render_system.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/render_system.cpp

CMakeFiles/game.dir/src/render_system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/render_system.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/render_system.cpp > CMakeFiles/game.dir/src/render_system.cpp.i

CMakeFiles/game.dir/src/render_system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/render_system.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/render_system.cpp -o CMakeFiles/game.dir/src/render_system.cpp.s

CMakeFiles/game.dir/src/text.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/text.cpp.o: ../src/text.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/game.dir/src/text.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/text.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/text.cpp

CMakeFiles/game.dir/src/text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/text.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/text.cpp > CMakeFiles/game.dir/src/text.cpp.i

CMakeFiles/game.dir/src/text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/text.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/text.cpp -o CMakeFiles/game.dir/src/text.cpp.s

CMakeFiles/game.dir/src/text_system.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/text_system.cpp.o: ../src/text_system.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/game.dir/src/text_system.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/text_system.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/text_system.cpp

CMakeFiles/game.dir/src/text_system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/text_system.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/text_system.cpp > CMakeFiles/game.dir/src/text_system.cpp.i

CMakeFiles/game.dir/src/text_system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/text_system.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/text_system.cpp -o CMakeFiles/game.dir/src/text_system.cpp.s

CMakeFiles/game.dir/src/texture.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/texture.cpp.o: ../src/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/game.dir/src/texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/texture.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/texture.cpp

CMakeFiles/game.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/texture.cpp > CMakeFiles/game.dir/src/texture.cpp.i

CMakeFiles/game.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/texture.cpp -o CMakeFiles/game.dir/src/texture.cpp.s

CMakeFiles/game.dir/src/tilemap.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/tilemap.cpp.o: ../src/tilemap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/game.dir/src/tilemap.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/tilemap.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/tilemap.cpp

CMakeFiles/game.dir/src/tilemap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/tilemap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/tilemap.cpp > CMakeFiles/game.dir/src/tilemap.cpp.i

CMakeFiles/game.dir/src/tilemap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/tilemap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/tilemap.cpp -o CMakeFiles/game.dir/src/tilemap.cpp.s

CMakeFiles/game.dir/src/timer.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/timer.cpp.o: ../src/timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/game.dir/src/timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/timer.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/timer.cpp

CMakeFiles/game.dir/src/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/timer.cpp > CMakeFiles/game.dir/src/timer.cpp.i

CMakeFiles/game.dir/src/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/timer.cpp -o CMakeFiles/game.dir/src/timer.cpp.s

CMakeFiles/game.dir/src/utils.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/utils.cpp.o: ../src/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/game.dir/src/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/utils.cpp.o -c /home/vushu/Desktop/emscripten_game_blob/src/utils.cpp

CMakeFiles/game.dir/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vushu/Desktop/emscripten_game_blob/src/utils.cpp > CMakeFiles/game.dir/src/utils.cpp.i

CMakeFiles/game.dir/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vushu/Desktop/emscripten_game_blob/src/utils.cpp -o CMakeFiles/game.dir/src/utils.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/src/Collision_corners.cpp.o" \
"CMakeFiles/game.dir/src/animated_sprite.cpp.o" \
"CMakeFiles/game.dir/src/collision_system.cpp.o" \
"CMakeFiles/game.dir/src/consumable_system.cpp.o" \
"CMakeFiles/game.dir/src/factories.cpp.o" \
"CMakeFiles/game.dir/src/game.cpp.o" \
"CMakeFiles/game.dir/src/gravity_system.cpp.o" \
"CMakeFiles/game.dir/src/items/apple.cpp.o" \
"CMakeFiles/game.dir/src/main.cpp.o" \
"CMakeFiles/game.dir/src/move_system.cpp.o" \
"CMakeFiles/game.dir/src/player_system.cpp.o" \
"CMakeFiles/game.dir/src/render_system.cpp.o" \
"CMakeFiles/game.dir/src/text.cpp.o" \
"CMakeFiles/game.dir/src/text_system.cpp.o" \
"CMakeFiles/game.dir/src/texture.cpp.o" \
"CMakeFiles/game.dir/src/tilemap.cpp.o" \
"CMakeFiles/game.dir/src/timer.cpp.o" \
"CMakeFiles/game.dir/src/utils.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/src/Collision_corners.cpp.o
game: CMakeFiles/game.dir/src/animated_sprite.cpp.o
game: CMakeFiles/game.dir/src/collision_system.cpp.o
game: CMakeFiles/game.dir/src/consumable_system.cpp.o
game: CMakeFiles/game.dir/src/factories.cpp.o
game: CMakeFiles/game.dir/src/game.cpp.o
game: CMakeFiles/game.dir/src/gravity_system.cpp.o
game: CMakeFiles/game.dir/src/items/apple.cpp.o
game: CMakeFiles/game.dir/src/main.cpp.o
game: CMakeFiles/game.dir/src/move_system.cpp.o
game: CMakeFiles/game.dir/src/player_system.cpp.o
game: CMakeFiles/game.dir/src/render_system.cpp.o
game: CMakeFiles/game.dir/src/text.cpp.o
game: CMakeFiles/game.dir/src/text_system.cpp.o
game: CMakeFiles/game.dir/src/texture.cpp.o
game: CMakeFiles/game.dir/src/tilemap.cpp.o
game: CMakeFiles/game.dir/src/timer.cpp.o
game: CMakeFiles/game.dir/src/utils.cpp.o
game: CMakeFiles/game.dir/build.make
game: /usr/lib/x86_64-linux-gnu/libSDL2.so
game: /usr/lib/x86_64-linux-gnu/libSDL2main.a
game: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable game"
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "symbolic link resources folder from /home/vushu/Desktop/emscripten_game_blob/resources => /home/vushu/Desktop/emscripten_game_blob/build/resources"
	/snap/cmake/252/bin/cmake -E create_symlink /home/vushu/Desktop/emscripten_game_blob/resources /home/vushu/Desktop/emscripten_game_blob/build/resources
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game

.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /home/vushu/Desktop/emscripten_game_blob/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vushu/Desktop/emscripten_game_blob /home/vushu/Desktop/emscripten_game_blob /home/vushu/Desktop/emscripten_game_blob/build /home/vushu/Desktop/emscripten_game_blob/build /home/vushu/Desktop/emscripten_game_blob/build/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

