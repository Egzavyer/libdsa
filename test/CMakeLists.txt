project(test)
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Google_Tests_run target
add_executable(Google_Tests_run  darrayTest.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)