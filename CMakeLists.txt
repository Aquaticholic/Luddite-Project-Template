cmake_minimum_required (VERSION 3.6)


project(Luddite-Project LANGUAGES C CXX VERSION 0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/Luddite-Engine/)

if(LINUX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -DCOMPILE_PATH=\"\\\"${CMAKE_BINARY_DIR}\\\"\"")
endif()

file(GLOB_RECURSE PROJECT_SOURCE "src/*.c" "src/*.cc" "src/*.cpp" "src/*.h" "src/*.hpp")
if(WINDOWS)
add_executable(Project WIN32 ${PROJECT_SOURCE})
else()
add_executable(Project ${PROJECT_SOURCE})
endif()

target_compile_definitions(Project PRIVATE
${ENGINE_PLATFORM_DEFINE} 
${ENGINE_CONFIGURATION_DEFINE}
)

target_link_libraries(Project
Luddite-Engine
)

target_include_directories(Project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
"${ENGINE_INCLUDE}"
)

target_precompile_headers(Project PUBLIC src/pch.hpp)
file(COPY ${CMAKE_SOURCE_DIR}/vendor/Luddite-Engine/Assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/Assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#file(COPY ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json DESTINATION ${CMAKE_SOURCE_DIR})
