class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nums1_map;
        vector<int> result;
        for(int num : nums1)
            nums1_map[num]++;
        for(int num : nums2)
            if(nums1_map[num]>0){
                result.push_back(num);
                nums1_map[num]--;
            }
        return result;
    }
};