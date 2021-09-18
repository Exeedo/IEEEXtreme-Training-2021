#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int n;
vector<int> numbers;

int dp[1000];
int next_idx[1000];

int LIS(int idx) {
	if (idx == n)
		return {};
	if (dp[idx] != -1)
		return dp[idx];

	// vector<int> ans = { numbers[idx] };
	int ans = 1; // numbers[idx]
	next_idx[idx] = -1;

	for (int i = idx + 1; i < n; i++) {
		if (numbers[i] > numbers[idx]) {
			int next_LIS = LIS(i);
			if (1 + next_LIS > ans) {
				ans = 1 + next_LIS;
				next_idx[idx] = i;
			}
		}
	}
	return dp[idx] = ans;
}


int main() {
	FILE* in_file, * out_file;
	freopen_s(&in_file, "LIS_input.txt", "r", stdin);
	freopen_s(&out_file, "LIS_output.txt", "w", stdout);

	cin >> n;
	numbers.resize(n);
	for (int& i : numbers)
		cin >> i;

	memset(dp, -1, sizeof(dp));

	int ans = 0;
	int start_idx = -1;
	for (int i = 0; i < n; i++) {
		int x = LIS(i);
		if (x > ans) {
			ans = x;
			start_idx = i;
		}
	}
	cout << ans << endl;
	while (start_idx != -1) {
		cout << numbers[start_idx] << ',';
		start_idx = next_idx[start_idx];
	}
}
