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

int main() {



    //Test_Backtracking();
    //Test_BTree_LeetCode();

    //Test_Sort_LeetCode();
    //Test_Binary_Search();
    //Test_String();

    vector<int> Array ;
//size应该为0，capacity的值依赖于具体实现
    cout << "Array size : " << Array.size() << " capacity : " << Array.capacity() << endl;

//向Array容器中添加24个元素
    for (vector<int>::size_type num= 0;  num < 24; num++)
        Array.push_back(num);
    cout << "Array size : " << Array.size() << " capacity : " << Array.capacity() << endl;

//对Array容器调整到25
    Array.resize(25);
    cout << "Array size : " << Array.size() << " capacity : " << Array.capacity() << endl;

//预分配的内存修改为50
    Array.reserve(50);
    cout << "Array size : " << Array.size() << " capacity : " << Array.capacity() << endl;

//向剩余内存中填值
    while (Array.size() != Array.capacity())
        Array.push_back(0);
    cout << "Array size : " << Array.size() << " capacity : " << Array.capacity() << endl;

//再一次填入值
    Array.push_back(51);
    cout << "Array size : " << Array.size() << " capacity : " << Array.capacity() << endl;


}
