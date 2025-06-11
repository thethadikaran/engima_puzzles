// PROBLEM -> https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary
// TIME COMPLEXITY  -> O(N)
// SPACE COMPLEXITY -> O(1)

double average(int* salary, int salarySize) {
  int min = salary[0], max = salary[0];
  double sum = 0;

  for (int emp = 0; emp < salarySize; emp++) {
    sum += salary[emp];

    if (salary[emp] < min) min = salary[emp];
    if (salary[emp] > max) max = salary[emp];
  }

  // exclude the min and mix from the sum
  sum -= (min + max);

  // avg salary excluding min and max
  return sum / (salarySize - 2);    
}
