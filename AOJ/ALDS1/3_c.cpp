#include <iostream>
#include <string>
using namespace std;

struct Node {
  long data;
  struct Node* next;
  struct Node* prev;
  Node (long x) {
    data = x;
    next = NULL;
    prev = NULL;
  }
};

void insert(Node** head_ref, long x) {
  struct Node* new_node = new Node{0}; 
  new_node->data = x;
  if (*head_ref == NULL) {
    (*head_ref) = new_node;
    return;
  } else {
    new_node->next = (*head_ref);
    (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
  }
}

void delete_(Node** head_ref, long x) {
  struct Node* current_node = (*head_ref);
  while (current_node->data != x) {
    if (current_node->next) {
      current_node = current_node->next;
    } else {
      return;
    }
  }
  if (current_node->prev && current_node->next) {
    current_node->prev->next = current_node->next;
    current_node->next->prev = current_node->prev;
    return;
  } else if (!current_node->prev && !current_node->next) {
    (*head_ref) = NULL;
    return;
  } else if (!current_node->prev) {
    current_node->next->prev = NULL;
    (*head_ref) = current_node->next;
  } else if (!current_node->next) {
    current_node->prev->next = NULL;
  }
}

void delete_first(Node** head_ref) {
  if ((*head_ref)->next) {
    (*head_ref)->next->prev = NULL;
    (*head_ref) = (*head_ref)->next;
  } else {
    (*head_ref) = NULL;
  }
}

void delete_last(Node** head_ref) {
  Node* current_node = (*head_ref);
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }
  if (current_node->prev) {
    current_node->prev->next = NULL;
  } else {
    (*head_ref) = NULL;
  }
}

int main() {
  long n;
  cin >> n;
  string command;
  struct Node* head_node = NULL;
  for (long i = 0; i < n; i++) {
    cin >> command;
    if (command == "insert") {
      long x; 
      cin >> x;
      insert(&head_node, x);
    }

    if (command == "delete") {
      long x;
      cin >> x;
      delete_(&head_node, x);
    }

    if (command == "deleteFirst") {
      delete_first(&head_node);
    }

    if (command == "deleteLast") {
      delete_last(&head_node);
    }
  }
  Node* current_node = head_node;
  cout << current_node->data;
  while (current_node->next != NULL) {
    cout << " ";
    current_node = current_node->next;
    cout << current_node->data;
  }
  cout << endl;
}
