#include <iostream>

using namespace std;
bool mycomp(pair<int,int> x,pair<int,int> y){
    return x.second>y.second;
}
int main(){
    pair<int,int>p[]={make_pair(4,50),make_pair(1,5),make_pair(1,20),make_pair(5,10),make_pair(5,80)};
    int n=sizeof(p)/sizeof(p[0]);
    sort(p,p+n,mycomp);
    int i=0,res=0;
    int z=1;
    int r[5];
    r[0]=r[1]=r[2]=r[3]=r[4]=0;
    for(int i=0;i<n;i++){
        if(r[p[i].first-1]==0){
            res+=p[i].second;
            r[p[i].first-1]=p[i].second;
        }
        else{
            int j=p[i].first-1;
            while(j>=0&&(r[j]!=0))
                j--;
            if(j>=0){
                res+=p[i].second;
                r[j]=p[i].second;
            }
        }
    }
    for(int i=0;i<5;i++)
        cout<<r[i]<<" ";
    cout<<res;
}
 