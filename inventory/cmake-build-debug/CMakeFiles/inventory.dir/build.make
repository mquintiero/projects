# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/inventory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/inventory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inventory.dir/flags.make

CMakeFiles/inventory.dir/main.cpp.o: CMakeFiles/inventory.dir/flags.make
CMakeFiles/inventory.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/inventory.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/inventory.dir/main.cpp.o -c /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/main.cpp

CMakeFiles/inventory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inventory.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/main.cpp > CMakeFiles/inventory.dir/main.cpp.i

CMakeFiles/inventory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inventory.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/main.cpp -o CMakeFiles/inventory.dir/main.cpp.s

CMakeFiles/inventory.dir/Inventory.cpp.o: CMakeFiles/inventory.dir/flags.make
CMakeFiles/inventory.dir/Inventory.cpp.o: ../Inventory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/inventory.dir/Inventory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/inventory.dir/Inventory.cpp.o -c /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/Inventory.cpp

CMakeFiles/inventory.dir/Inventory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inventory.dir/Inventory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/Inventory.cpp > CMakeFiles/inventory.dir/Inventory.cpp.i

CMakeFiles/inventory.dir/Inventory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inventory.dir/Inventory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/Inventory.cpp -o CMakeFiles/inventory.dir/Inventory.cpp.s

CMakeFiles/inventory.dir/Trie.cpp.o: CMakeFiles/inventory.dir/flags.make
CMakeFiles/inventory.dir/Trie.cpp.o: ../Trie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/inventory.dir/Trie.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/inventory.dir/Trie.cpp.o -c /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/Trie.cpp

CMakeFiles/inventory.dir/Trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inventory.dir/Trie.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/Trie.cpp > CMakeFiles/inventory.dir/Trie.cpp.i

CMakeFiles/inventory.dir/Trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inventory.dir/Trie.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/Trie.cpp -o CMakeFiles/inventory.dir/Trie.cpp.s

# Object files for target inventory
inventory_OBJECTS = \
"CMakeFiles/inventory.dir/main.cpp.o" \
"CMakeFiles/inventory.dir/Inventory.cpp.o" \
"CMakeFiles/inventory.dir/Trie.cpp.o"

# External object files for target inventory
inventory_EXTERNAL_OBJECTS =

inventory: CMakeFiles/inventory.dir/main.cpp.o
inventory: CMakeFiles/inventory.dir/Inventory.cpp.o
inventory: CMakeFiles/inventory.dir/Trie.cpp.o
inventory: CMakeFiles/inventory.dir/build.make
inventory: CMakeFiles/inventory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable inventory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inventory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inventory.dir/build: inventory

.PHONY : CMakeFiles/inventory.dir/build

CMakeFiles/inventory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inventory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inventory.dir/clean

CMakeFiles/inventory.dir/depend:
	cd /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/cmake-build-debug /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/cmake-build-debug /mnt/c/Users/manu_/OneDrive/Escritorio/projects/projects/inventory/cmake-build-debug/CMakeFiles/inventory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/inventory.dir/depend

