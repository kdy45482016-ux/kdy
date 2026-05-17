#include <iostream>
#include <cmath>

using namespace std;

long long n, k;

int main() {
    cin >> n;
    
    k = (-1 + sqrt(1 + 8 * n)) / 2;

    if(k * (k + 1) / 2 < n) k++;

    cout << k << "\n";
}
