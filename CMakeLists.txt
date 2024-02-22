cmake_minimum_required(VERSION 3.10)
project(UrbanDictionary)

# Find required packages
find_package(wxWidgets COMPONENTS core base REQUIRED)
find_package(CURL REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
link_libraries(${JSONCPP_LIBRARIES})

# Set source files
set(SOURCES
    main.cpp
    urban_dict_request.cpp
)

# Include directories
include(${wxWidgets_USE_FILE})
include_directories(${CURL_INCLUDE_DIRS})
include_directories(${JsonCpp_INCLUDE_DIRS})

# Add executable
add_executable(UrbanDictionary ${SOURCES})

# Link libraries
target_link_libraries(UrbanDictionary
    ${wxWidgets_LIBRARIES}
    ${CURL_LIBRARIES}
    ${JSONCPP_LIBRARIES}
)

