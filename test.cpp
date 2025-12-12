#include <iostream>
#include <string>

using namespace std;

int func(int n) // 1 ~ n 까지 더하기
{
    int num = (n + 1) * (n / 2);
    if(n % 2 == 1) num += n / 2 + 1;
    return num;
}

int main()
{
    string a = "wait";
    string b;
    cin >> b;
    if(a == b) cout << true << endl;
    else cout << false << endl;
}