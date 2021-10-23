/**
Time = O(logn)
Space = 1
**/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int minElement = INT_MAX;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            minElement = min(minElement, nums[mid]);
            if(nums[mid]>nums[r]){
                l = mid+1;
            }
            else if(nums[mid]<nums[r]){
                r = mid-1;
            }
            else{
                r--;
            }
        }
        return minElement;
    }
};
