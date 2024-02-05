class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       // If linked list is empty
       Node *node = new Node(data);
       if(head==NULL){
           node->next=head;
           return node;
       }
       
       //It interted element is first element
       Node *curr = head;
       if(data<head->data){
           node->next = head;
           Node *temp = head;
           
           while(temp->next!=head){
               temp=temp->next;
           }
           temp->next = node;
           head = node;
           
       }else{
           while(curr->next!=head && data<curr->next->data){
               curr = curr->next;
           }
           node->next = curr->next;
           curr->next = node;
       }
       return head;
    }
};