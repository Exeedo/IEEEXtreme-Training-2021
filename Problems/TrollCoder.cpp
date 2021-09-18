// Problem link: https://csacademy.com/ieeextreme-practice/task/troll-coder/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

const int N=100;
int n,x,idx,last;
bool a[N];

void question(){
    printf("Q ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    cout.flush();
}

void answer(){
    printf("A ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    cout.flush();
    exit(0);
}

int main() {
    cin >> n;
    memset(a,0,sizeof(a));
    question();
    cin >> x;
    if(x==n) answer();
    last=x;
    idx=0;
    while(idx<n){
        if(x<=last && idx>0){
            a[idx-1]=!a[idx-1];
        }
        a[idx]=!a[idx];
        question();
        idx++;
        last=x;
        cin >> x;
        if(x==n) answer();
    }
    return 0;
}
