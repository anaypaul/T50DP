#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int LCS_1(string X, string Y, int m, int n){
    if(m==0 || n==0){
        return 0;
    }
    if(X[m-1] == Y[n-1]){
        return LCS_1(X,Y, m-1, n-1) + 1;
    }
    return max(LCS_1(X,Y, m-1, n), LCS_1(X,Y, m, n-1));
}

int LCS_dp(string X, string Y){
    int m = X.length();
    int n = Y.length();
    vector<vector<int> > dp(m+1, vector<int>(n+1,-1));
    for(int i = 0;i<m+1;i++){
        dp[i][0] = 0;
    }
    for(int j = 0;j<n+1;j++){
        dp[0][j] = 0;
    }
    for(int i = 1;i<m+1;i++){
        for(int j = 1;j<n+1;j++){
            if(X[i-1] == Y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    string X = "ABCBDAB";
    string Y = "BDCABA";
    cout<<"Maximum Length of longest common subsequence : "<<LCS_dp(X,Y)<<endl;
    return 0;
}