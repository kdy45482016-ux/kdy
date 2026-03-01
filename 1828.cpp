#include <iostream>
#include <vector>

using namespace std;

struct Data{
    int s, e;
    Data(int a, int b){
        s = a;
        e = b;
    }
}

int n;
vector <Data> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back(Data(a, b));
    }
}