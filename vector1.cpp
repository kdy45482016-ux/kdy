#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector <int> v(0);
    v.resize(n, x);

    while(true){
        char op;
        cin >> op;

        if(op == 'i'){
            int num;
            cin >> num;
            v.push_back(num);
        }
        else if(op == 'r'){
            if(v.empty()) continue;
            v.pop_back();
        }
        else if(op == 's'){
            sort(v.begin(), v.end());
        }
        else if(op == 't'){
            if(v.empty()) continue;
            int temp = v.back();
            v[v.size() - 1] = v.front();
            v[0] = temp;
        }
        else if(op == 'e'){
            for(auto a : v){
                cout << a << " ";
            }
            break;
        }
    }

    return 0;
}