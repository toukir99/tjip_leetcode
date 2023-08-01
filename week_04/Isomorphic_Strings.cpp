/tc: 0(n)
//sc: 0(1)

class Solution {
public:
		bool isIsomorphicOneWay(string &s, string &t) {
       unordered_map<char,char>from;
			 for(int i=0;i<s.size();i++){
				 if(from.count(s[i]) and from[s[i]]!=t[i])
				 {
					 return false;
				 }
				 from[s[i]]=t[i];
			 }
			 return true;
    }
    bool isIsomorphic(string s, string t) {
       return isIsomorphicOneWay(s,t) and isIsomorphicOneWay(t,s);
    }
};
