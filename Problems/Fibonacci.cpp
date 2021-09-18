// Problem link: https://csacademy.com/ieeextreme-practice/task/09f92a575cc006d4a6a7f525f370ec30/
// By: Osama Khallouf

#include <iostream>
using namespace std;

int fib[60];

int main() {
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < 60; i++){
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] %= 10;
    }
    
    int t , m;
    cin >> t;
    while(t--) {
        cin >> m;
        cout << fib[m % 60] << endl;
    }
    return 0;
}
