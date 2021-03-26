#include "Sort/148_Sort_List.h"

int compare(int num1,int num2){
    return to_string(num1)+to_string(num2) > to_string(num2)+to_string(num1);
}

int main() {

    vector<int> nums {3,30,34,5,9};

    sort(nums.begin(),nums.end(),compare);

    string ans ;
    for (int i : nums) {
        ans.append(to_string(i));
    }

    cout << ans << endl;
    //Test();

    return 0;
}
