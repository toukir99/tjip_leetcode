//tc: O(4^n/sqrt(n))
//sc: O(2n)

class Solution {
    private:
    vector<string>results;
    string cand;
    void generate(int open, int close, int n){
        if(open==close && open==n){
            results.push_back(cand);
            return;
        }
        if(open<n){
            cand.push_back('(');
            generate(open+1,close,n);
            cand.pop_back();
        }
        if(open>close){
            cand.push_back(')');
            generate(open,close+1,n);
            cand.pop_back();
        }
    }
    void generate(int n){
        results.clear();
        cand.clear();
        generate(0,0,n);
    }
public:
    vector<string> generateParenthesis(int n) {
        generate(n);
        return results;
    }
};
