cmake_minimum_required(VERSION 3.14)
project(Puissance4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(IMGUI_DIR imgui)
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

set(GAME_DIR src)
set(GAME_SOURCES
    ${GAME_DIR}/Player.cpp
    ${GAME_DIR}/Board.cpp
    ${GAME_DIR}/Game.cpp
    ${GAME_DIR}/Piece.cpp
)

set(TEST_DIR test)
set(TEST_SOURCES
    ${TEST_DIR}/test_board.cpp
    ${TEST_DIR}/test_game.cpp
    ${TEST_DIR}/test_player.cpp
)

add_library(game
    ${GAME_SOURCES}
)

target_include_directories(game PUBLIC include)

add_executable(puissance4
    main.cpp
    ${IMGUI_SOURCES}
)
target_link_libraries(puissance4 PRIVATE game)


# -------------------------
# Tests
# -------------------------
enable_testing()

# Télécharger Catch2
include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(catch2)

# Exécutable de tests
add_executable(tests
    ${TEST_SOURCES}
)

# Inclure tes headers et ceux de Catch2
target_include_directories(tests PRIVATE include)

# Lier Catch2
target_link_libraries(tests PRIVATE game Catch2::Catch2WithMain)

# Découvrir automatiquement les tests
include(CTest)
include(Catch)
catch_discover_tests(tests)

#------------------------------------
#UI - variable alrealy set up on top-
#------------------------------------

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(puissance4 PRIVATE
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

target_link_libraries(puissance4 PRIVATE
    game
    glfw
    OpenGL::GL
)