#include "Tree/Test_BTree_LeetCode.h"
#include <iostream>
#include "Backtracking/Test_Backtracking.h"
#include "Sort/Test_Sort_LeetCode.h"
#include "Binary Search/Test_BinarySearch.h"
#include "string/Test_String.h"
#include <list>
#include "List/List.h"
#include "string/Test_String.h"


#include <list>
#include <forward_list>

#include <unordered_map>
using namespace std;


bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char,int> map;
    for(auto c : ransomNote)
        map[c]++;
    for(auto c : magazine) {
        if(map.count(c) > 0)
            map[c]--;
    }
    for(auto iter = map.begin(); iter != map.end(); iter ++) {
        cout << iter->first << ":" << iter->second << endl;
    }
    for(auto iter = map.begin(); iter != map.end(); iter ++) {
        if(iter->second != 0)
            return false;
    }
    return true;
}

int main() {

    cout << canConstruct("ab", "aa") << endl;
    //Test_Backtracking();
    //Test_BTree_LeetCode();

    //Test_Sort_LeetCode();
    //Test_Binary_Search();
    //Test_String();



}
