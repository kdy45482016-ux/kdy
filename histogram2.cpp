#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> input(n);
    vector <int> size(n);

    for(auto &a : input) cin >> a;

    int max = 0;

    for(int i = 0; i < n; i++){
        int len = 1;
        for(int j = i - 1; j >= 0; j--){
            if(input[j] < input[i]) break;
            len += 1; 
        }
        for(int j = i + 1; j < n; j++){
            if(input[j] < input[i]) break;
            len += 1;
        }
        if(input[i] > 0) size[i] = len;
        else size[i] = 0;

        int num = size[i] * input[i];
        if(max < num) max = num;
    }

    cout << max << endl;
}