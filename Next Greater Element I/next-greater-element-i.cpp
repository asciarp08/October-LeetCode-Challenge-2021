class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        stack<int> s;
        unordered_map<int,int> nextGreater;
        
        for(auto num:nums2){
            while(s.size() && s.top()<num){
                nextGreater[s.top()]=num;
                s.pop();
            }
            s.push(num);
        }
        vector<int> ans;
            
        for(auto num:nums1){
            if(nextGreater.count(num))
                ans.push_back(nextGreater[num]);
            else ans.push_back(-1);
        }
        return ans;
    }
};
