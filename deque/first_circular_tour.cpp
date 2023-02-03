#include <iostream>
#include <deque>
using namespace std;
struct petrolPump{
    int petrol;
    int distance;
};
int tour(petrolPump p[],int n){
        int pr=0,temp=0,k=0;
        for(int i=0;i<n;i++){
            temp+=p[i].petrol-p[i].distance;
            if(temp<0){
                pr+=temp;
                temp=0;
                k=i+1;
            }
        }
        return (pr+temp<0)?-1:k;
    }
int main(){
    int n=4;
    petrolPump p[4];
    p[0].petrol=4;
    p[1].petrol=6;
    p[2].petrol=7;
    p[3].petrol=4;
    p[0].distance=6;
    p[1].distance=5;
    p[2].distance=3;
    p[3].distance=5;
    cout<<tour(p,n);
}
 