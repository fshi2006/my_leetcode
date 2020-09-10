class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return nums.erase(unique(nums.begin(), nums.end()), nums.end()) - nums.begin();
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) 
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) nums.erase(nums.begin() + i + 1);
        return nums.size();
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        int fast_index ,slow_index = 1;
        for (fast_index = 0; fast_index <nums.size()-1; fast_index++)
        {
            if(nums[fast_index] != nums[fast_index+1])
            {
                nums[slow_index] =nums[fast_index+1];
                slow_index+=1;
            }
        }
        return slow_index;
    }
};




class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> nums_new;
        bool has_exist=false;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums_new.size() == 0)
            {
                nums_new.push_back(nums[i]);
            }
            else
            {
                for(int j = 0;j<nums_new.size();j++)
                {
                    if(nums_new[j] == nums[i])
                    {
                        has_exist = true;
                    }
                }
                if(has_exist == false)
                {
                    nums_new.push_back(nums[i]);
                }
            }
            has_exist = false;
        }
        nums.clear();
        nums.assign(nums_new.begin(),nums_new.end());
        return nums_new.size();
    }
};