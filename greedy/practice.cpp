#include <iostream>

using namespace std;
bool mycomp(pair<int,int> x,pair<int,int> y){
    return x.second<y.second;
}
int main(){
    pair<int,int>p[]={make_pair(1,3),make_pair(2,4),make_pair(3,8),make_pair(10,11)};
    sort(p,p+4,mycomp);
    int r=1,x=p[0].second;
    for(int i=1;i<4;i++){
        if(p[i].first>=x){
            r++;
            x=p[i].second;
        }
    }
    cout<<r;
}
 