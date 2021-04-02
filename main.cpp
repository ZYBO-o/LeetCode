#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int main() {

    map<string, size_t> map;
    string word;
    while(cin >> word && word != "stop") {
        ++ map[word];
    }


    for (auto i : map) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
