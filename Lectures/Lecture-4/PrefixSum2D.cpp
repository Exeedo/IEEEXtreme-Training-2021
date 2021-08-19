#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Streaming file "PrefixSum2DInput.txt" to stdin (to read it from cin or scanf)
	FILE* file;
	freopen_s(&file, "PrefixSum2DInput.txt", "r", stdin);

	int rows, cols;
	cin >> rows >> cols;
	vector< vector<int> > A(rows);
	for (int i = 0; i < rows; i++)
		A[i].resize(cols);

	// Input 2D array
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> A[i][j];
		}
	}

	// Initialize prefix sum array, size rows+1 x cols+1
	vector< vector<int> > R(rows+1);
	for (int i = 0; i <= rows; i++)
		R[i].resize(cols+1);

	// first row and first col are zeros:
	for (int i = 0; i <= rows; i++) {
		R[i][0] = 0;
	}
	for (int i = 0; i <= cols; i++) {
		R[0][i] = 0;
	}


	// Fill prefix sum array:
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			R[i][j] = R[i][j - 1] + R[i - 1][j] - R[i - 1][j - 1]
				+ A[i - 1][j - 1]; // This element is shifted because R is 1-indexed
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int Sr, Sc, Er, Ec; // row and col of positions: S and E
		cin >> Sr >> Sc >> Er >> Ec;
		
		// Get previous index (position D)
		Sr--; Sc--;
		
		// Answering queries
		// Answer = R(E) - R(B) - R(C) + R(D)
		int ans = R[Er][Ec] - R[Er][Sc] - R[Sr][Ec] + R[Sr][Sc];
		cout << ans << endl;
	}
	return 0;
}
