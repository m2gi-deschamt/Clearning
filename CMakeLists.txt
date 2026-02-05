cmake_minimum_required(VERSION 3.10)
project(Puissance4)

# Utiliser C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter tous les fichiers source
set(SOURCES
    main.cpp
    Player.cpp
    Board.cpp
)

# Créer l’exécutable
add_executable(puissance4 ${SOURCES})
