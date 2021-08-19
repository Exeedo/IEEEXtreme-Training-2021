#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Streaming file "PrefixSum1DInput.txt" to stdin (to read it from cin or scanf)
	FILE* file;
	freopen_s(&file, "PrefixSum1DInput.txt", "r", stdin);
	
	int n;
	vector<int> v;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// Fill prefix sum array:
	vector<int> s;
	s.resize(n+1);
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + v[i-1];
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		// Answering queries
		cin >> l >> r;
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}
