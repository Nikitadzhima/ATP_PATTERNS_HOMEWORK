cmake_minimum_required(VERSION 3.16)

project(sea_voyage)

set(CMAKE_CXX_STANDARD 17)

add_executable(sea_voyage main.cpp include/Card.h include/Card.cpp include/Field.h include/Field.cpp include/Card_storage.h include/Card_storage.cpp
                            include/Card_creator.h include/Card_creator.cpp include/Card_storage_creator.h include/Card_storage_creator.cpp
                            include/Game_settings.h include/Game_settings.cpp)
