// PROBLEM -> https://leetcode.com/problems/contains-duplicate/
// TIME COMPLEXITY  -> O(N) ; worst case O(N^2) if any collision occurs
// SPACE COMPLEXITY -> O(N)


#define TABLE_SIZE 100000

typedef struct Node {
  int key;
  int value;
  struct Node *next;
} Node;

typedef struct HashTable {
  Node **table;
} HashTable;

// Function to create a new hash table
HashTable* createHashTable() {
  HashTable *hashTable = malloc(sizeof(HashTable));
  hashTable->table = malloc(sizeof(Node*) * TABLE_SIZE);
  for (int i = 0; i < TABLE_SIZE; i++) {
      hashTable->table[i] = NULL;
  }
  return hashTable;
}

// Hash function
unsigned int hash(int key) {
  return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE; // Handles negative keys
}

// Function to insert a key-value pair
void insert(HashTable *hashTable, int key, int value) {
  unsigned int index = hash(key);
  Node *newNode = malloc(sizeof(Node));
  newNode->key = key;
  newNode->value = value;
  newNode->next = hashTable->table[index];
  hashTable->table[index] = newNode;
}

// Function to search for a value by key
int search(HashTable *hashTable, int key) {
  unsigned int index = hash(key);
  Node *current = hashTable->table[index];
  while (current != NULL) {
      if (current->key == key) {
          return current->value;
      }
      current = current->next;
  }
  return -1; // Not found
}




bool containsDuplicate(int* nums, int numsSize) {
  HashTable *ht = createHashTable();

  for (int i = 0; i < numsSize; i++) {
    // if the number is not present then add it else, return
    if (search(ht, nums[i]) == -1)
      insert(ht, nums[i], 1);
    else
      return true;
  }

  return false;    
}
