// Problem link: https://csacademy.com/ieeextreme-practice/task/9ca8fafd184f553a903734761546a224
// By: Osama Khallouf

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long a,b;
        cin >> a >> b;
        int answer = 0;
        while(a != b){
            if(a > b){
                a = a / 2;
            }
            else{
                b = b / 2;
            }
            answer++;
        }
        cout << answer << endl;
    }
    return 0;
}
