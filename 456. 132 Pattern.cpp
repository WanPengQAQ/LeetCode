/* naive solution O(n^3)*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        for(int i = 0; i < nums.size() ;i++){
            for(int j = i + 1; j < nums.size(); j++){
              //  if(nums[i] >= nums[j]) //nums[i] < nums[j]
               //     continue;
                for(int k = j + 1; k < nums.size(); k++)
                    if(nums[i] < nums[k] && nums[j] > nums[k] && nums[i] < nums[j])
                        return true;
            }
            
        }
        
        
        return false;
    }
};
