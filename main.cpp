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

    using namespace std::chrono;

    steady_clock::time_point t1 = steady_clock::now();

    std::cout << "printing out 1000 stars...\n";
    for (int i=0; i<1000; ++i) std::cout << "*";
    std::cout << std::endl;

    steady_clock::time_point t2 = steady_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;
    return 0;

}
