#include <iostream>
#include <vector>

using namespace std;

int n, m, max1 = 0, sum = 0;
vector <int> arr;

bool check(int num)
{
    int size = 0, cnt = 1;

    for(auto a : arr){
        size += a;
        if(size > num){
            size = a;
            cnt++;
        } 
    }

    return cnt <= m;
}

int search()
{
    int start = max1;
    int end = sum;

    while(start <= end){
        int mid = (start + end) / 2;
        if(check(mid)) end = mid - 1;
        else start = mid + 1;
    }

    return start;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(n);
    for(auto &a : arr){
        cin >> a;
        if(a > max1) max1 = a;
        sum += a;
    } 

    cout << search() << "\n";
}