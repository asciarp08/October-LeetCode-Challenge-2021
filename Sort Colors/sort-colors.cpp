/**
Time = O(n); it'll be O(2*n) in case of all 2's as we'll checking each position twice 
Space = O(1)
**/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        int start = 0; //to get all 0's at the start
        int end = n-1; //to get all 2's at the end
        int idx = 0; //for current positon
        
        while( idx <= end && start<end){ //take care of the condition IMPORTANT
            
            if(nums[idx]==0){
                swap(nums[idx], nums[start]);
                idx++;
                start++;
            }
            else if(nums[idx] == 2){
                swap(nums[idx], nums[end]);
                end--;
                //we arent increasing idx cause we need to check what we have exchanged with, for eg: [0,0,0,1,1,2,2,0] if our pointer 'idx' is at 5 and after swapping nums[5] = 0, disturbing the so far sorted part, hence we need to check idx before moving further 
            }
            else idx++;
            
        }
        
    }
};
