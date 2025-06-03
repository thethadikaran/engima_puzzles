// PROBLEM -> https://leetcode.com/problems/richest-customer-wealth/
// TIME COMPLEXITY  -> O(M x N)    ; M - no of customer, N - no of accounts each customer has
// SPACE COMPLEXITY -> O(1)

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
  int max = 0;

  for (int customer = 0; customer < accountsSize; customer++) {
    int money = 0;

    // calcualte total money a customer has
    for (int acc = 0; acc < *accountsColSize; acc++) 
      money += accounts[customer][acc];

    if (money > max) max = money;
  }

  return max;    
}
