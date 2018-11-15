#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
  int jan1_1901 = 1;
  int[] monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for(int month = 0; month < 12; month++){
    jan1_1901 += monthDays[month];
  }
  int totalDays = 365*100;
  int leapYears = 0;
  for(int year = 1900; year < 2001; year++){
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
      leapYears++;
    }
  }
  totalDays += leapYears;
  int sundays = totalDays/7;
  cout << sundays << endl;
  return 0;
}
