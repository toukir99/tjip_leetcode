//tc: 0(n*l); n= size of the string, l= minimum length 
//sc: 0(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       int min_len= strs.empty() ? 0:INT_MAX/2;
       int lcp_len=0;
       for(auto &str : strs)
       {
           min_len= min(min_len, (int)str.size());
       }
       bool isEqual=true;
       for(int i=0;i<min_len;i++)
       {
           for(int j=0;j+1<strs.size();j++)
           {
               isEqual &= (strs[j][i]==strs[j+1][i]);
           }
           lcp_len+=isEqual;
       }
       return strs.empty() ? "": strs[0].substr(0,lcp_len); 
    }
};
