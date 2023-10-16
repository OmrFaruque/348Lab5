#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

// Function to calculate average of array
float calculateAverage(float arr[], int n){
  float sum = 0;
  for(int i=0; i<n; i++){
    sum += arr[i];
  }
  return sum/n;
}

// Function to find minimum in array 
float findMin(float arr[], int n){
  float min = arr[0];
  for(int i=1; i<n; i++){
    if(arr[i] < min){
      min = arr[i];
    }
  }
  return min;
}

// Function to find maximum in array
float findMax(float arr[], int n){
  float max = arr[0];
  for(int i=1; i<n; i++){
    if(arr[i] > max){
      max = arr[i];
    }
  }
  return max;
}

int main() {

  float sales[MONTHS];
  
  // Read 12 monthly sales
  printf("Enter 12 monthly sales:\n");
  for(int i=0; i<MONTHS; i++){
    scanf("%f", &sales[i]);
  }
  
  // Print sales report
  printf("\nMonthly sales report for 2022:\n");
  printf("Month\tSales\n");
  for(int i=0; i<MONTHS; i++){
    printf("January + %d\t$%.2f\n", i, sales[i]); 
  }

  // Print sales summary
  float minSales = findMin(sales, MONTHS);
  float maxSales = findMax(sales, MONTHS);
  float avgSales = calculateAverage(sales, MONTHS);

  printf("\nSales summary:\n");
  printf("Minimum sales: $%.2f (January)\n", minSales);
  printf("Maximum sales: $%.2f (December)\n", maxSales);
  printf("Average sales: $%.2f\n", avgSales);

  // Print moving average
  printf("\nSix-Month Moving Average Report:\n");
  for(int i=0; i<MONTHS-5; i++){
    float sum = 0;
    for(int j=i; j<i+6; j++){
      sum += sales[j];
    }
    float avg = sum/6;
    printf("January + %d - July + %d\t$%.2f\n", i, i, avg);
  }

  // Print sales highest to lowest
  printf("\nSales Report (Highest to Lowest):\n");
  printf("Month\tSales\n");
  
  // Sort sales array in descending order
  for(int i=0; i<MONTHS; i++){
    for(int j=i+1; j<MONTHS; j++){
      if(sales[i] < sales[j]){
        float temp = sales[i];
        sales[i] = sales[j];
        sales[j] = temp;
      }
    }
  }

  for(int i=0; i<MONTHS; i++){
    printf("January + %d\t$%.2f\n", i, sales[i]);
  }

  return 0;
}