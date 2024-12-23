#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long modPow(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int maxNiceDivisors(int primeFactors) {
    if (primeFactors == 1) return 1;

    int a = primeFactors / 3;
    int b = primeFactors % 3;

    if (b == 0) {
        return modPow(3, a, MOD);
    } else if (b == 1) {
        return (modPow(3, a - 1, MOD) * 4) % MOD;
    } else { // b == 2
        return (modPow(3, a, MOD) * 2) % MOD;
    }
}

int main() {
    int primeFactors;
    cout << "Enter the number of prime factors: ";
    cin >> primeFactors;

    cout << "The number of nice divisors is: " << maxNiceDivisors(primeFactors) << endl;

    return 0;
}