/*
Write a program to generate FIRST and FOLLOW sets using a given CFG.
*/
#include<bits/stdc++.h>
using namespace std;

map<char, vector<string>>grammar;
map<char, set<char>>first;
map<char, set<char>>follow;
vector<char>order; //order of the grammar

int main() {
    freopen("","r",stdin);
    string production;
    while(getline(cin,production)){
        grammar[production[0]].push_back(production.substr(3));
        if(find(order.begin(),order.end(),production[0])==order.end())
            order.push_back(production[0]);
    }
    //print grammar
    cout<<"____Grammar_____"<<endl;
    for(auto c:order){
        cout<<c<<"-> ";
        for(auto x : grammar[c]){
            cout<<x<<" | ";
        }cout<<endl;
    }
    //first calculation
    for(int i = order.size()-1;i>=0;i--){
        
    }
}