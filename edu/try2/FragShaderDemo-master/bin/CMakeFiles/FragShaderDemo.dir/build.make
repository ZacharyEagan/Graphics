# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/bin

# Include any dependencies generated for this target.
include CMakeFiles/FragShaderDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FragShaderDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FragShaderDemo.dir/flags.make

CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o: CMakeFiles/FragShaderDemo.dir/flags.make
CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o: ../src/GLSL.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o"
	/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o -c /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/GLSL.cpp

CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.i"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/GLSL.cpp > CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.i

CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.s"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/GLSL.cpp -o CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.s

CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o.requires:
.PHONY : CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o.requires

CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o.provides: CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o.requires
	$(MAKE) -f CMakeFiles/FragShaderDemo.dir/build.make CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o.provides.build
.PHONY : CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o.provides

CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o.provides.build: CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o

CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o: CMakeFiles/FragShaderDemo.dir/flags.make
CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o: ../src/MatrixStack.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/bin/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o"
	/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o -c /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/MatrixStack.cpp

CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.i"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/MatrixStack.cpp > CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.i

CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.s"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/MatrixStack.cpp -o CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.s

CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o.requires:
.PHONY : CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o.requires

CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o.provides: CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o.requires
	$(MAKE) -f CMakeFiles/FragShaderDemo.dir/build.make CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o.provides.build
.PHONY : CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o.provides

CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o.provides.build: CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o

CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o: CMakeFiles/FragShaderDemo.dir/flags.make
CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o: ../src/Program.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/bin/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o"
	/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o -c /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/Program.cpp

CMakeFiles/FragShaderDemo.dir/src/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FragShaderDemo.dir/src/Program.cpp.i"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/Program.cpp > CMakeFiles/FragShaderDemo.dir/src/Program.cpp.i

CMakeFiles/FragShaderDemo.dir/src/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FragShaderDemo.dir/src/Program.cpp.s"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/Program.cpp -o CMakeFiles/FragShaderDemo.dir/src/Program.cpp.s

CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o.requires:
.PHONY : CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o.requires

CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o.provides: CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o.requires
	$(MAKE) -f CMakeFiles/FragShaderDemo.dir/build.make CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o.provides.build
.PHONY : CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o.provides

CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o.provides.build: CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o

CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o: CMakeFiles/FragShaderDemo.dir/flags.make
CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o: ../src/WindowManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/bin/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o"
	/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o -c /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/WindowManager.cpp

CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.i"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/WindowManager.cpp > CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.i

CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.s"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/WindowManager.cpp -o CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.s

CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o.requires:
.PHONY : CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o.requires

CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o.provides: CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/FragShaderDemo.dir/build.make CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o.provides.build
.PHONY : CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o.provides

CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o.provides.build: CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o

CMakeFiles/FragShaderDemo.dir/src/main.cpp.o: CMakeFiles/FragShaderDemo.dir/flags.make
CMakeFiles/FragShaderDemo.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/bin/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/FragShaderDemo.dir/src/main.cpp.o"
	/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FragShaderDemo.dir/src/main.cpp.o -c /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/main.cpp

CMakeFiles/FragShaderDemo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FragShaderDemo.dir/src/main.cpp.i"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/main.cpp > CMakeFiles/FragShaderDemo.dir/src/main.cpp.i

CMakeFiles/FragShaderDemo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FragShaderDemo.dir/src/main.cpp.s"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/src/main.cpp -o CMakeFiles/FragShaderDemo.dir/src/main.cpp.s

CMakeFiles/FragShaderDemo.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/FragShaderDemo.dir/src/main.cpp.o.requires

CMakeFiles/FragShaderDemo.dir/src/main.cpp.o.provides: CMakeFiles/FragShaderDemo.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/FragShaderDemo.dir/build.make CMakeFiles/FragShaderDemo.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/FragShaderDemo.dir/src/main.cpp.o.provides

CMakeFiles/FragShaderDemo.dir/src/main.cpp.o.provides.build: CMakeFiles/FragShaderDemo.dir/src/main.cpp.o

CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o: CMakeFiles/FragShaderDemo.dir/flags.make
CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o: ../ext/glad/src/glad.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/bin/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o"
	/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o   -c /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/ext/glad/src/glad.c

CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.i"
	/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/ext/glad/src/glad.c > CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.i

CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.s"
	/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/ext/glad/src/glad.c -o CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.s

CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o.requires:
.PHONY : CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o.requires

CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o.provides: CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o.requires
	$(MAKE) -f CMakeFiles/FragShaderDemo.dir/build.make CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o.provides.build
.PHONY : CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o.provides

CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o.provides.build: CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o

# Object files for target FragShaderDemo
FragShaderDemo_OBJECTS = \
"CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o" \
"CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o" \
"CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o" \
"CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o" \
"CMakeFiles/FragShaderDemo.dir/src/main.cpp.o" \
"CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o"

# External object files for target FragShaderDemo
FragShaderDemo_EXTERNAL_OBJECTS =

FragShaderDemo: CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o
FragShaderDemo: CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o
FragShaderDemo: CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o
FragShaderDemo: CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o
FragShaderDemo: CMakeFiles/FragShaderDemo.dir/src/main.cpp.o
FragShaderDemo: CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o
FragShaderDemo: CMakeFiles/FragShaderDemo.dir/build.make
FragShaderDemo: CMakeFiles/FragShaderDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable FragShaderDemo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FragShaderDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FragShaderDemo.dir/build: FragShaderDemo
.PHONY : CMakeFiles/FragShaderDemo.dir/build

CMakeFiles/FragShaderDemo.dir/requires: CMakeFiles/FragShaderDemo.dir/src/GLSL.cpp.o.requires
CMakeFiles/FragShaderDemo.dir/requires: CMakeFiles/FragShaderDemo.dir/src/MatrixStack.cpp.o.requires
CMakeFiles/FragShaderDemo.dir/requires: CMakeFiles/FragShaderDemo.dir/src/Program.cpp.o.requires
CMakeFiles/FragShaderDemo.dir/requires: CMakeFiles/FragShaderDemo.dir/src/WindowManager.cpp.o.requires
CMakeFiles/FragShaderDemo.dir/requires: CMakeFiles/FragShaderDemo.dir/src/main.cpp.o.requires
CMakeFiles/FragShaderDemo.dir/requires: CMakeFiles/FragShaderDemo.dir/ext/glad/src/glad.c.o.requires
.PHONY : CMakeFiles/FragShaderDemo.dir/requires

CMakeFiles/FragShaderDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FragShaderDemo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FragShaderDemo.dir/clean

CMakeFiles/FragShaderDemo.dir/depend:
	cd /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/bin /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/bin /home/zeagan/Desktop/Graphics/edu/try2/FragShaderDemo-master/bin/CMakeFiles/FragShaderDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FragShaderDemo.dir/depend

