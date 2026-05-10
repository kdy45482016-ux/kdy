#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> bw, fw;
vector<int> vis;
int index;
int cnt = 0;

void func(int pos, vector<vector<int>> &arr){
    vis[pos] = index;

    for(auto a : arr[pos]){
        if(vis[a] == index) continue;
        func(a, arr);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    bw.resize(n + 1);
    fw.resize(n + 1);
    vis.resize(n + 1);

    for(int i = 0 ; i < m; i++){
        int a, b;
        cin >> a >> b;
        fw[a].push_back(b);
        bw[b].push_back(a);
    }

    for(index = 1; index <= n; index++){
        vis[index] = index;
        for(auto a : bw[index]) if(vis[a] != index) func(a, bw);
        for(auto a : fw[index]) if(vis[a] != index) func(a, fw); 
        int is_all_visited = 1;
        for(int i = 1; i <= n; i++){
            if(vis[i] != index){
                is_all_visited = 0;
                break;
            }
        }
        cnt += is_all_visited;
    }

    cout << cnt << "\n";
}