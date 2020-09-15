#include <stdio.h>

//#define max 3
//#define n 4
//#define max 7
//#define n 8
#define max 15
#define n 16

int comparacao_merge=0, troca_merge=0, flag_1=0;

//int a[n] = { 3,6,5,2 };
//int a[n] = { 4, 8, 2, 1, 9, 0, 2, 3 };
int a[n] = { 1, 3, 2, 7, 5, 5, 2, 7, 2, 9, 3, 0, 8, 3, 1, 4 };
//int a[n] = { 60, 77, 26, 184 };
//int a[n] = { 58, 94,96, 32, 49, 180, 11, 21 };

int b[n-1];

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      comparacao_merge++;
      if(a[l1] <= a[l2])
      {
         b[i] = a[l1++];
         troca_merge += 1;
      }
      else
      {
         b[i] = a[l2++];
         troca_merge += 1;      
      }
   }
   
   while(l1 <= mid)
   {
      b[i++] = a[l1++];
      troca_merge += 1;
   }
   while(l2 <= high)   
   {

      b[i++] = a[l2++];
      troca_merge += 1;
   }
   for(i = low; i <= high; i++)
   {
      a[i] = b[i];
      troca_merge += 1;
   }
}

void sort(int low, int high) {
   int mid;
   
   if(low < high) {
      //comparacao_merge += 1;
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else { 
      //comparacao_merge += 1;
      return;
   }   
}

int main() { 
   int i;

   printf("List before sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);

   sort(0, max);

   printf("\nList after sorting\n");
   
   for(i = 0; i <= max; i++)
   {
      printf("%d ", a[i]);
   }
        printf("\n");
      printf("troca %d \n", troca_merge);
      printf("comparacao %d \n", comparacao_merge);
}