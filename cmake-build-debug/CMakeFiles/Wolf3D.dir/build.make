# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Users/ablizniu/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/ablizniu/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ablizniu/Documents/Wolf3D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ablizniu/Documents/Wolf3D/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Wolf3D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Wolf3D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Wolf3D.dir/flags.make

CMakeFiles/Wolf3D.dir/src/main.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Wolf3D.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/main.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/main.c

CMakeFiles/Wolf3D.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/main.c > CMakeFiles/Wolf3D.dir/src/main.c.i

CMakeFiles/Wolf3D.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/main.c -o CMakeFiles/Wolf3D.dir/src/main.c.s

CMakeFiles/Wolf3D.dir/src/draw.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/draw.c.o: ../src/draw.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Wolf3D.dir/src/draw.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/draw.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/draw.c

CMakeFiles/Wolf3D.dir/src/draw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/draw.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/draw.c > CMakeFiles/Wolf3D.dir/src/draw.c.i

CMakeFiles/Wolf3D.dir/src/draw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/draw.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/draw.c -o CMakeFiles/Wolf3D.dir/src/draw.c.s

CMakeFiles/Wolf3D.dir/src/preparation.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/preparation.c.o: ../src/preparation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Wolf3D.dir/src/preparation.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/preparation.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/preparation.c

CMakeFiles/Wolf3D.dir/src/preparation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/preparation.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/preparation.c > CMakeFiles/Wolf3D.dir/src/preparation.c.i

CMakeFiles/Wolf3D.dir/src/preparation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/preparation.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/preparation.c -o CMakeFiles/Wolf3D.dir/src/preparation.c.s

CMakeFiles/Wolf3D.dir/src/print.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/print.c.o: ../src/print.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Wolf3D.dir/src/print.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/print.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/print.c

CMakeFiles/Wolf3D.dir/src/print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/print.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/print.c > CMakeFiles/Wolf3D.dir/src/print.c.i

CMakeFiles/Wolf3D.dir/src/print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/print.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/print.c -o CMakeFiles/Wolf3D.dir/src/print.c.s

CMakeFiles/Wolf3D.dir/src/draw_utils.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/draw_utils.c.o: ../src/draw_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Wolf3D.dir/src/draw_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/draw_utils.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/draw_utils.c

CMakeFiles/Wolf3D.dir/src/draw_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/draw_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/draw_utils.c > CMakeFiles/Wolf3D.dir/src/draw_utils.c.i

CMakeFiles/Wolf3D.dir/src/draw_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/draw_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/draw_utils.c -o CMakeFiles/Wolf3D.dir/src/draw_utils.c.s

CMakeFiles/Wolf3D.dir/src/validation.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/validation.c.o: ../src/validation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Wolf3D.dir/src/validation.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/validation.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/validation.c

CMakeFiles/Wolf3D.dir/src/validation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/validation.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/validation.c > CMakeFiles/Wolf3D.dir/src/validation.c.i

CMakeFiles/Wolf3D.dir/src/validation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/validation.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/validation.c -o CMakeFiles/Wolf3D.dir/src/validation.c.s

CMakeFiles/Wolf3D.dir/src/init.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/init.c.o: ../src/init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Wolf3D.dir/src/init.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/init.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/init.c

CMakeFiles/Wolf3D.dir/src/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/init.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/init.c > CMakeFiles/Wolf3D.dir/src/init.c.i

CMakeFiles/Wolf3D.dir/src/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/init.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/init.c -o CMakeFiles/Wolf3D.dir/src/init.c.s

CMakeFiles/Wolf3D.dir/src/rotation_and_move.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/rotation_and_move.c.o: ../src/rotation_and_move.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Wolf3D.dir/src/rotation_and_move.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/rotation_and_move.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/rotation_and_move.c

CMakeFiles/Wolf3D.dir/src/rotation_and_move.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/rotation_and_move.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/rotation_and_move.c > CMakeFiles/Wolf3D.dir/src/rotation_and_move.c.i

