add_executable(Tests
    MatrixTest.cpp
    GeneratorTest.cpp
    TaskTest.cpp
)

target_link_libraries(Tests PRIVATE MatrixLib GTest::gtest_main)

add_test(NAME RunUnitTests COMMAND Tests)
