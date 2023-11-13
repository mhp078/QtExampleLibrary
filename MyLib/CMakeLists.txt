cmake_minimum_required(VERSION 3.14)

project(MyLib VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#dll and lib files name
set(PROJECT_NAME "MyLib")

#release folder name
set(CMAKE_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Release")

set(CMAKE_INSTALL_BINDIR "${CMAKE_INSTALL_DIR}/bin")
set(CMAKE_INSTALL_INCLUDEDIR "${CMAKE_INSTALL_DIR}/include")
set(CMAKE_INSTALL_LIBDIR "${CMAKE_INSTALL_DIR}/lib")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(MyLib SHARED
  MyLib_global.h
  mylib.cpp
  mylib.h
)

target_link_libraries(MyLib PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(MyLib PRIVATE MYLIB_LIBRARY)

#Set dll and lib file name
set_target_properties(MyLib PROPERTIES OUTPUT_NAME "${PROJECT_NAME}")

install(TARGETS MyLib
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} #dll files
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} #lib files
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}) #lib files

#It is possible to do the same for files of different types.
#In this section, it adds "*.h" extension files inside the project to the final Release folder of the library.

install(DIRECTORY / DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILE_PERMISSIONS
            OWNER_READ OWNER_EXECUTE OWNER_WRITE
            GROUP_READ GROUP_EXECUTE
            WORLD_READ WORLD_EXECUTE
        DIRECTORY_PERMISSIONS
            OWNER_READ OWNER_EXECUTE OWNER_WRITE
            GROUP_READ GROUP_EXECUTE GROUP_WRITE
            WORLD_READ WORLD_EXECUTE
        FILES_MATCHING PATTERN "*.h")