CMakeFiles/Wolf3D.dir/src/rotation_and_move.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/rotation_and_move.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/rotation_and_move.c -o CMakeFiles/Wolf3D.dir/src/rotation_and_move.c.s

CMakeFiles/Wolf3D.dir/src/textures.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/textures.c.o: ../src/textures.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Wolf3D.dir/src/textures.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/textures.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/textures.c

CMakeFiles/Wolf3D.dir/src/textures.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/textures.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/textures.c > CMakeFiles/Wolf3D.dir/src/textures.c.i

CMakeFiles/Wolf3D.dir/src/textures.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/textures.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/textures.c -o CMakeFiles/Wolf3D.dir/src/textures.c.s

CMakeFiles/Wolf3D.dir/src/preparation_utils.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/preparation_utils.c.o: ../src/preparation_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Wolf3D.dir/src/preparation_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/preparation_utils.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/preparation_utils.c

CMakeFiles/Wolf3D.dir/src/preparation_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/preparation_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/preparation_utils.c > CMakeFiles/Wolf3D.dir/src/preparation_utils.c.i

CMakeFiles/Wolf3D.dir/src/preparation_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/preparation_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/preparation_utils.c -o CMakeFiles/Wolf3D.dir/src/preparation_utils.c.s

CMakeFiles/Wolf3D.dir/src/vector_utils.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/vector_utils.c.o: ../src/vector_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/Wolf3D.dir/src/vector_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/vector_utils.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/vector_utils.c

CMakeFiles/Wolf3D.dir/src/vector_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/vector_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/vector_utils.c > CMakeFiles/Wolf3D.dir/src/vector_utils.c.i

CMakeFiles/Wolf3D.dir/src/vector_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/vector_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/vector_utils.c -o CMakeFiles/Wolf3D.dir/src/vector_utils.c.s

CMakeFiles/Wolf3D.dir/src/validation_utils.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/validation_utils.c.o: ../src/validation_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/Wolf3D.dir/src/validation_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/validation_utils.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/validation_utils.c

CMakeFiles/Wolf3D.dir/src/validation_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/validation_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/validation_utils.c > CMakeFiles/Wolf3D.dir/src/validation_utils.c.i

CMakeFiles/Wolf3D.dir/src/validation_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/validation_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/validation_utils.c -o CMakeFiles/Wolf3D.dir/src/validation_utils.c.s

CMakeFiles/Wolf3D.dir/src/validation_list_utils.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/validation_list_utils.c.o: ../src/validation_list_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/Wolf3D.dir/src/validation_list_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/validation_list_utils.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/validation_list_utils.c

CMakeFiles/Wolf3D.dir/src/validation_list_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/validation_list_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/validation_list_utils.c > CMakeFiles/Wolf3D.dir/src/validation_list_utils.c.i

CMakeFiles/Wolf3D.dir/src/validation_list_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/validation_list_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/validation_list_utils.c -o CMakeFiles/Wolf3D.dir/src/validation_list_utils.c.s

CMakeFiles/Wolf3D.dir/src/validation_fill.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/validation_fill.c.o: ../src/validation_fill.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/Wolf3D.dir/src/validation_fill.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/validation_fill.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/validation_fill.c

CMakeFiles/Wolf3D.dir/src/validation_fill.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/validation_fill.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/validation_fill.c > CMakeFiles/Wolf3D.dir/src/validation_fill.c.i

CMakeFiles/Wolf3D.dir/src/validation_fill.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/validation_fill.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/validation_fill.c -o CMakeFiles/Wolf3D.dir/src/validation_fill.c.s

CMakeFiles/Wolf3D.dir/src/validation_source.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/validation_source.c.o: ../src/validation_source.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/Wolf3D.dir/src/validation_source.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/validation_source.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/validation_source.c

