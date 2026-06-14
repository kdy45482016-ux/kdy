#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int y, x;
    Pos() {}
    Pos(int a, int b) { y = a; x = b; }
};

struct Bus { // 수직/수평 이동만 가능
    Pos src, dst;
    Bus() {}
    Bus(Pos a, Pos b) {
        if (a.y > b.y || a.x > b.x) { src = b; dst = a; }
        else { src = a; dst = b; }
    }
};

Pos s;
int k;
vector<Bus> bus_arr; // [k] : src, [k + 1] : dst
vector<vector<int>> tf_arr; // [k] : src, [k + 1] : dst
queue<pair<int, int>> q; // 버스 번호(index), cnt 저장, 0 ~ k - 1 : 일반 버스, k : src, k + 1 : dst
vector<int> vis;
bool is_find_ans = false;
int ans = 0;

bool can_tf(const Bus& a, const Bus& b) {
    int asy = a.src.y, asx = a.src.x;
    int ady = a.dst.y, adx = a.dst.x;
    int bsy = b.src.y, bsx = b.src.x;
    int bdy = b.dst.y, bdx = b.dst.x;

    bool ay = asy == ady;
    bool by = bsy == bdy;

    if (ay && by) { // 두 선분이 x축에 평행 (서로 평행)
        return asy == bsy && max(asx, bsx) <= min(adx, bdx);
        // true : y값이 같고 a b b a 또는 a b a b 또는 b a a b 또는 b a b a
        // false : y값이 다르거나 a a b b 또는 b b a a
    }
    if (!ay && !by) { // 두 선분이 y축에 평행 (서로 평행)
        return asx == bsx && max(asy, bsy) <= min(ady, bdy);
        // true : x값이 같고 a b b a 또는 a b a b 또는 b a a b 또는 b a b a
        // false : x값이 다르거나 a a b b 또는 b b a a
    }
    if (ay && !by) { // a가 x축, b가 y축에 평행 (서로 수직)
        return bsx >= asx && bsx <= adx && asy >= bsy && asy <= bdy;
        // true : asx ~ adx 안에 bsx(bdx)가 있고 bsy ~ bdy 안에 asy(ady)가 있음
        // false : asx ~ adx 안에 bsx(bdx)가 없거나 bsy ~ bdy 안에 asy(ady)가 없음
    }
    if (!ay && by) { // a가 y축, b가 x축에 평행 (서로 수직)
        return bsy >= asy && bsy <= ady && asx >= bsx && asx <= bdx;
        // true : asy ~ ady 안에 bsy(bdy)가 있고 bsx ~ bdx 안에 asx(adx)가 있음
        // false : asy ~ ady 안에 bsy(bdy)가 없거나 bsx ~ bdx 안에 asx(adx)가 없음
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s.x >> s.y;
    cin >> k;

    bus_arr.resize(k + 2);
    for (int i = 0; i < k; i++) {
        int temp;
        Pos src, dst;
        cin >> temp >> src.x >> src.y >> dst.x >> dst.y;
        bus_arr[i] = Bus(src, dst);
    }

    Pos src, dst;
    cin >> src.x >> src.y >> dst.x >> dst.y;
    bus_arr[k] = Bus(src, src);
    bus_arr[k + 1] = Bus(dst, dst);

    tf_arr.resize(k + 2);
    for (int i = 0; i < k + 2; i++) {
        for (int j = i + 1; j < k + 2; j++) {
            if (!can_tf(bus_arr[i], bus_arr[j])) continue;
            tf_arr[i].push_back(j);
            tf_arr[j].push_back(i);
        }
    }

    vis.resize(k + 2, false);

    q.push({ k, 0 });
    vis[k] = true;

    while (!q.empty() && !is_find_ans) {
        pair<int, int> node = q.front();
        q.pop();

        int cur = node.first;
        int cnt = node.second;

        for (int nxt : tf_arr[cur]) {
            if (vis[nxt]) continue;
            if (nxt == k + 1) {
                ans = cnt; // dst는 cnt + 1이 필요없음
                is_find_ans = true;
                break;
            }
            vis[nxt] = true;
            q.push({ nxt, cnt + 1 });
        }
    }

    cout << ans << "\n";
}