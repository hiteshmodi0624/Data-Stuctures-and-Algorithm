#include <iostream>
#include <vector>
using namespace std;
struct chain{
    int x,y;
};
bool sorting(chain a,chain b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int maxchain(chain b[],int n){
    vector<int>v;
    v.push_back(b[0].y);
    for(int i=1;i<n;i++){
        if(b[i].x>v.back())
            v.push_back(b[i].y);
        else{
            auto it=upper_bound(v.begin(),v.end(),b[i].y);
            if(it!=v.end())
                *it=b[i].y;
        }
    }
    return v.size();
}
int main(){
    chain b[]={{5,24},{39,60},{15,28},{27,40},{50,90}};
    int n=sizeof(b)/sizeof(b[0]);
    sort(b,b+n,sorting);
    cout<<maxchain(b,n);
}