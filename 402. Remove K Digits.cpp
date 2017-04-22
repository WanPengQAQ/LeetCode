/*Greedy solution O(k*n)*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k){
            string res = "0";
            return res;
        }
        while( k > 0 ) {
            int i = 0;
            while(i + 1 < n && num[i] <= num[i+1])
                i++;
            num.erase(i, 1);
            k--;
        }
        while(num[0] == '0' && num.size() > 1)
            num.erase(0, 1);
        return num;
    }
};
/*use stack*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        stack<char> s;
        for (int i = 0; i < num.size(); i++) {
            while (k > 0 && !s.empty() && s.top() > num[i]) {
                k--;
                s.pop();
            }
            s.push(num[i]);
        }
        while (k > 0 && !s.empty()) {
            k--;
            s.pop();
        }
        while (!s.empty()) {
            result = s.top() + result;
            s.pop();
        }
        int index = 0;
        while (result[index] == '0') index++;
        result = result.substr(index);
        if (result == "") return "0";
        return result;
        
    }
};
