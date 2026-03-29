#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <int> ans;

void DFS(int depth){
    if(depth == m){
        for(auto e : ans) cout << e + 1 << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++){
        ans.push_back(i);
        DFS(depth + 1);
        ans.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    DFS(0);
}