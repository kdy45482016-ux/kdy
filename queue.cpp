#include <iostream>
#include <queue>

using namespace std;

struct Data{
    int x, y, z;
};

int main()
{
    queue <Data> q;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        char op;
        cin >> op;

        if(op == 'i'){
            Data a;
            cin >> a.x >> a.y >> a.z;
            q.push(a);
        }
        else if(op == 'o'){
            if(q.empty()){
                cout << "empty" << endl;
                continue;
            }
            Data a = q.front();
            cout << a.x << " " << a.y << " " << a.z << endl;
            q.pop();
        }
        else if(op == 'c'){
            cout << q.size() << endl;
        }
        else if(op == 'z'){
            int a;
            cin >> a;
            if(q.empty() || a != q.front().z){
                cout << "no" << endl;
            }
            else cout << "yes" << endl;
        }
    }

    return 0;
}