project(json_t)
include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)
set (CMAKE_EXPORT_COMPILE_COMMANDS "ON")
add_executable(json json.cpp)
target_link_libraries(json PRIVATE nlohmann_json::nlohmann_json)
