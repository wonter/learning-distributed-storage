#include <iostream>

#include "boost/asio.hpp"
#include "boost/bind/bind.hpp"
#include "boost/thread/thread.hpp"

class Printer {
   public:
    Printer(boost::asio::io_context &io)
        : strand_(boost::asio::make_strand(io)),
          timer1_(io, boost::asio::chrono::seconds(1)),
          timer2_(io, boost::asio::chrono::seconds(1)) {
        timer1_.async_wait(boost::asio::bind_executor(
            strand_,
            boost::bind(&Printer::print1, this, boost::placeholders::_1)));
        timer2_.async_wait(boost::asio::bind_executor(
            strand_,
            boost::bind(&Printer::print2, this, boost::placeholders::_1)));
    }

    void print1(const boost::system::error_code & /*ec*/) {
        if (counter_ < 10) {
            std::cout << "Timer 1: counter = " << counter_ << std::endl;
            ++counter_;
            timer1_.expires_at(timer1_.expiry() +
                               boost::asio::chrono::seconds(1));
            timer1_.async_wait(boost::asio::bind_executor(
                strand_,
                boost::bind(&Printer::print1, this, boost::placeholders::_1)));
        }
    }

    void print2(const boost::system::error_code & /*ec*/) {
        if (counter_ < 10) {
            std::cout << "Timer 2: counter = " << counter_ << std::endl;
            ++counter_;
            timer2_.expires_at(timer2_.expiry() +
                               boost::asio::chrono::seconds(1));
            timer2_.async_wait(boost::asio::bind_executor(
                strand_,
                boost::bind(&Printer::print2, this, boost::placeholders::_1)));
        }
    }

   private:
    boost::asio::strand<boost::asio::io_context::executor_type> strand_;
    boost::asio::steady_timer timer1_;
    boost::asio::steady_timer timer2_;
    int counter_;
};

int main() {
    boost::asio::io_context io_context;

    std::cout << "start timer" << std::endl;
    Printer printer(io_context);

    std::thread t(boost::bind(&boost::asio::io_context::run, &io_context));
    io_context.run();
    t.join();
    return 0;
}
