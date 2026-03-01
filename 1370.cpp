#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meet{
    int n, s, e;
    bool operator<(const meet &r) const{
        if(e != r.e) return e < r.e;
        return s < r.s;
    }
};

int n;
vector <meet> arr;

int cnt;
vector <meet> ans;

void Input(){
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].n >> arr[i].s >> arr[i].e;
    }
}

void Solve(){
    sort(arr.begin(), arr.end());
    cnt = 1;
    ans.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        if(ans[cnt - 1].e > arr[i].s) continue;
        ans.push_back(arr[i]);
        cnt++;
    }
}

void Output(){
    cout << cnt << "\n";
    for(int i = 0; i < cnt; i++){
        cout << ans[i].n << " ";
    }
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