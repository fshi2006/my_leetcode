class Solution {
public:
    void reverse(vector<int>&nums,int start,int end){
        for(int i=0;i<(end-start)/2;i++){
            int tmp = nums[i+start];
            nums[i+start]=nums[end-i-1];
            nums[end-i-1]=tmp;
        }
         
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n);
        reverse(nums, 0, k);
        reverse(nums, k, n);
    }
};