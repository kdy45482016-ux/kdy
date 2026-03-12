#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data{
    int s, e;
    Data(int a, int b){
        s = a;
        e = b;
    }
    bool operator<(const Data &r) const{
        if(s != r.s) return s < r.s;
        return e < r.e;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector <Data> arr;

    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back(Data(a, b));
    }

    sort(arr.begin(), arr.end());

    int cnt = 1;
    Data f = arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i].s > f.e){
            cnt++;
            f = arr[i];
        }
        else{
            f.s = arr[i].s;
            f.e = min(f.e, arr[i].e);
        }
    }

    cout << cnt << "\n";
}