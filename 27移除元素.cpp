class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow_index = 0,fast_index;
        for(fast_index = 0;fast_index<nums.size();fast_index++)
        {
            if(nums[fast_index] != val)
            {
                nums[slow_index] = nums[fast_index];
                slow_index +=1;
            }
        }
        return slow_index; 
    }
};