class Solution {
    int dp[301][301];
    
    
    int helper(vector<int> &arr, int st, int end){
        if(end-st==1)return 0;
        
        if(dp[st][end]!=-1)return dp[st][end];
        
        int ans=0;
        for(int m=st+1; m<end; m++){
            int cost=(arr[st]*arr[m]*arr[end]) + helper(arr, st, m)+helper(arr,m, end);
            
            ans=max(ans, cost);
        }
        return dp[st][end]=ans;
    }
public:
    int maxCoins(int n, vector<int> &arr) {
           
        memset(dp, -1, sizeof(dp));
        vector<int>temp(n+2);
        temp[0]=1; temp[n+1]=1;
        
        for(int i=1; i<=n; i++){
            temp[i]=arr[i-1];
        }
       
        
        return helper(temp, 0, n+1);
    }
};
