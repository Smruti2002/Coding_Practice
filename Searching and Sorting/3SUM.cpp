// https://leetcode.com/problems/3sum/submissions/ 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> temp(3);
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            int sum = -nums[i];
            temp[0] = nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k && (i==0 || nums[i]!=nums[i-1])){
                if(sum==nums[j]+nums[k]){
                    temp[1]=nums[j];
                    temp[2]=nums[k];  
                    v.push_back(temp);
                    while(j<k && nums[j]==nums[j+1])j++;
                    while(j<k && nums[k]==nums[k-1])k--;
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k] < sum){
                    j++;
                }
                else
                    k--;
            }
        }
        return v;
    }
};
