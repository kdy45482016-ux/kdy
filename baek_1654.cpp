#include <iostream>
#include <vector>

using namespace std;

long long k, n, max1 = 0;
vector <long long> arr;

bool check(long long num) // num의 길이로 잘랐을 때의 랜선들의 개수가 n을 넘는가?
{
    long long cnt = 0;
    for(auto a : arr){
        cnt += a / num;
    }
    return cnt >= n;
}

long long search()    // 최대 랜선 길이 반환
{
    long long low = 1;
    long long high = max1;
    long long mid;

    while(low <= high){
        mid = (low + high) / 2;
        check(mid) ? low = mid + 1 : high = mid - 1;
    }

    return high;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n;
    arr.resize(k);
    for(auto &a : arr){
        cin >> a;
        if(a > max1) max1 = a; 
    }

    cout << search();
}