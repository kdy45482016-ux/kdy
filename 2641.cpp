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

    for(auto &el : arr){
        //el.Print();
        int m = el.n;
        
        for(int i = el.s; i < el.e; i++){
            m = min(m, cap[i]);
            //cout << "\ni : " << i << "\n";
            //cout << "m : " << m << "\n\n";
        }

        for(int i = el.s; i < el.e; i++){
            cap[i] -= m;
            //cout << "\ni : " << i << "\n";
            //cout << "cap : " << cap[i] << "\n\n";
        }

        sum += m;
        //cout << "\nsum : " << sum << "\n\n";
    }

    cout << sum << "\n";
}