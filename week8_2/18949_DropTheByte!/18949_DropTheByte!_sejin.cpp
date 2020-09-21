#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int charToHex(char c){
    if (c >= 0x30 && c <=0x39)
        return (int)(c-0x30);
    else
        return (int)(c-0x61+10);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;cin>>str;
    string::iterator it = str.begin();
    int N; cin>>N;
    
    while(N--){
        string type; cin>>type;
        unsigned long long size=0,value=0;
        if(!type.compare("char")){
            size= 2;
            for(int i = size; i >0; i--){
                value += charToHex(*it)*(unsigned long long)(pow(16,i-1));
                it++;
            }
        }
        else if(!type.compare("int")){
            size=8;
            for(int i = size; i >0; i--){
                value += charToHex(*it)*(unsigned long long)(pow(16,i-1));
                it++;
            }
        }            
        else{//ทีที
            size=16;
            for(int i = size; i >0; i--){
                value += charToHex(*it)*(unsigned long long)(pow(16,i-1));
                it++;
            }
        }
        cout<< value<< ' ';
    }
}
        
