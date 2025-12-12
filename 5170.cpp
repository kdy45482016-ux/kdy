#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <int> arr;

bool chk(int level){
    int cut = 0;
    for(int i = 0; i < n; i++){
        int wood = arr[i] - level;
        if(wood <= 0) break;
        cut += wood;
        if(cut >= m) return true;   // 자른 나무가 충분함
    }
    return false;   // 자른 나무가 부족함
}

int bs(){
    int l = 0, r = arr[0], m = (l + r) / 2;  // 자른 나무는 오른쪽으로 갈수록 적어짐
    while(l <= r){
        chk(m) ? l = m + 1 : r = m - 1;
        m = (l + r) / 2;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end(), greater<>());

    cout << bs() << "\n";
}