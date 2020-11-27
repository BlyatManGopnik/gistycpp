cmake_minimum_required(VERSION 3.10)
include(FetchContent)
SET(USE_SYSTEM_CURL ON CACHE BOOL "System CURL")
SET(BUILD_CPR_TESTS OFF CACHE BOOL "CPR TESTS")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set the project name
project(Gisty)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG c8d33915dbd88ad6c92b258869b03aba06587ff9)
FetchContent_MakeAvailable(cpr)
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.9.1)
FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
# add the executable
add_executable(gisty gisty.cpp headless.cpp post.cpp)
target_link_libraries(gisty PRIVATE cpr::cpr)
target_link_libraries(gisty PRIVATE nlohmann_json::nlohmann_json)
