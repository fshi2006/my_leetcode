class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
        x = 1/x;
        int index , reduce=abs(n);
        double sum = 1 , sum_ = x;
        while(reduce > 0)
        {
            if(reduce %2 == 1)
            {
                sum = sum *sum_;
            }
            sum_ *= sum_;
            reduce = reduce/2;
        }
        return sum;
    }
};