CMakeFiles/Wolf3D.dir/src/validation_source.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/validation_source.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/validation_source.c > CMakeFiles/Wolf3D.dir/src/validation_source.c.i

CMakeFiles/Wolf3D.dir/src/validation_source.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/validation_source.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/validation_source.c -o CMakeFiles/Wolf3D.dir/src/validation_source.c.s

CMakeFiles/Wolf3D.dir/src/key_controller.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/key_controller.c.o: ../src/key_controller.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/Wolf3D.dir/src/key_controller.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/key_controller.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/key_controller.c

CMakeFiles/Wolf3D.dir/src/key_controller.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/key_controller.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/key_controller.c > CMakeFiles/Wolf3D.dir/src/key_controller.c.i

CMakeFiles/Wolf3D.dir/src/key_controller.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/key_controller.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/key_controller.c -o CMakeFiles/Wolf3D.dir/src/key_controller.c.s

CMakeFiles/Wolf3D.dir/src/draw_calculations.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/draw_calculations.c.o: ../src/draw_calculations.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/Wolf3D.dir/src/draw_calculations.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/draw_calculations.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/draw_calculations.c

CMakeFiles/Wolf3D.dir/src/draw_calculations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/draw_calculations.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/draw_calculations.c > CMakeFiles/Wolf3D.dir/src/draw_calculations.c.i

CMakeFiles/Wolf3D.dir/src/draw_calculations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/draw_calculations.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/draw_calculations.c -o CMakeFiles/Wolf3D.dir/src/draw_calculations.c.s

CMakeFiles/Wolf3D.dir/src/draw_textures.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/draw_textures.c.o: ../src/draw_textures.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/Wolf3D.dir/src/draw_textures.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/draw_textures.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/draw_textures.c

CMakeFiles/Wolf3D.dir/src/draw_textures.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/draw_textures.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/draw_textures.c > CMakeFiles/Wolf3D.dir/src/draw_textures.c.i

CMakeFiles/Wolf3D.dir/src/draw_textures.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/draw_textures.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/draw_textures.c -o CMakeFiles/Wolf3D.dir/src/draw_textures.c.s

CMakeFiles/Wolf3D.dir/src/intersection_algorithm.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/intersection_algorithm.c.o: ../src/intersection_algorithm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/Wolf3D.dir/src/intersection_algorithm.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/intersection_algorithm.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/intersection_algorithm.c

CMakeFiles/Wolf3D.dir/src/intersection_algorithm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/intersection_algorithm.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/intersection_algorithm.c > CMakeFiles/Wolf3D.dir/src/intersection_algorithm.c.i

CMakeFiles/Wolf3D.dir/src/intersection_algorithm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/intersection_algorithm.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/intersection_algorithm.c -o CMakeFiles/Wolf3D.dir/src/intersection_algorithm.c.s

CMakeFiles/Wolf3D.dir/src/intersection_algorithm_extra.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/intersection_algorithm_extra.c.o: ../src/intersection_algorithm_extra.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building C object CMakeFiles/Wolf3D.dir/src/intersection_algorithm_extra.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/intersection_algorithm_extra.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/intersection_algorithm_extra.c

CMakeFiles/Wolf3D.dir/src/intersection_algorithm_extra.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/intersection_algorithm_extra.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/intersection_algorithm_extra.c > CMakeFiles/Wolf3D.dir/src/intersection_algorithm_extra.c.i

CMakeFiles/Wolf3D.dir/src/intersection_algorithm_extra.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/intersection_algorithm_extra.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/intersection_algorithm_extra.c -o CMakeFiles/Wolf3D.dir/src/intersection_algorithm_extra.c.s

CMakeFiles/Wolf3D.dir/src/draw_untextured.c.o: CMakeFiles/Wolf3D.dir/flags.make
CMakeFiles/Wolf3D.dir/src/draw_untextured.c.o: ../src/draw_untextured.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building C object CMakeFiles/Wolf3D.dir/src/draw_untextured.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Wolf3D.dir/src/draw_untextured.c.o   -c /Users/ablizniu/Documents/Wolf3D/src/draw_untextured.c

