class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> tmp_result;
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i){
                tmp_result.push_back(1);
                }else{
                tmp_result.push_back(result[i-1][j-1]+result[i-1][j]);}
            }
            result.push_back(tmp_result);
            for(int j=0;j<tmp_result.size();j++)
            cout<<tmp_result[j];
            cout<<endl;
            tmp_result.clear();
        }
        return result;
    }
};