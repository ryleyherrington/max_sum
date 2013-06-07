#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char*argv[]) {

   int count = argc>1 ? atoi(argv[1]) : 10000;
   
   for (int i=0; i<count-1; i++) {
      printf("%d,", rand()%200-100);
   }
   printf("%d\n", rand()%200-100);

   return 0;
}
