#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    long long sum = 0;
    vector <int> arr, open(0);

    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    open.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        for(int j = open.size() - 1; j >= 0; j--){
            if(arr[i] >= open[j]) open.pop_back();
            else break;
        }
        sum += (long long)open.size();
        open.push_back(arr[i]);
    }

    cout << sum << endl;

    return 0;
}

