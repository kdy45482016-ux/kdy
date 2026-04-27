#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<bool> vis;
vector<int> ans;

void func(int idx, int start_value){
    if(vis[idx]) return;
    
    vis[idx] = true;

    if(start_value == arr[idx]) ans.push_back(start_value);
    else func(arr[idx], start_value);

    vis[idx] = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i]--;
    }

    vis.resize(n, false);

    for(int i = 0; i < n; i++) func(arr[i], i);

    cout << ans.size() << "\n";
    for(auto e : ans) cout << e + 1 << "\n";
}