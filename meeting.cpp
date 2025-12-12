#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct Data{
    int i, s, e, len;
} a;

bool comp1(a l, a r)
{
    if(l.len != r.len) return l.len < r.len;
    return l.s < r.s;
}

bool comp2(a l, a r)
{
    if(l.s != r.s) return l.s < r.s;
    return l.len < l.len;
}

int main()
{
    int n;
    scanf("%d", &n);

    a arr[n];
    for(int i = 0; i < n; i++){
        arr[i].i = i + 1;
        scanf("%d %d", &arr[i].s, &arr[i].e);
        arr[i].len = arr[i].e - arr[i].s;
    }

    sort(arr, arr + n, comp2);
    sort(arr, arr + n, comp1);

    for(int i = 0; i < n; i++) printf("%d\n", arr[i].i);

    return 0;
}