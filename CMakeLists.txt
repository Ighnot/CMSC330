cmake_minimum_required(VERSION 3.26)
project(330p2newBuild_Leckie)

set(CMAKE_CXX_STANDARD 17)

# All source files in the src directory
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.h" "src/*.txt")

# In case I make a directory in /src
include_directories(include)

# Boom. I didn't have to type 20 filenames...
add_executable(330p2newBuild_Leckie ${SOURCE_FILES})
