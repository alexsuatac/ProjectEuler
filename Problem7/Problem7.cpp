// find the 10,001st prime number
// compile with g++ -g -std=c++17 -o p7 Problem7.cpp -ltbb
// requires libtbb to be installed for <execution>

#include <iostream>
#include <math.h>
#include <vector>
#include <numeric>
#include <execution>
#include <algorithm>


bool isPrime(long n) {
    if (n < 2) {
        return false;
    }

    // if a factor less than sqrt(n) exists, then the number is not prime
    for (long i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main () {

    const static int VAL = 1.1e5;
    
    // algorithm plan:
    // 1. generate vector of many values (say 10e6)
    std::vector<int> v(VAL/2); 
    // fill v with odd numbers in the range (2,VAL)
    // because even numbers can't be prime (except 2)
    v.at(0) = 2;
    std::generate (v.begin()+1, v.end(), []() { static int i = 1; return i+=2;});

    // 2. check for primality in parallel, and remove element if not prime
    v.erase(
        std::remove_if(std::execution::par, v.begin(), v.end(), [](int n){return !isPrime(n);}),
        v.end());

    // 3. once done, check for element 10001 and return if it exists (will be sorted)
    try {
        int p = v.at(10000);
        std::cout << "10001st prime is " << p << std::endl;
    } catch (...) {
        std::cout << VAL << " isn't big enough to contain 10001 primes\n"; 
    }

    return 0;
}
