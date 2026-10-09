cmake_minimum_required(VERSION 4.4.0)
project(GoTo)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

find_package(SFML 3.1 COMPONENTS Graphics Window System CONFIG QUIET)

if(NOT SFML_FOUND)
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG        3.1.0
    )
    
    set(SFML_BUILD_EXAMPLES OFF CACHE INTERNAL "")
    set(SFML_BUILD_TESTS OFF CACHE INTERNAL "")
    set(SFML_BUILD_DOC OFF CACHE INTERNAL "")

    FetchContent_MakeAvailable(SFML)
endif()

add_executable(GoTo src/ui.cpp)

target_include_directories(GoTo PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(WIN32)
    set_target_properties(GoTo PROPERTIES 
        WIN32_EXECUTABLE OFF
    )
endif()

target_link_libraries(GoTo PRIVATE 
    SFML::Graphics 
    SFML::Window 
    SFML::System 
)