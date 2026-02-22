#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, p;
vector <int> arr;
vector <int> ans;

int Input(){
    cin >> n >> p;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

int Solve(){
    ans.resize(n);
    for(int i = 0; i < n; i++){

    }
}

int Output(){
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
    Output();
}