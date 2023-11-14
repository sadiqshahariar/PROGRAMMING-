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

class TrieNode{
public:
    TrieNode* next[2];
    TrieNode()
    {
            next[0]=NULL;
            next[1]=NULL;
    }
};

class Trie{
public:
        TrieNode* root;
        Trie()
        {
                root=new TrieNode();
        }

        void insertUtil(TrieNode* root,int num)
        {

                for(int i=31;i>=0;i--)
                {
                        int bit=((num>>i)&1);
                        if(root->next[bit]==NULL)
                        {
                                root->next[bit] = new TrieNode();
                        }
                        root = root->next[bit];
                }
        }

        void insertbit(int num)
        {
                insertUtil(root,num);
        }

        int searchUtil(TrieNode* root,int num)
        {
                int ans=0;
                for(int i=31;i>=0;i--)
                {
                        int bit=(num>>i)&1;
                        if(root->next[!bit])
                        {
                                ans+=(1<<i);
                                root=root->next[!bit];
                        }
                        else root=root->next[bit];
                }
                return ans;
        }

        int searchsum(int num)
        {
                return searchUtil(root,num);
        }
};

int main()
{
    int n;
    cin>>n;
    int ar[n+3];
    Trie* t = new Trie();
    for(int i=0;i<n;i++)
    {
            int x;
            cin>>x;
            ar[i]=x;
    }
    sort(ar,ar+n);
    int q;
    cin>>q;
    vector<pair<int,pair<int,int> > >v;
    for(int i=0;i<q;i++)
    {
            int a,b,c;
            cin>>a>>b;
            v.push_back({b,{a,i}});
    }
    sort(v.begin(),v.end());
    vector<pair<int,int> >ans;
    cout<<v.size()<<endl;
    int i=0;
    for(int ii=0;ii<v.size();ii++)
    {
           int ind=v[ii].second.second;
           int val=v[ii].first;
           int xr=v[ii].second.first;
           while(i<n && ar[i]<=val)
           {
                   t->insertbit(ar[i]);
                   i++;
           }
           if(i==0)ans.push_back({ind,-1});
           else{
                int an=t->searchsum(xr);
                ans.push_back({ind,an});
           }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i].second<<" ";
    cout<<endl;

}
