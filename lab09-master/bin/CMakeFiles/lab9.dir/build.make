# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/bill/class/Graphics/lab09-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bill/class/Graphics/lab09-master/bin

# Include any dependencies generated for this target.
include CMakeFiles/lab9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab9.dir/flags.make

CMakeFiles/lab9.dir/src/MatrixStack.cpp.o: CMakeFiles/lab9.dir/flags.make
CMakeFiles/lab9.dir/src/MatrixStack.cpp.o: ../src/MatrixStack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/class/Graphics/lab09-master/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab9.dir/src/MatrixStack.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab9.dir/src/MatrixStack.cpp.o -c /home/bill/class/Graphics/lab09-master/src/MatrixStack.cpp

CMakeFiles/lab9.dir/src/MatrixStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab9.dir/src/MatrixStack.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/class/Graphics/lab09-master/src/MatrixStack.cpp > CMakeFiles/lab9.dir/src/MatrixStack.cpp.i

CMakeFiles/lab9.dir/src/MatrixStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab9.dir/src/MatrixStack.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/class/Graphics/lab09-master/src/MatrixStack.cpp -o CMakeFiles/lab9.dir/src/MatrixStack.cpp.s

CMakeFiles/lab9.dir/src/MatrixStack.cpp.o.requires:

.PHONY : CMakeFiles/lab9.dir/src/MatrixStack.cpp.o.requires

CMakeFiles/lab9.dir/src/MatrixStack.cpp.o.provides: CMakeFiles/lab9.dir/src/MatrixStack.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab9.dir/build.make CMakeFiles/lab9.dir/src/MatrixStack.cpp.o.provides.build
.PHONY : CMakeFiles/lab9.dir/src/MatrixStack.cpp.o.provides

CMakeFiles/lab9.dir/src/MatrixStack.cpp.o.provides.build: CMakeFiles/lab9.dir/src/MatrixStack.cpp.o


CMakeFiles/lab9.dir/src/Program.cpp.o: CMakeFiles/lab9.dir/flags.make
CMakeFiles/lab9.dir/src/Program.cpp.o: ../src/Program.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/class/Graphics/lab09-master/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab9.dir/src/Program.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab9.dir/src/Program.cpp.o -c /home/bill/class/Graphics/lab09-master/src/Program.cpp

CMakeFiles/lab9.dir/src/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab9.dir/src/Program.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/class/Graphics/lab09-master/src/Program.cpp > CMakeFiles/lab9.dir/src/Program.cpp.i

CMakeFiles/lab9.dir/src/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab9.dir/src/Program.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/class/Graphics/lab09-master/src/Program.cpp -o CMakeFiles/lab9.dir/src/Program.cpp.s

CMakeFiles/lab9.dir/src/Program.cpp.o.requires:

.PHONY : CMakeFiles/lab9.dir/src/Program.cpp.o.requires

CMakeFiles/lab9.dir/src/Program.cpp.o.provides: CMakeFiles/lab9.dir/src/Program.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab9.dir/build.make CMakeFiles/lab9.dir/src/Program.cpp.o.provides.build
.PHONY : CMakeFiles/lab9.dir/src/Program.cpp.o.provides

CMakeFiles/lab9.dir/src/Program.cpp.o.provides.build: CMakeFiles/lab9.dir/src/Program.cpp.o


CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o: CMakeFiles/lab9.dir/flags.make
CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o: ../src/tiny_obj_loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/class/Graphics/lab09-master/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o -c /home/bill/class/Graphics/lab09-master/src/tiny_obj_loader.cpp

CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/class/Graphics/lab09-master/src/tiny_obj_loader.cpp > CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.i

CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/class/Graphics/lab09-master/src/tiny_obj_loader.cpp -o CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.s

CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o.requires:

.PHONY : CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o.requires

CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o.provides: CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab9.dir/build.make CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o.provides.build
.PHONY : CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o.provides

CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o.provides.build: CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o


CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o: CMakeFiles/lab9.dir/flags.make
CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o: ../src/GLTextureWriter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/class/Graphics/lab09-master/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o -c /home/bill/class/Graphics/lab09-master/src/GLTextureWriter.cpp

CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/class/Graphics/lab09-master/src/GLTextureWriter.cpp > CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.i

CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/class/Graphics/lab09-master/src/GLTextureWriter.cpp -o CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.s

CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o.requires:

.PHONY : CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o.requires

CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o.provides: CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab9.dir/build.make CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o.provides.build
.PHONY : CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o.provides

CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o.provides.build: CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o


CMakeFiles/lab9.dir/src/GLSL.cpp.o: CMakeFiles/lab9.dir/flags.make
CMakeFiles/lab9.dir/src/GLSL.cpp.o: ../src/GLSL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/class/Graphics/lab09-master/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lab9.dir/src/GLSL.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab9.dir/src/GLSL.cpp.o -c /home/bill/class/Graphics/lab09-master/src/GLSL.cpp

CMakeFiles/lab9.dir/src/GLSL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab9.dir/src/GLSL.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/class/Graphics/lab09-master/src/GLSL.cpp > CMakeFiles/lab9.dir/src/GLSL.cpp.i

CMakeFiles/lab9.dir/src/GLSL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab9.dir/src/GLSL.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/class/Graphics/lab09-master/src/GLSL.cpp -o CMakeFiles/lab9.dir/src/GLSL.cpp.s

CMakeFiles/lab9.dir/src/GLSL.cpp.o.requires:

.PHONY : CMakeFiles/lab9.dir/src/GLSL.cpp.o.requires

CMakeFiles/lab9.dir/src/GLSL.cpp.o.provides: CMakeFiles/lab9.dir/src/GLSL.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab9.dir/build.make CMakeFiles/lab9.dir/src/GLSL.cpp.o.provides.build
.PHONY : CMakeFiles/lab9.dir/src/GLSL.cpp.o.provides

CMakeFiles/lab9.dir/src/GLSL.cpp.o.provides.build: CMakeFiles/lab9.dir/src/GLSL.cpp.o


CMakeFiles/lab9.dir/src/main.cpp.o: CMakeFiles/lab9.dir/flags.make
CMakeFiles/lab9.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/class/Graphics/lab09-master/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/lab9.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab9.dir/src/main.cpp.o -c /home/bill/class/Graphics/lab09-master/src/main.cpp

CMakeFiles/lab9.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab9.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/class/Graphics/lab09-master/src/main.cpp > CMakeFiles/lab9.dir/src/main.cpp.i

CMakeFiles/lab9.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab9.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/class/Graphics/lab09-master/src/main.cpp -o CMakeFiles/lab9.dir/src/main.cpp.s

CMakeFiles/lab9.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/lab9.dir/src/main.cpp.o.requires

CMakeFiles/lab9.dir/src/main.cpp.o.provides: CMakeFiles/lab9.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab9.dir/build.make CMakeFiles/lab9.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/lab9.dir/src/main.cpp.o.provides

CMakeFiles/lab9.dir/src/main.cpp.o.provides.build: CMakeFiles/lab9.dir/src/main.cpp.o


CMakeFiles/lab9.dir/src/Shape.cpp.o: CMakeFiles/lab9.dir/flags.make
CMakeFiles/lab9.dir/src/Shape.cpp.o: ../src/Shape.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/class/Graphics/lab09-master/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/lab9.dir/src/Shape.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab9.dir/src/Shape.cpp.o -c /home/bill/class/Graphics/lab09-master/src/Shape.cpp

CMakeFiles/lab9.dir/src/Shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab9.dir/src/Shape.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/class/Graphics/lab09-master/src/Shape.cpp > CMakeFiles/lab9.dir/src/Shape.cpp.i

CMakeFiles/lab9.dir/src/Shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab9.dir/src/Shape.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/class/Graphics/lab09-master/src/Shape.cpp -o CMakeFiles/lab9.dir/src/Shape.cpp.s

CMakeFiles/lab9.dir/src/Shape.cpp.o.requires:

.PHONY : CMakeFiles/lab9.dir/src/Shape.cpp.o.requires

CMakeFiles/lab9.dir/src/Shape.cpp.o.provides: CMakeFiles/lab9.dir/src/Shape.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab9.dir/build.make CMakeFiles/lab9.dir/src/Shape.cpp.o.provides.build
.PHONY : CMakeFiles/lab9.dir/src/Shape.cpp.o.provides

