#include <iostream>
#include <unordered_map>
using namespace std;
void permute(string str,int l,int r){
    if(l==r){
        cout<<str<<endl;
    }
    for(int i=l;i<=r;i++){
        swap(str[l],str[i]);
        permute(str,l+1,r);
        swap(str[l],str[i]);
    }
}
void permute_with_no_AB_substring_naive(string str,int l,int r){
    if(l==r){
        if(str.find("AB")==string::npos)
            cout<<str<<endl;
    }
    for(int i=l;i<=r;i++){
        swap(str[l],str[i]);
        permute_with_no_AB_substring_naive(str,l+1,r);
        swap(str[l],str[i]);
    }
}
bool isSafe(string str,int l,int i,int r){
    if(l!=0&&str[l-1]=='A'&&str[i]=='B')
        return false;
    if(r==l+1&&str[l]=='B'&&str[i]=='A')
        return false;
    return true;
}
void permute_with_no_AB_substring_backtracking(string str,int l,int r){
    if(l==r)
        cout<<str<<endl;
    for(int i=l;i<=r;i++){
        if(isSafe(str,l,i,r)){
            swap(str[l],str[i]);
            permute_with_no_AB_substring_backtracking(str,l+1,r);
            swap(str[l],str[i]);
        }
    }
}
int main(){
    string str="ABC";
    permute_with_no_AB_substring_backtracking(str,0,str.length()-1);
}