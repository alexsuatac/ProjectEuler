// find the Pythagorean triplet (a<b<c && a^2 + b^2 = c^2) for which a+b+c = 1000
// and return the product a*b*c
// compile with g++ -o p9 Problem9.cpp

#include <iostream>

const bool satisfiesComparison(int a, int b, int c) { // not actually needed, due to order in for loop
    return (a < b) && (a < c) && (b < c);
}

const bool satisfiesSquare(int a, int b, int c) {
    return (a*a + b*b) == c*c;
}

const bool satisfiesSum(int a, int b, int c) {
    return a+b+c == 1000;
}

int main () {
    for(int a = 1; a < 1000; ++a) {
        for(int b = 1; b < 1000; ++b) {
            for(int c = 1; c < 1000; ++c) {
                if(/*satisfiesComparison(a, b, c) &&*/ satisfiesSquare(a, b, c) && satisfiesSum(a, b, c)) {
                    std::cout << "a: " << a << " b: " << b << " c: " << c << "\n";
                    std::cout << "a*b*c = " << a*b*c << std::endl;
                    goto DONE;
                }
            }
        }
    }
DONE:
    return 0;
}
