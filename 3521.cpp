#include <iostream>
#include <vector>

#define size 5

using namespace std;

vector <int> input(size);
vector <int> value = {1, 2, 4, 8, 16};
int number;
int cnt = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(auto &a : input) cin >> a;
    cin >> number;

    for(int i = size - 1; i >= 0; i--){
        while(number - value[i] >= 0 && input[i] > 0){
            number -= value[i];
            input[i]--;
            cnt++;
        }
    }

    if(number == 0) cout << cnt << "\n";
    else cout << "impossible\n";
}