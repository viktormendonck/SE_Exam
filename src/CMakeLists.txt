

# Specify source files and target executable
set(PROJECT_SOURCES
    "GameWinMain.h" "GameWinMain.cpp"
    "GameEngine.h" "GameEngine.cpp"
    "Game.h" "Game.cpp"
    "AbstractGame.h" "AbstractGame.cpp"
    "GameDefines.h"
    "resource.h"
)

# Enable Needed Definitions In the project
add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE) #also exists apparently

# Create the project executable
add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCES})

# Set output directories
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
