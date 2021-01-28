class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1 || s.size() % 2 != 0)
            return false;
        
        stack<char> par;
        
        for(auto ch : s) {
            if(par.size() != 0) {
                if(par.top() == '(' && ch == ')') {
                    par.pop();
                    continue;
                }
                if(par.top() == '[' && ch == ']') {
                    par.pop();
                    continue;
                }
                if(par.top() == '{' && ch == '}') {
                    par.pop();
                    continue;
                }
            }
            par.push(ch);
        }
        
        return par.size() == 0 ? true : false;
    }
};