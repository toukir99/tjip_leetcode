//tc: 0(n)
//sc: 0(1)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>>dataKeyIndex;
        for(auto &s: strs)
        {    
           string keyValue = s; 
           dataKeyIndex[countingSort(s)].push_back(keyValue);
        }
        vector<vector<string>>resultAnagram;
        for(auto &i: dataKeyIndex)
        {
            resultAnagram.push_back(i.second);
        }
        return resultAnagram;
    }
    private:
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
};
