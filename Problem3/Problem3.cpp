#include <iostream>

bool isPrime(long n) {
    if (n == 0 || n == 1) {
        return false;
    }

    for (long i = 2; i < n/2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main () {

    const static long long VAL = 600851475143;
    
    for (long i = VAL/2; i > 0; --i) { // a number can't be evenly divisible by more than 1/2 of itself
        // find if i is a factor of VAL
        if (VAL % i == 0) {
            if (isPrime(i)) {
                std::cout << "Largest prime factor of "
                << VAL << " is " << i << std::endl;
                return 0;
            }
        }
    }

    std::cout << "There are no prime factors" << std::endl;
    return 0;
}
