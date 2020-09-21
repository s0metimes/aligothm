#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX_LENGTH_NAME 10
#define MAX_LIST 100000
#define MAX_DISTENCE 20000

using namespace std;

typedef struct personData{
    string name;
    char gender;
    int dist;
} Data;

char name[MAX_LENGTH_NAME+1];
char prefer[3];
vector<Data> list(MAX_LIST+1);
vector<string> result;

int main(int argc, char const *argv[])
{
    int N, i;
    int limit;
    cin >> name >> prefer >> limit;
    cin >> N;
    
    for(i = 0; i < N; i++) 
        cin >> list[i].name >> list[i].gender >> list[i].dist;
    

    for(i = 0; i < N; i++) {
        if(list[i].dist > limit) continue;
        
        bool flag = false;
        for(int j = 0; j < 2; j++) 
            if(prefer[j] == list[i].gender)
                flag = true;

        if(flag) 
            result.push_back(list[i].name);
    }

    sort(result.begin(), result.end());

    if(result.empty()) cout << "No one yet\n";
    else for(auto str: result) cout << str << endl;
    return 0;
}