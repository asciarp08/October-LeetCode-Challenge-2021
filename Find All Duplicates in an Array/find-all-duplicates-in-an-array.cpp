/**
Time = O(n)
Space = O(1)
**/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>duplicates;
        for(int i = 0; i<n; i++){
            if(nums[abs(nums[i])-1]<0){
                duplicates.push_back(abs(nums[i]));
            }
            nums[abs(nums[i])-1]*=-1;
        }
        return duplicates;
    }
};
