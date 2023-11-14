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

string s;
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

        void searchUtil(TrieNode* root)
        {
                int cnt=0;
                TrieNode* child;
                char ch;
                for(int i=0;i<26;i++)
                {
                        if(root->children[i]!=NULL)
                        {
                                cnt++;
                                child=root->children[i];
                                ch=root->children[i]->data;
                        }
                }
                if(cnt==1)
                {
                        s+=ch;
                        searchUtil(child);
                }
                else return;
        }
        void lcp()
        {
                searchUtil(root);
        }
};

int main()
{
        Trie *t = new Trie();
        t->insertWord("codable");
        t->insertWord("code");
        t->insertWord("coder");
        t->insertWord("coding");
        t->lcp();
        cout<<s<<endl;
}
