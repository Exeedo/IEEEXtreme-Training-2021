// Problem link: https://csacademy.com/ieeextreme-practice/task/product-rectangle/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> A,B;
vector<long long> sumA, sumB;

int main() {
    cin >> n >> m;
    A.resize(n+1);
    sumA.resize(n+1);
    B.resize(m+1);
    sumB.resize(m+1);
    for(int i=1;i<=n;i++){
        cin >> A[i];
        sumA[i] = sumA[i-1] + A[i];
    }
    for(int i=1;i<=m;i++){
        cin >> B[i];
        sumB[i] = sumB[i-1] + B[i];
    }
    
    long long minA, maxA;
    minA = 1e18;
    maxA = -1e18;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            long long range = sumA[j]-sumA[i];
            minA = min(minA, range);
            maxA = max(maxA, range);
        }
    }
    
    long long minB, maxB;
    minB = 1e18;
    maxB = -1e18;
    
    for(int i=0;i<m;i++){
        for(int j=i+1;j<=m;j++){
            long long range = sumB[j]-sumB[i];
            minB = min(minB, range);
            maxB = max(maxB, range);
        }
    }
    
    long long answer = max(max(maxA*maxB, minA*minB),
                            max(maxA*minB, minA*maxB));
    cout << answer;
    return 0;
}
