#include<stdio.h>
//#define n 16
//#define n 8
#define n 4

int main(){
   /* Here i & j for loop counters, temp for swapping,
    * count for total number of elements, number[] to
    * store the input numbers in array. You can increase
    * or decrease the size of number array as per requirement
    */
   int i, j, count=16, temp, flag_while;
   int comparacoes=0, trocas=0;

   //printf("How many numbers u are going to enter?: ");
   //scanf("%d",&count);
   
   //int number[n] = {1, 3, 2, 7, 5, 5, 2, 7, 2, 9, 3, 0, 8, 3, 1, 4};
   //int number[n] = {4, 8, 2, 1, 9, 0, 2, 3};
   //int number[n] = {58, 94, 96, 32, 49, 180, 11, 21};
   //int number[n] = {60, 77, 26, 184};
   int number[n] = {3, 6, 5, 2};
   //printf("Enter %d elements: ", count);
   // This loop would store the input numbers in array
   //for(i=0;i<count;i++)
   //   scanf("%d",&number[i]);

   // Implementation of insertion sort algorithm
   for(i=1;i<n;i++){
     //if(temp!=number[i])
     //{
       temp=number[i];
        trocas += 1;
     //}
      
      j=i-1;
//        printf("inicio %d%d%d%d%d%d%d%d\n", number[0],number[1],number[2],number[3],number[4],number[5],number[6],number[7]);
//        printf("trocas %d\n", trocas);
//        printf("j %d\n", j);
       flag_while = 0;
       while((j>=0)&&(temp<number[j])){
        flag_while = 1;
        comparacoes += 1;
        //if (number[j+1]!=number[j])
        //{
          number[j+1]=number[j];
          trocas += 1;
        //}        
         j=j-1;
        flag_while = 0;
        }
        // se nao entrou no while
        if(!flag_while&&j>=0)
        {
          comparacoes += 1;
        }

        //if(number[j+1] != temp){
          number[j+1]=temp; 
          trocas += 1;
        //}
      }
      


//  printf("Order of Sorted elements: ");
   for(i=0;i<n;i++)
      printf(" %d",number[i]);
      printf("\n");
    
//    printf("\n");
   printf("%d\n",trocas);
    printf("%d\n",comparacoes);
   return 0;
}