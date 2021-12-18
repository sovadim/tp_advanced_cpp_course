#include <gtest/gtest.h>
#include <loglevel.h>
#include <loglib.h>
#include <string_view>

class StderrLoggerTest : public ::testing::Test
{
protected:
    static constexpr std::string_view raw_message{"message"};
    static constexpr std::string_view expected_message{"message\n"};
};

TEST_F(StderrLoggerTest, LevelErrorWritesError)
{
    createStderrLogger(log::Level::ERROR);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::error(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, expected_message);
}

TEST_F(StderrLoggerTest, LevelErrorWritesWarning)
{
    createStderrLogger(log::Level::ERROR);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::warning(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, "");
}

TEST_F(StderrLoggerTest, LevelErrorWritesInfo)
{
    createStderrLogger(log::Level::ERROR);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::info(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, "");
}

TEST_F(StderrLoggerTest, LevelErrorWritesDebug)
{
    createStderrLogger(log::Level::ERROR);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::debug(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, "");
}

TEST_F(StderrLoggerTest, LevelWarningWritesError)
{
    createStderrLogger(log::Level::WARNING);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::error(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, expected_message);
}

TEST_F(StderrLoggerTest, LevelWarningWritesWarning)
{
    createStderrLogger(log::Level::WARNING);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::warning(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, expected_message);
}

TEST_F(StderrLoggerTest, LevelWarningWritesInfo)
{
    createStderrLogger(log::Level::WARNING);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::info(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, "");
}

TEST_F(StderrLoggerTest, LevelWarningWritesDebug)
{
    createStderrLogger(log::Level::WARNING);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::debug(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, "");
}

TEST_F(StderrLoggerTest, LevelInfoWritesError)
{
    createStderrLogger(log::Level::INFO);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::error(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, expected_message);
}

TEST_F(StderrLoggerTest, LevelInfoWritesWarning)
{
    createStderrLogger(log::Level::INFO);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::warning(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, expected_message);
}

TEST_F(StderrLoggerTest, LevelInfoWritesInfo)
{
    createStderrLogger(log::Level::INFO);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::info(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, expected_message);
}

TEST_F(StderrLoggerTest, LevelInfoWritesDebug)
{
    createStderrLogger(log::Level::INFO);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::debug(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, "");
}

TEST_F(StderrLoggerTest, LevelDebugWritesError)
{
    createStderrLogger(log::Level::DEBUG);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::error(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, expected_message);
}

TEST_F(StderrLoggerTest, LevelDebugWritesWarning)
{
    createStderrLogger(log::Level::DEBUG);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::warning(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, expected_message);
}

TEST_F(StderrLoggerTest, LevelDebugWritesInfo)
{
    createStderrLogger(log::Level::DEBUG);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::info(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, expected_message);
}

TEST_F(StderrLoggerTest, LevelDebugWritesDebug)
{
    createStderrLogger(log::Level::DEBUG);
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    log::debug(raw_message);
    std::string stdout = testing::internal::GetCapturedStdout();
    std::string stderr = testing::internal::GetCapturedStderr();
    ASSERT_EQ(stdout, "");
    ASSERT_EQ(stderr, expected_message);
}
