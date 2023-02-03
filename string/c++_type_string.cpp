#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <list>
#include<numeric>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;
int main(){
    string str="geeksforgeeks";
    int count[26]={0};
    for (int i=0;i<str.length();i++)
        count[str[i]-'a']++;
    for(int i=0;i<26;i++){
        if(count[i])
            cout<<char(i+'a')<<":"<<count[i]<<" ";
    }
    cout<<endl;
    str="gfg";
    cout<<str<<endl;
    str+="xyz";
    cout<<str<<endl;
    cout<<str.substr(1,2)<<endl;
    cout<<str.find("gx")<<endl;
    // find returns index of the first occurance of gx
    cout<<str.find("gdx")<<endl;
    cout<<str.length()<<endl;
    string y="gfgxyz";
    cout<<(str==y);
    cout<<(str>=y);
    cout<<(str<=y)<<endl;

    for(int i=0;i<str.length();i++)
        cout<<str[i];
    cout<<endl;
    for(char x:str)
        cout<<x;
    cout<<endl;
    cout<<"Input 2 full names separated by space:";
    cin>>str;
    // only saves first name, until space
    cout<<str<<endl;
    getline(cin,y);
    cout<<y;
    getline(cin,y,'a');
    cout<<y;
    // will stop at a

}
 