cmake_minimum_required(VERSION 3.14)

project(MyLibTest LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

set(MyLib_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../Release")

add_library(MyLib SHARED IMPORTED)

set_property(TARGET MyLib PROPERTY IMPORTED_LOCATION "${MyLib_PATH}/bin/MyLib.dll")
set_property(TARGET MyLib PROPERTY IMPORTED_IMPLIB "${MyLib_PATH}/lib/MyLib.lib")
target_include_directories(MyLib INTERFACE "${MyLib_PATH}/include")

add_executable(MyLibTest
  main.cpp
)
target_link_libraries(MyLibTest Qt${QT_VERSION_MAJOR}::Core MyLib)

include(GNUInstallDirs)
install(TARGETS MyLibTest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
