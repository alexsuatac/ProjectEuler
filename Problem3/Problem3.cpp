#include <iostream>

bool isPrime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }

    for (int i = 2; i < n/2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main () {

    // make function that determines if number is prime

    // main loop will count down from value, checking if each number is prime
    // when it is, it will be the largest one
     
    return 0;
}
