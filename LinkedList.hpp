#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

class LinkedList{
    private:
        string name;
        Node* head,*cur;
        int n;
    public:
        LinkedList(){
            head = nullptr;
            cur = nullptr;
            n=0;
        }

        void traverse(){
            if(n == 0){
                cout<<"Empty!"<<endl;
                return;
            }
            cur = head;
            while(cur != nullptr){
                cout<<cur->value<<"->";
                cur = cur->next;
            }
            cout<<endl;
        }

        Node* getHead(){
            return head;
        }

        void insertFront(int val){
            Node* nNode = new Node{val, nullptr};
            nNode->next = head;
            head = nNode;
            n++;
            cout<<"Value: "<<val<<endl;
        }

        void insertEnd(int val){
            if(n == 0){
                insertFront(val);
                return;
            }
            cur = head;
            for(int i=0; i<n-1; i++){
                cur= cur->next;
            }

            // while(cur->next != nullptr){
            //     cur =cur->next;
            // }

            Node* nNode = new Node{val, nullptr};
            cur->next = nNode;
            n++;
        }
        
        void insertAt(int val, int pos){
            if(pos > n){
                cout<<"Out of node range!\n";
                return;
            }
            if(pos == 0){
                insertFront(val);
                return;
            }

            if(pos == n){
                insertEnd(val);
                return;
            }
            cur = head;
            for(int i=0; i<pos-1; i++){
                cur = cur->next;
            }
            Node* nNode = new Node{val, nullptr};
            nNode->next = cur->next;
            cur->next = nNode;
            n++;
        }

        void deleteFront(){
            if(n == 0){
                cout<<"No node to del!\n";
                return;
            }
            Node * tmp = head;
            head = head->next;
            n--;
        }

        void deleteEnd(){
            if(n == 0){
                cout<<"No node to del!\n";
                return;
            }
            cur = head;
            while(cur->next->next != nullptr){
                cur = cur->next;
            }
            delete cur->next;
            cur->next = nullptr;
            n--;
        }

        void deleteAt(int pos){
            if(n == 0){
                cout<<"No node to delete!\n";
                return;
            }
            if(pos < 0 || pos >= n){
                cout<<"Invalid position!\n";
                return;
            }

            if(pos == 0){
                deleteFront();
                return;
            }

            if(pos == n - 1){
                deleteEnd();
                return;
            }

            cur = head;
            for(int i = 0; i < pos - 1; i++){
                cur = cur->next;  // move to the node before the one to delete
            }

            Node* tmp = cur->next;     // the node to delete
            cur->next = tmp->next;     // bypass it
            delete tmp;                // free memory
            n--;
        }
        
        void swapTwoNode(int val1, int val2){
            if(val1 == val2){
                cout << "Both values are the same no swap needed.\n";
                return;
            }

            Node *prev1 = nullptr, *prev2 = nullptr;
            Node *node1 = head, *node2 = head;

            // Find node1 and its previous node
            while(node1 != nullptr && node1->value != val1){
                prev1 = node1;
                node1 = node1->next;
            }

            // Find node2 and its previous node
            while(node2 != nullptr && node2->value != val2){
                prev2 = node2;
                node2 = node2->next;
            }

            // If either value is not found
            if(node1 == nullptr || node2 == nullptr){
                cout << "Values not found!\n";
                return;
            }

            // If node1 is not head
            if(prev1 != nullptr){
                prev1->next = node2;
            }else{
                head = node2; // node1 was head
            }

            // If node2 is not head
            if(prev2 != nullptr){
                prev2->next = node1;
            }else{
                head = node1; // node2 was head
            }

            // Swap their next pointers
            Node* temp = node1->next;
            node1->next = node2->next;
            node2->next = temp;
        }

        void search(int val){
            if (n == 0){  // empty list
                cout<<"List is empty!\n";
                return;
            }

            Node* temp = head;
            int pos = 0;  // to track position
            while (temp != nullptr){
                if (temp->value == val){
                    cout<<"Value "<<val<<" found at position "<<pos<<endl;
                    return;  
                }
                temp = temp->next;
                pos++;
            }

            cout<<"Value "<<val<<" not found in the list.\n";
        }

};