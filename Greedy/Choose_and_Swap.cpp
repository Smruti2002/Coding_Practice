// https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1

class Solution{
public:
    string chooseandswap(string s){
        int n = s.length();
        vector<int> arr(26,0);
        for(int i = 0; i<n; i++)
        {
            arr[s[i]-'a'] = 1;
        }
        bool temp = false;
        char s1='a',s2='a';
        int j;
        for(int i = 0; i<n; i++)
        {
            char ch = s[i];
            for(j = 0; j<(s[i]-'a'); j++)
            {
                if(arr[j]== 1)
                {
                    temp = true;
                    break;
                }
            }
            arr[s[i]-'a'] = 0;
            if(temp==true)
            {
                s1 = s[i];
                s2 = (char)(j+'a');
                break;
            }
        }
        for(int i = 0; i<n; i++)
        {
            if(s[i]==s1)
                s[i] = s2;
            else if(s[i]==s2)
                s[i] = s1;
        }
        return s;
    }
    
};
