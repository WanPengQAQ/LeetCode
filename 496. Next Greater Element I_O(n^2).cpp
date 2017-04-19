class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int>res(findNums.size());
        
        for(int i = 0; i < findNums.size(); i++){
            res[i] = search(nums, findNums[i]);
        }
        
        return res;
    }
    int search(vector<int>& nums, int a){
        int i;
        for(i = 0; i < nums.size(); i++)
            if(a == nums[i])    
                break;
                
        if(i == nums.size())
            return -1;
            
        for( ; i < nums.size(); i++)
            if(a < nums[i]){
                return nums[i];
            }
                
        return -1;
    }
};
