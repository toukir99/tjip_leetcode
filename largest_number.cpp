//tc:0(k*nlogn) k=size of the input string, n= size of the array
//sc:0(1)

class Solution {
public:
    static bool isLess(int &a, int &b){
        string sa=to_string(a);
        string sb=to_string(b);
        return (sa+sb)>(sb+sa);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),isLess);
        string result="";
        if(nums[0]==0){
            return "0";
        }
        for(auto &num: nums)
        {
            result+=to_string(num);
        }
        return result;
    }
};
