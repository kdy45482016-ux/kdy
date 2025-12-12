#include <iostream>
#include <queue>

using namespace std;

typedef struct data{
    string name;
    int age;
    float blood;
    bool operator < (const data &r) const {
        if(blood == r.blood) return age < r.age;
        return blood < r.blood;
    }
}Data;

int main()
{
    priority_queue <Data> q;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string op;
        cin >> op;

        if(op[1] == 'u'){
            Data input;
            cin >> input.name >> input.age >> input.blood;
            q.push(input);
        }
        else if(op[1] == 'o'){
            if(q.size() > 0){
                cout << q.top().name << endl;
                q.pop();
            }
        }
    }

    return 0;
}