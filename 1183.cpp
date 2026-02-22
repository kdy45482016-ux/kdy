#include <iostream>

#define n 6

using namespace std;

int values[] = {500, 100, 50, 10, 5, 1};
 
int price;
int coins[n];
int ans;

void Input(){
	cin >> price;
	for(int i = 0; i < n; i++) cin >> coins[i];
}
 
void Output(){
	cout << ans << "\n";
	for(int i = 0; i < n; i++) cout << coins[i] << " ";
	cout << "\n";
}

void Solution(){
	int sum_money = 0;
	int sum_coin = 0;
	
	for(int i = 0; i < n; i++){
		sum_money += coins[i] * values[i];
		sum_coin += coins[i];
	}
	
	int target = sum_money - price;
	int current = 0;
	
	for(int i = 0; i < n; i++){
		int use = min(coins[i], (target - current) / values[i]);
		current += values[i] * use;
		sum_coin -= use;
		coins[i] -= use;
		if(target == current) break;
	}
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Input();
	Solution();
	Output();
}
