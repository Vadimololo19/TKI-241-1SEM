add_executable(Tests
    Tests.cpp
)

target_link_libraries(Tests PRIVATE Lib GTest::gtest_main)
add_test(NAME RunUnitTests COMMAND Tests)
