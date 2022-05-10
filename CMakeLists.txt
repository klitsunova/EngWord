cmake_minimum_required(VERSION 3.22)
project(Duolingo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

set(MODELS
        Models/exercises_set.cpp
        Models/settings.cpp
        Models/words.cpp
        )

set(VIEWS
        Views/Exercises/animation.cpp
        Views/Exercises/audio_view.cpp
        Views/Exercises/exercises_set_view.cpp
        Views/Exercises/input_view.cpp
        Views/Exercises/pick_view.cpp
        Views/Menu/menu.cpp
        Views/Menu/settings_view.cpp
        )

set(CONTROLLERS
        Controllers/exercises_controller.cpp
        Controllers/main_window.cpp
        )

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
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Multimedia)
