#include <iostream>
#include <string>

using namespace std;

int n;
string ans;
bool is_print = false;

bool is_bad(string str){
    if(str.size() % 2 == 1) str = str.substr(1);

    int size = str.size() / 2;
    for(int i = size; i >= 1; i--){ // i : 검사할 문자열의 길이
        string a = str.substr((size - i) * 2, i);
        string b = str.substr(size * 2 - i, i);
        if(a.compare(b) == 0) return true;
    }

    return false;
}

void dfs(int depth){
    if(is_print) return;

    if(depth == n){
        cout << ans << "\n";
        is_print = true;
        return;
    }

    for(char i = '1'; i <= '3'; i++){
        if(is_bad(ans + i)) continue;
        ans.push_back(i);
        dfs(depth + 1);
        ans.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    dfs(0);
}