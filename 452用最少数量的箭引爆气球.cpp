class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]<b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        int result = 1;
        int left=-1,right=INT_MAX;
        sort(points.begin(),points.end(),cmp);
        for(vector<int> &tmp:points)
        {
            if(tmp[0]<right);
            {
                left=tmp[0];
                right=tmp[1]<right?tmp[1]:right;
            }
            if(tmp[0]>right)
            {
                result++;
                left=tmp[0];
                right=tmp[1];
            }
        }
        return result;
    }
};