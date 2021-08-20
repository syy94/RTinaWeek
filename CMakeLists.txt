cmake_minimum_required(VERSION 3.0.0)
project(RTinaWeek VERSION 0.1.0)

include(CTest)
enable_testing()

#source code management
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(RTinaWeek 
                src/main.cpp
                src/ray.cpp
                src/sphere.cpp
                src/vec3.cpp
                src/camera.cpp
                src/color.cpp
                src/hittable_list.cpp
                src/hittable.cpp

                include/vec3.hpp
                include/color.hpp
                include/ray.hpp
                include/sphere.hpp
                include/hittable.hpp
                include/hittable_list.hpp
                include/utility.hpp
                include/camera.hpp
                include/material.hpp
                
            )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
