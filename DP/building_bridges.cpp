#include <iostream>
#include <vector>
using namespace std;
struct bridges{
    int x,y;
};
bool sorting(bridges a,bridges b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int maxbridges(bridges b[],int n){
    vector<int>v;
    v.push_back(b[0].y);
    for(int i=1;i<n;i++){
        if(b[i].y>v.back())
            v.push_back(b[i].y);
        else
            *upper_bound(v.begin(),v.end(),b[i].y)=b[i].y;
    }
    return v.size();
}
int main(){
    bridges b[]={{1,1},{1,3},{8,1},{1,2},{4,3},{3,4},{2,6},{6,7},{7,8},{5,5}};
    int n=sizeof(b)/sizeof(b[0]);
    sort(b,b+n,sorting);
    cout<<maxbridges(b,n);
}