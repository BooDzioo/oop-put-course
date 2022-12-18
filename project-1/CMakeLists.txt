cmake_minimum_required(VERSION 3.22)
project(project_1)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS
        ./include/common/Card.h
        ./include/common/Collection.h
        ./include/common/CollectionsManager.h
        ./include/common/Gui.h
        )
set(PROJECT_SOURCES
        ./src/common/Card.cpp
        ./src/common/Collection.cpp
        ./src/common/CollectionsManager.cpp
        ./src/common/Gui.cpp
        )

add_executable(project_1 main.cpp ${PROJECT_SOURCES} ${PROJECT_HEADERS})

include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("${PROJECT_SOURCE_DIR}/include")
