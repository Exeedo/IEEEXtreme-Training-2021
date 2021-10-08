// Problem link: https://csacademy.com/ieeextreme-practice/task/6f960361da7beb7f3a083f4776c2cf79/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int nxt[N][27];

int main() {
	int n, q;
    string s;
	cin >> s >> q;
	n = s.length();
	reverse(s.begin(), s.end());
	memset(nxt, -1, sizeof nxt);
	
	for (int i = 1; i <= n; i++) {
		nxt[i - 1][s[i - 1] - 'a'] = i;
  }
  
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < 27; j++) {
			nxt[i - 1][j] = nxt[i][j];
		}
		nxt[i - 1][s[i - 1] - 'a'] = i;
	}

	while (q--) {
		string p;
		cin >> p;
		int m = p.length();
		reverse(p.begin(), p.end());
		p = p + (char)('a' + 27);
		int i = 0;
		int idx;
		for (idx = 0; idx <= m && i != -1; idx++) {
			i = nxt[i][p[idx] - 'a'];
		}
		cout << idx - 1 << endl;
	}
	return 0;
}
