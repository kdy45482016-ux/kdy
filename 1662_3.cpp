#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<int>& arr, vector<int>& dia_a, vector<int>& dia_b, int n, int start){
    int rs = 0;

    for(int i = start; i < arr.size(); i++){
        int dia_a_idx = (arr[i] / n) + (arr[i] % n);
        int dia_b_idx = n - (arr[i] % n) + (arr[i] / n) - 1;

        if(dia_a[dia_a_idx] || dia_b[dia_b_idx]) continue;

        dia_a[dia_a_idx] = true;
        dia_b[dia_b_idx] = true;

        rs = max(rs, 1 + dfs(arr, dia_a, dia_b, n, i + 1));

        dia_a[dia_a_idx] = false;
        dia_b[dia_b_idx] = false;
    }

    return rs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<int> w_can_put, b_can_put;
    vector<int> dia_a, dia_b;

    cin >> n;

    for(int i = 0; i < n * n; i++){
        int input;
        cin >> input;
        if(!input) continue;
        ((i / n) + (i % n)) % 2 == 0 ? w_can_put.push_back(i) : b_can_put.push_back(i);
    }

    dia_a.resize(n * 2);
    dia_b.resize(n * 2);

    int w_max = dfs(w_can_put, dia_a, dia_b, n, 0);
    int b_max = dfs(b_can_put, dia_a, dia_b, n, 0);

    cout << w_max + b_max << "\n";
}