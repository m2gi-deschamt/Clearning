cmake_minimum_required(VERSION 3.14)
project(Puissance4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------
# Exécutable principal
# -------------------------
add_executable(puissance4
    main.cpp
    src/Player.cpp
    src/Board.cpp
    src/Game.cpp
)

target_include_directories(puissance4 PRIVATE include)

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
    test/test_board.cpp
    test/test_game.cpp
    test/test_player.cpp
)

# Inclure tes headers et ceux de Catch2
target_include_directories(tests PRIVATE include)

# Lier Catch2
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# Découvrir automatiquement les tests
include(CTest)
include(Catch)
catch_discover_tests(tests)