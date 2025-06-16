cmake_minimum_required(VERSION 3.10)
project(MetricsLogger)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${PROJECT_SOURCE_DIR}/HelpersFunctions
    ${PROJECT_SOURCE_DIR}/MetricsCollector
)

add_executable(MetricsLogger
    main.cpp

    HelpersFunctions/RandomEvent.cpp

    MetricsCollector/MetricsCollector.cpp
)
