class Solution {
public:
    int dp[20];
    int f(int n){
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        int sum = 0;
        for(int k=1; k<=n; k++){
            sum = sum + f(k-1)*f(n-k);
        }
        return dp[n] =  sum;
    }
    int numTrees(int n) {
        memset(dp, 0, sizeof dp);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            for(int k=1; k<=i; k++){
                dp[i] = dp[i] + dp[k-1]*dp[i-k];
            }
        }
        return dp[n];
    }
};