#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MIN = 1000;
const int MAX = 9999;

int s, e;
vector<int> primes;
queue<pair<int, int>> q; // pos, cnt
vector<int> vis;
int cnt = 0;
 
vector<int> get_primes(int mi, int ma) {
    vector<int> arr;
    vector<int> sieve(ma + 1, true);

    sieve[0] = false;
    sieve[1] = false;

    for(int i = 2; i <= ma; i++) {
        if(!sieve[i]) continue;
        for(int j = i * i; j <= ma; j += i) sieve[j] = false;
    }

    for(int i = mi; i <= ma; i++) if(sieve[i]) arr.push_back(i);

    return arr;
}

bool is_way(int a, int b) {
    int cnt = 0;

    while(a > 1 && b > 1) {
        if(a % 10 != b % 10 && cnt++) return false;
    
        a /= 10;
        b /= 10;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> e;

    if(s == e) {
        cout << 0 << "\n";
        return 0;
    }

    primes = get_primes(MIN, MAX);
    vis.resize(MAX + 1, false);

    vis[s] = true;
    q.push({s, 0});
    
    while(!q.empty()) {
        int num = q.front().first; cout << num << "\n";
        cnt = q.front().second;
        q.pop();

        for(auto prime : primes) {
            if(vis[prime]) continue;
            if(!is_way(num, prime)) continue;

            vis[prime] = true;
            q.push({prime, cnt + 1});

            if(prime == e) {
                cout << cnt + 1 << "\n";
                return 0;
            }
        }
    }
}