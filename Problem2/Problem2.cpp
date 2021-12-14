#include <iostream>

int main () {
  int prevTerm = 1;
  int curTerm = 2;
  int finalSum = 0;
  int tmp = 0;
  const int MAX_SEQUENCE_VALUE = 4000000;

  do {

    tmp = prevTerm + curTerm;
    prevTerm = curTerm;
    curTerm = tmp;

    if(prevTerm % 2 == 0) {
      finalSum += prevTerm;
    }

  }while(curTerm < MAX_SEQUENCE_VALUE);

  std::cout << "Sum of all even fibonacci numbers not exceeding 4 million is: " << finalSum << std::endl;
  return 0;
}
