#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int size = 5;

vector <int> arr(5);
int weight;

int cnt = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(auto &a : arr) cin >> a;
    cin >> weight;

    for(int i = size - 1; i >= 0; i--){
        while(weight > pow(2, i) && arr[i] != 0){
            weight -= pow(2, i);
            arr[i]--;
            cnt++;
        }
    }

    if(weight == 0) cout << cnt << "\n";
    else cout << "impossible" << "\n";
}