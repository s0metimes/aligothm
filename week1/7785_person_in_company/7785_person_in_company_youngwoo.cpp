#include <stdio.h>
#include <map>
#include <utility>
#include <string>
#include <iostream>

using namespace std;
map<string, string> m;

int main(int argc, char const *argv[])
{
    int n;
    
    scanf("%d", &n);

    while(n--) {
        char move[6];
        char name[6];
        scanf("%s %s", name, move);
        m[name] = move;
    }
    map<string, string>::reverse_iterator it;
    for(it = m.rbegin(); it != m.rend(); it++) {
        if(it->second.compare("enter") == 0) 
            printf("%s\n", it->first.c_str());
            // printf("%s\n", it->first);
    }
    return 0;
}
