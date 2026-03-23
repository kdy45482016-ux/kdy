#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Flower{
    int sm, sd;
    int em, ed;

    Flower(int a, int b, int c, int d){
        if(c == 12) d = 1; // 12월 -> 12월 1일

        sm = a;
        sd = b;
        em = c;
        ed = d;
    }

    bool operator<(const Flower &r) const{  // e 기준 내림차순 -> s 기준 내림차순 정렬
        if(em != r.em) return em > r.em;
        if(ed != r.ed) return ed > r.ed;
        if(sm != r.sm) return sm > r.sm;
        return sd > r.sd;
    }
};

bool IsOverlap(Flower last, Flower current){ // 꽃이 피어 있는 시기가 서로 겹치는지 확인
    // (last e + 1일) 보다 (current s) 가 작으면 true 반환
    if(last.em > current.sm) return true;
    else if(last.em == current.sm){  // 월이 같음
        if(last.ed >= current.sd) return true;
        else return false;
    }
    else if(last.em < current.sm) return false;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector <Flower> arr;

    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr.push_back(Flower(a, b, c, d));
    }

    sort(arr.begin(), arr.end());

    Flower lastFlower = Flower(0, 0, 3, 1);
    int lastIndex = n;
    int cnt = 0;

    while(lastFlower.em != 12){
        cnt++;
        bool isOverlap = false;

        for(int i = 0; i < lastIndex; i++){ // 이전에 선택한 꽃 이전까지 반복
            if(IsOverlap(lastFlower, arr[i])){  // 겹치는가?
                isOverlap = true;
                lastFlower = arr[i];
                lastIndex = i;

                break;
            }
        }

        if(!isOverlap){ // 선택하지 못한 경우
            cnt = 0;
            break;
        }
    }

    cout << cnt << "\n";
}