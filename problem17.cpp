#include <cstdlib>
#include <iostream>

using namespace std;

// Gets the number of characters in the "ones place" of the input number,
// eg 5 (five) would return 4
int charsFromOnesPlace(int n){
  int onesDigit = n % 10;
  switch(onesDigit){
    case 0: {
      return 0;
    }
    case 1:
    case 2:
    case 6:
      return 3;

    case 4:
    case 5:
    case 9:
      return 4;

    case 3:
    case 7:
    case 8:
      return 5;

    default:
      return 0;
  }
}

// Works similarly to charsFromOnesPlaces, but has added options for the teen numbers,
// Which add logistical issues.
int charsFromTensPlace(int n){
  int tensDigit = (n/10) % 10;
  switch(tensDigit){
    case 0:
      return 0;

    case 1:
      switch(n % 10){
        case 0:
          return 3;
        case 1:
        case 2:
          return 6;

        case 3:
        case 4:
        case 8:
        case 9:
          return 8;

        case 5:
        case 6:
          return 7;

        case 7:
          return 9;

        default:
          return 0;
      }

    case 2:
    case 3:
    case 8:
    case 9:
      return 6;

    case 4:
    case 5:
    case 6:
      return 5;

    case 7:
      return 7;

    default:
      return 0;

  }
}

int charsFromHundredsPlace(int n){
  int hundredsDigit = (n/100) % 10;
  if(hundredsDigit != 0){
    return charsFromOnesPlace(hundredsDigit) + 7;
  }
  else return 0;
}

int main(){
  int sum = 0;
  for(int i = 1; i < 1000; i++){
    int hundreds = charsFromHundredsPlace(i);
    int tens = charsFromTensPlace(i);
    int ones = charsFromOnesPlace(i);
    int total;

    int andChars;
    if(hundreds == 0 || (tens == 0 && ones == 0)){
      andChars = 0;
    }
    else andChars = 3;

    if(i/10 % 10 == 1){
      total = hundreds + andChars + tens;
    }
    else{
      total = hundreds + andChars + tens + ones;
    }
    sum += total;
  }
  // Add "one thousand"
  sum += 11;

  cout << "Total sum: " << sum << endl;

  return 0;
}
