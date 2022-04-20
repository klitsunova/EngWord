cmake_minimum_required(VERSION 3.22)
project(Duolingo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "~/Qt/6.3.0/gcc_64/lib/cmake")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

set(MODELS
        Models/words.cpp
        Models/exercises_set.cpp)

set(VIEWS
        Views/Menu/menu.cpp
        Views/Menu/settings_view.cpp
        Views/Exercises/exercises_set_view.cpp
        Views/Exercises/audio_view.cpp
        Views/Exercises/input_view.cpp
        Views/Exercises/pick_view.cpp)

set(CONTROLLERS
        Controllers/MainWindow/main_window.cpp
        Controllers/settings.cpp
        Controllers/exercises_controller.cpp)

set(RESOURCES
        resources/audio.qrc
        resources/images.qrc
        resources/words.qrc)

set(SOURCES
        main.cpp
        ${MODELS}
        ${VIEWS}
        ${CONTROLLERS}
        ${RESOURCES})

add_executable(Duolingo ${SOURCES})

target_link_libraries(Duolingo
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia)
