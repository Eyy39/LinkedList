#include<iostream>
#include "LinkedList.hpp"
using namespace std;

int main(){
    LinkedList List;

    // InsertFront
    List.insertFront(2);
    List.insertFront(5);

    // InsertEnd
    List.insertEnd(10);
    List.insertEnd(15);
    List.insertEnd(20);

    // Insert at position
    List.insertAt(12,1);

    List.traverse();
    // Delete both front and end
    // List.deleteFront();
    // List.deleteEnd();
    // List.traverse();

    // DeleteAt
    // List.deleteAt(2);
    // List.traverse();

    // Swap Two Node
    // List.swapTwoNode(10,20);
    // List.swapTwoNode(15,12);
    // cout<<"After Swapped: \n";
    List.traverse();

    // Search in linked List
    List.search(15);
    List.search(6);
    cout<<"Head: "<<List.getHead()->value<<endl;

    return 0;
}