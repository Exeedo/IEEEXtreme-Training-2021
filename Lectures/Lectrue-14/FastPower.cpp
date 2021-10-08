#include <iostream>
using namespace std;

int fast_power_recursive(int x, int y, int m) { // Calculate (x ^ y) % m
	if (y == 0) {
		return 1;
	}
	int p = fast_power_recursive(x, y/2, m); // half the exponent
	int ans = (p * p) % m;
	if (y%2 == 1){ // if exponent is odd
		ans = (ans * x) % m;
	}
	return ans;
}

int fast_power_loop(int x, int y, int m) { // Calculate (x ^ y) % m
	int k = 1;
	int p = x;	// x ^ k where k is a power of 2 (1, 2, 4, 8, ...)
	int ans = 1;
	while (y > 0) {
		if (y%2 == 1) {
			ans = (ans * p) % m;
		}
		k++;
		p = (p * p) % m;
		y /= 2;
	}
	return ans;
}

int main(){
	int x, y, m;
	x = 5;
	y = 15;
	m = 10000;
	cout << "(x ^ y) % m = " << fast_power_recursive(x, y, m) << " ; using fast power (recursive)" << endl;
	cout << "(x ^ y) % m = " << fast_power_loop(x, y, m) << " ; using fast power (loop)" << endl;
	return 0;
}
