#include "base64.h"
#include <algorithm>
#include <iostream>
#include <string_view>
#include <vector>
#include <array>
#include <benchmark/benchmark.h>

static void BM_to_base64(benchmark::State& state) {
    std::vector<char> v;
    v.resize(16*1024*1024);
    std::generate(v.begin(), v.end(), rand);

    for (auto _ : state) {
        const std::string s = to_base64(std::string_view{ v.data(), v.size() });
        benchmark::DoNotOptimize(s);
    }
}

static void BM_from_base64(benchmark::State& state) {
    std::vector<char> v;
    v.resize(16*1024*1024);
    std::generate(v.begin(), v.end(), rand);

    const std::string o = to_base64(std::string_view{ v.data(), v.size() });

    for (auto _ : state) {
        const std::string s = from_base64(o);
        benchmark::DoNotOptimize(s);
    }
}

BENCHMARK(BM_to_base64);
BENCHMARK(BM_from_base64);
BENCHMARK_MAIN();