CMakeFiles/Wolf3D.dir/src/draw_untextured.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wolf3D.dir/src/draw_untextured.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ablizniu/Documents/Wolf3D/src/draw_untextured.c > CMakeFiles/Wolf3D.dir/src/draw_untextured.c.i

CMakeFiles/Wolf3D.dir/src/draw_untextured.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wolf3D.dir/src/draw_untextured.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ablizniu/Documents/Wolf3D/src/draw_untextured.c -o CMakeFiles/Wolf3D.dir/src/draw_untextured.c.s

# Object files for target Wolf3D
Wolf3D_OBJECTS = \
"CMakeFiles/Wolf3D.dir/src/main.c.o" \
"CMakeFiles/Wolf3D.dir/src/draw.c.o" \
"CMakeFiles/Wolf3D.dir/src/preparation.c.o" \
"CMakeFiles/Wolf3D.dir/src/print.c.o" \
"CMakeFiles/Wolf3D.dir/src/draw_utils.c.o" \
"CMakeFiles/Wolf3D.dir/src/validation.c.o" \
"CMakeFiles/Wolf3D.dir/src/init.c.o" \
"CMakeFiles/Wolf3D.dir/src/rotation_and_move.c.o" \
"CMakeFiles/Wolf3D.dir/src/textures.c.o" \
"CMakeFiles/Wolf3D.dir/src/preparation_utils.c.o" \
"CMakeFiles/Wolf3D.dir/src/vector_utils.c.o" \
"CMakeFiles/Wolf3D.dir/src/validation_utils.c.o" \
"CMakeFiles/Wolf3D.dir/src/validation_list_utils.c.o" \
"CMakeFiles/Wolf3D.dir/src/validation_fill.c.o" \
"CMakeFiles/Wolf3D.dir/src/validation_source.c.o" \
"CMakeFiles/Wolf3D.dir/src/key_controller.c.o" \
"CMakeFiles/Wolf3D.dir/src/draw_calculations.c.o" \
"CMakeFiles/Wolf3D.dir/src/draw_textures.c.o" \
"CMakeFiles/Wolf3D.dir/src/intersection_algorithm.c.o" \
"CMakeFiles/Wolf3D.dir/src/intersection_algorithm_extra.c.o" \
"CMakeFiles/Wolf3D.dir/src/draw_untextured.c.o"

# External object files for target Wolf3D
Wolf3D_EXTERNAL_OBJECTS =

Wolf3D: CMakeFiles/Wolf3D.dir/src/main.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/draw.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/preparation.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/print.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/draw_utils.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/validation.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/init.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/rotation_and_move.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/textures.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/preparation_utils.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/vector_utils.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/validation_utils.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/validation_list_utils.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/validation_fill.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/validation_source.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/key_controller.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/draw_calculations.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/draw_textures.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/intersection_algorithm.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/intersection_algorithm_extra.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/src/draw_untextured.c.o
Wolf3D: CMakeFiles/Wolf3D.dir/build.make
Wolf3D: libft.a
Wolf3D: CMakeFiles/Wolf3D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Linking C executable Wolf3D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Wolf3D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Wolf3D.dir/build: Wolf3D

.PHONY : CMakeFiles/Wolf3D.dir/build

CMakeFiles/Wolf3D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Wolf3D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Wolf3D.dir/clean

CMakeFiles/Wolf3D.dir/depend:
	cd /Users/ablizniu/Documents/Wolf3D/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ablizniu/Documents/Wolf3D /Users/ablizniu/Documents/Wolf3D /Users/ablizniu/Documents/Wolf3D/cmake-build-debug /Users/ablizniu/Documents/Wolf3D/cmake-build-debug /Users/ablizniu/Documents/Wolf3D/cmake-build-debug/CMakeFiles/Wolf3D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Wolf3D.dir/depend

