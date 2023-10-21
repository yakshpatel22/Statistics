
/*
*Program Name : Statistics (Lies, Damn Lies, and Statistics)
*Purpose : Creating a C17 console application to compile the following statistics on a list of real numbers
*Coder: Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define FILENAME "3d10_1M.txt"
#define FILENAME "linear_100.txt"
#define FILENAME "log_1.6_0.8_1K.txt"
//#define __FILENAME__ (strrchr(3d10_1M.txt, '\\') ? strrchr(3d10_1M.txt, '\\') + 1 : 3d10_1M.txt)

/*
*Function: Minimum Value
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which will find the minimum value in all the given input . I created it by  using a float and
*long long as the input values .
* The value that is less than or equal to all values in the set. min less than equal to x , where x belongs to all the real numbers.
*Return: This function will return smallest value in float from the given input values or from the user or  read from the file
*/
float getMinimumValue(float* x, long long y)
{
	long long  value = 0;
	for (long long i = 1; i < y; i++)
		if (x[i] < x[value])
			value = i;

	return x[value];
}

/*
*Function: Maximum Value
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which will find the Maximum value in all the given input . I created it by  using a float and
*int as the input values .
*The value that is greater than or equal to all the values in the set. max greater than or equal to x, where x belongs to real numbers. 
*Return: This function will return Largetst value in float from the given input values from the user or read from the file
*/
float getMaximumValue(float* x, int  y)
{
	int  value = 0;
	for (int i = 1; i < y; i++)
		if (x[i] > x[value])
			value = i;

	return x[value];
}

/*
*Function: Range
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which will find the range of the given input from the user or read from the file that is dataset . Range is obtained by
*subtracting the minimum value from the maximum value.
*The range of values of the dataset. Here minimum subtracted from maximum.
*Return: This function will return the Range of the input user or  read from the file in float.
*/
float getRange(float minValue, float maxValue)
{
	return maxValue - minValue;
}

/*
*Function: Median
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which will find the median of the given input from the user or read from the file . Median is obtained by
*The middle value of a sorted data set of odd length, or the arithmetic mean of the two closest values of the middle of a sorted data set of even length
* {(n + 1) ÷ 2}th, where “n” is the number of items in the set and “th” just means the (n)th number. To find the median, first ordering  the numbers
* from smallest to largest. Then find the middle number.
*The middle value of a sorted data set of odd length, or the arithmetic mean of the two closest values of the middle of a sorted data set of even length
*Return: This function will return the median of the input user or  read from the file in float.
*/
float getMedian(float* x, long long  y)
{

	long long  value = (y + 1) / 2 - 1;
	return x[value];

}

/*
*Function: Mean
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which will find the mean of the given input from the user or read from the file .
* The mean formula is given as the average of all the observations. It is expressed as Mean = {Sum of Observation} ÷ {Total numbers of Observations}.
*Return: This function will return the median of the input user or  read from the file in float.
*/
float getMean(float* x, long long  y)
{

	float sum = 0;

	for (long long i = 0; i < y; i++)
	{
		sum = sum + x[i];
	}

	return sum / y;

}

/*
*Function: Variance
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which will find the variance of the given input from the user or read from the file .
*The formula for variance of a is the sum of the squared differences between each data point and the mean, divided by the number of data values .
*Return: This function will return the variance of the input user or  read from the file in float .
*/
float getVariance(float* x, long long  y)
{
	float sum = 0;
	for (long long i = 0; i < y; i++) {
		sum += x[i];
	}
	float mean = (float)sum / (float)y;

	float sqr = 0;
	for (long long i = 0; i < y; i++) {
		sqr += (x[i] - mean) * (x[i] - mean);
	}
	return sqr / y;
}


/*
*Function: Standard Deviation
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which will find the standard deviation of the given input from the user or read from the file .
*The standard deviation is calculated as the square root of variance by determining each data point's deviation relative to the mean.
*If the data points are further from the mean, there is a higher deviation within the data set; thus, the more spread out the data, the higher the standard deviation.
*Return: This function will return the standard deviation  of the input user or  read from the file in float.
*/
float getStandardDeviation(float* x, long long  y)
{
	return sqrtf(getVariance(x, y));
}

