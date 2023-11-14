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

        bool searchUtil(TrieNode* root,string word)
        {
                if(word.length()==0)
                {
                        return true;
                }
                int x=word[0]-'a';
                TrieNode* child;
                if(root->children[x]!=NULL)
                {
                        child=root->children[x];
                }
                else return false;
                return searchUtil(child,word.substr(1));
        }
        bool searchWord(string word)
        {
                return searchUtil(root,word);
        }
};

int main()
{
        Trie *t = new Trie();
        t->insertWord("oaan");
        t->insertWord("etae");
        t->insertWord("ihkr");
        t->insertWord("iflv");
        t->insertWord("oeii");
        t->insertWord("athf");
        t->insertWord("aakl");
        t->insertWord("nerv");
        cout<<"yes or not "<<t->searchWord("oath")<<endl;
        cout<<"yes or not "<<t->searchWord("pea")<<endl;
        cout<<"yes or not "<<t->searchWord("eat")<<endl;
        cout<<"yes or not "<<t->searchWord("rain")<<endl;
}

