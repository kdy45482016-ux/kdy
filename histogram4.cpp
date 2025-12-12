#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    stack <pair <int, int>> s;  // stack(index, value)
    vector <int> size(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];

        while(!s.empty()){
            auto val = s.top();
            if(val.second > arr[i]) s.pop();
            else break;
            size[val.first] = i - val.first;
            if(!s.empty()) size[val.first] += val.first - s.top().first - 1;
            //cout << val.first << " : " << val.second << " : " << size[val.first] << endl;
        }
        s.push(make_pair(i, arr[i]));
    }

    while(!s.empty()){
        auto val = s.top();
        s.pop();
        size[val.first] = n - val.first;
        if(!s.empty()) size[val.first] += val.first - s.top().first - 1;
        else size[val.first] += val.first;
        //cout << val.first << " : " << val.second << " : " << size[val.first] << endl;
    }

    long long max = 0;

    for(int i = 0; i < n; i++){
        long long num = arr[i] * size[i];
        if(max < num) max = num;
    }

    cout << max << endl;

    return 0;
}

// 8 4 7 6 8 5 9 1 24