CMakeFiles/lab9.dir/src/Shape.cpp.o.provides.build: CMakeFiles/lab9.dir/src/Shape.cpp.o


CMakeFiles/lab9.dir/src/WindowManager.cpp.o: CMakeFiles/lab9.dir/flags.make
CMakeFiles/lab9.dir/src/WindowManager.cpp.o: ../src/WindowManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/class/Graphics/lab09-master/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/lab9.dir/src/WindowManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab9.dir/src/WindowManager.cpp.o -c /home/bill/class/Graphics/lab09-master/src/WindowManager.cpp

CMakeFiles/lab9.dir/src/WindowManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab9.dir/src/WindowManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/class/Graphics/lab09-master/src/WindowManager.cpp > CMakeFiles/lab9.dir/src/WindowManager.cpp.i

CMakeFiles/lab9.dir/src/WindowManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab9.dir/src/WindowManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/class/Graphics/lab09-master/src/WindowManager.cpp -o CMakeFiles/lab9.dir/src/WindowManager.cpp.s

CMakeFiles/lab9.dir/src/WindowManager.cpp.o.requires:

.PHONY : CMakeFiles/lab9.dir/src/WindowManager.cpp.o.requires

CMakeFiles/lab9.dir/src/WindowManager.cpp.o.provides: CMakeFiles/lab9.dir/src/WindowManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab9.dir/build.make CMakeFiles/lab9.dir/src/WindowManager.cpp.o.provides.build
.PHONY : CMakeFiles/lab9.dir/src/WindowManager.cpp.o.provides

CMakeFiles/lab9.dir/src/WindowManager.cpp.o.provides.build: CMakeFiles/lab9.dir/src/WindowManager.cpp.o


CMakeFiles/lab9.dir/src/Texture.cpp.o: CMakeFiles/lab9.dir/flags.make
CMakeFiles/lab9.dir/src/Texture.cpp.o: ../src/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/class/Graphics/lab09-master/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/lab9.dir/src/Texture.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab9.dir/src/Texture.cpp.o -c /home/bill/class/Graphics/lab09-master/src/Texture.cpp

CMakeFiles/lab9.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab9.dir/src/Texture.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bill/class/Graphics/lab09-master/src/Texture.cpp > CMakeFiles/lab9.dir/src/Texture.cpp.i

CMakeFiles/lab9.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab9.dir/src/Texture.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bill/class/Graphics/lab09-master/src/Texture.cpp -o CMakeFiles/lab9.dir/src/Texture.cpp.s

CMakeFiles/lab9.dir/src/Texture.cpp.o.requires:

.PHONY : CMakeFiles/lab9.dir/src/Texture.cpp.o.requires

CMakeFiles/lab9.dir/src/Texture.cpp.o.provides: CMakeFiles/lab9.dir/src/Texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab9.dir/build.make CMakeFiles/lab9.dir/src/Texture.cpp.o.provides.build
.PHONY : CMakeFiles/lab9.dir/src/Texture.cpp.o.provides

CMakeFiles/lab9.dir/src/Texture.cpp.o.provides.build: CMakeFiles/lab9.dir/src/Texture.cpp.o


CMakeFiles/lab9.dir/ext/glad/src/glad.c.o: CMakeFiles/lab9.dir/flags.make
CMakeFiles/lab9.dir/ext/glad/src/glad.c.o: ../ext/glad/src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bill/class/Graphics/lab09-master/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/lab9.dir/ext/glad/src/glad.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab9.dir/ext/glad/src/glad.c.o   -c /home/bill/class/Graphics/lab09-master/ext/glad/src/glad.c

CMakeFiles/lab9.dir/ext/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab9.dir/ext/glad/src/glad.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bill/class/Graphics/lab09-master/ext/glad/src/glad.c > CMakeFiles/lab9.dir/ext/glad/src/glad.c.i

CMakeFiles/lab9.dir/ext/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab9.dir/ext/glad/src/glad.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bill/class/Graphics/lab09-master/ext/glad/src/glad.c -o CMakeFiles/lab9.dir/ext/glad/src/glad.c.s

CMakeFiles/lab9.dir/ext/glad/src/glad.c.o.requires:

