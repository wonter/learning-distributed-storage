.PHONY : all clean
all: sync_timer async_timer async_timer_with_args async_timer_with_member_function async_timer_parallel
clean:
	rm -rf sync_timer async_timer async_timer_with_args async_timer_with_member_function async_timer_parallel

sync_timer: sync_timer.cc
	g++ -std=c++11 sync_timer.cc -lboost_chrono -o sync_timer

async_timer: async_timer.cc
	g++ -std=c++11 async_timer.cc -lboost_chrono -o async_timer

async_timer_with_args: async_timer_with_args.cc
	g++ -std=c++11 async_timer_with_args.cc -lboost_chrono -o async_timer_with_args

async_timer_with_member_function: async_timer_with_member_function.cc
	g++ -std=c++11 async_timer_with_member_function.cc -lboost_chrono -o async_timer_with_member_function

async_timer_parallel: async_timer_parallel.cc
	g++ -std=c++11 async_timer_parallel.cc -lboost_chrono -o async_timer_parallel
