#include <iostream>
using namespace std;

int gcd(int x, int y) {
	// assume x > y
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int lcm(int x, int y) {
	int g = gcd(x, y);
	int ans = x / g;
	return ans * y;
}

int main(){
	int x, y;
	x = 360;
	y = 108;
	int l, g;
	g = gcd(x, y);
	l = lcm(x, y);
	cout << "gcd = " << g << endl;
	cout << "lcm = " << l << endl;
	return 0;
}
