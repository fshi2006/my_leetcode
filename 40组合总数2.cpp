class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
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
            if(i>start_index&&candidates[i-1]==candidates[i]){
                continue;
            }
            sum = sum + candidates[i];
            result_temp.push_back(candidates[i]);
            calculatesum(candidates,target,sum,i+1);
            sum = sum -candidates[i];
            result_temp.pop_back();
        }
    }
};