#include <stdio.h>
#include <stack>
using namespace std;

char str[100];

int cToInt(char c);

int main(int argc, char const *argv[])
{
    stack<char> st;
    int sum = 0;
    bool isInBracket = false;
    int mid = 0;
    char bef = '*';
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++) {
        if(!isInBracket) {
            if(str[i] == '(') {
                if(bef == ')') sum += mid;
                else sum += cToInt(bef);
                if(!st.empty()) st.pop();
                mid = 0;
                isInBracket = true;
                bef = '(';
            }
            else if(str[i] <= '9' && str[i] >= '2'){
                if(!st.empty()) {
                    st.pop(); 
                    sum += cToInt(bef) * (str[i] - '0');
                } else 
                    sum += mid * (str[i] - '0');
                bef = str[i];
            } else {    //C,H,O
                if(bef == ')') {
                    sum += mid;
                    st.push(str[i]);
                    bef = st.top();
                } else { // bef가 C,H,O중 일때
                    if(!st.empty()) {
                        sum += cToInt(bef);
                        st.pop();
                        st.push(str[i]);
                        bef = st.top();
                    } else {
                        st.push(str[i]);
                        bef = st.top();
                    }
                }
            }
        } else {    //괄호 안 일때 
            if(str[i] <= '9' && str[i] >= '2'){
                st.pop();
                mid += cToInt(bef) * (str[i] - '0');
                bef = str[i];
            } else if(str[i] == ')') {
                isInBracket = false;
                if(bef <= '9' && bef >= '2') {
                    bef = ')';
                } else if(bef == '('){
                    isInBracket = false;
                } else { //C,H,O
                    mid += cToInt(bef);
                    st.pop();
                    bef = ')';
                }
            } else { //C,H,O
                if(!st.empty()) {
                    mid += cToInt(bef);
                    st.pop();
                    st.push(str[i]);
                    bef = st.top();
                } else {
                    st.push(str[i]);
                    bef = st.top();
                }
            }
        }
    }
    if(bef == ')') sum += mid;
    else sum += cToInt(bef);

    printf("%d\n", sum);
    return 0;
}

int cToInt(char c) {
    if(c == 'O') return 16;
    else if(c == 'C') return 12;
    else if(c == 'H') return 1;
    else return 0;
}

// #include <stdio.h>
// #include <stack>
// using namespace std;

// #define C 12
// #define O 16
// #define H 1

// char str[100];

// int cToInt(char c);

// int main(int argc, char const *argv[])
// {
//     stack<char> st;
//     int sum = 0;
//     bool isInBracket = false;
//     int mid = 0;
//     char bef = '*';
//     scanf("%s", str);

//     // printf("%s\n", str);
//     for(int i = 0; str[i] != '\0'; i++) {
//         if(!isInBracket) {
//             if(str[i] == '(') {
//                 // printf("1before - isBr : F / str[%d] : %c / sum : %d / mid : %d / bef : %c\n", i, str[i], sum, mid, bef);
//                 if(bef == ')') sum += mid;
//                 sum += cToInt(bef);
//                 if(!st.empty()) st.pop();
//                 mid = 0;
//                 isInBracket = true;
//                 bef = '(';
//                 // printf("1after - isBr : F / str[%d] : %c / sum : %d / mid : %d / bef : %c\n", i, str[i], sum, mid, bef);
//             }
//             else if(str[i] <= '9' && str[i] >= '2'){
//                 // printf("2before - isBr : F / str[%d] : %c / sum : %d / mid : %d / bef : %c\n", i, str[i], sum, mid, bef);
//                 if(!st.empty()) {
//                     st.pop(); 
//                     sum += cToInt(bef) * (str[i] - '0');
//                 } else 
//                     sum += mid * (str[i] - '0');
//                 bef = str[i];
//                 // printf("2after - isBr : F / str[%d] : %c / sum : %d / mid : %d / bef : %c\n", i, str[i], sum, mid, bef);
//             } else {    //C,H,O
//                 // printf("3before - isBr : F / str[%d] : %c / sum : %d / mid : %d / bef : %c\n", i, str[i], sum, mid, bef);
//                 if(bef == ')') {
//                     sum += mid;
//                     st.push(str[i]);
//                     bef = st.top();
//                 } else { // bef가 C,H,O중 일때
//                     if(!st.empty()) {
//                         sum += cToInt(bef);
//                         st.pop();
//                         st.push(str[i]);
//                         bef = st.top();
//                     } else {
//                         st.push(str[i]);
//                         bef = st.top();
//                     }
//                 }
//                 // printf("3after - isBr : F / str[%d] : %c / sum : %d / mid : %d / bef : %c\n", i, str[i], sum, mid, bef);
//             }
//         } else {    //괄호 안 일때 
//             if(str[i] <= '9' && str[i] >= '2'){
//                 // printf("4before - isBr : T / str[%d] : %c / sum : %d / mid : %d / bef : %c\n", i, str[i], sum, mid, bef);
//                 st.pop();
//                 mid += cToInt(bef) * (str[i] - '0');
//                 bef = str[i];
//                 // printf("4after - isBr : F / str[%d] : %c / sum : %d / mid : %d / bef : %c\n", i, str[i], sum, mid, bef);
//             } else if(str[i] == ')') {
//                 // printf("5before - isBr : T / str[%d] : %c / sum : %d / mid : %d / bef : %c\n", i, str[i], sum, mid, bef);
//                 isInBracket = false;
//                 if(bef <= '9' && bef >= '2') {
//                     bef = ')';
//                 } else if(bef == '('){
//                     isInBracket = false;
//                 } else { //C,H,O
//                     mid += cToInt(bef);
//                     st.pop();
//                     bef = ')';
//                 }
//                 // sum += mid;
//                 // printf("5after - isBr : F / str[%d] : %c / sum : %d / mid : %d / bef : %c\n", i, str[i], sum, mid, bef);
//             } else { //C,H,O
//                 // printf("6before - isBr : T / str[%d] : %c / sum : %d / mid : %d / bef : %c\n", i, str[i], sum, mid, bef);
//                 if(!st.empty()) {
//                     // printf("stack is not empty\n");
//                     mid += cToInt(bef);
//                     st.pop();
//                     st.push(str[i]);
//                     bef = st.top();
//                 } else {
//                     // printf("stack is empty\n");
//                     st.push(str[i]);
//                     bef = st.top();
//                 }
//                 // printf("6after - isBr : F / str[%d] : %c / sum : %d / mid : %d / bef : %c\n", i, str[i], sum, mid, bef);
//             }
//         }
//     }
//     if(bef == ')') sum += mid;
//     else sum += cToInt(bef);

//     printf("%d\n", sum);
//     return 0;
// }

// int cToInt(char c) {
//     if(c == 'O') {
//         // printf("[%c] to 16\n", c);
//         return 16;
//     }
//     else if(c == 'C') {
//         // printf("[%c] to 12\n", c);
//         return 12;
//     }
//     else if(c == '*') {
//         // printf("[%c] to 0\n", c);
//         return 0;
//     }
//     else if(c == 'H') {
//         // printf("[%c] to 1\n", c);
//         return 1;
//     }
//     return 0;
// }