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
CMAKE_SOURCE_DIR = /home/murongyuyue/mypreload

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/murongyuyue/mypreload/build

# Include any dependencies generated for this target.
include CMakeFiles/start.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/start.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/start.dir/flags.make

CMakeFiles/start.dir/start.c.o: CMakeFiles/start.dir/flags.make
CMakeFiles/start.dir/start.c.o: ../start.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murongyuyue/mypreload/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/start.dir/start.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/start.dir/start.c.o   -c /home/murongyuyue/mypreload/start.c

CMakeFiles/start.dir/start.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/start.dir/start.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murongyuyue/mypreload/start.c > CMakeFiles/start.dir/start.c.i

CMakeFiles/start.dir/start.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/start.dir/start.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murongyuyue/mypreload/start.c -o CMakeFiles/start.dir/start.c.s

CMakeFiles/start.dir/intercept_syscall.c.o: CMakeFiles/start.dir/flags.make
CMakeFiles/start.dir/intercept_syscall.c.o: ../intercept_syscall.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murongyuyue/mypreload/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/start.dir/intercept_syscall.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/start.dir/intercept_syscall.c.o   -c /home/murongyuyue/mypreload/intercept_syscall.c

CMakeFiles/start.dir/intercept_syscall.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/start.dir/intercept_syscall.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murongyuyue/mypreload/intercept_syscall.c > CMakeFiles/start.dir/intercept_syscall.c.i

CMakeFiles/start.dir/intercept_syscall.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/start.dir/intercept_syscall.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murongyuyue/mypreload/intercept_syscall.c -o CMakeFiles/start.dir/intercept_syscall.c.s

CMakeFiles/start.dir/syscall_logger.c.o: CMakeFiles/start.dir/flags.make
CMakeFiles/start.dir/syscall_logger.c.o: ../syscall_logger.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murongyuyue/mypreload/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/start.dir/syscall_logger.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/start.dir/syscall_logger.c.o   -c /home/murongyuyue/mypreload/syscall_logger.c

CMakeFiles/start.dir/syscall_logger.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/start.dir/syscall_logger.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murongyuyue/mypreload/syscall_logger.c > CMakeFiles/start.dir/syscall_logger.c.i

CMakeFiles/start.dir/syscall_logger.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/start.dir/syscall_logger.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murongyuyue/mypreload/syscall_logger.c -o CMakeFiles/start.dir/syscall_logger.c.s

CMakeFiles/start.dir/arithmetic.c.o: CMakeFiles/start.dir/flags.make
CMakeFiles/start.dir/arithmetic.c.o: ../arithmetic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murongyuyue/mypreload/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/start.dir/arithmetic.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/start.dir/arithmetic.c.o   -c /home/murongyuyue/mypreload/arithmetic.c

CMakeFiles/start.dir/arithmetic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/start.dir/arithmetic.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murongyuyue/mypreload/arithmetic.c > CMakeFiles/start.dir/arithmetic.c.i

CMakeFiles/start.dir/arithmetic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/start.dir/arithmetic.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murongyuyue/mypreload/arithmetic.c -o CMakeFiles/start.dir/arithmetic.c.s

# Object files for target start
start_OBJECTS = \
"CMakeFiles/start.dir/start.c.o" \
"CMakeFiles/start.dir/intercept_syscall.c.o" \
"CMakeFiles/start.dir/syscall_logger.c.o" \
"CMakeFiles/start.dir/arithmetic.c.o"

# External object files for target start
start_EXTERNAL_OBJECTS =

libstart.so: CMakeFiles/start.dir/start.c.o
libstart.so: CMakeFiles/start.dir/intercept_syscall.c.o
libstart.so: CMakeFiles/start.dir/syscall_logger.c.o
libstart.so: CMakeFiles/start.dir/arithmetic.c.o
libstart.so: CMakeFiles/start.dir/build.make
libstart.so: CMakeFiles/start.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/murongyuyue/mypreload/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C shared library libstart.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/start.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/start.dir/build: libstart.so

.PHONY : CMakeFiles/start.dir/build

CMakeFiles/start.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/start.dir/cmake_clean.cmake
.PHONY : CMakeFiles/start.dir/clean

CMakeFiles/start.dir/depend:
	cd /home/murongyuyue/mypreload/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/murongyuyue/mypreload /home/murongyuyue/mypreload /home/murongyuyue/mypreload/build /home/murongyuyue/mypreload/build /home/murongyuyue/mypreload/build/CMakeFiles/start.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/start.dir/depend

