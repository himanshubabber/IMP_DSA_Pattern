class Solution {
public:
    vector<vector<int>>dp;

    int solve(int i,int j,vector<int>&nums,int n){
        if(i>=n) return 0;
        
        if(dp[i][j+1]!=-1) return dp[i][j+1];

        int exc=solve(i+1,j,nums,n);

        int inc=0;
        if(j==-1 || j>=0 && nums[i]>nums[j]){
          inc=1+solve(i+1,i,nums,n);
        }

        return dp[i][j+1]=max(inc,exc);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // dp.assign(n+1,vector<int>(n+1,-1));
        // return solve(0,-1,nums,n);

        vector<int>temp;
        int len=0;

        for(int i=0;i<n;i++){
            if(temp.empty() || nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
               int l=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
               temp[l]=nums[i];
            }
        }

        return len;
    }
};
