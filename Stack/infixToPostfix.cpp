#include<bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c == '^'){
        return 3;
    }else if(c == '*' || c=='/'){
        return 2;
    }else{
        return 1;
    }
}

string infixToPostfix(string s){
    stack<char> a;
    string ans;
    for(int i=0;i<s.length();i++){
        if((s[i] >= 'a' && s[i]<='z') || (s[i] >= 'A' && s[i]<='Z')){
            ans+=s[i];
        }else if(s[i] == '('){
            a.push(s[i]);
        }else if(s[i] == ')'){
            while(a.top()!='('){
                ans+=a.top();
                a.pop();
            }
            if(!a.empty())
                a.pop();
        }else{
            if( !a.empty() && prec(a.top())>prec(s[i])){
                ans+=a.top();
                a.pop();
                a.push(s[i]);
            }else{
                a.push(s[i]);
            }
        }
    }
    while(!a.empty()){
        ans+=a.top();
        a.pop();
    }
    return ans;
}

int main(){
    cout<<infixToPostfix("(a-b/c)*(a/k-l)");
    return 0;
}