#define E_OK               1
#define E_NOT_OK           0

#define SMA_SAMPLE_NUMBER  5

int ReadConsoleData(float *temperature,float *soc,int size);
float FindMinimumValue(float *values, int size);
float FindMaximumValue(float *values, int size);
float FindSimpleMovingAverage(float *values, int totalData, int numberOfSamples);
int PrintMinMaxSMAData(float *temperature,float *soc,int size);

  
