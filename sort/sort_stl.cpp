#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<numeric>
#include<algorithm>

using namespace std;
struct co{
    int x,y;
};
bool grx(co p1,co p2){
    return(p1.x>p2.x);
}
bool compare(int x,int y){
    return(x%10>y%10);
}
int main(){
    int arr[]={22,36,19,24};
    vector<int> vect(arr,arr+4);
    sort(arr,arr+4);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr,arr+4,compare);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr,arr+4,greater<int>());
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(vect.begin(),vect.end());
    for(int i=0;i<4;i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    co pt[]={{3,10},{2,20},{7,30}};
    sort(pt,pt+3,grx);
    for(int i=0;i<3;i++){
        cout<<"{"<<pt[i].x<<","<<pt[i].y<<"} ";
    }
    
}
 