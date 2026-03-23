#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
int n;
vector <int> arr;

vector <int> ans;

bool CanRook(int pos){  // 배치 가능한지 확인, pos : y * n + x
    //
}

void DFS(int depth){
    if(depth == n){
        cnt++;
        return;
    }

    for(int i = 0; i < n * n; i++){
        //
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.resize(n * n);

    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < n; j++) arr[i * n + j] = (input[j] == '.') ? 0 : 1;
    }

    DFS(0);

    cout << cnt;
}