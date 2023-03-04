# Project #-----------------------------------------------------------------------------------------
project ( Project-CPD )

cmake_minimum_required ( VERSION 2.8.12 )

# Ajout des flags pour lier JSONCpp à votre projet
#target_link_libraries(your_target jsoncpp)

#find_package ( REQUIRED libsfml)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# C++ Warning Level #-------------------------------------------------------------------------------
if ( CMAKE_COMPILER_IS_GNUCXX )
 set ( CMAKE_CXX_FLAGS "-g -Wall -pedantic ${CMAKE_CXX_FLAGS}" )
endif ()

# C++14 #-------------------------------------------------------------------------------------------
include ( CheckCXXCompilerFlag )

check_cxx_compiler_flag ( "-std=gnu++14" COMPILER_SUPPORTS_CPP14 )
check_cxx_compiler_flag ( "-std=gnu++1y" COMPILER_SUPPORTS_CPP1Y )
check_cxx_compiler_flag ( "-std=gnu++11" COMPILER_SUPPORTS_CPP11 )
check_cxx_compiler_flag ( "-std=gnu++0x" COMPILER_SUPPORTS_CPP0X )

if ( COMPILER_SUPPORTS_CPP14 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++14 ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP1Y )
 set ( CMAKE_CXX_FLAGS "-std=gnu++1y ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP11 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}" )
elseif( COMPILER_SUPPORTS_CPP0X )
 set ( CMAKE_CXX_FLAGS "-std=gnu++0x ${CMAKE_CXX_FLAGS}" )
else ()
 message ( STATUS "Compiler ${CMAKE_CXX_COMPILER} has no C++11/14 support." )
endif ()

message ( STATUS "Compiler flags: ${CMAKE_CXX_FLAGS}" )

# Sources #-----------------------------------------------------------------------------------------
set ( ZZ3_HEADERS
    )

set ( ZZ3_SOURCES
      src/main.cpp
    )

include_directories ( src/ )

# Executables #-------------------------------------------------------------------------------------
add_executable ( Prog
		src/main.cpp
                 ${ZZ3_HEADERS}
                 ${ZZ3_SOURCES}
               )
# Build #-------------------------------------------------------------------------------------------
set_target_properties ( Prog PROPERTIES LINKER_LANGUAGE C )
target_link_libraries ( Prog ${CMAKE_SFML_LIBS_INIT})
