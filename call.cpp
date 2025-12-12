#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    queue <int> wait;
    int sum = 0;

    for(int i = 0; i < n; i++){
        string op;
        int num;

        cin >> op;

        if(op == "call"){
            cin >> num;
            wait.push(num);
            sum += num;
        }
        else if(op == "wait"){
            cin >> num;
            sum -= num;
            if(sum < 0) sum = 0;
            while (num > 0 && !wait.empty())
            {
                wait.front() -= num;
                if(wait.front() <= 0){
                    num = -wait.front();
                    wait.pop();
                }
                else break;
            }
        }
        else if(op == "check"){
            cout << wait.size() << " people " << sum << " minutes" << endl;
        }
    }

    return 0;
}