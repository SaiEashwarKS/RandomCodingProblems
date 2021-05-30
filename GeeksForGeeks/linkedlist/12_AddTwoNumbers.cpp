// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    struct Node* insertAtBeginning(struct Node* head, int data)
    {
        struct Node* temp = new struct Node(data);
        temp -> next = head;
        return temp;
    }
    
    struct Node* reverse (struct Node* head)
    {
        if(!head || !head->next)
        {
            return head;
        }
        struct Node* curr = NULL;
        struct Node* succ = head;
        struct Node* temp;
        while(succ)
        {
            temp = succ -> next;
            succ -> next = curr;
            curr = succ;
            succ = temp;
        }
        return curr;
        
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        int sumDigit;
        int sum;
        int carry = 0;
        struct Node* res = nullptr;
        first = reverse(first);
        second = reverse(second);
        while(first && second)
        {
            sum = (first->data + second->data + carry);
            sumDigit = sum % 10;
            carry = sum / 10;
            res = insertAtBeginning(res, sumDigit);
            first = first->next;
            second = second -> next;
        }
        while(first)
        {
            sum = first->data + carry;
            sumDigit = sum % 10;
            carry = sum / 10;
            res = insertAtBeginning(res,sumDigit);
            first = first -> next;
        }
        while(second)
        {
            sum = second->data + carry;
            sumDigit = sum % 10;
            carry = sum / 10;
            res = insertAtBeginning(res, sumDigit);
            second = second -> next;
        }
        if(carry)
        {
            res = insertAtBeginning(res, carry);
        }
        return res;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
