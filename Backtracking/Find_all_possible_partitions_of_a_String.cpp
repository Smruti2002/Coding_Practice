// https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1/

/*
    lets take the example of "madam"
    we go first to index i = 0;
    then we check every substring starting from i=0, whether it is a pal or not
    if it is a palindrome then (i to j), then we recur by passing j+1 as index
    
    In case of example
    at i = 0::
    'm' -> 'a' -> 'd' -> 'a' -> 'm'
        -> "ada" -> 'm'
        
    
*/



class Solution {
  public:
  
    vector<vector<string>> res;
    
    bool pal(string s)
    {
        int i = 0;
        int j = s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    
    void solve(string s,int index, vector<string> part)
    {
        if(index>=s.length())
        {
            res.push_back(part);
            return;
        }
        vector <string> copy = part;
        for(int i = index; i<s.length(); i++)
        {
            if(pal(s.substr(index,i-index+1)))
            {
                part.push_back(s.substr(index,i-index+1));
                solve(s,i+1,part);
                part.clear();
                part = copy;
            }
        }
        
    }
  
    vector<vector<string>> allPalindromicPerms(string S) {
        
        vector<string> part;
        solve(S,0,part);
        return res;
        
    }
};
