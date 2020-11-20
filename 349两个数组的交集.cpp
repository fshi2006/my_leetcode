class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1_hash,nums2_hash;
        for(int i:nums1) nums1_hash.insert(i);
        for(int i:nums2) 
            if(nums1_hash.count(i))
                nums2_hash.insert(i);
        return vector<int> (nums2_hash.begin(),nums2_hash.end());
    }
};