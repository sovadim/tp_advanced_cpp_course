#include <gtest/gtest.h>
#include <loglevel.h>
#include <loglib.h>
#include <string_view>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

class FileLoggerTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        fs::remove(filename);
    }

    void TearDown() override
    {
        fs::remove(filename);
    }

    std::string read_log_file()
    {
        std::ifstream ifstream{fs::path(filename)};
        std::stringstream buffer;
        buffer << ifstream.rdbuf();
        return buffer.str();
    }

    bool file_exists()
    {
        return fs::exists(filename);
    }
    
    bool log_is_empty()
    {
        return fs::is_empty(filename);
    }

    static constexpr std::string_view filename {"test_filelogger.log"};
    static constexpr std::string_view raw_message {"message"};
    static constexpr std::string_view expected_message {"message\n"};
};

TEST_F(FileLoggerTest, LoggerCreatesFile)
{
    ASSERT_FALSE(file_exists());
    createFileLogger(filename, log::Level::ERROR);
    ASSERT_TRUE(file_exists());
    ASSERT_TRUE(log_is_empty());
}

TEST_F(FileLoggerTest, LevelErrorWritesError)
{
    createFileLogger(filename, log::Level::ERROR);
    log::error(raw_message);
    log::flush();
    std::string output = read_log_file();
    ASSERT_EQ(output, expected_message);
}

TEST_F(FileLoggerTest, LevelErrorWritesWarning)
{
    createFileLogger(filename, log::Level::ERROR);
    log::warning(raw_message);
    log::flush();
    ASSERT_TRUE(log_is_empty());
}

TEST_F(FileLoggerTest, LevelErrorWritesInfo)
{
    createFileLogger(filename, log::Level::ERROR);
    log::info(raw_message);
    log::flush();
    ASSERT_TRUE(log_is_empty());
}

TEST_F(FileLoggerTest, LevelErrorWritesDebug)
{
    createFileLogger(filename, log::Level::ERROR);
    log::debug(raw_message);
    log::flush();
    ASSERT_TRUE(log_is_empty());
}

TEST_F(FileLoggerTest, LevelWarningWritesError)
{
    createFileLogger(filename, log::Level::WARNING);
    log::error(raw_message);
    log::flush();
    std::string output = read_log_file();
    ASSERT_EQ(output, expected_message);
}

TEST_F(FileLoggerTest, LevelWarningWritesWarning)
{
    createFileLogger(filename, log::Level::WARNING);
    log::warning(raw_message);
    log::flush();
    std::string output = read_log_file();
    ASSERT_EQ(output, expected_message);
}

TEST_F(FileLoggerTest, LevelWarningWritesInfo)
{
    createFileLogger(filename, log::Level::WARNING);
    log::info(raw_message);
    log::flush();
    ASSERT_TRUE(log_is_empty());
}

TEST_F(FileLoggerTest, LevelWarningWritesDebug)
{
    createFileLogger(filename, log::Level::WARNING);
    log::debug(raw_message);
    log::flush();
    ASSERT_TRUE(log_is_empty());
}

TEST_F(FileLoggerTest, LevelInfoWritesError)
{
    createFileLogger(filename, log::Level::INFO);
    log::error(raw_message);
    log::flush();
    std::string output = read_log_file();
    ASSERT_EQ(output, expected_message);
}

TEST_F(FileLoggerTest, LevelInfoWritesWarning)
{
    createFileLogger(filename, log::Level::INFO);
    log::warning(raw_message);
    log::flush();
    std::string output = read_log_file();
    ASSERT_EQ(output, expected_message);
}

TEST_F(FileLoggerTest, LevelInfoWritesInfo)
{
    createFileLogger(filename, log::Level::INFO);
    log::info(raw_message);
    log::flush();
    std::string output = read_log_file();
    ASSERT_EQ(output, expected_message);
}

TEST_F(FileLoggerTest, LevelInfoWritesDebug)
{
    createFileLogger(filename, log::Level::INFO);
    log::debug(raw_message);
    log::flush();
    ASSERT_TRUE(log_is_empty());
}

TEST_F(FileLoggerTest, LevelDebugWritesError)
{
    createFileLogger(filename, log::Level::DEBUG);
    log::error(raw_message);
    log::flush();
    std::string output = read_log_file();
    ASSERT_EQ(output, expected_message);
}

TEST_F(FileLoggerTest, LevelDebugWritesWarning)
{
    createFileLogger(filename, log::Level::DEBUG);
    log::warning(raw_message);
    log::flush();
    std::string output = read_log_file();
    ASSERT_EQ(output, expected_message);
}

TEST_F(FileLoggerTest, LevelDebugWritesInfo)
{
    createFileLogger(filename, log::Level::DEBUG);
    log::info(raw_message);
    log::flush();
    std::string output = read_log_file();
    ASSERT_EQ(output, expected_message);
}

TEST_F(FileLoggerTest, LevelDebugWritesDebug)
{
    createFileLogger(filename, log::Level::DEBUG);
    log::debug(raw_message);
    log::flush();
    std::string output = read_log_file();
    ASSERT_EQ(output, expected_message);
}
