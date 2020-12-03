class Solution {
public:
    int countPrimes(int n)
{
    int a[n+1]; 
    int count = 0;
    for(int i = 2; i < n; i++)
        a[i] = 1;
    
    for(int i = 2; i < n; i++)
        if(a[i]==1)
        {
            count++;
            for(int j = 2 * i; j < n; j += i)
                a[j] = 0;
        }
    
    return count;
}
};