// find the sum of all prime numbers below 2e6
// compile with g++ -g -std=c++17 -o p10 Problem10.cpp -ltbb
// requires libtbb to be installed for <execution>

#include <iostream>
#include <math.h>
#include <vector>
#include <numeric>
#include <execution>
#include <algorithm>
    
using typ = long long unsigned int;

bool isPrime(typ n) {
    if (n < 2) {
        return false;
    }

    // if a factor less than or equal to sqrt(n) exists, then the number is not prime
    for (typ i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main () {
    const typ VAL = 2e6;
    
    // algorithm plan:
    // 1. generate vector and fill in increments of 1 from 2 up to 2e6
    std::vector<typ> v(VAL);
    std::iota(v.begin(), v.end(), 2);

    // 2. check for primality in parallel, and remove element if not prime
    v.erase(std::remove_if(std::execution::par, v.begin(), v.end(), [](typ n){return !isPrime(n);}), v.end());
    
    // 3. once done, accumulate sum and return value
    std::cout << std::accumulate(v.begin(), v.end(), static_cast<typ>(0) ) << std::endl;

    return 0;
}
