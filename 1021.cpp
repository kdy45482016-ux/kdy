#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <vector <pair <int, int>>> part_arr;
vector <int> cnt_arr;

void func(int part, int num){
    if(part_arr[part].size() == 0){
        cnt_arr[part] += num;
        return;
    }

    for(auto e : part_arr[part]){
        func(e.first, e.second * num);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    part_arr.resize(n + 1);
    cnt_arr.resize(n + 1, 0);
    
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        part_arr[a].push_back(make_pair(b, c));
    }

    func(n, 1);

    for(int i = 0; i < n; i++){
        if(cnt_arr[i] != 0) cout << i << " " << cnt_arr[i] << "\n";
    }
}