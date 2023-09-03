//tc: O(2^n)
//sc: O(2^n)

class Solution {
private:
    vector<vector<int>>results;
    void generateSubsets(vector<int> &nums, vector<int> &cand, int pos){
        if(pos>=nums.size()){
            results.push_back(cand); 
            cout<<pos<<endl;
            return;
        }
        generateSubsets(nums,cand,pos+1);
        cand.push_back(nums[pos]); 
        generateSubsets(nums,cand,pos+1);
        cand.pop_back(); 
    }
    void generateSubsets(vector<int> &nums){
        results.clear();
        vector<int>cand;
        generateSubsets(nums,cand,0);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        generateSubsets(nums);
        return results;
    }
};
