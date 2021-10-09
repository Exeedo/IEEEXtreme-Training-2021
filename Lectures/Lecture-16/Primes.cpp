#include <iostream>
#include <vector>
using namespace std;

const int N = 1000'000; // enough to test primes up to 10^12
vector<int> primes;
bool composite[N];

bool test_prime(int x) { // O(log(N)) given primes vector
    for (int p : primes) {
        if (p*p > x)
            break;
        if (x % p == 0)
            return false;
    }
    return true;
}

bool test_prime_2(int x) { // O(sqrt(N))
    for (int i = 2; i * i < x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    composite[0] = true;
    composite[1] = true;
    // To find all prime numbers below N:
    for (int i = 2; i * i <= N; i++) { // i = 10
        if (composite[i])
            continue;
        for (int j = i * i; j < N; j += i) { // multiples of i
            composite[j] = true;
        }
        /*
        if (test_prime(i)) {
            primes.push_back(i);
        }
        else {
            composite[i] = true;
        }
        */
    }
    for (int i = 2; i < N; i++) {
        if (!composite[i])
            primes.push_back(i);
    }
    for (int p : primes) {
        cout << p << endl;
    }
}

// Complexity: O(N*log(N))
