#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> v[n];

    for(int i = 0; i < n; i++){
        int len;
        cin >> len;
        for(int j = 0; j < len; j++){
            int num;
            cin >> num;
            v[i].push_back(num);
        }
    }

    for(int i = 0; i < n; i++){
        int index;
        cin >> index;
        for(int a : v[index]){
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}