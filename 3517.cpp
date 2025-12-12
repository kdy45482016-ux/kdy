#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> v;

int BinarySearch(int target){
    int l = 0, r = n - 1;   // l : 첫번쨰 인덱스, r : 마지막 인덱스
    while(l <= r){  // l과 r의 차이가 0일때 l이 1 증가하거나 r이 1 감소하면서 종료 
        int mid = (l + r) / 2;  // l과 r의 중간, 찾는 배열의 중간
        if(target == v[mid]) return mid;    // 찾는 값이 중간값이면 mid(index) 반환
        if(target > v[mid]) l = mid + 1;    // 찾는 값이 중간값보다 크면 l = mid + 1
        else r = mid - 1;   // 찾는 값이 중간값보다 작으면 r = mid - 1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int query;
        cin >> query;
        cout << BinarySearch(query) << " ";
    }
    cout << endl;

    return 0;
}