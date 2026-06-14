#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int y, x;
    Pos() {}
    Pos(int a, int b) {y = a; x = b;}
    const Pos operator+(const Pos& a) const {return {y + a.y, x + a.x};}
};

struct Bus {
    int code;
    Pos src, dst;
    char move;
    Bus() {}
    Bus(int a, Pos b, Pos c, char d) {code = a; src = b; dst = c; move = d;}
};

Pos s;
int k;
vector<Bus> bus_arr;
Pos src, dst;

vector<vector<vector<int>>> bus_map;
vector<int> bus_vis;
queue<pair<Pos, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s.x >> s.y;
    cin >> k;

    bus_arr.resize(k + 1);
    bus_map.resize(s.y);
    bus_vis.resize(k + 1);

    for(int i = 0; i < s.y; i++) {
        bus_map[i].resize(s.x);
    } 

    for(int i = 0; i < k; i++) {
        int n, x1, y1, x2, y2;

        cin >> n;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        x1--; y1--;
        x2--; y2--;

        char m = x1 != x2 ? 'x' : 'y';

        bus_arr[n] = Bus(n, {y1, x1}, {y2, x2}, m);

        if(m == 'x') {
            int mn = min(x1, x2);
            int mx = max(x1, x2);
            int y = y1;

            for(int x = mn; x <= mx; x++) {
                bus_map[y][x].push_back(n);
            }
        }
        else {
            int mn = min(y1, y2);
            int mx = max(y1, y2);
            int x = x1;

            for(int y = mn; y <= mx; y++) {
                bus_map[y][x].push_back(n);
            }
        }
    }
    
    cin >> src.x >> src.y;
    cin >> dst.x >> dst.y;

    src.y--; src.x--;
    dst.y--; dst.x--;

    q.push({src, 0});

    while(!q.empty()) {
        pair<Pos, int> node = q.front();
        q.pop();

        Pos pos = node.first;
        int cnt = node.second;

        if(pos.y == dst.y && pos.x == dst.x) {
            cout << cnt << "\n";
            return 0;
        }

        for(int bus_code : bus_map[pos.y][pos.x]) {
            if(bus_vis[bus_code]) continue;
            
            Bus bus = bus_arr[bus_code];
            
            if(bus.move == 'x') {
                int mn = min(bus.src.x, bus.dst.x);
                int mx = max(bus.src.x, bus.dst.x);
                int y = bus.src.y;

                for(int x = mn; x <= mx; x++) {
                    q.push({{y, x}, cnt + 1});
                }
            }
            else {
                int mn = min(bus.src.y, bus.dst.y);
                int mx = max(bus.src.y, bus.dst.y);
                int x = bus.src.x;

                for(int y = mn; y <= mx; y++) {
                    q.push({{y, x}, cnt + 1});
                }
            }

            bus_vis[bus_code] = true;
        }
    }
}