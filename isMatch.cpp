class Solution {
public:
    bool isMatch(string s, string p) {
        int slength=s.size();
        int plength=p.size();
        vector<vector<bool>>dp(plength+1,vector<bool>(slength+1,false));
        dp[0][0]=true;
        for(int i=2;i<=plength;++i){
            if(p[i-1]=='*')dp[i][0]=dp[i-2][0];
        }
        for(int i=1;i<=plength;++i){
            for(int j=1;j<=slength;++j){
                if(p[i-1]=='*'){
                    dp[i][j]=dp[i-2][j]||(dp[i][j-1]&&(s[j-1]==p[i-2]||p[i-2]=='.'));
                }
                else dp[i][j]=dp[i-1][j-1]&&(s[j-1]==p[i-1]||p[i-1]=='.');
            }
        }
        return dp[plength][slength];
    }
};
