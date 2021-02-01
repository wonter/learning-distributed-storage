#include <iostream>

#include "boost/asio.hpp"
#include "boost/bind/bind.hpp"

void end_handler(const boost::system::error_code & /*ec*/,
                 boost::asio::steady_timer *timer, int *counter) {
    std::cout << "counter=" << *counter << std::endl;
    if (*counter < 5) {
        ++(*counter);
        timer->expires_at(timer->expiry() + std::chrono::seconds(1));
        timer->async_wait(boost::bind(end_handler, boost::placeholders::_1,
                                      timer, counter));
    }
}

int main() {
    boost::asio::io_context io_context;

    int counter = 0;
    boost::asio::steady_timer timer(io_context,
                                    boost::asio::chrono::seconds(1));

    std::cout << "start timer" << std::endl;
    timer.async_wait(
        boost::bind(end_handler, boost::placeholders::_1, &timer, &counter));
    io_context.run();
    return 0;
}
