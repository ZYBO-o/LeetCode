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


bool cmp(const  unordered_map<int, int>::iterator &p1,const  unordered_map<int, int>::iterator &p2)//要用常数，不然编译错误
{
    return p1->second < p2->second;
}


int main() {
    unordered_map<int, int>map ;
    vector<int> nums  {1,1,1,2,2,3};

    for(auto num : nums)
        map[num]++;

    vector<pair<int, int>> vtMap;

    for (auto it = map.begin(); it != map.end(); it++)
        vtMap.push_back(make_pair(it->first, it->second));



    sort(vtMap.begin(), vtMap.end(),
         [](const pair<int, int> &x, const pair<int, int> &y) -> int {
             return x.second > y.second;
         });

    for (auto it = vtMap.begin(); it != vtMap.end(); it++)
        cout << it->first << ':' << it->second << '\n';
    return 0;

    //Test_Backtracking();
    //Test_BTree_LeetCode();

    //Test_Sort_LeetCode();
    //Test_Binary_Search();
    //Test_String();



}
