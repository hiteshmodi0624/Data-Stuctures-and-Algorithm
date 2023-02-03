#include <iostream>
#include <stack>
#include <vector>
#include<math.h>
using namespace std;
int eval(string s){
    stack<int>st;
    for(int i=s.length()-1;i>=0;i--){
        string res="";
        int x;
        if(s[i]==' ')continue;
        if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'||s[i]=='^'){ 
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(s[i]=='+')st.push(a+b);
            else if(s[i]=='^')st.push(pow(a,b));
            else if(s[i]=='/')st.push(a/b);
            else if(s[i]=='*')st.push(a*b);
            else if(s[i]=='-')st.push(a-b);
            continue;
        }
        while(s[i]>='0'&&s[i]<='9'&&i>=0){
            res=s[i]+res;
            i--;
        }
        i++;
        st.push(stoi(res));
    }
    return st.top();
}
int main(){
    string postflix="+*10 2 3";
    cout<<eval(postflix);
}
        