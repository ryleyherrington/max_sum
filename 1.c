#include <stdio.h>
#include <stdlib.h>

int getInvCount(int arr[], int n) {
  int inv_count = 0;
  int i, j;

  for(i = 0; i < n - 1; i++){
    for(j = i+1; j < n; j++){
      if(arr[i] > arr[j]){
        inv_count++;
	  }
	}
  }
  return inv_count;
}

/* Driver progra to test above functions */
int main(int argv, char** args) {
  int arr[] = {1, 4, 2, 5, 3};
  printf(" Number of inversions are %d \n", getInvCount(arr, 5));
  getchar();
  return 0;
  exit(-1);
}
