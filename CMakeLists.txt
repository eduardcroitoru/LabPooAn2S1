cmake_minimum_required(VERSION 3.20)
project(Desktop)

set(CMAKE_CXX_STANDARD 14)

add_executable(Desktop main.cpp Singer.cpp Singer.h Song.cpp Song.h Playlist.cpp Playlist.h ListaCantece.cpp ListaCantece.h Album.cpp Album.h SingletoneMenu.cpp SingletoneMenu.h)
