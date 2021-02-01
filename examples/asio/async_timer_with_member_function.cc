#include <iostream>

#include "boost/asio.hpp"
#include "boost/bind/bind.hpp"

class Printer {
   public:
    Printer(boost::asio::io_context &io)
        : timer_(io, boost::asio::chrono::seconds(1)) {
        timer_.async_wait(
            boost::bind(&Printer::end_handler, this, boost::placeholders::_1));
    }

    void end_handler(const boost::system::error_code & /*ec*/) {
        std::cout << "counter=" << counter_ << std::endl;
        if (counter_ < 5) {
            ++counter_;
            timer_.expires_at(timer_.expiry() + std::chrono::seconds(1));
            timer_.async_wait(boost::bind(&Printer::end_handler, this,
                                          boost::placeholders::_1));
        }
    }

   private:
    boost::asio::steady_timer timer_;
    int counter_;
};

int main() {
    boost::asio::io_context io_context;

    std::cout << "start timer" << std::endl;
    Printer printer(io_context);

    io_context.run();
    return 0;
}
