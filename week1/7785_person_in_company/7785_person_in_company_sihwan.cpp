#include<stdio.h>
#include<string.h>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool comp(string s1, string s2) {
    return strcmp(s1.c_str(), s2.c_str()) < 0;
}

void lower(string str) {
    for(int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char **argv) {
    int i, j, n, size;
    char name[6], enterleave[6];
    string tmp;
    unordered_map<string, int> m;
    unordered_map<string, int>::iterator it;
    string names[100000];
    
    
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%s %s", name, enterleave);
        
        if(strcmp(enterleave, "enter") == 0)
            m.insert(make_pair(name, 1));
        else if(strcmp(enterleave, "leave") == 0)
            m.erase(name);
    }

    size = 0;
    for(it = m.begin(); it != m.end(); it++)
        names[size++] = it->first;
        lower(names[size-1]);
    
    sort(names, names+size-1, comp);
    
    for(i = size-1; i >= 0; i--) {
        printf("%s\n", names[i].c_str());
    }

    return 0;
}