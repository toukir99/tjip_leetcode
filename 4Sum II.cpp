//tc:0(n^2)
//sc:0(1)

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>pair_sum;
        for(auto x: nums1){
            for(auto y:nums2){
                pair_sum[x+y]++;
            }
        }
        int tuple_cnt=0;
        for(auto x: nums3){
            for(auto y:nums4){
                tuple_cnt+=pair_sum[-(x+y)];
            }
        }
        return tuple_cnt;
    }
};
