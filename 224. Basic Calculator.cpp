class Solution {
public:
	int calculate(string s) {
		stack<int> stack;
		int result = 0;
		int sgin = 1;// 1 +   -1 +
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {//是数字
				int n = s[i] - '0';
				while (i + 1 < s.size() && (s[i + 1] >= '0' && s[i + 1] <= '9')) {
					n = n * 10 + (s[i + 1] - '0');  i++;
				}
				result += sgin * n;
			}
			else if (s[i] == '-')   sgin = -1;
			else if (s[i] == '+')   sgin = 1;
			else if (s[i] == '(') {//  1 + (1 + 2 -1)
				stack.push(result);
				stack.push(sgin);
				result = 0;
				sgin = 1;
			}
			else if (s[i] == ')') {
				int lastSgin = stack.top(); stack.pop();
				int lastResult = stack.top(); stack.pop();

				result = lastResult + lastSgin * result;
			}
		}
		return result;
	}
};
