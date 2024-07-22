# Minimum CMake version required
cmake_minimum_required(VERSION 3.22)

# Project name, version, and description
project(WeatherBot VERSION 1.0 DESCRIPTION "A Discord bot")

# Add path to CMake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Create an executable
add_executable(WeatherBot
    src/main.cpp
    src/event_listeners/ready.cpp
    src/event_listeners/slashcommand.cpp
    src/utils/utils.cpp
)

add_custom_command(TARGET WeatherBot POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/data/commands_info.json
    $<TARGET_FILE_DIR:WeatherBot>/data/commands_info.json
)

# Add the 'include' directory to the project
target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_SOURCE_DIR}/include
)

# Find the pre-installed DPP package (using FindDPP.cmake)
find_package(DPP REQUIRED)

# Link the pre-installed DPP package
target_link_libraries(${PROJECT_NAME}
    PRIVATE ${DPP_LIBRARIES}
)

# Include the DPP directories
target_include_directories(${PROJECT_NAME}
    PRIVATE ${DPP_INCLUDE_DIR}
)

# Set C++ standard
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
