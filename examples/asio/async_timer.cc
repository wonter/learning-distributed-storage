#include <iostream>

#include "boost/asio.hpp"

void end_handler(const boost::system::error_code& /*ec*/) {
    std::cout << "end timer" << std::endl;
}

int main() {
    boost::asio::io_context io_context;
    boost::asio::steady_timer timer(io_context,
                                    boost::asio::chrono::seconds(3));

    std::cout << "start timer" << std::endl;
    timer.async_wait(end_handler);

    io_context.run();
    return 0;
}
