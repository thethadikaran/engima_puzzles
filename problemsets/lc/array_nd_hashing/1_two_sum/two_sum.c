// PROBLEM -> https://leetcode.com/problems/two-sum/
// TIME COMPLEXITY  -> O(N)
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




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  // result array 
  int *res = malloc(2 * sizeof(int));
  *returnSize = 2;

  int diff = 0;

  // hashtable initialization
  HashTable *ht = createHashTable();

  for (int i = 0; i < numsSize; i++) {
    if ( search(ht, target-nums[i]) != -1) {
      // found the match that sums to target
      res[0] = i; 
      res[1] = search(ht, target-nums[i]);
      break;
    }
    insert(ht, nums[i], i);
  }

  return res;
}
