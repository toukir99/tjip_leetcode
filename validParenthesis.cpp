//tc:0(n)
/sc:0(1)
  
class Solution {
public:
    bool isCharacterOpeningBracket(char ch)
    {
        return ch=='(' || ch=='{' || ch=='[';
    }
    bool isValid(string s) {
        unordered_map<char,char>bracketMap{{')','('},{'}','{'},{']','['}};
        stack<char>stk;
        for(auto ch:s){
            if(isCharacterOpeningBracket(ch)){
                stk.push(ch);
            }
            else
            {
                if(stk.empty() || stk.top()!=bracketMap[ch])
                    return false;
                stk.pop();
            }         
        }
        return stk.empty();
    }
};
