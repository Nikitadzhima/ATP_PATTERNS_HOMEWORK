cmake_minimum_required(VERSION 3.16)

project(SeaVoyage)

set(CMAKE_CXX_STANDARD 17)

add_executable(SeaVoyage main.cpp include/Card.h include/Card.cpp include/Field.h include/Field.cpp include/CardStorage.h include/CardStorage.cpp
                    include/CardCreator.h include/CardCreator.cpp include/GameSettings.h include/GameSettings.cpp include/Game.h include/Game.cpp
                    include/PrintDecorator.h include/PrintDecorator.cpp include/CardPlay.cpp include/Command.h include/Command.cpp)
