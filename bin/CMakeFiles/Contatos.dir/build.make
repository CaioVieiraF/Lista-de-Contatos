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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/doctor/Documents/Programming/C C++/C/contatos/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/doctor/Documents/Programming/C C++/C/contatos/bin"

# Include any dependencies generated for this target.
include CMakeFiles/Contatos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Contatos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Contatos.dir/flags.make

CMakeFiles/Contatos.dir/ex01.c.o: CMakeFiles/Contatos.dir/flags.make
CMakeFiles/Contatos.dir/ex01.c.o: /home/doctor/Documents/Programming/C\ C++/C/contatos/src/ex01.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/doctor/Documents/Programming/C C++/C/contatos/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Contatos.dir/ex01.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Contatos.dir/ex01.c.o   -c "/home/doctor/Documents/Programming/C C++/C/contatos/src/ex01.c"

CMakeFiles/Contatos.dir/ex01.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Contatos.dir/ex01.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/doctor/Documents/Programming/C C++/C/contatos/src/ex01.c" > CMakeFiles/Contatos.dir/ex01.c.i

CMakeFiles/Contatos.dir/ex01.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Contatos.dir/ex01.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/doctor/Documents/Programming/C C++/C/contatos/src/ex01.c" -o CMakeFiles/Contatos.dir/ex01.c.s

# Object files for target Contatos
Contatos_OBJECTS = \
"CMakeFiles/Contatos.dir/ex01.c.o"

# External object files for target Contatos
Contatos_EXTERNAL_OBJECTS =

Contatos: CMakeFiles/Contatos.dir/ex01.c.o
Contatos: CMakeFiles/Contatos.dir/build.make
Contatos: CMakeFiles/Contatos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/doctor/Documents/Programming/C C++/C/contatos/bin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Contatos"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Contatos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Contatos.dir/build: Contatos

.PHONY : CMakeFiles/Contatos.dir/build

CMakeFiles/Contatos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Contatos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Contatos.dir/clean

CMakeFiles/Contatos.dir/depend:
	cd "/home/doctor/Documents/Programming/C C++/C/contatos/bin" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/doctor/Documents/Programming/C C++/C/contatos/src" "/home/doctor/Documents/Programming/C C++/C/contatos/src" "/home/doctor/Documents/Programming/C C++/C/contatos/bin" "/home/doctor/Documents/Programming/C C++/C/contatos/bin" "/home/doctor/Documents/Programming/C C++/C/contatos/bin/CMakeFiles/Contatos.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Contatos.dir/depend
