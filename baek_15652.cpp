#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <int> ans;

void DFS(int depth, int num){
    if(depth == m){
        for(auto e : ans) cout << e + 1 << " ";
        cout << "\n";
        return;
    }

    for(int i = num; i < n; i++){
        ans.push_back(i);
        DFS(depth + 1, i);
        ans.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    DFS(0, 0);
}