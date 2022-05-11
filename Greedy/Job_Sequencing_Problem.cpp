/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution 
{
    public:
    
    
    // comparator function to sort the jobs
    // sorting the jobs with higher profit first
    static bool cmp(Job j1, Job j2)
    {
        if(j1.profit > j2.profit)
            return true;
        else if(j1.profit < j2.profit)
            return false;
        else
        {
            return j1.dead >= j2.dead;
        }
    }
    
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        vector<int>deadline(101,0);
        int j = 1;
        for(int i = 0; i<n; i++)
        {
            for(int j = arr[i].dead; j>=1; j--)
            {
                if(deadline[j]==0)
                {
                    deadline[j] = arr[i].profit;
                    break;
                }
            }
        }
        int num = 0, sum = 0;
        for(int i = 1; i<101; i++)
        {
            if(deadline[i]>0)
            num++;
            sum += deadline[i];
        }
        vector <int> res;
        res.push_back(num);
        res.push_back(sum);
        return res;
    } 
};
