// https://practice.geeksforgeeks.org/problems/largest-number-with-given-sum-1587115620/1

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        string s ="";
        int k = 0;
        if(9*n < sum)
            return "-1";
        while(sum>9)
        {
            s = s + '9';
            sum -= 9;
            k++;
        }
        if(sum>0)
        {
            s = s + (char)(sum+'0');
            k++;
        }
        for(int i = 1; i <=(n-k); i++)
            s = s+ '0';
        return s;
    }
};
