// Name: Amer Yono
// Student ID: 200711334
// Email: yono004@cougars.csusm.edu

#include <iostream>
using std::cout, std::endl;

// Node Structure
struct Node {
    int num;
    Node* next;
};

// Function that adds nodes to a linked list.
void addToLinkedList(Node** linkedList, int numberToAdd) {
    // Initialize and add new node
    Node* newItem = NULL;
    newItem = new Node();

    // Add values to the node
    newItem->num = numberToAdd;
    newItem->next = *linkedList;

    // Add the node the linked list
    *linkedList = newItem;
}

Node* unionLL(Node* LA, Node* LB) {
    // Initialize unionizedLL
    Node* unionizedLL = NULL;
    
    // Add both linked lists to unionizedLL
    while (LA) {
        addToLinkedList(&unionizedLL, LA->num);
        LA = LA->next;
    }

    while (LB) {
        addToLinkedList(&unionizedLL, LB->num);
        LB = LB->next;
    }

    // Set pointer equal to unionizedLL
    Node* unionizedPointer = unionizedLL;

    // Create pointers for looping through unionizedPointer and removing duplicates
    Node* insidePointer;
    Node* duplicateNumber;
    
    // Go through the linked list by 1. The insidePointer will loop through every node during this.
    while (unionizedPointer->next) {
        insidePointer = unionizedPointer;

        // Go through every unionizedPointer->num to check for duplicates
        while (insidePointer->next) {
            if (unionizedPointer->num == insidePointer->next->num) {
                duplicateNumber = insidePointer->next;
                insidePointer->next = insidePointer->next->next;
                delete(duplicateNumber);
            } else insidePointer = insidePointer->next;
        }
        unionizedPointer = unionizedPointer->next;
    }

    return unionizedLL;
}

Node* mergeLL(Node* LA, Node* LB) {
    // Initialize unionizedLL
    Node* mergeLL = NULL;
    
    // Add both linked lists to unionizedLL
    while (LA) {
        addToLinkedList(&mergeLL, LA->num);
        LA = LA->next;
    }

    while (LB) {
        addToLinkedList(&mergeLL, LB->num);
        LB = LB->next;
    }

    return mergeLL;
}

// Function that outputs all nodes in a linked list.
void outputLinkedList(Node* node) {
    // Check if a node exists
    while (node) {
        // If the next node does not exist, output two new lines instead of a comma
        if (!node->next) cout << node->num << endl << endl;
        else cout << node->num << ", ";
    
        // Set node equal to the next node
        node = node->next;
    }
}

int main() {
    // Initialize linkedLists
    Node* linkedListA = NULL;
    Node* linkedListB = NULL;
    Node* linkedListUnion = NULL;
    Node* linkedListMerge = NULL;

    // Add elements to linkedListA
    addToLinkedList(&linkedListA, 10);
    addToLinkedList(&linkedListA, 16);
    addToLinkedList(&linkedListA, 18);
    addToLinkedList(&linkedListA, 21);
    addToLinkedList(&linkedListA, 26);
    
    // Add elements to linkedListB
    addToLinkedList(&linkedListB, 10);
    addToLinkedList(&linkedListB, 13);
    addToLinkedList(&linkedListB, 16);
    addToLinkedList(&linkedListB, 17);
    addToLinkedList(&linkedListB, 20);
    addToLinkedList(&linkedListB, 23);

    // Output all nodes in linkedListA
    cout << "Linked List A:\n";
    outputLinkedList(linkedListA);

    // Output all nodes in linkedListB
    cout << "Linked List B:\n";
    outputLinkedList(linkedListB);

    // Unionize linkedLists
    linkedListUnion = unionLL(linkedListA, linkedListB);

    // Output all nodes in linkedListUnion
    cout << "Linked List Union:\n";
    outputLinkedList(linkedListUnion);

    // Merge linkedLists
    linkedListMerge = mergeLL(linkedListA, linkedListB);

    // Output all nodes in linkedListMerge
    cout << "Linked List Merge:\n";
    outputLinkedList(linkedListMerge);

    delete(linkedListA);
    delete(linkedListB);
    delete(linkedListUnion);
    delete(linkedListMerge);

    return 0;
}