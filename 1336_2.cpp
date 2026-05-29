#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MIN = 1000;
const int MAX = 9999;

vector<int> sieve;
int s, e;
vector<int> vis;
queue<pair<int, int>> q;

void get_prime_sieve(vector<int> & arr, int ma) {
    arr.resize(ma + 1, true);

    arr[0] = false;
    arr[1] = false;

    for(int i = 2; i <= ma; i++) {
        if(!arr[i]) continue;
        for(int j = i * i; j <= ma; j += i) {
            arr[j] = false;
        }
    }
}

vector<int> int_to_vec(int num) {
    vector<int> arr;
    for(int i = 10000; i > 1; i /= 10) arr.push_back(num % i / (i / 10));
    return arr;
}

int vec_to_int(vector<int> arr) {
    int num = 0, i = 1000;
    for(auto a : arr) {
        num += a * i;
        i /= 10;
    }
    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> e;
    if(s == e) {
        cout << 0 << "\n";
        return 0;
    }

    vis.resize(MAX + 1, false);

    get_prime_sieve(sieve, MAX);

    q.push({s, 0});
    vis[s] = true;
    
    while(!q.empty()) {
        int cur_num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        vector<int> arr = int_to_vec(cur_num);
        
        for(int i = 0; i < arr.size(); i++) {
            vector<int> nxt_arr = arr;
            for(int j = 0; j < 10; j++) {
                if(i == 0 && j == 0) continue;
                if(arr[i] == j) continue;
                
                nxt_arr[i] = j;
                int nxt_num = vec_to_int(nxt_arr); // 새 수
                
                if(!sieve[nxt_num]) continue; // 소수 아님
                if(vis[nxt_num]) continue; // 이미 방문함

                if(nxt_num == e) {
                    cout << cnt + 1 << "\n";
                    return 0;
                }

                vis[nxt_num] = true;
                q.push({nxt_num, cnt + 1});
            }
        }
    }
}