// Problem link: https://csacademy.com/ieeextreme-practice/task/concentration-game/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

const int N=2005;
int n,card[N];
bool taken[N];
string s;

void send(int a,int b){
    cout << a << ' ' << b << endl;
    cin >> s;
    if(s[0]=='M'){
        taken[a]=1;
        taken[b]=1;
    }
    else{
        int x=stoi(s);
        int y; cin>>y;
        if(card[x]) send(card[x],a);
        else card[x]=a;
        if(card[y]) send(card[y],b);
        else card[y]=b;
    }
}

int main() {
    cin >> n;
    n<<=1;
    for(int i=0,j=0;j<n;){
        i=j+1;
        while(taken[i]) i++;
        j=i+1;
        while(taken[j]) j++;
        send(i,j);
    }
    cout << -1;
    return 0;
}
