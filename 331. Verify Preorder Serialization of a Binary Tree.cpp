
class Solution {
public:
	bool isValidSerialization(string preorder) {
		stack<int> s; // 用1代表数字 0代表结束

		for (auto it = begin(preorder); it != end(preorder); it++)
		{
			if (*it == ',')
				continue;

			if (*it == '#')
				s.push(0);
			else {
				while (it + 1 != end(preorder) && *(it) >= '0' &&  *(it) <= '9') 
				    it++;
				s.push(1);
			}

			while (s.size() >= 3 && s.top() == 0)
			{
				s.pop();

				int tempLast = s.top();
				if (tempLast == 0)
				{
					s.pop();
					
					int temp = s.top();
					if(temp == 1){
				    	s.pop();
				    	s.push(0);
					}
					else
					    return false;
				}
				else
				{
					s.push(0);
					break;
				}
			}
		}
		return s.size() == 1 && s.top() == 0;
	}
};
