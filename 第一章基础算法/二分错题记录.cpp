#include <bits/stdc++.h>
using namespace std ;

// 旋转排序数组后进行二分查找(特定值)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0 , r = nums.size() - 1 ;
        while(l <= r){
            int mid = l + (r - l) / 2 ;
            if(target == nums[mid])return mid ; // 单独判断

            if(nums[l] <= nums[mid]){ // 数组[l , mid]间为左递增
                if(target < nums[mid] && target >= nums[l])r = mid - 1 ; // target在[l , mid-1]之间
                else l = mid + 1 ; // target在[mid+1 , r]之间
            }else { // [r , mid]间为右递增
                if(target > nums[mid] && target <= nums[r])l = mid + 1 ; // target在[mid+1 , r]之间
                else r = mid - 1 ; // target在[l , mid-1]之间
            }
        }
        // 出循环条件 : l > r
        return -1 ;
    }
};

// 