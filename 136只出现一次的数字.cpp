class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<2)
            return nums[0];
        int p=0;
        while(p<nums.size()){
            if(nums[p]==nums[p+1]){
                p+=2;
            }
            else if(nums[p]!=nums[p+1]){
                return nums[p];  
            }        
        }
        return 0;
    }
};