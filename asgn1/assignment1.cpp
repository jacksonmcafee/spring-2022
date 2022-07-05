#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <iostream>
#include <algorithm>

void userInput(int* number_length, int* max_range, int* generation_range);
void lotteryPulls(int number_length, int max_range, int generation_range);
double factorial(int n);
void lotteryChances(int n, int r);

int main() {
    // used for function calls and program stucture
    int number_length, max_range, generation_range;
    userInput(&number_length, &max_range, &generation_range);
    lotteryPulls(number_length, max_range, generation_range);

    return 0;
}

void userInput(int* number_length, int* max_range, int* generation_range) {
    // used to collect information from user about their pull specs
    // prints majority of code aside from actual pulls themselves
    // error checking built into while functions

    // variable declaration
    int a = 0, b = 0, c = 0;

    while(a == 0 || a > 7 || a < 3) {
    std::cout << "How many values do you want per number? (3-7)" << std::endl;
    std::cin >> a;
    }
    *number_length = a;
    std::cout << "You will select " << a << " numbers" << std::endl;

    while(b == 0 || b > 70 || b < 45) {
    std::cout << "What is the maximum number you want generated? (45-70)" << std::endl;
    std::cin >> b;
    }
    *max_range = b;
    std::cout << "The numbers will range from 1 to " << b << std::endl;

    while(c == 0 || c > 100 || c < 1) {
    std::cout << "How many tickets do you want to be generated? (1-100)" << std::endl;
    std::cin >> c;
    }
    *generation_range = c;
}

void lotteryPulls(int number_length, int max_range, int generation_range) {
    // generates number pulls for user and prints them
    int a = number_length;
    int b = generation_range;
    int pull = 0;
    std::vector<int> arr;
    srand(time(NULL));
    std::cout << "YOUR LOTTERY SELECTIONS ARE:" << std::endl;

    // generation loop + printing
    for(b > 0; b--;) {
      while(a > 0) {
        while(std::find(arr.begin(), arr.end(), pull) != arr.end()) {
          // generate a new value
          pull = (rand() % max_range + 1);
        }
        arr.push_back(pull);
        a--;
      }

      a = number_length;
      for(int i=0; i < arr.size(); i++) {
        std::cout << arr.at(i) << ' ';
      }
      arr.clear();
      std::cout << std::endl;
    }
    lotteryChances(max_range, generation_range);
}

double factorial(int z) {
  double answer = 1;
  for(double i = 1; i <= z; ++i) {
            answer *= i;
        }
  return answer;
}

void lotteryChances(int n, int r) {
    double chances = (factorial(n) / (factorial(r) * factorial(n-r)));

    std::cout << "Your chances to win are approximately 1 in " << chances << std::endl;
}
