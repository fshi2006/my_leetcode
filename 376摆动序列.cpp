class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        vector<int> nums1;
        nums1.push_back(nums[0]);
        for(int i=1;i<nums.size();i++) {
            if (nums[i]!=nums[i-1]) nums1.push_back(nums[i]);
        } 
        int now=0,last=-1;
        int result = 0;
        for(int i=1;i<nums1.size();i++)
        {
            now=nums1[i]<nums1[i-1]?0:1;
            if(last!=now)
                result++;
            last=now;
        }
        return result+1;
        
    }
};