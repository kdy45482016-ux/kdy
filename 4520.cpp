#include <iostream>
#include <vector>

using namespace std;

int n, k;
string arr;
int cnt = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> arr;

    for(int i = 0; i < n; i++){
        if(arr[i] == 'P'){
            bool temp = false;
            // (i - k) ~ (i + k) 검사
            int start = max(i-k, 0);
            int end = min(i+k, n-1);
            for(int j = start; j <= end; j++){
                if(arr[j] == 'H'){
                    cnt++;
                    arr[j] = 'N';
                    break;
                }
            } 
        }
    }

    cout << cnt << "\n";
}