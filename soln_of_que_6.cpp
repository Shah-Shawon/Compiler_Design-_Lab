/*
Build a lexical analyzer implementing the following regular expressions:
Character variable =ch_(a-zA-Z0-9)(a-zA-Z0-9)*
Binary variable = bn_(a-zA-Z0-9)(a-zA-Z0-9)* 
Binary Number = 0(0|1)(0|1)*
Invalid Input or Undefined = Otherwise
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input_of_que_6.txt","r",stdin);
    string word;
    while(getline(cin,word)){
        bool flag = true;
        if(word.size()>=4 and (word.substr(0,3)== "ch_" or word.substr(0,3)=="bn_")){
            for(int i=3;i<word.size();i++){
                if(!isalnum(word[i])){
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(word.substr(0,3)=="ch_"){
                    cout<<word<<" : Character Variable" << endl;
                }else{
                     cout<<word<<" : Binary Variable" << endl;
                }
            }
        }else if(word.size()>=2 and (word[0]=='0') and (word[1]=='0' or word[1]=='1')){
            for(int i = 2;i<word.size();i++){
                if(word[i]!='0' and word[i] !='1'){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<word<<" : Binary Number"<<endl;
            }
        }else{
            flag = false;
        }
        if(!flag){
            cout<<word<<" : Invalid input"<<endl;
        }
    }
}