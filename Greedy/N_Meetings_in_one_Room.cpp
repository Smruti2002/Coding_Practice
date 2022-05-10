
// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        int res = 1;
        vector<pair<int,int>> meet;
        for(int i = 0; i<n; i++)
        {
            meet.push_back({end[i],start[i]});
        }
        sort(meet.begin(),meet.end());
        int prev_time = meet[0].first;
        for(int i = 1; i<n; i++)
        {
            if(meet[i].second>prev_time)
            {
                res++;
                prev_time = meet[i].first;
            }
        }
        return res;
    }
};
