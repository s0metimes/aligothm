#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
char alpha[15];

bool possible(string passwd)
{
    int vow = 0, con = 0;
    for (char c : passwd)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vow++;
        else
            con++;
    }
    if (vow >= 1 && con >= 2)
        return true;
    else
        return false;
}

void solve(int index, string passwd)
{
    if (passwd.length() == L)
    {
        if (possible(passwd))
            cout << passwd << '\n';
        return;
    }
    if (index >= C)
        return;
    solve(index + 1, passwd + alpha[index]);
    solve(index + 1, passwd);
}

int main()
{
    scanf("%d %d", &L, &C);
    for (int i = 0; i < C; i++)
        scanf(" %c", &alpha[i]);
    sort(alpha, alpha + C);
    solve(0, "");
}
