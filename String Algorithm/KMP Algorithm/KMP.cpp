#include<bits/stdc++.h>
using  namespace  std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define all(x) x.begin(),x.end()
#define nl      '\n'
#define pi          acos(-1.0)
#define mod               1000000007

typedef long long int ll;
typedef unsigned long long int  llu;

vector<int>suffixandprefix(string pattern)
{
        vector<int>lps(pattern.size());
        int index=0;
        for(int i=1;i<pattern.size();)
        {
                if(pattern[i]==pattern[index])
                {
                        lps[i]=index+1;
                        ++index;
                        ++i;
                }
                else{
                        if(index!=0)index=lps[index-1];
                        else
                        {
                                lps[i]=index;
                                ++i;
                        }
                }
        }
        return lps;
}


void KMP(string text,string pattern)
{

        bool found = false;
        vector<int>lps = suffixandprefix(pattern);

        int j=0,i=0;
        while(i<text.size())
        {
                if(text[i]==pattern[j])
                {
                        ++i,++j;
                }
                else{
                        if(j!=0)j=lps[j-1];
                        else ++i;
                }

                if(j==pattern.size())
                {
                        cout<<"Found Match at: "<<i-pattern.size()<<endl;
                        j=lps[j-1];
                        found=true;
                }
        }
        if(!found)cout<<"Not Found"<<endl;
}

int main()
{
    string text, pattern;

    getline(cin,text);
    getline(cin,pattern);

    KMP(text,pattern);

    return 0;
}
