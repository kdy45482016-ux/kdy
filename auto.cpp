#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    pair <int, string> arr[10];

    for(auto &i : arr){
        cin >> i.second >> i.first;
        i.first *= -1;
    }

    sort(arr, arr + 10);

    for(auto i : arr) cout << i.second << " " << -i.first << endl;

    return 0;
}