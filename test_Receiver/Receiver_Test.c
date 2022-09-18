#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Receiver/receiver.h"

void TEST_CASE_01()
{
	printf("\n Test case to console read of temperature and soc values\n");
  float temperature_1[10],soc_1[10];
  int size=2;
  assert(ReadConsoleData(float *temperature,float *soc,int size)==size);
  printf("\n read data from console");
  for(int i=0;i<size;i++)
  {
    printf("%f , %f ",temperature_1[i],soc_1[i]);
  }
}

int main()
{
   TEST_CASE_01();
}
