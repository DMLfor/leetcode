//用一个stack来储存左边括号，遇到右边括号则取栈顶元素，不匹配则false
class Solution {
public:
    bool isValid(string str) {
        stack<char> sta;
        map<char, char> mp
        {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };
        for(int i = 0; i<str.size(); i++)
        {
            if(str[i] == ']' || str[i] == '}' || str[i] == ')')
            {
                if(sta.empty())
                    return false;
                if(sta.top() != mp[str[i]])
                    return false;
                else sta.pop();
            }
            else sta.push(str[i]);
        }
        if(!sta.empty()) return false;
        return true;
    }
};

