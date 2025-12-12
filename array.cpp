#include <cstdio>
#include <algorithm>
#include <array>

using namespace std;

array<int, 5> arr[100005];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d", &arr[i][j]);
            if(j == 1 || j == 3) arr[i][j] *= -1;
        }
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ", arr[i][j] * (j == 1 || j == 3 ? -1 : 1));
        }
        printf("\n");
    }

    return 0;
}