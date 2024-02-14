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

class Node{
public:
        int val;
        Node* next;
        Node(int val)
        {
                this->val=val;
                this->next=NULL;
        }
};
void insertnode(Node* &head,Node* &tail,int val)
{
        Node* nd=new Node(val);
        if(head==NULL)
        {
                head=nd;
                tail=head;
        }
        else
        {
                tail->next=nd;
                tail=nd;
        }
}
void inserthead(Node* &head,int val)
{
        Node* temp = new Node(val);
        temp->next=head;
        head=temp;
}
void deletenode(Node* &head , int val)
{
        Node* temp = head;
        while(temp!=NULL)
        {
                if(temp->next->val==val)
                {
                        temp->next=temp->next->next;
                        return;
                }
                if(temp->val==val && temp==head)
                {
                        head=temp->next;
                        return;
                }
        }
}
void print(Node* root)
{
        Node* temp=root;
        while(temp!=NULL)
        {
                cout<<temp->val<<" ";
                temp=temp->next;
        }
}
int main()
{
    Node* head=NULL;
    Node* tail=head;

    int n;
    cin>>n;
    while(n--)
    {
            int x;
            cin>>x;
            insertnode(head,tail,x);
    }
    inserthead(head,10);
    deletenode(head,10);
    print(head);
}
