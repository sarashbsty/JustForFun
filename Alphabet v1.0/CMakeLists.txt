cmake_minimum_required(VERSION 3.15)
project(Alphabet LANGUAGES CXX)
set(CMAKE_CXX_COMPILER g++)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include headers globally
include_directories(include)

# -----------------------------
# Collect all sources and headers
# -----------------------------
file(GLOB_RECURSE ALL_SOURCES
    "sources/*.cpp"
    "alpha_sources/*.cpp"
)
file(GLOB_RECURSE ALL_HEADERS
    "include/*.h"
    "include/*.hpp"
)

# -----------------------------
# Create main executable
# -----------------------------
add_executable(alphabet ${ALL_SOURCES} ${ALL_HEADERS})

# Output directory
set_target_properties(alphabet PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)
