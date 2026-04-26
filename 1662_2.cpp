#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int max_bishop = 0;
vector<bool> dia1, dia2;

void dfs(int count, int start){
    for(int i = start; i < arr.size(); i++){
        int dia1_index = (arr[i] / n) + (arr[i] % n);
        int dia2_index = n - (arr[i] % n) + (arr[i] / n) - 1;

        if(dia1[dia1_index] || dia2[dia2_index]) continue;
        
        dia1[dia1_index] = true;
        dia2[dia2_index] = true;

        dfs(count + 1, i + 1);

        dia1[dia1_index] = false;
        dia2[dia2_index] = false;
    }

    if(count > max_bishop) max_bishop = count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n * n; i++){
        int temp;
        cin >> temp;
        if(temp) arr.push_back(i);
    }

    dia1.resize(n * 2, false);
    dia2.resize(n * 2, false);

    dfs(0, 0);

    cout << max_bishop << "\n";
}