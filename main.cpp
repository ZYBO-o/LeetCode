#include "Bit operation/137_single_number_ii.h"
#include <iostream>
#include <vector>
using namespace std;

class SingleNumber {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //用于记录，区分“两个”数组
        int diff = 0;
        for(int i = 0; i < nums.size(); i ++) {
            diff ^= nums[i];
        }
        //取最后一位1
        //先介绍一下原码，反码和补码
        //原码，就是其二进制表示（注意，有一位符号位）
        //反码，正数的反码就是原码，负数的反码是符号位不变，其余位取反
        //补码，正数的补码就是原码，负数的补码是反码+1
        //在机器中都是采用补码形式存
        //diff & (-diff)就是取diff的最后一位1的位置
        cout << diff << endl;
        diff &= (-diff);
        cout << diff << endl;
        vector<int> rets = {0, 0};
        for(int i = 0; i < nums.size(); i ++) {
            //分属两个“不同”的数组
            if ((nums[i] & diff) == 0) {
                rets[0] ^= nums[i];
            }
            else {
                rets[1] ^= nums[i];
            }
        }
        return rets;
    }
};


int main() {

    //Test();
    vector<int> nums {7,8,3,3,4,4,5,5,6,6};
    SingleNumber singleNumber;
    vector<int> ans = singleNumber.singleNumber(nums);
    cout << ans[0] << endl;
    cout << ans[1] << endl;

    return 0;
}
