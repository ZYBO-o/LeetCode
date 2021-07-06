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

using namespace std;

vector<int> grayCode(int n) {
    vector<int> ans={0};
    for(int i=0; i<n; i++){
        int num = 1 << i;
        int size = ans.size();
        for(int j =size - 1; j>=0; j--){  // 反向遍历
            ans.push_back(ans[j] + num);  // 相当于在前缀加1
        }
    }
    return ans;

}

int main() {



    //Test_Backtracking();
    //Test_BTree_LeetCode();

    //Test_Sort_LeetCode();
    //Test_Binary_Search();
    //Test_String();

    vector<int> ans = grayCode(4);
    for(auto i : ans)
        cout << i << " ";
    cout << endl;


}
