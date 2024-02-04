class Solution {
public:
    Node* reverse(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* curr = head;
    Node* prev = NULL;
    Node* temp = NULL;
    
    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
  }
  
  pair<Node*,bool>SubstractLL(Node* head1,Node* head2){
      Node* ans = new Node(-1);
      Node* curr = ans;
      int carry = 0;
      while(head1 && head2){
          int first = head1->data;
          if(carry==1){
              if(first==0){
                  first = 9;
                  carry=1;
              }else{
                  first--;
                  carry=0;
              }
          }
          int second = head2->data;
          if(first<second){
              first+=10;
              carry = 1;
          }
          curr->next = new Node(first-second);
          
          curr = curr->next;
          head1 = head1->next;
          head2 = head2->next;
      }
      while(head1){
          int first = head1->data;
          
          if(carry==1){
              if(first==0){
                  carry = 1;
                  first = 9;
              }else{
                  first--;
                  carry=0;
              }
          }
          curr->next = new Node(first);
          curr = curr->next;
          head1 = head1->next;
      }
      if(carry==1) return {NULL,false};
      
      while(head2){
          if(head2->data!=0) return {NULL,false};
          head2=head2->next;
      }
      curr->next = NULL;
      return {ans->next,true};
      
      
  }
  Node* subLinkedList(Node* head1, Node* head2) {
    // Your implementation of subLinkedList goes here
    // Make sure to return the head of the resulting linked list
    
    head1=reverse(head1);
    head2 = reverse(head2);
    
    pair<Node*, bool> one = SubstractLL(head1,head2);
    pair<Node*, bool>two  = SubstractLL(head2,head1);
    
    if(one.second==true){
        Node* temp1=reverse(one.first);
        while(temp1->next && temp1->data==0){
            temp1=temp1->next;
        }
        return temp1;
    }
    if(two.second==true){
        Node* temp2 = reverse(two.first);
        
        while(temp2->next && temp2->data==0){
            temp2 = temp2->next;
        }
        return temp2;
    }
    return NULL;
  }
};