/*
*Function: Frequency Table
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which will create the Frequency table from the given input from the user or read from the file .
*A frequency table is a table that lists items and shows the number of times the items occur.
*/
void getFrequencyTable(float* x, long long int* y, float* z, float m, double  n, long long int  q)
{


	float value = m;
	for (long long i = 0; i < 10; i++)
	{
		for (long long j = 0; j < q; j++)
		{
			if (x[j] >= value && x[j] < (value + n))
			{

				y[i]++;
			}

		}
		value = value + n;
	}

	char notation = 'A';
	value = m;
	for (long long int i = 0; i < 10; i++)
	{
		printf("%c [%*.2f..%*.2f) =%*lld:%*.2f %%\n", notation++, 8, value, 8, value + n - 1, 8, y[i], 8, ((float)y[i] / q) * 100);

		value = value + n;
	}

	for (long long int i = 0; i < 10; i++)
	{
		z[i] = ((double)y[i] / q) * 100;
	}

}

/*
*Function: Histogram
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which will create a histogram from the given input from the user or read from the file .
* A histogram is a graphical representation that organizes a group of data points into user-specified ranges.
*Similar in appearance to a bar graph, the histogram condenses a data series into an easily interpreted visual by taking many data points
*and grouping them into logical ranges or bins.
*/
void getHistogram(long long* x, float* y, float z, double n, float size)
{
	float percent = getMaximumValue(y, 10);
	char counter = 'A';
	float value = 0;
	printf("\nGrp\t%% %.1f\t", value);
	for (int i = 0; i < 10; i++)
	{
		printf("   %.1f\t", value + 10);
		value = value + 10;
	}
	printf("\n");

	for (int i = 0; i < 7; i++)
	{
		printf("%c", 196);
	}

	printf(" ");
	for (int i = 0; i < 12; i++)
	{
		printf("%c%c%c%c%c%c%c", 196, 196, 196, 193, 196, 196, 196);
	}

	printf("\n");

	for (int i = 0; i < 10; i++)
	{

		printf("%c  %*.2f%%  %c ", counter++, 5, y[i], 179);
		size = (y[i] * 75) / 100;

		for (int j = 0; j < size; j++)
		{
			printf("%c", 254);
		}
		printf("\n");
	}

	for (int i = 0; i < 7; i++)
	{
		printf("%c", 196);
	}

	printf(" ");
	for (int i = 0; i < 12; i++)
	{
		printf("%c%c%c%c%c%c%c", 196, 196, 196, 193, 196, 196, 196);
	}

}

/*
*Function: Logarthmic Transform
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which will create the Logarthmic Transform from the given input from the user or read from the file .Similarly,
* Log transformation is a data transformation method in which it replaces each variable x with a log(x). The choice of the logarithm base
*is usually left up to the analyst and it would depend on the purposes of statistical modeling.
*Log transformation is a data transformation method in which it replaces each variable x with a log(x).
*The choice of the logarithm base is usually left up to the analyst and it would depend on the purposes of statistical modeling.
*/
void getLogarthmicTransform(float* x, float* t, long long  y)
{

	for (long long i = 0; i < y; i++)
	{
		t[i] = log(x[i]);
	}

}


/*
*Function: Merge(Sorting the data)
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which sort the data which given from the user or read from the file  .
*/
void Merge(float* x, long long int l, long long int m, long long int r)
{
	const long long int arr1 = m - l + 1;
	const long long int arr2 = r - m;


	float* S = (float*)malloc(arr1 * sizeof(float)), * E = (float*)malloc(arr2 * sizeof(float));

	for (long long int i = 0; i < arr1; i++) {
		S[i] = x[l + i];
	}
	for (long long int j = 0; j < arr2; j++) {
		E[j] = x[m + 1 + j];
	}

	long long int i = 0;
	long long int j = 0;
	long long int k = l;

	while (i < arr1 && j < arr2) {
		if (S[i] <= E[j]) {
			x[k] = S[i];
			i++;
		}
		else {
			x[k] = E[j];
			j++;
		}
		k++;
	}


	while (i < arr1) {
		x[k] = S[i];
		i++;
		k++;
	}


	while (j < arr2) {
		x[k] = E[j];
		j++;
		k++;
	}
}

/*
*Function: Merge sort
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which will merge sort the data from the given input from the user or read from the file .
*Merge Sort  works on the principle of Divide and Conquer. Merge sort repeatedly breaks down a list into several sublists until
*each sublist consists of a single element and merging those sublists in a manner that results into a sorted list.
*/
void mergeSort(float* x, long long int y, long long int r)
{
	if (y >= r)
	{
		return;
	}
	long long int m = y + (r - y) / 2;
	mergeSort(x, y, m);
	mergeSort(x, m + 1, r);
	Merge(x, y, m, r);
}

