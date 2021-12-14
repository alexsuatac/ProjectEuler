#include <iostream>
#oinm

int main (int argc, char *argv[]) {
    
    bool goodArg = (argc == 2) && (std::stoi(argv[1]) > 0);
    if (!goodArg) {
        std::cout << "Usage: p3 <positive integer>" << std::endl;\
        return 0;
    }


    return 0;
}