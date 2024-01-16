#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    freopen("whatbase.in", "r", stdin);
    freopen("whatbase.out", "w", stdout);
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int digit1, digit2;
        cin >> digit1 >> digit2;
        long long a = digit1 / 100, b = (digit1 / 10) % 10, c = digit1 % 10;
        long long d = digit2 / 100, e = (digit2 / 10) % 10, f = digit2 % 10;
        for (long long Y = 10; Y <= 15000; Y++) {
            long long s = b*b - 4*a*(c - d*Y*Y - e*Y - f);
            if (s < 0)
                continue;
            double sq = sqrt(s);
            if (sq != (long long) sq)
                continue;
            long long int_sq = sq;
            long long X1 = (- b + int_sq) / (2*a);
            if (X1 > 0 && ((-b + int_sq) % (2*a)) == 0 && X1 >= 10) {
                cout << X1 << " " << Y << endl;
                break;
            }
            long long X2 = (- b - int_sq) / (2*a);
            if (X2 > 0 && ((-b - int_sq) % (2*a)) == 0 && X2 >= 10) {
                cout << X2 << " " << Y << endl;
                break;
            }
        }
    }
}