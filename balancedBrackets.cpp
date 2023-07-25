//tc:0(n)
/sc:0(1)
  
class Solution {
public:
    bool isValid(string s) {
        stack<char>stkParenthesis;
        for(auto &str:s){
            if(stkParenthesis.empty()){
                stkParenthesis.push(str);
            }
            else if((stkParenthesis.top()=='(' && str==')')||(stkParenthesis.top()=='{' && str=='}')||(stkParenthesis.top()=='[' && str==']')){
                stkParenthesis.pop();
            }
            else{
                stkParenthesis.push(str);
            }
        }
        if(stkParenthesis.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
