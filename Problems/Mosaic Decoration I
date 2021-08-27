// Problem link: https://csacademy.com/ieeextreme-practice/task/mosaic1/
// By: Osama Khallouf

#include <iostream>
using namespace std;

int main() {
    int n, cb, cp;
    cin >> n >> cb >> cp;
    
    int black = 0, pink = 0;
    for(int i=0;i<n;i++){
        int b,p;
        cin >> b >> p;
        black += b;
        pink += p;
    }
    
    black = (black + 9) / 10;
    pink = (pink + 9) / 10;
    
    int answer = black * cb + pink * cp;
    cout << answer;
	return 0;
}

