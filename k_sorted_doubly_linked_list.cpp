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

struct compare{
    bool operator()(Node* first, Node* second)
    {
        return first->data > second->data;
    }
};


Node* sortbyk(Node *head, int k)
{ 
    if(head == NULL) return head;
    priority_queue<Node*, vector<Node*>, compare> pq;
    Node *ptr = head;
    Node *newhead = NULL;
    Node *cur = NULL;
    for(int i=0; ptr!=NULL && i<=k;i++)
    {
        pq.push(ptr);
        ptr = ptr->next;
    }
    while(!pq.empty())
    {
        if(newhead == NULL)
        {
            newhead = pq.top();
            cur = newhead;
        }else{
        cur->next = pq.top();
        pq.top()->prev = cur;
        cur = pq.top();
        }
        pq.pop();
        if(ptr!=NULL){
        pq.push(ptr);
        ptr = ptr->next;
        }
    }
    cur->next = NULL;
    return newhead;
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
        Node *ans = sortbyk(head,k);
        while(ans)
        {
            cout<<ans->data<<" ";
            ans = ans->next;
        }
    }
	return 0;
}
