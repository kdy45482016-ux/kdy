#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

map <string, int> m;
vector <string> v;

int main(){
    while(true){
        string str;
        getline(cin, str);

        if(str == "END") break;

        stringstream ss(str);

        string word;

        while(ss >> word){
            if(++m[word] == 1) v.push_back(word);
        }

        for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << "\n";
    }
}