#include <stdio.h>
#define MAX 5000
#define MODULE 1000000

int dp[MAX+1] = {1,};
char pwd[MAX+1];

bool possible(int i) {
    return pwd[i-1] == '1' || (pwd[i-1] == '2' && pwd[i] <= '6' && pwd[i] >='0');
}

int main(int argc, char const *argv[])
{
    char c;

    c = getchar();

    if(c == '0') {
        printf("0\n");
        return 0;
    }
    int len = 0;
    while(c >= '0' && c <= '9') {
        pwd[len++] = c;
        c = getchar();
    }
    
    if(possible(1)) {
        if(pwd[1] == '0') dp[1] = 1;
        else dp[1] = 2;        
    }
    else {
        if(pwd[1] == '0') {
            printf("0\n");
            return 0;
        }
        else dp[1] = 1;
    }
        
    for(int i = 2; i < len; i++) {
        if(pwd[i] == '0' && pwd[i-1] == '0') {  // 00제거 
            printf("0\n");
            return 0;
        }
        if(possible(i)) { //10-19 || 20-26
            if(pwd[i] == '0') dp[i] = dp[i-2]; //10, 20
            else dp[i] = dp[i-1] + dp[i-2]; //11-19 || 21-26
        }
        else {
            if(pwd[i] != '0') dp[i] = dp[i-1];  //
            else {  // 문제 
                printf("0\n");
                return 0;
            }
        }
        dp[i] = dp[i]%MODULE;
    }   
    printf("%d\n", dp[len-1]);
    return 0;
}

// #include <stdio.h>
// #include <string>
// #include <iostream>
// #include <vector>
// #define MAX 5000
// #define MODULE 1000000

// using namespace std;
// int dp[MAX+1] = {1,};
// char pwd[MAX+1];
// vector<string> dps[MAX+1];


// void debugByPrint(int len);
// bool possible(int i) {
//     return pwd[i-1] == '1' || (pwd[i-1] == '2' && pwd[i] <= '6' && pwd[i] >='0');
// }

// int main(int argc, char const *argv[])
// {
//     char c;

//     c = getchar();

//     if(c == '0') {
//         printf("0\n");
//         return 0;
//     }

//     int len = 0;
//     while(c >= '0' && c <= '9') {
//         pwd[len++] = c;
//         c = getchar();
//     }

//     vector<string>::iterator it;
//     dps[0].push_back("");
//     dps[0][0].push_back(pwd[0]);
//     if(possible(1)) {   // 10-19 && 20-26
//         if(pwd[1] == '0') {
//             dp[1] = 1;
//             dps[1].push_back("");
//             dps[1][0].push_back(pwd[0]);
//             dps[1][0].push_back(pwd[1]);            
//         }
//         else {
//             dp[1] = 2;
//             dps[1].push_back("");
//             dps[1].push_back("");
//             dps[1][0].push_back(pwd[0]);
//             dps[1][0].push_back(',');
//             dps[1][0].push_back(pwd[1]);
//             dps[1][1].push_back(pwd[0]);
//             dps[1][1].push_back(pwd[1]);
//         }
//     }
//     else {  // 그 이외 
//         if(pwd[1] == '0') {
//             printf("0\n");
//             return 0;
//         }
//         dp[1] = 1;
//         dps[1].push_back("");
//         dps[1][0].push_back(pwd[0]);
//         dps[1][0].push_back(',');
//         dps[1][0].push_back(pwd[1]);
//     }
    

//     for(int i = 2; i < len; i++) {
//         if(possible(i)) { //10-19 || 20-26
//             if(pwd[i] == '0') {
//                 dp[i] = dp[i-2]%MODULE;
//                 dps[i].assign(dps[i-2].begin(), dps[i-2].end());
//                 for(it = dps[i].begin(); it != dps[i].end(); it++) {
//                     it->push_back(',');
//                     it->push_back(pwd[i-1]);
//                     it->push_back(pwd[i]);
//                 }
//                 printf("dp[%d] 를 구하기 위해 dp[%d]에 %c%c를 추가합니다\n",i,i-2,pwd[i-1],pwd[i]);
//                 for(it = dps[i].begin(); it != dps[i].end(); it++) 
//                     cout<<*it<<" / ";
//                 cout<<endl;
//             }
//             else {
//                 dp[i] = dp[i-1]%MODULE + dp[i-2]%MODULE;
//                 dps[i].assign(dps[i-2].begin(), dps[i-2].end());
//                 for(it = dps[i].begin(); it != dps[i].end(); it++) {
//                     it->push_back(',');
//                     it->push_back(pwd[i-1]);
//                     it->push_back(pwd[i]);
//                 }
//                 printf("dp[%d] 를 구하기 위해 dp[%d]에 %c%c를 추가합니다\n",i,i-2,pwd[i-1],pwd[i]);
//                 for(it = dps[i].begin(); it != dps[i].end(); it++) 
//                     cout<<*it<<" / ";
//                 cout<<endl;
//                 printf("dp[%d] 를 구하기 위해 dp[%d]에 %c를 추가합니다\n",i,i-1,pwd[i]);
//                 for(it = dps[i-1].begin(); it != dps[i-1].end(); it++) {
//                     string temp = *it;
//                     temp.push_back(',');
//                     temp.push_back(pwd[i]);
//                     dps[i].push_back(temp);
//                 }
//                 for(it = dps[i].begin(); it != dps[i].end(); it++) 
//                     cout<<*it<<" / ";
//                 cout<<endl;
//             }
//         }
//         else { //00-09 && 27-29 && 30-99
//             if(pwd[i] != '0') {
//                 dp[i] = dp[i-1];
//                 dps[i].assign(dps[i-1].begin(), dps[i-1].end());
//                 for(it = dps[i].begin(); it != dps[i].end(); it++) {
//                     it->push_back(',');
//                     it->push_back(pwd[i]);
//                 }
//             } else {
//                 printf("암호를 만들수 없음\n");
//                 return 0;
//             }
//         }
//     }   
//     debugByPrint(len);
//     return 0;
// }

// void debugByPrint(int len) {
//     printf("len : %d\n", len);
//     for(int i = 0; i < len; i++) 
//         printf("%c ", pwd[i]);
//     printf("\nidx | ");
//     for(int i = 0; i < len; i++) 
//         printf("%3d", i);
//     printf("\npwd | ");
//     for(int i = 0; i < len; i++) 
//         printf("%3c", pwd[i]);
//     printf("\ndp  | ");
//     for(int i = 0; i < len; i++) 
//         printf("%3d", dp[i]);
//     printf("\n");
//     printf("%d\n", dp[len-1]);
//     vector<string>::iterator it;
//     for(int i = 0; i < len; i++) {
//         printf("i = %d 의 경우의 수 | ", i);
//         for(it = dps[i].begin(); it != dps[i].end(); it++) 
//             cout<<*it<<" / ";
//         cout<<endl;
//     }
// }