.PHONY : CMakeFiles/lab9.dir/ext/glad/src/glad.c.o.requires

CMakeFiles/lab9.dir/ext/glad/src/glad.c.o.provides: CMakeFiles/lab9.dir/ext/glad/src/glad.c.o.requires
	$(MAKE) -f CMakeFiles/lab9.dir/build.make CMakeFiles/lab9.dir/ext/glad/src/glad.c.o.provides.build
.PHONY : CMakeFiles/lab9.dir/ext/glad/src/glad.c.o.provides

CMakeFiles/lab9.dir/ext/glad/src/glad.c.o.provides.build: CMakeFiles/lab9.dir/ext/glad/src/glad.c.o


# Object files for target lab9
lab9_OBJECTS = \
"CMakeFiles/lab9.dir/src/MatrixStack.cpp.o" \
"CMakeFiles/lab9.dir/src/Program.cpp.o" \
"CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o" \
"CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o" \
"CMakeFiles/lab9.dir/src/GLSL.cpp.o" \
"CMakeFiles/lab9.dir/src/main.cpp.o" \
"CMakeFiles/lab9.dir/src/Shape.cpp.o" \
"CMakeFiles/lab9.dir/src/WindowManager.cpp.o" \
"CMakeFiles/lab9.dir/src/Texture.cpp.o" \
"CMakeFiles/lab9.dir/ext/glad/src/glad.c.o"

# External object files for target lab9
lab9_EXTERNAL_OBJECTS =

lab9: CMakeFiles/lab9.dir/src/MatrixStack.cpp.o
lab9: CMakeFiles/lab9.dir/src/Program.cpp.o
lab9: CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o
lab9: CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o
lab9: CMakeFiles/lab9.dir/src/GLSL.cpp.o
lab9: CMakeFiles/lab9.dir/src/main.cpp.o
lab9: CMakeFiles/lab9.dir/src/Shape.cpp.o
lab9: CMakeFiles/lab9.dir/src/WindowManager.cpp.o
lab9: CMakeFiles/lab9.dir/src/Texture.cpp.o
lab9: CMakeFiles/lab9.dir/ext/glad/src/glad.c.o
lab9: CMakeFiles/lab9.dir/build.make
lab9: CMakeFiles/lab9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bill/class/Graphics/lab09-master/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable lab9"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab9.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab9.dir/build: lab9

.PHONY : CMakeFiles/lab9.dir/build

CMakeFiles/lab9.dir/requires: CMakeFiles/lab9.dir/src/MatrixStack.cpp.o.requires
CMakeFiles/lab9.dir/requires: CMakeFiles/lab9.dir/src/Program.cpp.o.requires
CMakeFiles/lab9.dir/requires: CMakeFiles/lab9.dir/src/tiny_obj_loader.cpp.o.requires
CMakeFiles/lab9.dir/requires: CMakeFiles/lab9.dir/src/GLTextureWriter.cpp.o.requires
CMakeFiles/lab9.dir/requires: CMakeFiles/lab9.dir/src/GLSL.cpp.o.requires
CMakeFiles/lab9.dir/requires: CMakeFiles/lab9.dir/src/main.cpp.o.requires
CMakeFiles/lab9.dir/requires: CMakeFiles/lab9.dir/src/Shape.cpp.o.requires
CMakeFiles/lab9.dir/requires: CMakeFiles/lab9.dir/src/WindowManager.cpp.o.requires
CMakeFiles/lab9.dir/requires: CMakeFiles/lab9.dir/src/Texture.cpp.o.requires
CMakeFiles/lab9.dir/requires: CMakeFiles/lab9.dir/ext/glad/src/glad.c.o.requires

.PHONY : CMakeFiles/lab9.dir/requires

CMakeFiles/lab9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab9.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab9.dir/clean

CMakeFiles/lab9.dir/depend:
	cd /home/bill/class/Graphics/lab09-master/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bill/class/Graphics/lab09-master /home/bill/class/Graphics/lab09-master /home/bill/class/Graphics/lab09-master/bin /home/bill/class/Graphics/lab09-master/bin /home/bill/class/Graphics/lab09-master/bin/CMakeFiles/lab9.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab9.dir/depend
