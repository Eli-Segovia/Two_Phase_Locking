# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /opt/clion/clion-2020.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/clion-2020.3.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Locking.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Locking.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Locking.dir/flags.make

CMakeFiles/Locking.dir/LockManager.cpp.o: CMakeFiles/Locking.dir/flags.make
CMakeFiles/Locking.dir/LockManager.cpp.o: ../LockManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Locking.dir/LockManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Locking.dir/LockManager.cpp.o -c /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/LockManager.cpp

CMakeFiles/Locking.dir/LockManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Locking.dir/LockManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/LockManager.cpp > CMakeFiles/Locking.dir/LockManager.cpp.i

CMakeFiles/Locking.dir/LockManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Locking.dir/LockManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/LockManager.cpp -o CMakeFiles/Locking.dir/LockManager.cpp.s

CMakeFiles/Locking.dir/Transaction.cpp.o: CMakeFiles/Locking.dir/flags.make
CMakeFiles/Locking.dir/Transaction.cpp.o: ../Transaction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Locking.dir/Transaction.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Locking.dir/Transaction.cpp.o -c /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/Transaction.cpp

CMakeFiles/Locking.dir/Transaction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Locking.dir/Transaction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/Transaction.cpp > CMakeFiles/Locking.dir/Transaction.cpp.i

CMakeFiles/Locking.dir/Transaction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Locking.dir/Transaction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/Transaction.cpp -o CMakeFiles/Locking.dir/Transaction.cpp.s

CMakeFiles/Locking.dir/Database.cpp.o: CMakeFiles/Locking.dir/flags.make
CMakeFiles/Locking.dir/Database.cpp.o: ../Database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Locking.dir/Database.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Locking.dir/Database.cpp.o -c /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/Database.cpp

CMakeFiles/Locking.dir/Database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Locking.dir/Database.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/Database.cpp > CMakeFiles/Locking.dir/Database.cpp.i

CMakeFiles/Locking.dir/Database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Locking.dir/Database.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/Database.cpp -o CMakeFiles/Locking.dir/Database.cpp.s

# Object files for target Locking
Locking_OBJECTS = \
"CMakeFiles/Locking.dir/LockManager.cpp.o" \
"CMakeFiles/Locking.dir/Transaction.cpp.o" \
"CMakeFiles/Locking.dir/Database.cpp.o"

# External object files for target Locking
Locking_EXTERNAL_OBJECTS =

libLocking.a: CMakeFiles/Locking.dir/LockManager.cpp.o
libLocking.a: CMakeFiles/Locking.dir/Transaction.cpp.o
libLocking.a: CMakeFiles/Locking.dir/Database.cpp.o
libLocking.a: CMakeFiles/Locking.dir/build.make
libLocking.a: CMakeFiles/Locking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libLocking.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Locking.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Locking.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Locking.dir/build: libLocking.a

.PHONY : CMakeFiles/Locking.dir/build

CMakeFiles/Locking.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Locking.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Locking.dir/clean

CMakeFiles/Locking.dir/depend:
	cd /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/cmake-build-debug /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/cmake-build-debug /home/esegovia/Documents/School_Stuff/DB_File_Mgmt/Two_Phase_Locking/cmake-build-debug/CMakeFiles/Locking.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Locking.dir/depend
