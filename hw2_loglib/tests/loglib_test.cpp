#include <gtest/gtest.h>
#include <loglib.h>

class StdouLoggerTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // TODO: setup logger
    }
};

TEST_F(StdouLoggerTest, OutputTest)
{
    ASSERT_TRUE(true);
}
