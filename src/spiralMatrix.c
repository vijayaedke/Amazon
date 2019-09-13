#include<stdio.h>
#include<stdlib.h>
#define rows 3
#define cols 3 
int getLength(int a,int b){
    return a>b? (int)a/b  : (int)b/a;
}

void getSpiralMatrix(int array[rows][cols]){
    
   int *returnSize=(int *)malloc(sizeof(int) * rows * cols);
   int len=getLength(rows,cols), k=0;
    
   int rows_s=0, cols_s=0, rows_e=rows, cols_e=cols;
   
   /*
   rows_s = start of row index
   rows_e = end of row index
   end_s = start of column index
   end_e = end of column index
   */
   
   while(rows_s < rows_e && cols_s < cols_e){
       
       for(int i=cols_s;i<cols_e;i++){
            // printf("%d\t",array[rows_s][i]);
            returnSize[k++]=array[rows_s][i];
       }
       rows_s++;
       
       for(int i=rows_s;i<rows_e;i++){
        //   printf("%d\t", array[i][cols_e-1]);
           returnSize[k++]=array[i][cols_e-1];
       }
       cols_e--;
       
       if(rows_s < rows_e){
           for(int i=cols_e-1;i>=cols_s;i--){
            //   printf("%d\t",array[rows_e-1][i]);
               returnSize[k++]=array[rows_e-1][i];
           }
        rows_e--;
       }
       
       if(cols_s < cols_e){
           for(int i=rows_e-1;i>=rows_s;i--){
            //   printf("%d\t",array[i][cols_s]);
               returnSize[k++]=array[i][cols_s];
           }
        cols_s++;
       }
       
   }//while
    
    for(int i=0;i<k;i++)
        printf("%d\t",returnSize[i]);
}//getSpiralMatrix

int main() {
//   int a[rows][cols] = { { 1, 2, 3, 4, 5, 6 }, 
//                     { 7, 8, 9, 10, 11, 12 }, 
//                     { 13, 14, 15, 16, 17, 18 } }; 
                    
  int a[rows][cols] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  getSpiralMatrix(a);
  
  
  return 0;
}

/*
output :-
1	2	3	6	9	8	7	4	5	
*/
