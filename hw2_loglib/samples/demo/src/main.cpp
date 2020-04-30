#include <loglib.h>

int main() {

    // TODO: getopt
    // --verbose - all logs
    // --quiet
    // --log-to-file <path>

    // tmp
    log::create_stdout_logger();

    log::debug("debug");
    log::info("info");
    log::warning("warning");
    log::error("error");

    std::string str("str");
    log::debug(str);
    log::info(str);
    log::warning(str);
    log::error(str);

    // TODO: implement some examples which write logs with all levels

    return 0;
}