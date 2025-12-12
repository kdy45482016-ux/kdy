#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <int> arr;

bool check(int num)
{
    int remain = m;
    for(auto a : arr){
        remain -= a < num ? a : num;
    }
    return remain >= 0; 
}

int search()
{
    int l = 1, r = arr[0], m = (l + r) / 2;
    while(l <= r){
        check(m) ? l = m + 1 : r = m - 1;
        m = (l + r) / 2;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;

    sort(arr.begin(), arr.end(), greater<>());

    int result = search();
    cout << result << "\n";
}