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
    ${TEST_DIR}/test_main.cpp
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

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.16.0 
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Exécutable de tests
add_executable(tests
    ${TEST_SOURCES}
)

target_link_libraries(tests PRIVATE gtest_main game)

add_test(NAME RunAllTests COMMAND tests)

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