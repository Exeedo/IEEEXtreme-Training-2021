#include <iostream>
using namespace std;

int n;

int factorial_by_loops(int x) { // x! = x * (x-1) * (x-2) * ... * 2 * 1
	int answer = 1;
	for (int i = 1; i <= x; i++) {
		answer *= i;
	}
	return answer;
}

int factorial_by_recursion(int x) {
	int answer = 1;
	if (x == 1)
		return answer;

	answer = x * factorial_by_recursion(x - 1);
	return answer;
}

int main() {
	cin >> n;
	cout << factorial_by_loops(n) << endl;
}

/*
3! = 3 * 2 * 1 = 6
4! = 4 * 3 * 2 * 1 = 24 = 4 * (3!)
n! = n * (n-1) * (n-2) * ... = n * ((n-1)!)
*/
