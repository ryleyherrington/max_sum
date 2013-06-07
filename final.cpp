/*
 * Ryley Herrington 
 * February 24, 2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>
#define LINELEN 1000000

int brute_force(int arr[], int size){
	int sum = INT_MIN;	
	int max_sum = 0;
	for(int i=0; i < size; i++) {
		for(int j=i; j < size; j++) {
		sum = 0;
			for(int k=i ; k < j; k++) {
				sum = sum + arr[k];
			}
		max_sum = (max_sum > sum)?max_sum:sum;
		}
	}
	return max_sum;
}

int dynamic(std::vector<int>& arr) {
        size_t begin, temp, end = 0;
        int curr_max  = arr[0], temp_max = arr[0];
        for(size_t i=1; i<arr.size(); ++i) {
                if(temp_max < 0) {
                        temp_max = arr[i];
                        temp = i;
                }
                else {
                        temp_max += arr[i];
                }
                if(temp_max > curr_max ) {
                        curr_max  = temp_max;
                        begin = temp;
                        end = i;
                }
        }
        return curr_max ;
}

int d_c(int arr[], int left, int right) {
	int mid, sum, max_left, max_right, max_cross, max_a, max_b;
	int i;
	
	if(left > right){
		return 0;
	}
	if(left==right){
		return((0 > arr[left])? 0 : arr[left]);
	}
	mid = (left + right)/2;
	
	sum=0;
	max_left=0;
	for(i=mid; i >= left; i--) {
		sum = sum + arr[i];
		max_left = ((max_left > sum)? max_left : sum);
	}
	
	sum=0;
	max_right=0;
	for(i=mid+1; i <= right; i++) {
		sum = sum + arr[i];
		max_right = (max_right > sum)?max_right:sum;
	}
	
	max_cross = max_left + max_right;
	max_a = d_c(arr, left,mid);
	max_b = d_c(arr, mid+1,right);
	return(((max_cross > max_a)?max_cross:max_a) > max_b?((max_cross>max_a)?max_cross:max_a):max_b);
}
int main(int argc, char* argv[]) {

  int function_select = argc>1 ? atoi(argv[1]) : 1;

  int val;
  char *linebuff = (char*)malloc(LINELEN);
  std::vector<int> numarr;
  if (!linebuff) exit(-1);
  while (fgets(linebuff, LINELEN, stdin) != NULL) {
      numarr.clear();
      char *p = linebuff;
      char *n = p;
      while ((p = strchr(p, ',')) != NULL) {
         *p = '\0';
         val = atoi(n);
         numarr.push_back(val);
         p++;
         n = p;
      }
      val = atoi(n);
      numarr.push_back(val);
      int myanswer;
      switch (function_select) {
         case 1 : myanswer = brute_force(numarr.data(), numarr.size()); break;
         case 2 : myanswer = d_c(numarr.data(), 0, numarr.size()-1); break;
         case 3 : myanswer = dynamic(numarr); break;
         default : printf("Invalid function selection\n"); break;
      }
      printf("my answer == %6d \n", myanswer);   
  }

  return 0;
}
