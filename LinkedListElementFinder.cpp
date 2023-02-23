#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node** head_ref, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int getNthFromLast(Node* head, int n) {
    if (head == NULL) {
        return -1;
    }
    Node* ptr1 = head;
    Node* ptr2 = head;
    for (int i = 0; i < n; i++) {
        if (ptr1 == NULL) {
            return -1;
        }
        ptr1 = ptr1->next;
    }
    while (ptr1 != NULL) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr2->data;
}

int main() {
    Node* head = NULL;
    int n, data, num;
    cout << "\nEnter the number of elements to be inserted: ";
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> data;
        insertNode(&head, data);
    }
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "\nYour Linked List: ";
    printList(head);
    int result = getNthFromLast(head, n);
    if (result == -1 ){
        cout << "\nOutput: -1." << "\nExplanation: there are " << num << " nodes in the linked\n"
             << "list and we need to find " << n << "th from the end.\n"
             << "Since 'n' is more than the number of nodes \n"
             << "in the linked list, the output is -1.\n"
             << endl;
    }
    else {
        if (n == 2){
             cout << "\nOutput: " << result << "." << "\nExplanation: there are " << num << " nodes in the linked\n"
             << "list and we need to find " << n << "nd from the end.\n"
             << "The "<< n << "nd node from the end is: " << result << "\n"
             << endl;
        } else if (n == 1) {
             cout << "\nOutput: " << result << "." << "\nExplanation: there are " << num << " nodes in the linked\n"
             << "list and we need to find " << n << "st from the end.\n"
             << "The "<< n << "st node from the end is: " << result << "\n"
             << endl;
        } else {
             cout << "\nOutput: " << result << "." << "\nExplanation: there are " << num << " nodes in the linked\n"
             << "list and we need to find " << n << "th from the end.\n"
             << "The "<< n << "th node from the end is: " << result << "\n"
             << endl;
        }
    }
    return 0;
}
