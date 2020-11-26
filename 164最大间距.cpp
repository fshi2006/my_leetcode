class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int result=0;
        for(int i=1;i<nums.size();i++)
        {
            if(result<nums[i]-nums[i-1])
                result=nums[i]-nums[i-1];
        }
        return result;
    }
};