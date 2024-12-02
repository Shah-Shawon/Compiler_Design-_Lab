/*
Write a program to implement a shift reducing parsing.
*/
#include<bits/stdc++.h>
using namespace std;

void shift(string stk,string ip,char c){
    cout<<stk<<"\t\t"<<ip<<"\t\t"<<"Shift "<<c<<endl;
}

void reduceTo(string stk, string ip,char a,char b){
    cout<<stk<<"\t\t"<<ip<<"\t\t"<<"Reduce to "<<a<<"->"<<b<<endl;
}

int main(){
    int n;
    cout << "Enter the number of Production Rule: ";
    cin >> n;
    cin.ignore();

    string gra_left[n],gra_right[n];

    for(int i = 0;i<n;i++){
        string temp;
        cout<<"Enter Production Rule "<<i+1<<" : ";
        getline(cin, temp);
        gra_left[i].push_back(temp[0]);
        for(int j = 3; j<temp.size();j++) gra_right[i].push_back(temp[j]);
    }
    cout<<"\n\nGiven Grammar is:\n";
    for(int i=0;i<n;i++){
        cout<<gra_left[i]<<"->"<<gra_right[i]<<endl;
    }

    string input;
    cout<<"Enter input String: ";
    cin>>input;

    string stk = "$";
    input.push_back('$');

    printf("\nStack\t\t Input \t\t\tActions\n");
     while(input !="$"){
        stk.push_back(input[0]);
        char ch = input[0];
        input.erase(input.begin());
        shift(stk,input,ch);

        for(int i=0;i<n;i++){
            bool reduce = false;
            if(stk.find(gra_right[i])<stk.length()){
                stk.erase(stk.find(gra_right[i]),stk.length());
                stk += gra_left[i];
                reduceTo(stk,input,gra_left[i][0],gra_right[i][0]);
                reduce = true;
            }
            if(reduce)  i = -1;
        }
     }
     input+=gra_left[0];
     if(stk==input){
        cout<<"ACCEPTED!"<<endl;
     }else{
        cout<<"REJECTED"<<endl;
     }
}