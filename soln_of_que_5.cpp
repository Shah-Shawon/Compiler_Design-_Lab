/*
Build a lexical analyzer implementing the following regular expressions:
Float variable = (a-hA-Ho-zO-Z)(a-zA-Z0-9)*
Float Number = 0.(0-9)(0-9)|(1-9)(0-9)*.(0-9)(0-9)
Double Number = 0.(0-9)(0-9)(0-9)+|(1-9)(0-9)*.(0-9)(0-9)(0-9)+
Invalid Input or Undefined = Otherwise
*/

#include<bits/stdc++.h>
using namespace std;

bool isVariable(string s){
    if(s.size()==0) return false;
    if(!(tolower(s[0])>='a' && tolower(s[0])<='h')and !(tolower(s[0])>='o' && tolower(s[0])<='z')) return false;
    int n = s.size();

    for(int i=1;i<n;i++){
        if(isalnum(s[i])) continue;
        else return false;
    }
    return true;
}

int isFloatOrDouble(string s)   {
    if(!isdigit(s[0])) return false;
    int n = s.size();
    int cnt = 0;
    for(char ch : s){
        if(ch=='.') cnt++;
        else if(!isdigit(ch)) return false;
    }
    if(cnt>1 or cnt ==0) return false;
    cnt = 0;
    if(s[0]=='0' and s[1] !='.') return false;
    for(int i = n-1; i>=0;i--){
        if(s[i]=='.') {
            break;
        }else{
            cnt++;
        }
    }
    return cnt;
}
int main(){
    freopen("que5.txt","r",stdin);
    string word;
    while(getline(cin,word)){
        if(isVariable(word)){
            cout<<word<<" : is variable"<<endl;
        }else if(isFloatOrDouble(word)==2){
            cout<<word<<" : is float"<<endl;
        }else if(isFloatOrDouble(word)>2){
            cout<<word<<" : is double"<<endl;
        }else{
            cout<<word<<" : is Undefiend!"<<endl;
        }
    }
}