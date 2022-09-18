#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Receiver/receiver.h"

void TEST_CASE_01()
{
  printf("\n Test case to console read of temperature and soc values\n");
  float temperature_01[10],soc_01[10];
  int size_01=2;
  assert(ReadConsoleData(&temperature_01[0],&soc_01[0],size_01)==size_01);
  printf("\n read data from console");
  for(int i=0;i<size_01;i++)
  {
    printf("%f , %f ",temperature_01[i],soc_01[i]);
  }
}
void TEST_CASE_02()
{
  printf("\n Test case to find minimum and maximum values from array\n");
  float temperature_02[10]={1.5,55,89.5,25.6,6,2.8,9.8,22,15.6,8.9};
  float soc_02[10]={98,56,85.6,95,1,56,89,26,6.8,7.9};
  int size_02=10;
  assert(FindMaximumValue(&temperature_02[0],size_02)==89.5);
  assert(FindMaximumValue(&soc_02[0],size_02)==98);
  assert(FindMinimumValue(&temperature_02[0],size_02)==1.5);
  assert(FindMinimumValue(&soc_02[0],size_02)==1);
}
void TEST_CASE_03()
{
  printf("\n Test case to find SMA \n");
  float temperature_03[10]={1.5,55,89.5,25.6,6,8,2,10,5,15};
  float soc_03[10]={98,56,85.6,95,1,3.5,1.5,20,2.1,7.9};
  int size_03=10;
  assert(FindSimpleMovingAverage(&temperature_03[0],size_03,5)==8);
  assert(FindSimpleMovingAverage(&soc_03[0],size_03,5)==7);
}

void TEST_CASE_04()
{
  printf("\n Test case to find min ,max and SMA from the console read if data size not zero \n");
  float temperature_04[10],soc_04[10];
  int size_04=10;
  assert(PrintMinMaxSMAData(&temperature_04[0],&soc_04[0],size_04)==E_OK);
} 
void TEST_CASE_05()
{
  printf("\n Test case to find min ,max and SMA from the console read if data size is zero \n");
  float temperature_05[10],soc_05[10];
  int size_05=0;
  assert(PrintMinMaxSMAData(&temperature_05[0],&soc_05[0],size_05)==E_NOT_OK);
} 
void TEST_CASE_06()
{
  printf("\n Test case to find min ,max and SMA from the console read if data size is not zero but less than 5 \n");
  float temperature_06[10],soc_06[10];
  int size_06=2;
  assert(PrintMinMaxSMAData(&temperature_06[0],&soc_06[0],size_06)==E_NOT_OK);
} 
int main()
{
   TEST_CASE_01();
   TEST_CASE_02();
   TEST_CASE_03();
   TEST_CASE_04();
   TEST_CASE_05();
   TEST_CASE_06();
}
