// linked_list.cc -- functions for linked_list lab (cs221) 

struct Node {
  int key;
  Node* next;
}; 

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: newKey is the value for the key in the new Node 
 * POST: the new Node is now the head of the linked_list
 */ 
void insert(Node*& head, int newKey) {
  Node * curr = new Node;
  curr->key  = newKey;
  curr->next = head;

  head = curr;
}

/**
 * Print the keys of a linked_list in order, from head to tail 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
void print(Node* head) {
  std::cout << "[";
  for (Node* curr = head; curr != NULL; curr = curr->next){ 
    std::cout << curr->key;
    if (curr->next != NULL) std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

/** 
 * Returns the size (number of Nodes) of the linked_list  
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
int size(Node* head){ 
  if (! head) return 0; 
  return 1 + size(head->next); 
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * POST: a new vector<int> containing the keys in the correct order has been returned.  
 */ 
std::vector<int>* to_vector(Node* head){ 
  std::vector<int>* result = new std::vector<int>(); 
  for (Node* curr = head; curr != NULL; curr = curr->next ){ 
    result->push_back(curr->key); 
  }
  return result; 
}

/** 
 * Delete the last Node in the linked_list
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * POST: the last Node of the linked_list has been removed
 * POST: if the linked_list is now empty, head has been changed 
 */
void delete_last_element(Node*& head){
  // ******** WRITE YOUR CODE HERE ********
  Node* curr = head;
  Node* last;
  while(curr->next != NULL) {
      last = curr;
      curr = curr->next;
  }
  delete curr;
  last->next = NULL;


}

/**
 * Removes an existing Node (with key=oldKey) from the linked_list. 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value of the key in the Node to be removed 
 * PRE: if no Node with key=oldKey exists, the linked_list has not changed 
 * POST: if a Node with key=oldKey was found, then it was deleted
 * POST: other Nodes with key=oldKey might still be in the linked_list
 */ 
void remove(Node*& head, int oldKey) {
    //
}

/**
 * Insert a new Node (with key=newKey) after an existing Node (with key=oldKey)
 * If there is no existing Node with key=oldKey, then no action.
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value to look for (in the key of an existing Node)  
 * PRE: newKey is the value of the key in the new Node (that might be inserted) 
 * POST: If no Node with key=oldKey was found, then the linked_list has not changed 
 * POST: Else a new Node (with key=newKey) is right after the Node with key = oldKey. 
 */
void insert_after(Node* head, int oldKey, int newKey){
  Node* curr = head;

  while( curr->next != NULL && curr->key != oldKey ) {
      curr = curr->next;
  }

  if( curr->key == oldKey ) {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = curr->next;
      curr->next = newNode;
  }
}

/** 
 * Create a new linked_list by merging two existing linked_lists. 
 * PRE: list1 is the first Node in a linked_list (if NULL, then it is empty)
 * PRE: list2 is the first Node in another linked_list (if NULL, then it is empty)
 * POST: A new linked_list is returned that contains new Nodes with the keys from 
 * the Nodes in list1 and list2, starting with the key of the first Node of list1, 
 * then the key of the first Node of list2, etc. 
 * When one list is exhausted, the remaining keys come from the other list.
 * For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
 */
Node* interleave(Node* list1, Node* list2){
  Node* curr1 = list1; //for keeping track of current position in list1
  Node* curr2 = list2; //for keeping track of current position in list2
  Node* newNode; //pointer for creating new node
  Node* newList = new Node; //list we will return
  Node* currNew = newList; //for keeping track of position in new list
  // Initializing head of new list
  if(curr1 != NULL) { //if list1 isnt empty we set it to the head of new list
      newList->key = curr1->key;
      curr1 = curr1->next;
      if(curr2 != NULL) { //also check list2 so our loop works
          newNode = new Node;
          newNode->key = curr2->key;
          currNew->next = newNode;
          curr2 = curr2->next;
          currNew = newNode;
      }
  }
  else if(curr2 != NULL) {
      newList->key = curr2->key;
      curr2 = curr2->next;
  }
  while( curr1 != NULL || curr2 != NULL ) {
      if(curr1 != NULL) {
          newNode = new Node;
          newNode->key = curr1->key;
          curr1 = curr1->next;
          currNew->next = newNode;
          currNew = newNode;
      }
      if(curr2 != NULL) {
          newNode = new Node;
          newNode->key = curr2->key;
          curr2 = curr2->next;
          currNew->next = newNode;
          currNew = newNode;
      }
  }
  return newList;
}

