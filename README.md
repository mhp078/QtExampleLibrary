
# Qt Library Example

In this example, a library is built with Qt and an output is provided that can be used in any other project.
Cmake is used in this library.

[MyLib Project](#mylib-project) \
[MyLibTest Project](#mylibtest-project) \
[Usage](#Usage)


# MyLib Project

To build an exportable library, the following are required.

**CMakeLists.txt**

```
set(PROJECT_NAME "MyLib")

set(CMAKE_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Release")

set(CMAKE_INSTALL_BINDIR "${CMAKE_INSTALL_DIR}/bin")
set(CMAKE_INSTALL_INCLUDEDIR "${CMAKE_INSTALL_DIR}/include")
set(CMAKE_INSTALL_LIBDIR "${CMAKE_INSTALL_DIR}/lib")
```

```
set_target_properties(MyLib PROPERTIES OUTPUT_NAME "${PROJECT_NAME}")

install(TARGETS MyLib
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

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
```

**Note:** It is possible to do the same for files of different types.
In this section, it adds "*.h" extension files inside the project to the final Release folder of the library.


Now use **"MYLIB_EXPORT"** in classes for export.

```
class MYLIB_EXPORT MyLib
{
    ...
}
```


# MyLibTest Project

To use the output of the "MyLib" library, follow the steps below.

**CMakeLists.txt**

```
set(MyLib_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../Release")

add_library(MyLib SHARED IMPORTED)

set_property(TARGET MyLib PROPERTY IMPORTED_LOCATION "${MyLib_PATH}/bin/MyLib.dll")
set_property(TARGET MyLib PROPERTY IMPORTED_IMPLIB "${MyLib_PATH}/lib/MyLib.lib")
target_include_directories(MyLib INTERFACE "${MyLib_PATH}/include")
```

Add "MyLib" in target_link_libraries.

```
target_link_libraries(MyLibTest Qt${QT_VERSION_MAJOR}::Core MyLib)
```

Now use library in main.cpp .

```
#include <QCoreApplication>
#include <mylib.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyLib mylib;

    mylib.Test_1();
    mylib.Test_2();

    return a.exec();
}

```

# Usage

## **Step 1**

After building the MyLib library, you must run the following command in that folder.


```command
cmake --install ./
```

**Note:** That Cmake must be installed on your system before that.

Now you will have a folder called Release in the folder next to "MyLib", where the library outputs are placed.

**Release Folder Structure**
```
└── bin
|   └── MyLib.dll
└── include
|   ├── MyLib_global.h
|   └── mylib.h
└── lib
    └── MyLib.lib
```

## **Step 2**

Now you can use this library by running the MyLibTest project using the Release folder.
