#include "Tree/Test_BTree_LeetCode.h"
#include <iostream>
#include "Backtracking/Test_Backtracking.h"


using namespace std;



int main() {

    vector<int> nums {1,2,3};
    vector<string>res;
    string temp;
    for(auto i : nums) {
        temp += to_string(i);
        temp += "->";
    }
    res.emplace_back(temp.begin(), (temp.end()-2));
    for (auto i : res) {
        cout << i << endl;
    }
    //Test_Backtracking();
    //Test_BTree_LeetCode();

    return 0;
}
