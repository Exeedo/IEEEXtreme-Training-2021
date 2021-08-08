#include <iostream>
using namespace std;

/* Problem Description:
*
* Find the value of the Cube Root of the input n without
* using any library given that the answer is integer.
*
* Examples: 1728 -> 12, 135'796'744 -> 514
*
*/

int find_cube_root(int x) {
	int hi, lo; // high low
	lo = 0;
	hi = x;
	while (lo <= hi) {
		// cout << hi << ' ' << lo << endl;
		// limits = (lo, hi)
		int md = (lo + hi) / 2;
		int cube = md * md * md;
		if (cube == x) {
			return md;
		}
		if (cube < x) {
			// new limits = (md+1, hi)
			lo = md + 1;
			hi = hi;
		}
		else { // cube > x
			// new limits = (lo, md-1)
			lo = lo;
			hi = md - 1;
		}
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;
	cout << find_cube_root(n) << endl;
}
