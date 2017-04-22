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
