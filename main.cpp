#include "Tree/Test_BTree_LeetCode.h"
#include <iostream>
#include "Backtracking/Test_Backtracking.h"
#include "Sort/Test_Sort_LeetCode.h"
#include "Binary Search/Test_BinarySearch.h"
#include "string/Test_String.h"
#include <list>
#include "List/List.h"
#include "string/Test_String.h"
#include <numeric>
#include "Monotonic Stack/Test_MonotonicStack.h"

#include <string>
#include <regex>
#include <list>
#include <forward_list>

#include <unordered_map>


#include <ratio>
#include <chrono>
#include <ctime>
using namespace std;




int main() {


    //Test_MonotonicStack();

    //Test_Backtracking();
    //Test_BTree_LeetCode();

    //Test_Sort_LeetCode();
    //Test_Binary_Search();
    //Test_String();

    regex patten("^([^:]*): ?(.*)$");
    smatch subMatch;
    string line = "Accept: image/gif HOST: image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, application/vnd.ms-excel, application/vnd.ms-powerpoint, application/msword, */*";
    string method_ ;
    string path_;
    string version_;

    if(regex_match(line, subMatch, patten)) {
         method_ = subMatch[1];
         path_ = subMatch[2];

    }

    cout << "method_ = " << method_ << endl;
    cout << "path_ = " <<  path_ << endl;

    return 0;

}
