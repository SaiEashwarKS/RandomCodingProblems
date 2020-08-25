/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;

node* create_node(int value) //function to create a new node
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node -> val = value;
    new_node -> next = NULL;
    
    return new_node;
}

//function which returns a new reversed list of the list passed as argument 
node* create_rev_list(node* head){
    node* n = head;
    node* new_head = NULL;
    while(n)
    {
        node* new_node = create_node(n->val);
        if(!new_head)
        {
            new_head = new_node;
        }
        else
        {
            new_node -> next = new_head;
            new_head = new_node;
        }
        n = n -> next;
    }
    return new_head;
}

//returns lenght of the list
int length(node* head){
    int len = 0;
    node n = *head;
    while(n.next != NULL){
        ++len;
        n = *(n.next);
    }
    ++len;
    //printf("Length : %d\n", len);
    return len;
}

void reorderList(struct ListNode* head){
    if(!head)
        return head;
    int og_len = length(head);
    node* rev_list = create_rev_list(head);
    node* left = head;
    node* right = rev_list;
    node* result_head;
    node* result_node;
    result_head = left;
    left = left -> next;
    result_node = result_head;
    int res_len = 1;
    while(left && right && res_len < og_len)
    {
        result_node -> next = right;
        right = right -> next;
        result_node = result_node -> next;
        ++res_len; 
        
        if(res_len == og_len)
            break;
        
        result_node -> next = left;
        left = left -> next;
        result_node = result_node -> next;
        ++res_len;
    }
    result_node -> next = NULL;
    head = result_head;    
}
