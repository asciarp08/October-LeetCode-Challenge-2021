/**
Time = O(31) 
Spac = O(1)
**/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int ans = 0;
        for(int i = 30; i>=0 ; i--){
            if((left&(1<<i))==(right&(1<<i))){
                ans |= (left&(1<<i));
            }
            else
                break;
        }
        return ans;
    }
};
