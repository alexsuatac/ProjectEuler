// compile with g++ -g -std=c++17 -o p3 Problem3.cpp -ltbb
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
    for (long i = 2; i < std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main () {

    const static long long VAL = 600851475143;
    std::vector<long long> v(VAL/2e3); // TODO: use paging
    // fill v with odd numbers in the range (3,VAL/2)
    // because even numbers can't be prime (except 2)
    // and a number can't be evenly divided by more than
    // half of itself
    std::generate (std::begin(v), std::end(v),
    []() { static long long i = 1; return i+=2;});

    // algorithm plan:
    // 1. if element in vector does not evenly divide VAL, remove from vector
    v.erase(
        std::remove_if(std::execution::par, v.begin(), v.end(), [](long long n){return VAL % n;}),
        v.end());

    // 2. if element in resulting vector is not prime, remove from vector
    v.erase(
        std::remove_if(std::execution::par, v.begin(), v.end(), [](long n){return !isPrime(n);}),
        v.end());

    // 3. largest value in resulting vector is largest prime factor of VAL
    long long largest_prime_factor = *(std::max_element(v.cbegin(), v.cend()));    

    if (largest_prime_factor == 0) {
        std::cout << "There are no prime factors" << std::endl;
    } else {
        std::cout << "Largest prime factor of "
            << VAL << " is " << largest_prime_factor << std::endl;
    }

    return 0;
}
