/**
 * Source : https://leetcode-cn.com/problems/binary-search/
 * Author : Hu Jingbo
 * Date   : 2021-09-06
 * 
 * 704. 二分查找
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target，写一个函数搜索
 * nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 * 
 * 示例 1:
 * 输入: nums = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4
 * 
 * 示例 2:
 * 输入: nums = [-1,0,3,5,9,12], target = 2
 * 输出: -1
 * 解释: 2 不存在 nums 中因此返回 -1
 * 
 * 提示：
 * 你可以假设 nums 中的所有元素是不重复的。
 * n 将在 [1, 10000]之间。
 * nums 的每个元素都将在 [-9999, 9999]之间。
 */

#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 二分查找
     * 
     * 在升序数组 nums 中寻找目标值 target，对于特定下标 i，比较 num[i] 和 target
     * 的大小：
     *      如果 num[i] = target，则下标 i 即为要寻找的下标。
     *      如果 num[i] < target，则 target 只可能在下标 i 的右侧。
     *      如果 num[i] > target，则 target 只可能在下标 i 的左侧。
     * 二分查找的做法是，定义查找的范围 [left, right]，初始的查找范围为整个数组。每
     * 次取查找范围的中点 mid，比较 nums[mid] 和 target 的大小。如果相等则 mid 即为
     * 要寻找的下标，如果不相等，则根据 nums[mid] 和 target 的大小关系将查找范围缩小
     * 一半。
     * 
     * 由于每次查找会将查找范围缩小一半，因此二分查找的时间复杂度为 O(log n)，其中 n
     * 是数组的长度。空间复杂度为 O(1)。
     * 
     * 二分查找的条件是查找范围不为空，即 left <= right。如果 target 在数组中，二分
     * 查找可以保证找到 target，返回 target 在数组中的下标。如果 target 不在数组中，
     * 则当 lefg > right 时结束查找，返回 -1。
     */    
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

TEST(Solution, binarySearch) {
    Solution s;
    vector<int> v = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(4, s.search(v, 9));
    EXPECT_EQ(-1, s.search(v, 2));
    vector<int> v1 = {5};
    EXPECT_EQ(0, s.search(v1, 5));
}