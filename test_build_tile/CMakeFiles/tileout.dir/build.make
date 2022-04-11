# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mr_Isachenko/projects/tp_project/tp-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile

# Include any dependencies generated for this target.
include CMakeFiles/tileout.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tileout.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tileout.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tileout.dir/flags.make

CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.o: CMakeFiles/tileout.dir/flags.make
CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.o: ../src/convert_map_file_to_matrix.cpp
CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.o: CMakeFiles/tileout.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.o -MF CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.o.d -o CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.o -c /home/mr_Isachenko/projects/tp_project/tp-project/src/convert_map_file_to_matrix.cpp

CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mr_Isachenko/projects/tp_project/tp-project/src/convert_map_file_to_matrix.cpp > CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.i

CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mr_Isachenko/projects/tp_project/tp-project/src/convert_map_file_to_matrix.cpp -o CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.s

CMakeFiles/tileout.dir/src/tilemap.cpp.o: CMakeFiles/tileout.dir/flags.make
CMakeFiles/tileout.dir/src/tilemap.cpp.o: ../src/tilemap.cpp
CMakeFiles/tileout.dir/src/tilemap.cpp.o: CMakeFiles/tileout.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tileout.dir/src/tilemap.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tileout.dir/src/tilemap.cpp.o -MF CMakeFiles/tileout.dir/src/tilemap.cpp.o.d -o CMakeFiles/tileout.dir/src/tilemap.cpp.o -c /home/mr_Isachenko/projects/tp_project/tp-project/src/tilemap.cpp

CMakeFiles/tileout.dir/src/tilemap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tileout.dir/src/tilemap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mr_Isachenko/projects/tp_project/tp-project/src/tilemap.cpp > CMakeFiles/tileout.dir/src/tilemap.cpp.i

CMakeFiles/tileout.dir/src/tilemap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tileout.dir/src/tilemap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mr_Isachenko/projects/tp_project/tp-project/src/tilemap.cpp -o CMakeFiles/tileout.dir/src/tilemap.cpp.s

CMakeFiles/tileout.dir/src/default_map_settings.cpp.o: CMakeFiles/tileout.dir/flags.make
CMakeFiles/tileout.dir/src/default_map_settings.cpp.o: ../src/default_map_settings.cpp
CMakeFiles/tileout.dir/src/default_map_settings.cpp.o: CMakeFiles/tileout.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tileout.dir/src/default_map_settings.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tileout.dir/src/default_map_settings.cpp.o -MF CMakeFiles/tileout.dir/src/default_map_settings.cpp.o.d -o CMakeFiles/tileout.dir/src/default_map_settings.cpp.o -c /home/mr_Isachenko/projects/tp_project/tp-project/src/default_map_settings.cpp

CMakeFiles/tileout.dir/src/default_map_settings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tileout.dir/src/default_map_settings.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mr_Isachenko/projects/tp_project/tp-project/src/default_map_settings.cpp > CMakeFiles/tileout.dir/src/default_map_settings.cpp.i

CMakeFiles/tileout.dir/src/default_map_settings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tileout.dir/src/default_map_settings.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mr_Isachenko/projects/tp_project/tp-project/src/default_map_settings.cpp -o CMakeFiles/tileout.dir/src/default_map_settings.cpp.s

CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.o: CMakeFiles/tileout.dir/flags.make
CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.o: ../src/tiles/default_tile_settings.cpp
CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.o: CMakeFiles/tileout.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.o -MF CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.o.d -o CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.o -c /home/mr_Isachenko/projects/tp_project/tp-project/src/tiles/default_tile_settings.cpp

CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mr_Isachenko/projects/tp_project/tp-project/src/tiles/default_tile_settings.cpp > CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.i

CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mr_Isachenko/projects/tp_project/tp-project/src/tiles/default_tile_settings.cpp -o CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.s

CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.o: CMakeFiles/tileout.dir/flags.make
CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.o: ../src/tiles/initialization_of_tiles.cpp
CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.o: CMakeFiles/tileout.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.o -MF CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.o.d -o CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.o -c /home/mr_Isachenko/projects/tp_project/tp-project/src/tiles/initialization_of_tiles.cpp

CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mr_Isachenko/projects/tp_project/tp-project/src/tiles/initialization_of_tiles.cpp > CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.i

CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mr_Isachenko/projects/tp_project/tp-project/src/tiles/initialization_of_tiles.cpp -o CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.s

CMakeFiles/tileout.dir/src/tiles/tile.cpp.o: CMakeFiles/tileout.dir/flags.make
CMakeFiles/tileout.dir/src/tiles/tile.cpp.o: ../src/tiles/tile.cpp
CMakeFiles/tileout.dir/src/tiles/tile.cpp.o: CMakeFiles/tileout.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tileout.dir/src/tiles/tile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tileout.dir/src/tiles/tile.cpp.o -MF CMakeFiles/tileout.dir/src/tiles/tile.cpp.o.d -o CMakeFiles/tileout.dir/src/tiles/tile.cpp.o -c /home/mr_Isachenko/projects/tp_project/tp-project/src/tiles/tile.cpp

CMakeFiles/tileout.dir/src/tiles/tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tileout.dir/src/tiles/tile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mr_Isachenko/projects/tp_project/tp-project/src/tiles/tile.cpp > CMakeFiles/tileout.dir/src/tiles/tile.cpp.i

CMakeFiles/tileout.dir/src/tiles/tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tileout.dir/src/tiles/tile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mr_Isachenko/projects/tp_project/tp-project/src/tiles/tile.cpp -o CMakeFiles/tileout.dir/src/tiles/tile.cpp.s

CMakeFiles/tileout.dir/main.cpp.o: CMakeFiles/tileout.dir/flags.make
CMakeFiles/tileout.dir/main.cpp.o: main.cpp
CMakeFiles/tileout.dir/main.cpp.o: CMakeFiles/tileout.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/tileout.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tileout.dir/main.cpp.o -MF CMakeFiles/tileout.dir/main.cpp.o.d -o CMakeFiles/tileout.dir/main.cpp.o -c /home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile/main.cpp

CMakeFiles/tileout.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tileout.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile/main.cpp > CMakeFiles/tileout.dir/main.cpp.i

CMakeFiles/tileout.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tileout.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile/main.cpp -o CMakeFiles/tileout.dir/main.cpp.s

# Object files for target tileout
tileout_OBJECTS = \
"CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.o" \
"CMakeFiles/tileout.dir/src/tilemap.cpp.o" \
"CMakeFiles/tileout.dir/src/default_map_settings.cpp.o" \
"CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.o" \
"CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.o" \
"CMakeFiles/tileout.dir/src/tiles/tile.cpp.o" \
"CMakeFiles/tileout.dir/main.cpp.o"

# External object files for target tileout
tileout_EXTERNAL_OBJECTS =

../bin/tileout: CMakeFiles/tileout.dir/src/convert_map_file_to_matrix.cpp.o
../bin/tileout: CMakeFiles/tileout.dir/src/tilemap.cpp.o
../bin/tileout: CMakeFiles/tileout.dir/src/default_map_settings.cpp.o
../bin/tileout: CMakeFiles/tileout.dir/src/tiles/default_tile_settings.cpp.o
../bin/tileout: CMakeFiles/tileout.dir/src/tiles/initialization_of_tiles.cpp.o
../bin/tileout: CMakeFiles/tileout.dir/src/tiles/tile.cpp.o
../bin/tileout: CMakeFiles/tileout.dir/main.cpp.o
../bin/tileout: CMakeFiles/tileout.dir/build.make
../bin/tileout: CMakeFiles/tileout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../bin/tileout"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tileout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tileout.dir/build: ../bin/tileout
.PHONY : CMakeFiles/tileout.dir/build

CMakeFiles/tileout.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tileout.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tileout.dir/clean

CMakeFiles/tileout.dir/depend:
	cd /home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mr_Isachenko/projects/tp_project/tp-project /home/mr_Isachenko/projects/tp_project/tp-project /home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile /home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile /home/mr_Isachenko/projects/tp_project/tp-project/test_build_tile/CMakeFiles/tileout.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tileout.dir/depend
