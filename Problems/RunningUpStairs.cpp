// Problem link: https://csacademy.com/ieeextreme-practice/task/96c8b1313edd72abf600facb0a14dbab/
// By: Osama Khallouf

// ====================================================================
// THIS CODE IS UN-RECOMMENDED. CHECK THE PYTHON CODE FOR THIS PROBLEM.
// ====================================================================

#include <bits/stdc++.h>
using namespace std;

const long long D = 1e18;

// Creationg of a class to hold big integers as a vector of integers
class v_int{
    public:
        vector<long long> numbers;
        void init(long long x){
            numbers.clear();
            numbers.push_back(x);
        }
        
        // Only the addition operation is needed in this problem
        v_int operator+(v_int &a) {
            v_int ans;
            long long sum, carry = 0;
            int sz = max(a.numbers.size(), numbers.size());
            a.numbers.resize(sz);
            numbers.resize(sz);
            ans.numbers.resize(sz);
            for(int i = 0; i < sz; i++) {
                x = a.numbers[i] + numbers[i] + carry;
                carry = sum / D;
                sum %= D;
                ans.numbers[i] = sum;
            }
            if(carry != 0) {
                ans.numbers.push_back(carry);
            }
            return ans;
        }
        
        void print(){
            reverse(numbers.begin(), numbers.end());
            for(int i = 0; i < numbers.size(); i++) {
                if(i==0) {
                    printf("%018lld", numbers[i]);
                }
                else {
                    printf("%lld", numbers[i]);
                }
            }
            reverse(numbers.begin(), numbers.end());
            puts("");
        }
};


const int N = 22005;
int n, t;
v_int fib[N];

int main() {
    fib[0].init(1);
    fib[1].init(1);
    for(int i = 2; i < N; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    cin >> t;
    while(t--){
        cin >> n;
        fib[n].print();
    }
    return 0;
}
