#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int start_point, end_point;
vector<vector<pair<int, int>>> cave; // first : 도착지, second : 거리
vector<int> vis;
vector<int> ans;
int sum = 0, max_val = 0;

bool func(int pos) {
    if(pos == end_point) return true;

    for(auto a : cave[pos]){
        if(vis[a.first]) continue;

        vis[a.first] = true;
        ans.push_back(a.second);
        
        if(func(a.first)) return true;

        vis[a.first] = false;
        ans.pop_back();
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> start_point >> end_point;

    cave.resize(n + 1);
    vis.resize(n + 1, false);
    
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cave[a].push_back(make_pair(b, c));
        cave[b].push_back(make_pair(a, c));
    }

    vis[start_point] = true;
    func(start_point);

    for(auto a : ans) {
        sum += a;
        max_val = max(max_val, a);
    }

    cout << sum - max_val << "\n";
}