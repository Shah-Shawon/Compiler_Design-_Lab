/*Write a program to build a lexical analyzer implementing the following regular
expressions. It takes a text as input from a file (e.g., input.txt) and display output in console mode:
Integer variable = (i-n|I-N)(a-zA-Z 0-9)*
ShortInt Number = (1-9)|(1-9)(0-9)|(1-9)(0-9)(0-9)|(1-9)(0-9)(0-9)(0-9)
Longint Number = (1-9)(0-9)(0-9)(0-9)(0-9)+
Constant Integer (1)*(2)*... (9)*
Keyword = 1|12|123...|123456789 give me the c++ code for this problem*/
#include<bits/stdc++.h>
using namespace std;

bool isConstantInt(string word)  {
    if(word.empty())    return false;
    char ch = word[0];
    for(int i=1;i<word.size();i++) {
        if(word[i]!=ch) return false;
    }
    return true;
}

bool isKeyWord(const string& word) {
    string keyword = "123456789";
    size_t len = word.size();
    if (len == 0 || len > 9) return false; // Keywords are at most 9 digits long
    for (size_t i = 0; i < len; i++) {
        if (word[i] != keyword[i]) return false; // Match incremental sequence
    }
    return true;
}

// bool isKeyWord(const string& word) {
//     string keyword = "123456789";
//     size_t len = word.size();
//     if (len == 0 || len > 9) return false; // Keywords are at most 9 digits long
//     return word == keyword.substr(0, len);
// }

bool isIntegerVariable(string word){
    if(word.empty())    return false;
    if(tolower(word[0])<'i' || tolower(word[0])>'n')    return false;
    for(int i = 1;i<word.size();i++){
        if(!isalnum(word[i])) return false;
    }
    return true;
}

bool isShortIntNum(string word) {
    if(word.empty())    return false;
    if(word.size() >4)  return false;
    if(!isdigit(word[0]) || word[0]=='0')   return false;
    for(char ch : word) {
        if(!isdigit(ch))    return false;
    }
    return true;
}

bool isLongIntNum(string word) {
    if(word.empty())    return false;
    if(word.size() <4)  return false;
    if(!isdigit(word[0]) || word[0]=='0')   return false;
    for(char ch : word) {
        if(!isdigit(ch))    return false;
    }
    return true;
}

int main(){
    freopen("que_lab_exmple1.txt","r",stdin);
    string word;

    while (getline(cin, word)) {
        if(isConstantInt(word)){
            cout<<word<<" : Constant Integer"<<endl;
        }else if(isKeyWord(word)){
            cout<<word<<" : Keyword"<<endl;
        }else if(isIntegerVariable(word)){
            cout<<word<<" : Integer Variable"<<endl;
        }else if(isShortIntNum(word)){
            cout<<word<<" : Short Integer Number"<<endl;
        }else if(isLongIntNum(word)){
            cout<<word<<" : Long Integer Number"<<endl;
        }else{
            cout<<word<<" : Invalid Input or Undefined"<<endl;
        }
    }
}