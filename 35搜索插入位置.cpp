class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int nums_size = nums.size();
      int left_index = 0, right_index = nums_size -1 ,mid_index;
      if(target<nums[0])
      {
          return 0;
      }
      if(target>nums[nums_size-1])
      {
          return nums_size;
      }
      while(left_index <= right_index)
      {
          mid_index = (right_index - left_index)/2 + left_index;
          if(target <= nums[mid_index] )
          {
              right_index = mid_index -1;
          }
          else
          {
              left_index = mid_index +1 ;
          }
      }
      return left_index;
    }
};