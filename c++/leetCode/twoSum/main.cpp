#include <iostream>
using namespace std;
int* twoSum(int* nums, int numsSize, int target){

    int* ret = new int[2];
  
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if((nums[i] + nums[j]) == target){
                ret[0] = i;
                ret[1] = j;
                goto ok;
            }
        }
    }
ok:
    return ret;
}
/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

int main()
{   
    int nums[4] = {2, 7, 11, 15};
    int* ret = twoSum(nums, sizeof(nums) / sizeof(nums[0]), 18);
    cout << "ret[0]：" <<  ret[0] << " ret[1]：" << ret[1] << endl;
    delete[] ret;
    return 0;
}
