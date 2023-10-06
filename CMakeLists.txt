cmake_minimum_required(VERSION 3.25)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP main.cpp RawEthernetPacket.cpp RawEthernetPacket.h ECPRIPacket.cpp ECPRIPacket.h)
