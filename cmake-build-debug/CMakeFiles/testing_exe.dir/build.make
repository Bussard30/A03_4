# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Jonas\CLionProjects\testing_exe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Jonas\CLionProjects\testing_exe\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\testing_exe.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\testing_exe.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\testing_exe.dir\flags.make

CMakeFiles\testing_exe.dir\main.c.obj: CMakeFiles\testing_exe.dir\flags.make
CMakeFiles\testing_exe.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Jonas\CLionProjects\testing_exe\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/testing_exe.dir/main.c.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\testing_exe.dir\main.c.obj /FdCMakeFiles\testing_exe.dir\ /FS -c C:\Users\Jonas\CLionProjects\testing_exe\main.c
<<

CMakeFiles\testing_exe.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testing_exe.dir/main.c.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\testing_exe.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Jonas\CLionProjects\testing_exe\main.c
<<

CMakeFiles\testing_exe.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testing_exe.dir/main.c.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\testing_exe.dir\main.c.s /c C:\Users\Jonas\CLionProjects\testing_exe\main.c
<<

# Object files for target testing_exe
testing_exe_OBJECTS = \
"CMakeFiles\testing_exe.dir\main.c.obj"

# External object files for target testing_exe
testing_exe_EXTERNAL_OBJECTS =

testing_exe.exe: CMakeFiles\testing_exe.dir\main.c.obj
testing_exe.exe: CMakeFiles\testing_exe.dir\build.make
testing_exe.exe: CMakeFiles\testing_exe.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Jonas\CLionProjects\testing_exe\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable testing_exe.exe"
	"E:\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\testing_exe.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\testing_exe.dir\objects1.rsp @<<
 /out:testing_exe.exe /implib:testing_exe.lib /pdb:C:\Users\Jonas\CLionProjects\testing_exe\cmake-build-debug\testing_exe.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\testing_exe.dir\build: testing_exe.exe
.PHONY : CMakeFiles\testing_exe.dir\build

CMakeFiles\testing_exe.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\testing_exe.dir\cmake_clean.cmake
.PHONY : CMakeFiles\testing_exe.dir\clean

CMakeFiles\testing_exe.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Jonas\CLionProjects\testing_exe C:\Users\Jonas\CLionProjects\testing_exe C:\Users\Jonas\CLionProjects\testing_exe\cmake-build-debug C:\Users\Jonas\CLionProjects\testing_exe\cmake-build-debug C:\Users\Jonas\CLionProjects\testing_exe\cmake-build-debug\CMakeFiles\testing_exe.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\testing_exe.dir\depend
