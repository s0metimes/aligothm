#include<stdio.h>
#include<string>
#include<sstream>

using namespace std;

#define MAX 50

int getPlusResult(string s) {
    int result = 0;
    istringstream ss(s);
    string stringBuffer;
    while (getline(ss, stringBuffer, '+')) {
        result += stoi(stringBuffer);
    }

    return result;
}

int main(int argc, char **argv) {
    char s[MAX];
    scanf("%s", s);
    int result = 0;
    bool isFirst = true;
    
    string str(s);
        
    istringstream ss(str);
    string stringBuffer;
    while(getline(ss, stringBuffer, '-')) {
        if(isFirst) {
            result = getPlusResult(stringBuffer);
            isFirst = false;
        }
        else
            result -= getPlusResult(stringBuffer);
    }

    printf("%d\n", result);

    return 0;
}