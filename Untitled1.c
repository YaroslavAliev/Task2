#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//создаем масив
void Masiv(double* array, int size){
  srand(time(NULL));
  for(int i = 0;i < size;i++){
    array[i] = (double)(rand() % 101 + (-50)) + (double)(rand() % 100)/100; 
  }
}

//среднее
double seredn(double* array, int size)
{
  double sum = 0.0;
  for(int i = 0;i < size;i++){
    sum += array[i];
  }
  return sum/size;
}

//печать массива
void print_Masiv(double* array, int size)
{
  for(int i = 0;i < size;i++){
    printf("Masiv[%d] = %0.2lf \n", i, array[i]);
  }
}

//больше суммы
int moreSum(double* array, int size)
{
  double sum_num = seredn(array, size);
  int count = 0;
  for(int i = 0;i < size; i++){
    if(array[i] > sum_num)
      count++;
  }
  return count;
}

 //после минусования
double sum2(double* array, int size){
  int flag = 0;
  int indx = -1;
  double sum = 0;
  for(int i = 0;i < size; i++){
    if(array[i] < 0){
      flag = 1;
      indx = i+1;
      break;
    }
  }
  if(flag != 0 && indx < size)
    for(indx; indx < size;indx++)
      sum+= fabs(array[indx]);
  return sum;
}

//главная менюшка
int main(){
int n = 0;
printf("Enter size Masiva(10): ");
scanf("%d", &n);
if(n <= 0){
printf("EROR, not zero");
  return 0;
}
double* arr = (double*)malloc(sizeof(double) * n);

Masiv(arr, n);
print_Masiv(arr, n);
printf("seredn = %0.2lf\n", seredn(arr, n));
printf("%d numbers more seredn\n", moreSum(arr,n));
printf("sum elements after first nagative = %0.2lf\n", sum2(arr, n)); 

free(arr);
return 0;
}