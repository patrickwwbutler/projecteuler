//created by Patrick Butler 8/18/17

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>

using namespace std;

void get_each_digit(int x, vector<int>& ret){
    if(x >= 10)
       get_each_digit(x / 10, ret);

    int digit = x % 10;

    ret.push_back(digit);
    //cout << digit << '\n';
}

void get_each_digit(long x, vector<int>& ret){
    if(x >= 10)
       get_each_digit(x / 10, ret);

    int digit = x % 10;

    ret.push_back(digit);
    //cout << digit << '\n';
}

bool palCheck(vector<int> digits){
	for(int i = 0; i < digits.size()/2; i++){
		if(digits[i] != digits[digits.size()-1-i]) return false;
	}
	return true;
}

void largestPalindrome(){
	vector<int> pals;
	for(int i = 999; i >= 100; i--){
		for(int j = i; j >= 100; j--){
			vector<int> dig_vec;
			get_each_digit(i*j, dig_vec);
			if(palCheck(dig_vec)) pals.push_back(i*j);
		}
	}
	int max = 0;
	for(int i = 0; i < pals.size(); i++){
		if(pals[i] > max){
			max = pals[i];
		}
	}
	cout << max << endl;
}

vector<int> string_to_int_vec(string s){
	vector<int> ret;
	for(int i = 0; i < s.length(); i++){
		ret.push_back(stoi(s.substr(i, 1)));
	}
	return ret;
}

void largestProdInSeries(){
	string num_string = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

	vector<int> digits = string_to_int_vec(num_string);
	vector<int> zero_ind;
	for(int i = 0; i < digits.size(); i++){
		if(digits[i] == 0){
			zero_ind.push_back(i);
		}
	}

	long max = 0;
	for(int i = 0; i < digits.size() - 12; i++){
		bool has_zero = false;
		for(int j = 0; j < zero_ind.size(); j++){
			if(i <= zero_ind[j] && i + 12 >= zero_ind[j]){
				i = zero_ind[j] + 1;
				has_zero = true;
			}
		}
		if(!has_zero){
			long product = digits[i];
			for(int j = 1; j < 13; j++){
				product *= digits[i + j];
			}
			if(product > max) max = product;
		}
	}
	cout << max << endl;
}

void pythagTriplet(){
	for(int i = 998; i > 0; i--){
		for(int j = 1; j < 1000 - i; j++){
			int k = 1000 - i - j;
			if((j*j + k*k) == (i*i)){
				cout << (i*j*k) << endl;
			}
		}
	}
}

void primeSum(){
	vector<int> primes;
	primes.push_back(2);
	cout << 2 << endl;
	for(int i = 3; i < 2000000; i+= 2){
		bool div = false;
		for(int j = 0; j < primes.size(); j++){
			if(i % primes[j] == 0){
				div = true;
				break;
			}
		}
		if(!div){
			primes.push_back(i);
			cout << i << endl;
		}
	}
	long sum = 0;
	for(int i = 0; i < primes.size(); i++){
		sum += primes[i];
	}
	cout << sum << endl;
}

void gridProduct(){



	cout << "Please enter the grid to be analyzed:" << endl;
	vector<vector<int> > grid;
	for(int i = 0; i < 20; i++){
		vector<int> row;
		for(int j = 0; j < 20; j++){
			int in;
			cin >> in;
			row.push_back(in);
		}
		grid.push_back(row);
	}
	long max = 0;
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			//right
			if(j < 17){
				if(grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3] > max){
					max = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
				}
			}
			//left
			if(j > 2){
				if(grid[i][j] * grid[i][j-1] * grid[i][j-2] * grid[i][j-3] > max){
					max = grid[i][j] * grid[i][j-1] * grid[i][j-2] * grid[i][j-3];
				}
			}
			//down
			if(i < 17){
				if(grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j] > max){
					max = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
				}
			}
			//up
			if(i > 2){
				if(grid[i][j] * grid[i-1][j] * grid[i-2][j] * grid[i-3][j] > max){
					max = grid[i][j] * grid[i-1][j] * grid[i-2][j] * grid[i-3][j];
				}
			}
			//down and right
			if(i < 17 && j < 17){
				if(grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3] > max){
					max = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
				}
			}
			//up and left
			if(i > 2){
				if(grid[i][j] * grid[i-1][j-1] * grid[i-2][j-2] * grid[i-3][j-3] > max){
					max = grid[i][j] * grid[i-1][j-1] * grid[i-2][j-2] * grid[i-3][j-3];
				}
			}
			//down and left
			if(i < 17){
				if(grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3] > max){
					max = grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3];
				}
			}
			//up and right
			if(i > 2){
				if(grid[i][j] * grid[i-1][j+1] * grid[i-2][j+2] * grid[i-3][j+3] > max){
					max = grid[i][j] * grid[i-1][j+1] * grid[i-2][j+2] * grid[i-3][j+3];
				}
			}
		}
	}

	cout << max << endl;
}

int numDivisors(int x){
	int total = 0;
	for(int i = 1; i <= sqrt(x); i++){
		if(x % i == 0){
			total += 2;
		}
	}
	return total;
}

void triNumber(){
	bool div = false;
	int sum = 0;
	int i = 1;
	while(!div){
		sum += i;
		i++;
		cout << sum << " has " << numDivisors(sum) << " divisors" << endl;
		if(numDivisors(sum) > 500){
			div = true;
		}
	}
	cout << sum << endl;
}

int collatzSequence(long x){
	int count = 1;
	while(x != 1){
		if(x % 2 == 0){
			x = x/2;
		}
		else{
			x = 3*x + 1;
		}
		count++;
	}
	return count;
}

void highestCollatz(){
	int max_count = 0;
	int max = 0;
	for(long i = 1; i <= 1000000; i++){
		cout << i << " " << max_count << endl;
		int temp = collatzSequence(i);
		if(temp > max_count){
			max_count = temp;
			max = i;
		}
	}
	cout << max << endl;
}

int numPaths(int x, int y){

	if(x == 0 && y == 0){
		return 1;
	}
	else if(x > 0 && y > 0){
		return numPaths(x-1, y) + numPaths(x, y-1);
	}
	else if((x > 0 && y == 0) || (x == 0 && y > 0)){
		return 1;
	}
}

void powerDigits(){
	long two_exp = 1;
	for(int i = 0; i < 1000; i++){
		two_exp = two_exp * 2;
		cout << two_exp << endl;
	}
	cout << two_exp << endl;
	vector<int> digits;
	get_each_digit(two_exp, digits);
	int sum = 0;
	for(int i = 0; i < digits.size(); i++){
		sum += digits[i];
	}
	cout << sum << endl;
}

int sum(vector<int> vec){
	int sum = 0;
	for(int i = 0; i < vec.size(); i++){
		sum += vec[i];
	}
	return sum;
}

//How many number of x digits have a digit sum of y
int digitSum(int x, int y){
	int count = 0;
	int max = 1;
	for(int i = 0; i < x; i++){
		max *= 10;
	}

	for(int i = 0; i < max; i++){
		vector<int> digits;
		get_each_digit(i, digits);
		if(sum(digits) == y){
			count++;
		}
	}
	return count;
}

int main(){
	//largestPalindrome();
	//largestProdInSeries();
	//pythagTriplet();
	//primeSum();
	//gridProduct();
	//triNumber();
	//highestCollatz();
	//latticePaths();
	//powerDigits();
	cout << digitSum(6, 27) << endl;

	return 0;
}
