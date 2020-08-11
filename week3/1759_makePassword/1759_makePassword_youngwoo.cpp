#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#define MAX 15
using namespace std;

vector<char> av;
vector<string> res;
int solution[MAX];
int len, num;
char mov[5] = {'a', 'e', 'i', 'o', 'u'};

void backTracking(int level);

int main(int argc, char const *argv[])
{
    char alpha;
    scanf("%d %d", &len, &num);
    
    for(int i = 0; i < num; i++) {  // 입력받기
        getchar();
        alpha = getchar();
        av.push_back(alpha);
    }
    sort(av.rbegin(), av.rend()); // 입력받은 alphabet 정렬 내름차순 

    backTracking(0);

    sort(res.begin(), res.end());

    for(int i = 0; i < res.size(); i++) 
        cout<<res[i]<<endl;
    
    return 0;
}

void backTracking(int level) {
    if(level == num+1) return;

    int cnt = 0;
    int moCnt = 0;
    int zaCnt = 0;
    for(int i = 0; i < num; i++) {
        if(solution[i] == 1) {
            cnt++;
            int isInMov = false;
            for(int j = 0; j < 5; j++) 
                if(mov[j] == av[i]) isInMov = true;
            if(isInMov) moCnt++;
            else zaCnt++;
        }
    }
    if(cnt == len && moCnt >= 1 && zaCnt >= 2) {
        string str ="";
        for(int i = num - 1; i >= 0; i--) 
            if(solution[i] == 1) str += av[i];
        res.push_back(str);
        return ;
    }

    for(int i = 0; i < 2; i++) {
        solution[level] = i;
        backTracking(level + 1);
    }
}