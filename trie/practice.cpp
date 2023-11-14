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
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char ch)
        {
                data=ch;
                for(int i=0;i<26;i++)
                {
                        children[i]=NULL;
                }
                isTerminal=false;
        }
};

class Trie{
public:
        TrieNode* root;
        Trie()
        {
                root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root,string word)
        {
                if(word.length()==0)
                {
                        root->isTerminal=true;
                        return;
                }
                int x = word[0]-'a';
                TrieNode* child;
                if(root->children[x]!=NULL)
                {
                        child = root->children[x];
                }
                else
                {
                        child=new TrieNode(word[0]);
                        root->children[x]=child;
                }
                insertUtil(child,word.substr(1));
        }

        void insertWord(string word)
        {
                insertUtil(root,word);
        }


        bool searchUtil(TrieNode* root,string s)
        {
                if(s.length()==0)
                {
                        return root->isTerminal;
                }
                int x = s[0]-'a';
                TrieNode* child;
                if(root->children[x]!=NULL)
                {
                        child=root->children[x];
                }
                else{
                        return false;
                }
                return searchUtil(child,s.substr(1));
        }
        bool searchword(string s)
        {
                return searchUtil(root,s);
        }


};
int main()
{
    Trie* t =  new Trie();
    t->insertWord("abcd");
    cout<<"ans is "<<t->searchword("abcd")<<endl;
}
