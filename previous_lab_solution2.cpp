/* Build a lexical analyzer implementing the following regular expressions:
a)Integer variable = (i-nI-N)(a-zA-Z0-9)* 
b)ShortInt Number = (1-9)|(1-9)(0-9)|(1-9)(0-9)(0-9)|(1-9)(0-9)(0-9)(0-9) 
c)Double Number = 0.(0-9)(0-9)(0-9)+|(1-9)(0-9)*.(0-9)(0-9)(0-9)+ 
d) Character variable =ch_(a-zA-Z0-9)(a-zA-Z0-9)* 
Invalid Input or Undefined = Otherwise
*/
#include<bits/stdc++.h>
using namespace std;

bool isIntVariable(string word){
    if(word.empty())     return false;
    if(tolower(word[0])<'i' || tolower(word[0])>'n')    return false;
    for(int i =1;i<word.size();i++){
        if(!isalnum(word[i]))   return false;
    }
    return true;
}

bool isShortInt(string word){
    if(word.empty() || word.size()>4)     return false;
    if(word[0]!='0' || !isdigit(word[0]))   return false;
    for(int i=1;i<word.size();i++){
        if(!isdigit(word[i]))   return false;
    }
    return true;
}
bool isCharVariable(string word){
    if(word.size()<4)     return false;
    if(word[0]!='c' || word[1]!='h'|| word[2]!='_') return false;
    for(int i=3;i<word.size();i++){
        if(!isalnum(word[i]))   return false;
    }
    return true;
}

bool isDoubleNumber(string word){
    if(!isdigit(word[0]))   return false;
    int n = word.size();
    int cnt = 0;
    for(char ch:word){
        if(ch=='.') cnt++;
        else if(!isdigit(ch))   return false;
    }
    if(cnt==0 || cnt>1)    return 0;
    cnt= 0;
    if(word[0]=='0' && word[1]!='.')  return false;
    return true;
}


int main(){
    freopen("que_lab_exmple2.txt","r",stdin);
    string word;

    while(getline(cin, word)) {
        if(isIntVariable(word)){
        cout<<word<<" : interger variable."<<endl;
        }else if(isShortInt(word)){
            cout<<word<<" : short interger number."<<endl;
        }else if(isCharVariable(word)){
            cout<<word<<" : charcter variable."<<endl;
        }else if(isDoubleNumber(word)){
            cout<<word<<" : double number."<<endl;
        }else{
            cout<<word<<" : invalid input or undefined"<<endl;
        }
    }
}