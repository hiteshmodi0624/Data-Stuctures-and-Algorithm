#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool check(char a,char b){
    if(a=='^')
        return false;
    if(b=='*'||b=='/'||b=='^'||a=='+'||a=='-')
        return true;
    else
        return false;
}
string preflix(string a){
    string res="";
    stack<char>s;
    for(char x:a){
        if((x>='a'&&x<='z')||(x>='1'&&x<='9')||(x>='A'&&x<='Z'))
            res=res+x;
        else if (x==')')
            s.push(x);
        else if (x=='('){
            while(s.top()!=')'){
                res=res+s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            if(s.empty()||s.top()==')'||check(s.top(),x))
                s.push(x);
            else{
                while(s.empty()==false&&s.top()!=')'&&check(s.top(),x)==0){
                    res=res+s.top();
                    s.pop();
                }
                s.push(x);
            }
        }
    }
    while(s.empty()==false){
        res+=s.top();
        s.pop();
    }
    return res;
}
string topreflix(string s){
    reverse(s.begin(),s.end());
    s=preflix(s);
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    string inflix="x+y/z-w*u";
    cout<<inflix<<endl;
    cout<<topreflix(inflix);
}