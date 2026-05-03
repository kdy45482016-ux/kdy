#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> move_y = {1, 0, -1, 0};
vector <int> move_x = {0, 1, 0, -1};

int n, m, k;
vector <vector <int>> sq_arr;
vector <int> arr;
vector <int> ans;

int func(int pos){
    arr[pos] = 1;

    int cnt = 0;

    for(int i = 0; i < 4; i++){
        int new_y = pos / m + move_y[i];
        if(new_y >= n || new_y < 0) continue;
        
        int new_x = pos % m + move_x[i]; 
        if(new_x >= m || new_x < 0) continue;

        int new_pos = new_y * m + new_x;
        if(arr[new_pos]) continue;

        cnt += func(new_pos);
    }

    return cnt + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    sq_arr.resize(k);
    for(auto &a : sq_arr){
        a.resize(4);
        for(auto &b : a) cin >> b;
    }

    arr.resize(n * m);
    for(auto a : sq_arr){
        for(int i = a[1]; i < a[3]; i++){
            for(int j = a[0]; j < a[2]; j++){
                arr[i * m + j] = 1;
            }
        }
    }

    for(int i = 0; i < n * m; i++){
        if(arr[i]) continue;
        ans.push_back(func(i));
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}