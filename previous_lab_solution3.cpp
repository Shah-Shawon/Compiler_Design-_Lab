/*Write a program to build a lexical analyzer implementing the following regular expressions. It takes a text as input from a file (e.g., input.txt) and display output in console mode:
Character variable =ch_(a-zA-Z0-9) (a-zA-Z0-9)*
Integer variable = (i-n|I-N)_(a-zA-Z0-9)(a-zA-Z0-9)*
Binary Number=0(0|1)(0/1)*
Integer Number = (1-9) (1-9)*
Invalid Input or Undefined = Otherwise*/

#include <bits/stdc++.h>
using namespace std;

bool isCharVariable(string word){
    if(word.size()<5)     return false;
    if(word[0]!='c' || word[1]!='h'|| word[2]!='_') return false;
    for(int i=3;i<word.size();i++){
        if(!isalnum(word[i]))   return false;
    }
    return true;
}

bool isIntVariable(string word) {
    if(word.size()<4)    return false;
    if(tolower(word[0])<'i' || tolower(word[0])>'n')    return false;
    if(word[1]!='_')    return false;
    for(int i=2;i<word.size();i++){
        if(!isalnum(word[i])){
            return false;
        }
    }
    return true;
}
//Binary Number=0(0|1)(0/1)*
bool isBinaryNumber(string word){
    if(word.size()<3)   return false;
    if(word[0]!='0')    return false;
    for(int i=1;i<word.size();i++){
        if(word[i]!='0'&& word[i]!='1'){
            return false;
        }
    }
    return true;
}
//Integer Number = (1-9) (1-9)*
bool isIntNum(string word){
    if(word.size()<2)   return false;
    for(char ch:word){
        if(ch=='0' || !isdigit(ch)){
            return false;
            break;
        }
    }
    return true;
}

int main() {
    freopen("que_lab_exmple3.txt","r",stdin);
    string word;
    while(getline(cin,word)){
        if(isCharVariable(word)){
            cout<<word<<" : character variable"<<endl;
        }else if(isIntVariable(word)){
            cout<<word<<" : Integer variable"<<endl;
        }else if(isBinaryNumber(word)){
            cout<<word<<" : Binary number."<<endl;
        }else if(isIntNum(word)){
            cout<<word<<" : Integer number."<<endl;
        }else{
            cout<<word<<": Invalid input"<<endl;
        }
    }
}