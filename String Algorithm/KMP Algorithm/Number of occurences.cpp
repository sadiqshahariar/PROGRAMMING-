#include<bits/stdc++.h>
using namespace std;

vector<int> prefix(200000,0);

void formPrefix(string search) {

    for(int i=1;i<search.size();i++)
    {
        int j = prefix[i-1];
        while(j>0 && search[i]!=search[j])
        {
            j = prefix[j-1];
        }
        if(search[i]==search[j])j++;
        prefix[i] = j;
    }
    return ;
}

int main() {
    string p,t;
    cin >> p >> t;
    string search = p + "#" + t;
    formPrefix(search);
    int occurences = 0;
    for(auto num:prefix) {
        if(num==p.size())
            occurences++;
    }
    cout << occurences << endl;
    return 0;
}
