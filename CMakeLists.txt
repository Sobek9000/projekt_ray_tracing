cmake_minimum_required(VERSION 3.14)
project(raytracer LANGUAGES CXX)

# konfiguracja projektu
# cmake -S . -B build
# kompilacja daje raytracer.exe w build\Debug
# cmake --build build
# uruchomienie programu:
# build\Debug\raytracer.exe
# czyszczenie skompilowanych plikow
# cmake --build build --target clean
# full czyszczenie usuwa caly build:
# Remove-Item -Recurse -Force build

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(raytracer
    src/Vec3.cpp
    src/Ray.cpp
    src/Color.cpp
    src/Sphere.cpp
    src/MirrorMaterial.cpp
    src/Scene.cpp
    src/Camera.cpp
    src/Renderer.cpp
    src/main.cpp
)
