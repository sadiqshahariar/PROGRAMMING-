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

bool ans=false;
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

        void searchUtil(TrieNode* root,string word)
        {
                if(word.length()==0)
                {
                        if(root->isTerminal==true)
                        {
                                ans=true;
                        }
                        return;
                }
                if(word[0]=='.')
                {
                        for(int i=0;i<26;i++)
                        {
                                if(root->children[i]!=NULL)
                                {
                                        TrieNode* child;
                                        child=root->children[i];
                                        searchUtil(child,word.substr(1));
                                }
                        }
                }
                else
                {
                        int x=word[0]-'a';
                        TrieNode* child;
                        if(root->children[x]!=NULL)
                        {
                                child=root->children[x];
                        }
                        else return;
                        searchUtil(child,word.substr(1));
                }
        }
        bool searchWord(string word)
        {
                ans=false;
                searchUtil(root,word);
                return ans;
        }
};

int main()
{
        Trie *t = new Trie();
        t->insertWord("bad");
        t->insertWord("dad");
        t->insertWord("mad");
        cout<<"yes or not "<<t->searchWord("pad")<<endl;
        cout<<"yes or not "<<t->searchWord("bad")<<endl;
        cout<<"yes or not "<<t->searchWord(".ad")<<endl;
        cout<<"yes or not "<<t->searchWord("b..")<<endl;
}

