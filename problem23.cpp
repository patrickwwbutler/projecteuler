/*
Problem:
A perfect number is a number for which the sum of its proper divisors is exactly
equal to the number. For example, the sum of the proper divisors of 28 would be
1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n
and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
number that can be written as the sum of two abundant numbers is 24.

By mathematical analysis, it can be shown that all integers greater than 28123
can be written as the sum of two abundant numbers. However, this upper limit
cannot be reduced any further by analysis even though it is known that the
greatest number that cannot be expressed as the sum of two abundant numbers is
less than this limit.

Find the sum of all the positive integers which cannot be written as the sum
of two abundant numbers.
*/

#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <iostream>

using namespace std;

// Returns all divisors of n in order, including 1, but not n, AKA the proper divisors
bool abundant(int n){
  double sqrtDouble = sqrt((double) n);
  int sqrt = (int) sqrtDouble;
  int sum = 0;
  if(n % sqrt == 0){
    sum += sqrt;
  }
  for(int i = sqrt - 1; i > 1; i--){
    if(n % i == 0){
      sum += i;
      sum += (n / i);
    }
  }

  sum += 1;

  return sum > n;
}


int main(void){
  vector<int> abundants;
  for(int i = 2; i < 28123; i++){
    if(abundant(i)){
      abundants.push_back(i);
    }
  }
  // The sum of every integer from 1 to 28123
  int totalSum = 28123*(1 + 28123)/2;
  for(int i = 0; i < abundants.size(); i++){
    for(int j = i; j < abundants.size(); j++){
      if(abundants[i] + abundants[j] <= 28123){
        totalSum -= (abundants[i] + abundants[j]);
      }
    }
  }
  cout << totalSum << endl;
}
