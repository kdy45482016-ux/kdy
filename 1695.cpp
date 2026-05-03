#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> pos_y = {1, 0, -1, 0};
vector <int> pos_x = {0, 1, 0, -1};

int n;
vector <int> arr;
vector <int> vis;
vector <int> ans;

int dfs(int pos){
    vis[pos] = true;

    int y = pos / n, x = pos % n;
    
    int rs = 1;
    
    for(int i = 0; i < 4; i++){
        int next_y = y + pos_y[i];
        int next_x = x + pos_x[i];
        int next_pos = next_y * n + next_x;

        if(next_y >= n || next_y < 0) continue;
        if(next_x >= n || next_x < 0) continue;
        if(!arr[next_pos] || vis[next_pos]) continue;

        rs += dfs(next_pos);
    }

    return rs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    arr.resize(n * n);
    vis.resize(n * n, 0);
    
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < n; j++) arr[i * n + j] = input[j] - '0';
    }

    for(int i = 0; i < n * n; i++){
        if(arr[i] && !vis[i]) ans.push_back(dfs(i));
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto e : ans) cout << e << "\n";
}