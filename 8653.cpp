#include <iostream>
#include <algorithm>

using namespace std;

typedef long long intl;

bool bs(intl arr[], int start, int size, intl target)
{
    int l = start, r = size, m = (start + size) / 2;

    while(l <= r){
        if(target == arr[m]) return true;
        target < arr[m] ? r = m - 1 : l = m + 1;
        m = (l + r) / 2;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    intl a;
    cin >> n >> q;

    intl arr[n], max = 0;
    int top;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > max){
            max = arr[i];
            top = i;
        }
    }

    sort(arr + top, arr + n);

    for(int i = 0; i < q; i++){
        cin >> a;

        if(a == max){
            cout << "T\n";
            continue;
        }
        else if(bs(arr, 0, top, a)){
            cout << "L\n";
            continue;
        }
        else if(bs(arr, top, n, a)){
            cout << "R\n";
            continue;
        }

        cout << "N\n";
    }

    return 0;
}

/*
binary_search(arr, arr + top, a)
binary_search(arr + top, arr + n, a)
*/