#include <iostream>
#include <vector>

using namespace std;

int size_y, size_x;
vector< vector <int>> arr;  // 
int cnt = 0, ans;

int func(int y, int x){ // 공기 전파, return : 한시간 뒤에 녹는 치즈 개수

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> size_y >> size_x;

    arr.resize(size_y);
    for(auto &a : arr){
        a.resize(size_x);
        for(auto &b : a) cin >> b;
    }

    while(true){
        cnt++;

    }

    cout << cnt << "\n";
}