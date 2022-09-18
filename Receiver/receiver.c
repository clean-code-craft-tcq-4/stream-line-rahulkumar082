#include <stdio.h>
#include "receiver.h"


/*
 **********************************************************************************************************************
 * Service name             : ReadConsoleData
 * Syntax                   : int ReadConsoleData(float *temperature,float *soc,int size)
 * param[in/out]            : temperature (pointer to array for storing console read data)
 * param[in/out]            : soc (pointer to array for storing console read data)
 * param[in]                : size    (total data size)
 * return                   : processed data size
 * Description              : Function to read the console data(Temperature and SOC values ) 
 **********************************************************************************************************************
 */
int ReadConsoleData(float *temperature,float *soc,int size)
{
    int count;
    char dummy;
    for(count=0;count<size;count++)
    {
        scanf("%c",&dummy);
        if(dummy == ']')
        {
            /*This part cannot be covered ,it's a special usecase to the specific receiver*/
            break;   
        }
        scanf("%c",&dummy);
        scanf("%f",&temperature[count]);
        scanf("%c",&dummy);
        printf("%c",dummy);
        scanf("%f",&soc[count]);
        scanf("%c",&dummy);
    }
    return count; /*return the total number of Data pair*/
}

/*
 **********************************************************************************************************************
 * Service name             : FindMinimumValue
 * Syntax                   : float FindMinimumValue(float *values, int size)
 * param[in/out]            : values (pointer to array having data)
 * param[in]                : size    (total data size)
 * return                   : minimum value
 * Description              : Function to find the minimum value from an array of values
 **********************************************************************************************************************
 */ 

float FindMinimumValue(float *values, int size)
{
    float minimumValue = values[0];
    for (int i = 1; i < size; i++)
    {
        if (values[i] < minimumValue)
        {
            minimumValue = values[i];
        }
    }
    return minimumValue;
}

/*
 **********************************************************************************************************************
 * Service name             : FindMaximumValue
 * Syntax                   : float FindMaximumValue(float *values, int size)
 * param[in/out]            : values (pointer to array having data)
 * param[in]                : size    (total data size)
 * return                   : maximum value
 * Description              : Function to find the maximum value from an array of values
 **********************************************************************************************************************
 */

float FindMaximumValue(float *values, int size)
{
    float maximumValue = values[0];
    for (int i = 1; i < size; i++)
    {
        if (values[i] > maximumValue)
        {
            maximumValue = values[i];
        }
    }
    return maximumValue;
}

/*
 **********************************************************************************************************************
 * Service name             : FindSimpleMovingAverage
 * Syntax                   : float FindSimpleMovingAverage(float *values, int totalData, int numberOfSamples)
 * param[in/out]            : values (pointer to array having data)
 * param[in]                : totalData    (total data size)
 * param[in]                : numberOfSamples (last required number of samples for calculate SMA)
 * return                   : simple moving average
 * Description              : Function to find the simple moving average of last few values
 **********************************************************************************************************************
 */

float FindSimpleMovingAverage(float *values, int totalData, int numberOfSamples)
{
    float sum = 0;
    for (int i = 0; i < numberOfSamples; i++)
    {
        sum += values[totalData-1-i];
    }
    return (sum / numberOfSamples);
}

/*
 **********************************************************************************************************************
 * Service name             : PrintMinMaxSMAData
 * Syntax                   : int PrintMinMaxSMAData(float *temperature,float *soc,int size)
 * param[in/out]            : temperature (pointer to array for storing console read data)
 * param[in/out]            : soc (pointer to array for storing console read data)
 * param[in]                : size    (total data size)
 * return                   : data processed or not (0-Data not processed,1-Data processed)
 * Description              : Function to print minimum,maximum and SMA values
 **********************************************************************************************************************
 */

int PrintMinMaxSMAData(float *temperature,float *soc,int size)
{
  int functionStatus=E_NOT_OK;
    if(size!=0)
    {
      functionStatus=E_OK;
    	int dataSize;
    	float TempeartureMin,TempeartureMax,SocMin,SocMax,TemperatureSma,SocSma;
    	dataSize=ReadConsoleData(temperature,soc,size);
    	TempeartureMin = FindMinimumValue(temperature,dataSize);
    	TempeartureMax = FindMaximumValue(temperature,dataSize);
    	SocMin = FindMinimumValue(soc,dataSize);
    	SocMax = FindMaximumValue(soc,dataSize);
    	
    	printf("\nMaximum and Minimum Temperature values\n");
    	printf("Maximum = %f    Minimum = %f \n",TempeartureMax,TempeartureMin);
    	printf("\n\nMaximum and Minimum SOC values\n");
    	printf("Maximum = %f    Minimum = %f \n",SocMax,SocMin);
    	if(dataSize>=SMA_SAMPLE_NUMBER)
    	{
    	TemperatureSma = FindSimpleMovingAverage(temperature,dataSize,SMA_SAMPLE_NUMBER);
    	SocSma = FindSimpleMovingAverage(soc,dataSize,SMA_SAMPLE_NUMBER);
    
    	printf("\n\nSimple Moving Average of Temperature and SOC\n");
    	printf("SMA of Temperature = %f    SMA of SOC = %f \n",TemperatureSma,SocSma);
    	}
    	else
    	{
    	    printf("couldn't take %d samples for SMA",(int)SMA_SAMPLE_NUMBER);
            functionStatus=E_NOT_OK;
    	}
    }
  return(functionStatus);
}
