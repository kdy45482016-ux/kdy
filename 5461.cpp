#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m;
ll sum, maxVal;
vector <ll> narr;

bool check(ll num){
    ll sumVal = 0;
    int mcnt = 0, temp = true;
    for(int i = 0; i < n; i++){
        if(sumVal + narr[i] > num){
            if(mcnt >= m) temp = false;
            sumVal = 0;
            mcnt++;
        }
        sumVal += narr[i];
    }

    return mcnt <= (m - 1);
}

ll search(){   // 최소값 구하기
    ll l = maxVal, r = sum, mid = (l + r) / 2;
    while(l <= r){
        !check(mid) ? l = mid + 1 : r = mid - 1;
        mid = (l + r) / 2;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    narr.resize(n);

    for(int i = 0; i < n; i++){
        cin >> narr[i];
        sum += narr[i];
        if(narr[i] > maxVal) maxVal = narr[i];
    }

    ll result = search();
    cout << result << "\n";
}