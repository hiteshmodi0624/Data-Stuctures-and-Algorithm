#include <iostream>

using namespace std;
bool mycomp(pair<int,int> x,pair<int,int> y){
    return (x.second/x.first)>(y.second/y.first);
}
int main(){
    pair<int,int>p[]={make_pair(50,600),make_pair(20,500),make_pair(30,400)};
    int cap=70,n=3;
    sort(p,p+n,mycomp);
    int i=0,res=0;
    for(int i=0;i<n&&cap!=0;i++){
        if(cap>=p[i].first){
            cap-=p[i].first;
            res+=p[i].second;
        }
        else{
            res+=p[i].second*((float)cap/(float)p[i].first);
            break;
        }
    }
    cout<<res;
}
 