/*
*Function: statistics
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which will display mean , median,range,minimum,maximum , number of elements,variance ,
*standard deviation , frequency table and Histogran from the user or read from the file  .
*Return: This function will return the calculated output of the depicted earlier mathematical calculations.
*/
void getStatistics(float* x, float* y, long long int* z, float* q, double n, long long int a, float width)
{
	n = 0;

	for (long long int i = 0; i < 10; i++)
	{
		z[i] = 0;
	}

	for (long long int i = 0; i < a; i++) {
		y[i] = x[i];
	}

	mergeSort(y, 0, a - 1);
	float min = y[0];
	float max = y[a - 1];
	n = (max - min) / 10;
	printf("___________________________________________________________________\n");
	printf("___________________________________________________________________\n");
	printf("# element         %10d\n", a);
	printf("minimum           %10.3f \n", min);
	printf("maximum           %10.3f \n", max);
	printf("range             %10.3f \n", getRange(min, max));
	printf("mean              %10.3f \n", getMean(x, a));
	printf("median            %10.3f \n", getMedian(y, a));
	printf("variance          %10.3f \n", getVariance(x, a));
	printf("std. dev.         %10.3f \n", getStandardDeviation(x, a));
	printf("___________________________________________________________________\n");
	printf("___________________________________________________________________\n");
	printf("Frequency Table\n");
	getFrequencyTable(x, z, q, min, n, a);
	printf("___________________________________________________________________\n");
	printf("___________________________________________________________________\n");
	printf("Histogram\n");
	getHistogram(z, q, min, n, width);

}

/*
*Function: Statistics1
*Author : Yaksh Patel
*Date: 15-October-2021
*Version : 1.0.0
*Description : Writing a function which output the Log frequency Table and Log Histogram .
*Return: This function will return thecreated log frequency table and log histogram from  the file or got from the user's input .
*/
void getFreqTableHistogram(float* x, float* y, long long int* z, float* q, double n, long long int a, float width)
{
	n = 0;

	for (long long int i = 0; i < 10; i++)
	{
		z[i] = 0;
	}

	for (long long int i = 0; i < a; i++) {
		y[i] = x[i];
	}

	mergeSort(y, 0, a - 1);
	float min = y[0];
	float max = y[a - 1];
	n = (max - min) / 10;

	printf("___________________________________________________________________\n");
	printf("___________________________________________________________________\n");
	printf("Log Frequency Table\n");
	getFrequencyTable(x, z, q, min, n, a);
	printf("___________________________________________________________________\n");
	printf("___________________________________________________________________\n");
	printf("Log Histogram\n");
	getHistogram(z, q, min, n, width);

}


int getValue(char* ch)
{
	char* str = ch;
	while (*str) {
		if (isdigit(*str) || ((*str == '-' || *str == '+') && isdigit(*(str + 1)))) {
			return strtol(str, &str, 10);
		}
		else {
			str++;
		}
	}

}
int main()
{
	double  n = 0;
	long long int  size[10];
	float sizePer[10];

	printf("Enter a list of whitespace-separated real numbers terminated by \"end\" .");
	char ch[10] = " ";
	float array[10000];
	long long int  i = 0;
	int fileRead = 0;

	char* file[100];
	while (1)
	{
		if (i >= 10000)
			break;

		scanf("%s", ch);

		if (strcmp(ch, "end") == 0)
			break;

		else if (strchr(ch, '.'))
		{
			strcpy(file, ch);

			fileRead = 1;
			break;
		}

		else if (getValue(ch) != NULL)
		{
			array[i] = (float)getValue(ch);
			i++;
		}
	}

	if (fileRead == 0)
	{

		long long int dataSize = i;
		float* dataWidth = (float*)malloc(i * sizeof(float));
		float* sortedData = (float*)malloc(i * sizeof(float));
		float* logData = (float*)malloc(i * sizeof(float));

		for (i = 0; i < dataSize; i++)
		{
			dataWidth[i] = array[i];
		}


		printf("\n\n");

		getStatistics(dataWidth, sortedData, size, sizePer, n, dataSize, 5);
		getLogarthmicTransform(dataWidth, logData, dataSize);
		printf("\n\n");
		getFreqTableHistogram(logData, sortedData, size, sizePer, n, dataSize, 3);
	}

}