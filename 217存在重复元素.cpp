class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_hash;
        for(int i=0;i<nums.size();i++)
        {
            if(nums_hash.count(nums[i]))
                return true;
            else
                nums_hash.insert(nums[i]);
        }
        return false;
    }
};