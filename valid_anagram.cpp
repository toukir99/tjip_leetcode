//tc: 0(n)
//sc: 0(1)

class Solution {
public:
    string countingSort(string &str){
        vector<int>freq(26,0);
        for(auto &c : str){
            freq[c-'a']++;
        }
        int p=0;
        for(int i=0;i<26;i++){
            while(freq[i]-->0){
                str[p++]=i+'a';
            }
        }
        return str;
    }
    bool isAnagram(string s, string t) {
       return countingSort(s)==countingSort(t);
    }
};
