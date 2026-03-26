#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt = 0;
string arr = "";   // pos : y * n + x

vector <int> ans;

bool CanRook(int pos){  // 배치 가능한지 확인, pos : y * n + x
    if(arr[pos] == '#') return false;

    for(auto e : ans){  // 이전에 배치한 룩의 위치
        if((pos/n == e/n) || (pos%n == e%n)) return false;  // y or x 같음
    }
    return true;
}

void DFS(int depth, int pos){
    if(depth == n){
        cnt++;
        return;
    }

    for(int i = pos; i < n * n; i++){
        if(CanRook(i)){
            ans.push_back(i);
            DFS(depth + 1, i + n - (i % n));
        }
        else continue;

        ans.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        arr += input;
    }

    DFS(0, 0);

    cout << cnt;
}