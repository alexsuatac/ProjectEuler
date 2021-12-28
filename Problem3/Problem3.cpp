#include <iostream>
#include <math.h>

bool isPrime(long n) {
    if (n == 0 || n == 1) {
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
    unsigned largest_prime_factor = 0;
    
    // a number can't be evenly divisible by more 
    // than 1/2 of itself, and even numbers can't be prime
    for (long i = 3; i < VAL/2; i+=2) { 

        // find if i is a factor of VAL
        if (VAL % i == 0) {
            if (isPrime(i)) {
                largest_prime_factor = i;
            }
        }
    }

    if (largest_prime_factor == 0) {
        std::cout << "There are no prime factors" << std::endl;
    }
    else {
        std::cout << "Largest prime factor of "
            << VAL << " is " << largest_prime_factor << std::endl;
    }
    return 0;
}
