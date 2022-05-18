// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        long long int mod = 1e9+7;
        long long int curr = 2, prev = 1, temp;
        for(int i = 3; i<=n; i++)
        {
            temp = curr;
            curr = (curr + (i-1)*prev)%mod;
            
            prev = temp;
        }
        if(n==1)
            return 1;
        return (int)curr;
    }
};    
 
