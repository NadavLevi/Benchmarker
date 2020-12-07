#include <thread>
#include <iostream>
#include "BenchMarker.hpp"

int wait2sec(int a)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a;
}

int main()
{
    std::function<void()> func = [] { return wait2sec(3); };
    auto ret = BenchMarker::Benchmark<std::chrono::nanoseconds>(func);
    std::cout << ret.count() << std::endl;
    return 0;
}