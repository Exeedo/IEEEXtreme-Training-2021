#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v1 = { 5,3,7,-4,2,0,-1,4,6,1 };
vector<int> v2 = v1;

void merge_sort(vector<int> &v) {
	int n = v.size();
	if (n == 1)
		return;

	vector<int> a, b;
	for (int i = 0; i < n / 2; i++) {
		a.push_back(v[i]);
	}
	for (int i = n / 2; i < n; i++) {
		b.push_back(v[i]);
	}
	merge_sort(a);
	merge_sort(b);

	v.clear();

	// merging a and b into v
	int i = 0, j = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i] < b[j]) {
			v.push_back(a[i]);
			i++;
		}
		else {
			v.push_back(b[j]);
			j++;
		}
	}
	if (i != a.size()) {
		for (; i < a.size(); i++) {
			v.push_back(a[i]);
		}
	}
	if (j != b.size()) {
		for (; j < b.size(); j++) {
			v.push_back(b[j]);
		}
	}
}


int main() {
	sort(v1.begin(), v1.end());
	merge_sort(v2); // sorting v2
	cout << "Elements of v1 sorted :" << endl;
	for (int x : v1) {
		cout << x << ' ';
	}
	cout << endl;

	cout << "Elements of v2 sorted :" << endl;
	for (int x : v2) {
		cout << x << ' ';
	}
	cout << endl;
}
