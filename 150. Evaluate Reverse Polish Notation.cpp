class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<string> s;

		for (int i = 0; i < tokens.size(); i++) {
			string temp = tokens[i];
			//  + - * /
			//  1 2 3 4
			int op = -1;
			if (temp[0] == '+')	op = 1;
			if (temp[0] == '-' && temp.size() == 1)	op = 2;
			if (temp[0] == '*')	op = 3;
			if (temp[0] == '/')	op = 4;

			if (op == -1) {//是数字
				s.push( temp );
			}
			else {//是运算符
				int b = stoi(s.top()); s.pop();
				int a = stoi(s.top()); s.pop();
				// a () b
				
				int res = 0;
				if (temp[0] == '+')	res = a + b;
				if (temp[0] == '-')	res = a - b;
				if (temp[0] == '*')	res = a * b;
				if (temp[0] == '/')	res = a / b;

				s.push(to_string(res));
			}
		}

		return stoi(s.top());
	}
};
