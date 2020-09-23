#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//맞는거 같은데 왜 틀리지.. 
typedef struct User{
    string name;
    int pref;// 1 : M, 2: F, 3:MF; //프리미엄의 성별선호도 && 그냥성별
    int dist;
    User(){}
    User(string _name, string prefString, int _dist){
        name = _name;
        dist =_dist;
        int preferenceNumber;
        if (prefString.length() == 2)
            pref =3;
        else
            pref = (prefString== "M" ? 1 : 2);
    }
} User;

bool isAvailable(User prem, User candi){
    if(prem.dist < candi.dist)
        return false;
    else if(prem.pref == 3)
        return true;
    else if(prem.pref == candi.pref)
        return true;
    return false; 
}




int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    User premium;
    string name, prefString; int dist;
    int N;

    cin>>name>>prefString>>dist;
    premium = User(name,prefString,dist);
    cin>>N;

    vector<string> ans;
    
    while(N--){
        User candi;
        string name, prefString; int dist;
        cin>>name>>prefString>>dist;
        candi = User(name,prefString,dist);
        if(isAvailable(premium, candi))
            ans.push_back(candi.name);
    }

    if(ans.size() == 0){
        cout<<"No one yet";
    }
    else{
        sort(ans.begin(),ans.end());
        for(string x : ans)
            cout << x <<"\n";
    }


    return 0;
}
