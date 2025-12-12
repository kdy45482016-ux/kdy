#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack <int> s;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        char op;
        cin >> op;

        if(op == 'i'){
            int num;
            cin >> num;
            s.push(num);
        }
        else if(op == 'o'){
            if(s.empty()){
                cout << "empty" << endl;
                continue;
            }
            cout << s.top() << endl;
            s.pop();
        }
        else if(op == 'c'){
            cout << s.size() << endl;
        }
    }

    return 0;
}