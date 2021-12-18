#include <gtest/gtest.h>
#include <loglevel.h>
#include <loglib.h>
#include <string_view>

class StdoutLoggerTest : public ::testing::Test
{
protected:
    static constexpr std::string_view raw_message{"message"};
    static constexpr std::string_view expected_message{"message\n"};
};

TEST_F(StdoutLoggerTest, LevelErrorWritesError)
{
    createStdoutLogger(log::Level::ERROR);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::error(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, expected_message);
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelErrorWritesWarning)
{
    createStdoutLogger(log::Level::ERROR);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::warning(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelErrorWritesInfo)
{
    createStdoutLogger(log::Level::ERROR);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::info(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelErrorWritesDebug)
{
    createStdoutLogger(log::Level::ERROR);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::debug(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelWarningWritesError)
{
    createStdoutLogger(log::Level::WARNING);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::error(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, expected_message);
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelWarningWritesWarning)
{
    createStdoutLogger(log::Level::WARNING);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::warning(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, expected_message);
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelWarningWritesInfo)
{
    createStdoutLogger(log::Level::WARNING);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::info(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelWarningWritesDebug)
{
    createStdoutLogger(log::Level::WARNING);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::debug(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelInfoWritesError)
{
    createStdoutLogger(log::Level::INFO);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::error(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, expected_message);
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelInfoWritesWarning)
{
    createStdoutLogger(log::Level::INFO);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::warning(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, expected_message);
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelInfoWritesInfo)
{
    createStdoutLogger(log::Level::INFO);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::info(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, expected_message);
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelInfoWritesDebug)
{
    createStdoutLogger(log::Level::INFO);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::debug(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelDebugWritesError)
{
    createStdoutLogger(log::Level::DEBUG);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::error(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, expected_message);
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelDebugWritesWarning)
{
    createStdoutLogger(log::Level::DEBUG);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::warning(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, expected_message);
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelDebugWritesInfo)
{
    createStdoutLogger(log::Level::DEBUG);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::info(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, expected_message);
    ASSERT_EQ(stderr, "");
}

TEST_F(StdoutLoggerTest, LevelDebugWritesDebug)
{
    createStdoutLogger(log::Level::DEBUG);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::debug(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, expected_message);
    ASSERT_EQ(stderr, "");
}
