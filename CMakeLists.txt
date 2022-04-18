cmake_minimum_required(VERSION 3.22)
project(Duolingo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "~/Qt/6.2.3/gcc_64/lib/cmake")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(MODELS
        )

set(VIEWS
        Views/menu.cpp
        )

set(CONTROLLERS
        )

set(MAIN_WINDOW
        MainWindow/main_window.cpp
        )

set(SOURCES
        main.cpp
        ${MODELS}
        ${VIEWS}
        ${CONTROLLERS}
        ${MAIN_WINDOW})

add_executable(Duolingo ${SOURCES})

target_link_libraries(Duolingo
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
