int minJumps_dp(int c[],int n){
//     int dp[n];
//     dp[n-1]=0;
//     for(int i=n-2;i>=0;i--){
//         dp[i]=INT_MAX;
//         for(int j=1;j<=c[i];j++){
//             if(i+j<=n-1){
//                 dp[i]=min(dp[i+j]+1,dp[i]);
//             }
//         }
//     }
//     return dp[1];
// }