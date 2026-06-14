#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;

    while(true) {
        cin >> a >> b;
        if(a < 2 || a > 9 || b < 2 || b > 9) cout << "INPUT ERROR!\n";
        else break;
    }


    int val = (a < b ? 1 : -1);

    int i = a;
    while(i != b + val) {
        for(int j = 1; j <= 9; j++) {
            cout << i << " * " << j << " = " << i * j << "\n";
        }
        cout << "\n";
        i += val;
    }
}