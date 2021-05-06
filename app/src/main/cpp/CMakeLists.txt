# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

### add
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/DES)
add_library( DES
        STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/keyGeneration.c
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/BitPermutationFunctions.c
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/DESEncrypt.c
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/DESDecrypt.c
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/FileReader.c
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/DataPrint.c
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/keyReader.c
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/CBCDESEncryption.c
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/CBCDESDecryption.c
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/tripleDESCBCEncryption.c
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/tripleDESCBCDecryption.c
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/tripleKeyDESCBCEncryption.c
        ${CMAKE_CURRENT_SOURCE_DIR}/DES/tripleKeyDESCBCDecryption.c
        )
#add_library(lib_des STATIC IMPORTED)
#set_target_properties(lib_des PROPERTIES IMPORTED_LOCATION
#        ${CMAKE_SOURCE_DIR}/libDES1.a)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             native-lib.cpp utils.c)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib
        DES
#        lib_des
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )