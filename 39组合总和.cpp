class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        calculatesum(candidates,target,0,0);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> result_temp;
    void calculatesum(vector<int>& candidates, int target,int sum,int start_index)
    {
        if(sum > target)
        {
            return;
        }
        if(sum == target)
        {
            result.push_back(result_temp);
            return;
        }
        
        for(int i = start_index;i<candidates.size();i++)
        {
            sum = sum + candidates[i];
            result_temp.push_back(candidates[i]);
            calculatesum(candidates,target,sum,i);
            sum = sum -candidates[i];
            result_temp.pop_back();
        }
    }
};