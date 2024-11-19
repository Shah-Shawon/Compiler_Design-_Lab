/*
Write a program to recognize C++
 i) Keyword ii) Identifier iii) Operator iv) Constant
*/
#include<bits/stdc++.h>
using namespace std;

bool isKeyword(string x){
    vector<string> keywords = {
        "true","false",
        "or","and","xor",
        "for","if","else","else if","while","do while","break","continue",
        "int","float","double","bool","long","signed","unsigned",
        "char","string","void","auto","new","switch","main",
        "namespace","class","const","sizeof","typedef",
        "delete","nullptr"
    };
    for(int i=0;i<keywords.size();i++){
        if(keywords[i].compare(x)==0){
            return true;
        }
    }
    return false;
}

bool isOperator(string x){
    vector<string>operators = {
        "+","-","*","/","%",
        "==","!=","<",">","<=",">=",
        "&&","||","!",
        "&","|","!","^","<<",">>",
        "=","+=","-=","%=","&=","|=",
        "++","--",
        "?",":",
        ",",".",
        "->",
        "::"
    };
    for(int i=0;i<operators.size();i++){
        if(operators[i].compare(x)==0){
            return true;
        }
    }
    return false;
}

bool isIdentifier(string x){
    if(isdigit(x[0])) return false;
    for(char ch : x){
        if(ch != '_' and !isalnum(ch)) return false;
    }
    return true;
}

bool isStringConstant(string x){
    char ch = '"';
    if(x[0] == ch and x[x.size()-1]==ch){
        return true;
    }
}

bool is_constant(string x){
    int cnt = 0;
    for(char ch:x){
        if(ch =='.') cnt++;
    }
    if(cnt>1) return false;
    for(int i=0;x[i];i++){
        if(isdigit(x[i]) or x[i]=='.'){
            continue;
        }else return false;
    }
    return true;
}

int main(){
    freopen("input_of_que_7.txt","r",stdin);
    string word;
    while(getline(cin,word)){
        if(isKeyword(word)) cout<<word<<" is a Keyword"<<endl;
        else if(isOperator(word)) cout<<word<<" is an Operator\n";
        else if(isStringConstant(word)) cout<<word<<" is a String Constant\n";
        else if(isIdentifier(word)) cout<<word<<" is identifier\n";
        else if(is_constant(word)) cout<<word<<" is a Constant"<<endl;
        else cout<<word<<"is Invalid"<<endl;
    }
}