class Solution {
public:
    string decodeString(string s) {
        string res = "";
        
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            if((s[i] >= '0' && s[i] <= '9')||(s[i] == '[')||(s[i] >= 'a' && s[i] <= 'z')){
                st.push(s[i]);
                continue;
            }
            
            if(s[i] == ']'){
                string temp;
                while(st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();//because s.top == '['
                
                string num = "";
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    num = st.top() + num;
                    st.pop();
                }
                int k =stoi(num);
                
                string ss = "";
                for(int i = 1; i <= k; i++)
                    ss = ss + temp;
                
                for(int i = 0; i < ss.size(); i++)
                    st.push(ss[i]);
            }
        }
         
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }        
        return res;
    }
};
