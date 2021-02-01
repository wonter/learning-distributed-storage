#include <iostream>

#include "boost/asio.hpp"

int main() {
    boost::asio::io_context io_context;
    boost::asio::steady_timer timer(io_context,
                                    boost::asio::chrono::seconds(3));

    std::cout << "start timer" << std::endl;
    timer.wait();
    std::cout << "end timer" << std::endl;
    return 0;
}
