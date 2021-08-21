// Problem link: https://csacademy.com/ieeextreme-practice/task/8761fb7efefcf1d890df1d8d91cae241/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> names[251];
    for(int i = 0; i < n; i++){
        int height;
        string name;
        cin >> name >> height;
        names[height].push_back(name);
    }
    
    int m = 1;
    
    for(int height = 120; height <= 250; height++){
        if(names[height].empty()) {
            continue;
        }
        sort(names[height].begin(), names[height].end());
        
        int k = 0;
        for(string name : names[height]) {
            cout << name << ' ';
            k++;
        }
        
        cout << m << ' ' << m + k - 1 << endl;
        m += k;
    }
    return 0;
}
