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

set(USER_SOURCES
    src/user/User.cpp
    src/user/Admin.cpp
    src/user/VipUser.cpp
    src/user/Support.cpp
    src/user/UserProfile.cpp
    src/user/DriverLicense.cpp
    src/user/Wallet.cpp
    src/user/ActiveHistory.cpp
    src/user/UserValidator.cpp
    src/user/PasswordHasher.cpp
)

add_executable(GoTo 
    src/main.cpp 
    src/box.cpp
    src/loadFont.cpp
    src/inputBox.cpp
    src/outBox.cpp
    src/textBox.cpp
    src/caret.cpp
    src/formScreen.cpp
    src/signUp.cpp
    src/signIn.cpp
    ${USER_SOURCES}
)

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

add_executable(test_user
    test/user/test_user.cpp
    ${USER_SOURCES}
)
target_include_directories(test_user PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)