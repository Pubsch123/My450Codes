#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node* rotatebyk(Node *head, int k)
{ 
    if(!head) return head;
    head->prev = NULL;
    Node *ptr;
    Node *cur = head, *tail;
    int c=0;
    while(cur && c<k)
    {
        tail = cur;
        ptr = cur->prev;
        cur->prev = cur->next;
        cur->next = ptr;
        cur = cur->prev;
        c++;
    }
    
     // checking if the reversed LinkedList size is
     // equal to K or not
     // if it is not equal to k that means we have reversed
     // the last set of size K and we don't need to call the
     // recursive function
    
    if(c>=k){
    Node *rest = rotatebyk(cur,k);
    head->next = rest;
      if(rest)
      {
          // it is required for prev link otherwise u wont
          // be backtrack list due to broken links
          rest->prev = head;
      }
    }
    return tail;
}

int main() {
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        Node *head = NULL;
        int x;
        cin>>x;
        head = new Node(x);
        Node *tail = head;
        for(int i=0;i<n-1;i++)
        {
            cin>>x;
            Node* temp = new Node(x);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        int k;
        cin>>k;
        Node *ans = rotatebyk(head,k);
        while(ans)
        {
            cout<<ans->data<<" ";
            ans = ans->next;
        }
    }
	return 0;
}
