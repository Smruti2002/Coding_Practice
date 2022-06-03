// https://leetcode.com/problems/count-of-smaller-numbers-after-self/submissions/

/*
    Used the kth segment tree method
    converted all the numbers from (-1e4,1e4) to (0,2e4) as the negative numbers 
    were giving problems.
    
*/

class Solution {
public:
    
    int tr[80080]; 
    int L = 0;
    int R = 20000;
    void update(int index, int l , int r, int val)
    {
        if(l>r)
            return;
        if(val<l || val>r)
            return;
        if(l==r)
        {tr[index]++;return ;}
        int mid = (l+r)/2;
        if(val<=mid)
            update(2*index,l,mid,val);
        else
            update(2*index+1,mid+1,r,val);
        tr[index] = tr[2*index] + tr[2*index+1];
    }
    
    int query(int index,int l, int r, int val)
    {
        if(l>r)
            return 0;
        if(val<=l)
            return  0;
        if(r<val)
            return tr[index];
        int mid = (l+r)/2;
        return query(2*index,l,mid,val)+query(2*index+1,mid+1,r,val);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        memset(tr,0,sizeof(tr));
        int n = nums.size();
        int k = 10000;
        for(int i = 0; i<n; i++)
        {
            nums[i]+= k;
        }
        vector<int> res(n);
        res[n-1] = 0;
        update(1,L,R,nums[n-1]);
        for(int i = n-2; i>=0; i--)
        {
            res[i] = query(1,L,R,nums[i]);
            update(1,L,R,nums[i]);
        }
        return res;
    }
};
