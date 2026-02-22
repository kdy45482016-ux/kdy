#include <iostream>
#include <vector>

#define n 6

using namespace std;

vector <int> value = {500, 100, 50, 10, 5, 1};
int price;
vector <int> coins(n);
int cnt;

void Input(){
    cin >> price;
    for(int i = 0; i < n; i++) cin >> coins[i];
}

void Solution(){
    int sum_money = 0;
    int sum_coins = 0;

    for(int i = 0; i < n; i++){
        sum_money += coins[i] * value[i];
        sum_coins += coins[i];
    }

    int target = sum_money - price;
    cnt = sum_coins;
    for(int i = 0; i < n; i++){
        int use = min(target / value[i], coins[i]);
        target -= use * value[i];
        coins[i] -= use;
        cnt -= use;
        if(target == 0) break;
    }
}

void Output(){
    cout << cnt << "\n";
    for(int i = 0; i < n; i++) cout << coins[i] << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    Output();
}