#include <iostream>
#include <string>
#include <cmath>
#define MAX 64

using namespace std;

char temp[MAX+2][MAX+2];
string b[MAX+2][MAX+2];

void qt(int n);
string customComp(int k, int i, int j) ;

int main(int argc, char const *argv[])
{
    int n, i, j;
    cin>>n;

    for(i = 1; i <= n; i++) 
        for(j = 1; j <= n; j++)
            cin>>temp[i][j];

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            b[i][j] = temp[i][j];
    
    cout<<"****"<<endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            cout<<temp[i][j];
        cout<<endl;
    }

    cout<<"****"<<endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            cout<<b[i][j];
        cout<<endl;
    }
    cout<<"****"<<endl;
    qt(n);
    cout<<b[n][n]<<endl;
    return 0;
}

void qt(int n) {
    int k, i, j;
    for(k = 2; k <= n; k*=2) {
        for(i = 1; i <= n/k; i++) {
            for(j = 1; j <= n/k; j++) {
                b[k*i][k*j] = customComp(k, i, j);
                cout<<"****"<<endl;
                for(int i = 1; i <= n; i++) {
                    for(int j = 1; j <= n; j++)
                        cout<<b[i][j];
                    cout<<endl;
                }
                cout<<"****"<<endl;
            }
        }
    }            
}

string customComp(int k, int i, int j) {
    string lt = b[k*i - k/2][k*j - k/2];
    string rt = b[k*i - k/2][k*j];
    string lb = b[k*i][k*j - k/2];
    string rb = b[k*i][k*j];
    cout<<"function : customComp("<<k<<", "<<i<<", "<<j<<")"<<endl;
    cout<<"["<<k*i - k/2<<"]"<<"["<<k*j - k/2<<"]"<<" and "<<"["<<k*i - k/2<<"]"<<"["<<k*j<<"]"<<" and "<<"["<<k*i<<"]"<<"["<<k*j - k/2<<"]"<<" and "<<"["<<k*i<<"]"<<"["<<k*j<<"]"<<endl;
    if(lt.compare(rt) == 0 && lt.compare(lb) == 0 && lt.compare(rb) == 0) {
        if(lt.compare("1") == 0) return "1";
        else if(lt.compare("0") == 0) return "0";
    }
    return "("+lt+rt+lb+rb+")";
}
