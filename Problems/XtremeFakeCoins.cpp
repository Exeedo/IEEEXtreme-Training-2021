// Problem link: https://csacademy.com/ieeextreme-practice/task/xtreme-fake-coins/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

int compare(string &leftPart, string &rightPart, string &s){
    int a = 0;
    for(int i = 0; i < leftPart.length(); i++) {
        if(leftPart[i] == s[0] || leftPart[i] == s[1])
            a++;
        if(rightPart[i] == s[0] || rightPart[i] == s[1])
            a--;
    }
    if(a > 0) return +1;
    if(a < 0) return -1;
    return 0;
}

bool same(vector<pair<string,string>> &all, string &s1, string &s2){
    int a, b;
    for(int i = 0; i < all.size(); i++){
        a = compare(all[i].first, all[i].second, s1);
        b = compare(all[i].first, all[i].second, s2);
        if(a != b) return false;
    }
    return true;
}

int main() {
    int n,m;
    char ch;
    string s;
    cin >> n >> ch >> m;
    getline(cin, s);
    
    vector<pair<string,string>> all;
    all.resize(m);
    
    for(int i = 0; i < m; i++){
        getline(cin,s);
        auto f = s.find("-",0);
        all[i].first  = s.substr(0 , f);
        all[i].second = s.substr(f + 1);
    }
    
    char last = 'A' + n - 1;
    string s1 = "AA",s2 = "AA";
    for(s1[0] = 'A';     s1[0] <= last; s1[0]++)
        for(s1[1] = s1[0]+1; s1[1] <= last; s1[1]++)
            for(s2[0] = s1[0];   s2[0] <= last; s2[0]++)
                for(s2[1] = s2[0]+1; s2[1] <= last; s2[1]++) {
                    if(s1[0] == s2[0] && s2[1] <= s1[1])
                        continue;
                    if(same(all, s1, s2))
                        cout << s1 << '=' << s2 << endl;
                }
    return 0;
}
