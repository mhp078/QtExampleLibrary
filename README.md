
# Qt Library Example

In this example, a library is built with Qt and an output is provided that can be used in any other project.

Cmake is used in this library.


# MyLib Project

To build an exportable library, the following are required.

**CMakeLists.txt**

```
set(PROJECT_NAME "MyLib")
set(CMAKE_MYLIB_RELEASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Release")
```

```
set_target_properties(MyLib PROPERTIES OUTPUT_NAME "${PROJECT_NAME}")

install(TARGETS MyLib
        RUNTIME DESTINATION "${CMAKE_MYLIB_RELEASE_DIR}/bin"
        LIBRARY DESTINATION "${CMAKE_MYLIB_RELEASE_DIR}/lib"
        ARCHIVE DESTINATION "${CMAKE_MYLIB_RELEASE_DIR}/lib")

install(DIRECTORY / DESTINATION "${CMAKE_MYLIB_RELEASE_DIR}/include"
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