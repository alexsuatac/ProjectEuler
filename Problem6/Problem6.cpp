// compute the difference between the sum of squares
// and square of sums for all integers between 1 and 100
// compile with "g++ -std=c++17 -o p6 Problem6.cpp"

// algorithm plan
// 1. use std::reduce for summing range of integers and square it
// 2. use a transform_reduce to take a vector of ints and square all elements
// and return their sum
// three return the difference of 1. and 2.

#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> v(100);
    std::iota (std::begin(v), std::end(v), 1); // fill v with ints 1..100

    // sum range of ints and square it
    int sum = std::reduce(v.cbegin(), v.cend());
    int sum_squared = sum*sum;

    // sum transform range by squaring each value and reduce into sum
    int squared_sum = std::transform_reduce(
    v.cbegin(), v.cend(),
    0,
    [] (auto a, auto b) {return a+b;},
    [] (auto a) {return a*a;}
    );

    std::cout << sum_squared - squared_sum << std::endl;

    return 0;
}
