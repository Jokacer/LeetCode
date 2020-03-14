class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())return 0;
        int len=nums.size();
        vector<int >lis;
        lis.push_back(nums[0]);
        for(int i=0;i<len;++i){
            if(lis.back()<nums[i])lis.push_back(nums[i]);
            else{
                vector<int>::iterator ite=lower_bound(lis.begin(),lis.end(),nums[i]);
                *ite=nums[i];
            }
        }
        return lis.size();
    }
};
