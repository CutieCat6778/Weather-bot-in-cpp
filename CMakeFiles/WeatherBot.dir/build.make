# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/st/stm32cubeclt_1.16.0/CMake/bin/cmake

# The command to remove a file.
RM = /opt/st/stm32cubeclt_1.16.0/CMake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/thinh/Developer/Weather-bot-in-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/thinh/Developer/Weather-bot-in-cpp

# Include any dependencies generated for this target.
include CMakeFiles/WeatherBot.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WeatherBot.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WeatherBot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WeatherBot.dir/flags.make

CMakeFiles/WeatherBot.dir/src/main.cpp.o: CMakeFiles/WeatherBot.dir/flags.make
CMakeFiles/WeatherBot.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/WeatherBot.dir/src/main.cpp.o: CMakeFiles/WeatherBot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/thinh/Developer/Weather-bot-in-cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WeatherBot.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WeatherBot.dir/src/main.cpp.o -MF CMakeFiles/WeatherBot.dir/src/main.cpp.o.d -o CMakeFiles/WeatherBot.dir/src/main.cpp.o -c /media/thinh/Developer/Weather-bot-in-cpp/src/main.cpp

CMakeFiles/WeatherBot.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WeatherBot.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/thinh/Developer/Weather-bot-in-cpp/src/main.cpp > CMakeFiles/WeatherBot.dir/src/main.cpp.i

CMakeFiles/WeatherBot.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WeatherBot.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/thinh/Developer/Weather-bot-in-cpp/src/main.cpp -o CMakeFiles/WeatherBot.dir/src/main.cpp.s

# Object files for target WeatherBot
WeatherBot_OBJECTS = \
"CMakeFiles/WeatherBot.dir/src/main.cpp.o"

# External object files for target WeatherBot
WeatherBot_EXTERNAL_OBJECTS =

WeatherBot: CMakeFiles/WeatherBot.dir/src/main.cpp.o
WeatherBot: CMakeFiles/WeatherBot.dir/build.make
WeatherBot: /usr/lib/libdpp.so
WeatherBot: CMakeFiles/WeatherBot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/media/thinh/Developer/Weather-bot-in-cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable WeatherBot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WeatherBot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WeatherBot.dir/build: WeatherBot
.PHONY : CMakeFiles/WeatherBot.dir/build

CMakeFiles/WeatherBot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WeatherBot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WeatherBot.dir/clean

CMakeFiles/WeatherBot.dir/depend:
	cd /media/thinh/Developer/Weather-bot-in-cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/thinh/Developer/Weather-bot-in-cpp /media/thinh/Developer/Weather-bot-in-cpp /media/thinh/Developer/Weather-bot-in-cpp /media/thinh/Developer/Weather-bot-in-cpp /media/thinh/Developer/Weather-bot-in-cpp/CMakeFiles/WeatherBot.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/WeatherBot.dir/depend

