// Problem link: https://csacademy.com/ieeextreme-practice/task/hotel-wiring/
// By: Osama Khallouf

#include <iostream>
#include <algorithm>
using namespace std;

int t, m, n, k;
vector<int> v;

int main() {
    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        v.resize(m);
        for(int i = 0; i < m; i++)
            cin >> v[i];
        
        sort(v.begin(),v.end());
        long long answer = 0;
        for(int i = 0; i < m; i++) {
            if (i<k) {
                answer += n - v[i];
            }
            else {
                answer += v[i];
            }
        }
        cout << answer << endl;
    }
	return 0;
}

