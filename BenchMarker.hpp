#ifndef BENCHMARKER_HPP
#define BENCHMARKER_HPP


#include <functional>
#include <chrono>
#include <type_traits>


template<typename T>
struct is_duration : std::false_type { };

template<typename Rep, typename Period>
struct is_duration<std::chrono::duration<Rep, Period>> : std::true_type { };

class BenchMarker {
public:
    template<typename Duration>
    static Duration Benchmark(const std::function<void()>& func)
    {
        // Compile-time sanity check
        static_assert(is_duration<Duration>::value, "Duration typename must be a std::chrono::duration");
        auto start = std::chrono::high_resolution_clock::now();
        func();
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<Duration>(end - start);
    }

};


#endif
