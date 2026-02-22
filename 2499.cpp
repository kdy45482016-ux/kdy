#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> arr;
int ans = 1;

void Input(){
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void Solve(){
    sort(arr.begin(), arr.end());

    if(arr[0] != 1) return;

    int sum = arr[0];

    for(int i = 1; i < n; i++){
        if(sum < (arr[i] - 1)) break;
        sum += arr[i];
    }

    ans = sum + 1;
}

void Output(){
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
    Output();
}