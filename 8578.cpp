#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
vector <int> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int min1 = 2147483647;
    for(int i = 1; i < n; i++){
        int temp = abs(arr[i] - arr[i-1]);
        if(temp < min1) min1 = temp;
    }

    cout << min1 << "\n";
}