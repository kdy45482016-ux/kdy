#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int arr[10];

    for(int &i : arr) cin >> i;

    sort(arr, arr + 10);

    for(int i : arr) cout << i + 1 << " ";

    return 0;
}