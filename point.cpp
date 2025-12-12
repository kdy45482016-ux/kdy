#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    sort(arr, arr + n);

    if(n % 2 == 0){
        int a = arr[n/2-1];
        int b = arr[n/2];

        if(a == b) printf("%d\n", a);
        else printf("%d %d\n", a, b);
    }
    else printf("%d\n", arr[n/2]);

    return 0;
}