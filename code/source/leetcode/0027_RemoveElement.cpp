/**
 * Author : Hu Jingbo
 * Date   : 2022-01-07
 * 
 * 27. 移除元素
 * 
 * 给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，并返回移除
 * 后数组的新长度。不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数
 * 组。
 * 
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 * 
 * 说明:
 * 为什么返回数值是整数，但输出的答案是数组呢?
 * 请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可
 * 见的。
 * 你可以想象内部操作如下:
 * // nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
 * int len = removeElement(nums, val);
 * // 在函数里修改输入数组对于调用者是可见的。
 * // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
 * for (int i = 0; i < len; i++) {
 *     print(nums[i]);
 * }
 * 
 * 示例 1：
 * 输入：nums = [3,2,2,3], val = 3
 * 输出：2, nums = [2,2]
 * 解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超
 * 出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = 
 * [2,2,0,0]，也会被视作正确答案。
 * 
 * 示例 2：
 * 输入：nums = [0,1,2,2,3,0,4,2], val = 2
 * 输出：5, nums = [0,1,4,0,3]
 * 解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五
 * 个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
 * 
 * 提示：
 * 0 <= nums.length <= 100
 * 0 <= nums[i] <= 50
 * 0 <= val <= 100
 */

#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 方法一：双指针
     */
    int removeElement(vector<int>& nums, int val) {
        int left = 0, n = nums.size();
        for (int right = 0; right < n; ++right) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                ++left;
            }
        }
        nums.resize(left);
        return left;
    }
};

TEST(Solution, 0027_RemoveElement) {
    Solution s;

    vector<int> nums = {3, 2, 2, 3};
    vector<int> ans = {2, 2};
    EXPECT_EQ(ans.size(), s.removeElement(nums, 3));
    EXPECT_EQ(ans, nums);

    vector<int> nums_2 = {0,1,2,2,3,0,4,2};
    vector<int> ans_2 = {0,1,3,0,4};
    EXPECT_EQ(ans_2.size(), s.removeElement(nums_2, 2));
    EXPECT_EQ(ans_2, nums_2);
}