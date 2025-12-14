#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector <int> arr;

void print(string name, int value){
    cout << name << " : " << value << "\n";
}

void enter(){
    cout << "\n";
}

bool check(int dist){    // 주어진 거리로 모든 나무를 심을 수 있는가?
    int cnt = 1;
    int last = arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i] - last >= dist){
            cnt++;
            last = arr[i];
        }
    }

    return cnt >= c;
}

int search(){   // 나무 사이의 최대 거리
    int low = 1, high = arr[n-1], mid;
    int ans;

    while(low <= high){
        mid = (low + high) / 2;
        if(check(mid)){
            ans = mid;
            low = mid + 1;
        } 
        else high = mid - 1;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    cout << search();
}