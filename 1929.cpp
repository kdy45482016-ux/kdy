#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    priority_queue <int, vector<int>, greater<int>> pq;

    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        pq.push(input);
    }

    long long cost = 0;

    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a + b;

        pq.push(sum);
        cost += (long long)sum;
    }

    cout << cost << "\n";
}