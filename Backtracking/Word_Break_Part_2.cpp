// https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

class Solution{
public:

    vector <string> res;
    
    bool search(string s, vector<string> &dict, int n)
    {
        for(int i = 0; i<n; i++)
        {
            if(dict[i]==s)
            return true;
        }
        return false;
    }
    
    void solve(int n,vector<string> &dict,int i,int j,string sent,string s)
    {
        string copy = sent;
        if(s.length()-1==j)
        {
            string temp = s.substr(i,j-i+1);
            if(search(temp,dict,n))
            {
                sent = sent + temp;
                res.push_back(sent);
            }
            return;
        }
        string temp = s.substr(i,j-i+1);
        if(search(temp,dict,n))
        {
            sent = sent + temp + " ";
            solve(n,dict,j+1,j+1,sent,s);
            sent = copy;
            solve(n,dict,i,j+1,sent,s);
        }
        else
        {
            solve(n,dict,i,j+1,sent,s);
        }
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        solve(n,dict,0,0,"",s);
        return res;
    }
};
