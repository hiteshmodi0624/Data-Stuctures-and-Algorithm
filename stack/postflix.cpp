#include <iostream>
#include <stack>
#include <vector>
#include<math.h>
using namespace std;
int eval(string s){
    stack<int>st;
    for(int i=0;i<s.length();i++){
        string res="";
        int x;
        if(s[i]==' ')continue;
        if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'||s[i]=='^'){ 
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(s[i]=='+')st.push(b+a);
            else if(s[i]=='^')st.push(pow(b,a));
            else if(s[i]=='/')st.push(b/a);
            else if(s[i]=='*')st.push(b*a);
            else if(s[i]=='-')st.push(b-a);
            continue;
        }
        while(s[i]>='0'&&s[i]<='9'){
            res+=s[i];
            i++;
        }
        i--;
        st.push(stoi(res));
    }
    return st.top();
}
int main(){
    string postflix="231*+9-";
    cout<<eval(postflix);
}
        