#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data{
    int s, e, n;
    Data(int a, int b, int c){
        s = a;
        e = b;
        n = c;
    }
    void Print(){
        cout << "\n";
        cout << s << " ";
        cout << e << " ";
        cout << n << " ";
        cout << "\n";
    }
    bool operator<(const Data &r) const{
        if(e != r.e) return e < r.e;
        return s < r.s;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C, M;
    vector <Data> arr;

    cin >> N >> C >> M;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back(Data(a, b, c));
    }

    sort(arr.begin(), arr.end());

    vector <int> cap(N + 1, C);
    int sum = 0;

    for(auto e : arr){
        int m = min(e.n, C);

        for(int i = e.s; i < e.e; i++){
            m = min(m, cap[i]);
        }

        for(int i = e.s; i < e.e; i++){
            cap[i] -= m;
        }

        sum += m;
    }

    cout << sum << "\n";
}