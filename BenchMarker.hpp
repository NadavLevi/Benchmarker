#ifndef BENCHMARKER_HPP
#define BENCHMARKER_HPP


#include <functional>
#include <chrono>

class BenchMarker {
public:
    template<typename ReturnType>
    static ReturnType Benchmark(std::function<void()> func);

};


#endif
