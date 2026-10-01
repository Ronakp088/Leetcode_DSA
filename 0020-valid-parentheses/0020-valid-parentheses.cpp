class Solution {
public:
    bool isValid(string s) {
        stack<int> open;
        if(s.size()%2 != 0) return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                open.push(s[i]);
            else {
                if (open.empty())
                    return false;
                else if (s[i] == ')' && open.top() == '(')
                    open.pop();
                else if (s[i] == ']' && open.top() == '[')
                    open.pop();
                else if (s[i] == '}' && open.top() == '{')
                    open.pop();
                else
                    return false;
            }
        }

        return open.empty();
    }
};
