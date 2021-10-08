#include <bits/stdc++.h>
using namespace std;

struct book{
    int t;
    int bitwise_topics;
};

vector<book> books;
map<string, int> number;
int idx = 0;
int desired;

vector<int> fill_topics(string &s){
    int l = s.length();
    string topic = "";
    vector<int> ans;
    for(int i=1;i<l;i++){
        if(s[i]==' '){
            if (!number[topic]){
                number[topic] = ++idx;
            }
            ans.push_back(number[topic]);
            topic ="";
        }
        else{
            topic += s[i];
        }
    }
    if (!number[topic]){
        number[topic] = ++idx;
    }
    ans.push_back(number[topic]);
    return ans;
}
int dp[2][(1<<22)];

int find_bitwise(vector<int> &v){
    int ans = 0;
    for(int x:v){
        ans |= (1<<x);
    }
    return ans;
}

int main() {
    string topics;
    int t;
    while(cin >> t){
        getline(cin, topics);
        book b;
        b.t = t;
        vector<int> v = fill_topics(topics);
        b.bitwise_topics = find_bitwise(v);
        books.push_back(b);
    }
    desired = (1 << (idx + 1)) - 2;
    for(int i=0;i<2;i++){
        for(int tp=0;tp<=desired;tp++){
            dp[i][tp] = 1e9;
        }
    }
    
    dp[0][books[0].bitwise_topics] = books[0].t;
    dp[0][0] = 0;
    for (int i=1;i<books.size(); i++){
        book b = books[i];
        
        // try not to read this book
        for(int tp=0;tp<=desired;tp++){
            dp[i%2][tp] = dp[(i-1)%2][tp];
        }
        
        // try to read this book
        for(int tp=0;tp<=desired;tp++){
            dp[i%2][tp | b.bitwise_topics] = min(dp[i%2][tp | b.bitwise_topics], dp[(i-1)%2][tp] + b.t);
        }
    }
    cout << dp[(books.size()-1)%2][desired] << endl;
}
