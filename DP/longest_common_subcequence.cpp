#include <iostream>
#include <vector>
using namespace std;


int LCS_memoriation(string s1,string s2,int i,int j,vector<vector<int> >&memo){
    if(i<0||j<0)
        return 0;
    if(memo[i][j]==-1){
        if(s1[i]==s2[j])
            memo[i][j]=LCS_memoriation(s1,s2,i-1,j-1,memo)+1;
        else memo[i][j]=max(LCS_memoriation(s1,s2,i-1,j,memo),LCS_memoriation(s1,s2,i,j-1,memo));
    }
    return memo[i][j]; 
}
int LCS_tabulation(string s1,string s2){
    int memo[s1.length()+1][s2.length()+1];
    for(int i=0;i<=s1.length();i++)
        memo[i][0]=0;
    for(int i=0;i<=s2.length();i++)
        memo[0][i]=0;
    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if(s1[i-1]==s2[j-1])
                memo[i][j]=memo[i-1][j-1]+1;
            else
                memo[i][j]=max(memo[i][j-1],memo[i-1][j]);
        }
    }
    return memo[s1.length()][s2.length()];
}
int LCS_tabulation_optimised(string s1,string s2){
    int memo[2][s2.length()+1];
    for(int i=0;i<=s2.length();i++)
        memo[0][i]=0;
    memo[1][0]=0;
    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if(s1[i-1]==s2[j-1])
                memo[i%2][j]=memo[(i+1)%2][j-1]+1;
            else
                memo[i%2][j]=max(memo[i%2][j-1],memo[(i+1)%2][j]);
        }
    }
    cout<<endl;
    for(int i=1;i<=s2.length();i++){
        if(memo[s1.length()%2][i]-memo[s1.length()%2][i-1])
            cout<<s2[i-1];
    }
    cout<<endl;
    return memo[s1.length()%2][s2.length()];
}
int main(){
    string s1="AGGTABCDEDS",s2="GXTXAYBCED";
    vector<vector<int> >memo(s1.length(),vector<int>(s2.length(),-1));
    cout<<LCS_memoriation(s1,s2,s1.length()-1,s2.length()-1,memo)<<endl;
    cout<<LCS_tabulation(s1,s2);
    cout<<LCS_tabulation_optimised(s1,s2);

}

 