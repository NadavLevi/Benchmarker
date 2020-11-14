#include <iostream>
#include "BenchMarker.hpp"

template<typename ReturnType>
ReturnType BenchMarker::Benchmark(std::function<void()> func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<ReturnType>(end - start).count();
}
