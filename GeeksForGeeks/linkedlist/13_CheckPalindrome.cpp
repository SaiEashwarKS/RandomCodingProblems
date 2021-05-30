// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    Node* reverse(Node* head)
    {
            Node* curr = NULL;
            Node* succ = head;
            Node* temp;
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
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node* prev_slow = NULL;
        Node* slow = head;
        Node* fast = head;
        Node* mid;
        if(head && head->next)
        {
            while(fast && fast->next)
            {
                fast = fast->next->next;
                prev_slow = slow;
                slow = slow->next;
            }
            if(fast)
            {
                mid = slow;
                slow = slow -> next;
            }
            Node* second_half = slow;
            prev_slow -> next = NULL;
            second_half = reverse(second_half);
             while(head && second_half)
            {
                if(head->data != second_half->data)
                {
                    return false;
                }
                head = head->next;
                second_half = second_half-> next;
            }
        }
       
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends
