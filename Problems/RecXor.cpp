// Problem link: https://csacademy.com/ieeextreme-practice/task/f8d68dbb0c844910797ce64354c66143/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

long long xorRange(long long a) { // xor for all values from 0 to a
    if(a % 4 == 0){
        return a;
    }
    else if(a % 4 == 1){
        return 1;
    }
    else if(a % 4 == 2){
        return a + 1;
    }
    else { // a % 4 == 3
        return 0;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long l, h;
        cin >> l >> h;
        long long n;
        cin >> n;
        long long d1, d2;
        cin >> d1 >> d2;
        
        long long answer = 0 ;
        answer ^= xorRange(n - 1 + l*h);
        answer ^= xorRange(n - 1);

        long long c1,c2,range;
        c1 = (d1 - n) % l;
        c2 = (d2 - n) % l;
        if(c1>c2){
            d1 -= c1 - c2;
            d2 += c1 - c2;
        }
        range = abs(c1 - c2);
        
        long long i = d1;
        long long j = d1 + range;
        
        while(j <= d2){
            answer ^= xorRange(j);
            answer ^= xorRange(i - 1);
            j += l;
            i += l;
        }
        cout << answer << endl;
    }
    return 0;
}
