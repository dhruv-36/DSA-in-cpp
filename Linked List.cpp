

/////////////////////////  Singly Linked List  /////////////////////////////

//   head and tail is the pointer which points the data present in the current node
#include <iostream>
using namespace std;
////  Creating the linked list
  class Node{
      public: 
      int data;
      Node* next;  // next pointer of (((Node type)))  imp
      ////   constructor  ////   object creation
      Node(int data){
          this -> data =data;
          this -> next= NULL;
      }
      
      ////   Desctructor///  object deletion  ( dynamically created object cant be deleted automaticaly, they needed to delete manually by destructor)
      
      ~Node(){
          int value= this-> data;
          // memory free
          if(this-> next!= NULL){
              delete next;
              this-> next=NULL;
          }
          cout<<"memory is free for the node with value"<< value<<endl;
      }
      
      
      
  };
      ////  Head is the pointer of first linked list
      void InsertAtHead(Node* &head, int data){  ///   & used REFERENCE because it need to be reflected in the main code ( out of the function also) when return     (NO COPY  CHANGES INTO THE ORIGNAL LINKED LIST)
         
          // create the node which is having integer and null pointer
          
          Node* temp=new Node(data);  // object
          temp-> next=head;
          head=temp;
      } 
      
      void print( Node * & head){
          Node* temp= head;
          while(temp!=NULL){
              cout<<temp-> data<<" ";
              temp=temp -> next;
              
          }
          cout<<endl; 
      }
      
 void InsertAtTail(Node* & tail, int data){
     Node* temp=new Node(data);
     tail-> next=temp ;
     tail= temp;  // or    tail=tail-> next;
     
 }

void InsertAtPosition( Node*& head, Node* & tail, int position, int data){
    Node* temp= head;   
    int cnt=1;
    // remember  we neeed to make cases for the first and the last insetion 
    //  Case 1:first position [ update head ]
    if(position==1){
        InsertAtHead(head, data);
        return;
    }
    
    // Case 2 : At middle
    while(cnt<position-1){
        temp=temp-> next;
        cnt++;
    }     ///////////////////////////////////  iss loop ke baat temp apni jagah pe aajayega, lets see whether its need to insert at any position or at the end
    
    // case 3 :  At last position  ( here still tail at the second last node as tail not updated in this function hence need to update the tail also if need to add the node at the last)
    
    if(temp-> next==NULL){                ///////  mtlb ki previous while loop ke baat 
        InsertAtTail(tail,data);
        return;
    }
    
    Node * nodeToInsert= new Node(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}
 
// deletion of the linked list
 void DeleteNode(int position, Node * & head , Node* & tail){
     // case1: deleting the start node
     if(position==1){
         Node* temp=head;
         head=head->next;
         // memory free start value  ( calling DESTRUCTOR)  v imp
         temp->next=NULL;
         delete temp;
     }
     else{  // case 2: deleting the middle or last node
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr-> next;
            cnt++; 
        }//////////////////////////////////  yahan pe temp aagya hai apni jagah pe i.e ith position to delete
        // case 3: deleting the last node then updating the tail
        
        if(curr->next==NULL){
            tail=prev;
        }
        prev->next=curr-> next;
        curr-> next=NULL;
        delete curr;
         
     }
 }


int main() {
    
    
   
    
    //  4 //  insert from tail
    Node* node1 = new Node(10);
    // it has a data of val 10  and a null pointer
    Node *tail= node1;
    Node* head= node1;
    InsertAtTail(tail,12);
    InsertAtTail(tail,15);
    print(head);
    
     //  5 // insert from the given positon;
     
     InsertAtPosition(head,tail,4,50); 
     print(head);
     
     //  6// DELETION
     
     DeleteNode(4,head, tail);
     print(head);
    
    cout<<"head"<< head->data<<endl;
    cout<<"tail"<<tail->data<<endl;
    
    // // 3 //  insert from head
    // Node* node1= new Node(10);
    // cout<<node1-> data<<endl;
    // cout<< node1-> next<<endl;
    
    // /// SETTING Head to node 1
    
    // Node* head= node1;
    // // Insrerting at the head
    // InsertAtHead(head, 12);
    // InsertAtHead(head, 15);
    // print(head);
    
    
    // 2 //
    //  Node* node2=new Node(10);  //  used constructor for creating the object correctly
    // cout<<node2->data<<endl;
    // cout<<node2->next<<endl;
    
    
    
    
    // 1  //  Node* node1 =new Node();  // making the node1 object dynamically; in HEAP; Pointer format;;;;
    
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    ////   giving the garbage values  hence use the parameterised constructor for initialization/////   to create new node////
    
    
    
    

    return 0;
}







////////////////////////////    Doubly Linked List   //////////////////////////////

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
    Node * prev;
    
    Node(int data){      // constructor 
        this->data=data;
        this->next=NULL;
        this-> prev=NULL;
    }
    
    ~Node(){
        int val=this-> data;
        if(next!= NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for the node with data"<< val<< endl;
    }
    
};
void print( Node* & head){
    Node * temp= head;
    while(temp!=NULL){
        cout<<temp-> data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void InsertAtHead(int data, Node* & head){
    Node * temp= new Node(data);
    temp-> next=head;
    head-> prev=temp;
    head=temp;
}

void InsertAtTail(int data , Node* & tail){
    Node * temp= new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void InsertAtMiddle(int data, int position, Node* & tail, Node * & head){
    if(position==1){   //  case 1: at first
        // Node * temp= new Node(data);
        // temp-> next=head;
        // head-> prev=temp;
        // head= temp;               OR
        
        InsertAtHead(data, head);
        return;
    }
    
    Node * NodeToInsert=new Node(data);
    Node* temp=head;
    int cnt=1;
    
    while(cnt<position-1){   
        temp=temp->next;
        cnt++;
    }
    
    if(temp-> next==NULL){    //    case 2: at end
        InsertAtTail(data, tail);
        return;
    }
    
    NodeToInsert -> next=temp->next;     //   case 3: at middle
    temp->next->prev=NodeToInsert;
    NodeToInsert->prev=temp;
    temp->next=NodeToInsert;
    
}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}


int main(){
     Node * node1=new Node(10);
     Node * tail=node1;
     Node * head= node1;
     InsertAtTail(12, tail);
     InsertAtTail(15, tail);
     InsertAtTail(16, tail);
     print(head);
     InsertAtMiddle(18, 5, tail, head);
     print(head);
     cout<<head->data<<endl;
     cout<<tail->data;
     
     deleteNode(5,head); 
     
     print(head);
     return 0;
}












////////////////////////////////      Circular Singly Linked List  //////////////////////////////////////////////////

//circular singly linked list in C++. It provides various operations such as inserting a node, deleting a node, printing the list, checking if the list is circular, and detecting if there is a loop in the list using a map to track visited nodes.


#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertNode(Node* &tail, int element, int d) {
    

    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}    

void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {    // no tail left as all deleted
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {    // curr is at last
            tail = prev;    //// if tail is curr and we are deleting the curr (i.e it is at last)  hence need to handle the tail, it will shift to prev
        }

        curr -> next = NULL;
        delete curr;

    }

}

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;

}

bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}


int main() {

    Node* tail = NULL;

   // insertNode(tail, 5, 3);
    //print(tail);

  //  insertNode(tail, 3, 5);
   // print(tail);

/*
    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);
   

    deleteNode(tail, 5);
    print(tail);
     */

    if(isCircularList(tail)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }

    return 0;
}










