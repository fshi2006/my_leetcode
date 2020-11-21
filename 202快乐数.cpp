class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> happy_hash;
        while(1){
            int sum = HappySum(n);
            if(sum == 1) return true;
            if(happy_hash.count(n)) {return false;}
            else happy_hash.insert(n);
            n = sum;
        }
    }

    int HappySum(int x)
    {
        int sum = 0;
        while(x)
        {
            sum+=pow((x%10),2);
            x/=10;
        }
        return sum;
    }
};