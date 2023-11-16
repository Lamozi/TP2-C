cmake_minimum_required(VERSION 3.26)
project(TP_Final C)

set(CMAKE_C_STANDARD 99)

add_executable(TP_Final main.c
        ListeDesTaches.c
        ListeDesTaches.h
        Date.c
        Date.h
        Tache.c
        Tache.h)
