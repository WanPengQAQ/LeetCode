class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int>res(nums.size(),-1);
		stack<int>s;
		int n = nums.size();
		/*first round*/
	/*	for (int i = 0; i < nums.size(); i++) {
			while (!s.empty() &&  nums[s.top()] < nums[i]) {
				res[s.top()] = nums[i];
				s.pop();
			}
			s.push(i);
		}
    second ronud
		for (int i = 0; i < nums.size(); i++) {
			while (!s.empty() && nums[s.top()] < nums[i]){
				res[s.top()] = nums[i];
				s.pop();
			}
		}
		*/
    
    /*merge first and sceond*/
		for (int i = 0; i < nums.size()*2; i++) {
			while (!s.empty() &&  nums[s.top()] < nums[i%n]) {
				res[s.top()] = nums[i%n];
				s.pop();
			}
			s.push(i%n);
		}
		
		return res;
	}
};
