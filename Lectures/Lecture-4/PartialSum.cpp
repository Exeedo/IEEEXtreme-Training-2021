#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Streaming file "PartialSumInput.txt" to stdin (to read it from cin or scanf)
	FILE* file;
	freopen_s(&file, "PartialSumInput.txt", "r", stdin);
	
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cout << "Elements before:" << endl;
	for (int i = 0; i < n; i++) {
		cout << A[i] << ' ';
	}
	cout << endl;

	vector<int> R(n + 1, 0); // Initialize R with zeros
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r, val;
		cin >> l >> r >> val;
		// Convert indices to 0-based
		l--; r--;

		// Add val to elements from l to r
		R[l] += val;
		R[r + 1] -= val;
	}

	// Converting R to R'
	for (int i = 1; i <= n; i++) {
		R[i] += R[i - 1];
	}

	// Converting A to A'
	for (int i = 0; i < n; i++) {
		A[i] += R[i];
	}

	cout << "Elements after:" << endl;
	for (int i = 0; i < n; i++) {
		cout << A[i] << ' ';
	}
	return 0;
}
