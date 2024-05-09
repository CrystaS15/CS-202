// #######################################################################
//  CS 202 - Provided Main
//	This main uses the statsType class for
//	various data sets of different types

// #######################################################################
//  Includes

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

#include "statsType.h"

using namespace std;


// #######################################################################

int main()
{
// **********************************************************
//  Initalizations and headers

	string	bars, stars;
	bars.append(50,'-');
	stars.append(70,'=');

	cout << endl << "Assignment #7 - Statistics Testing" << endl << endl;

// **********************************************************
//  Some tests for the statsType class for char type.

	statsType <char> set0;
	char	min0, max0, med0, sum0, ave0;
	char	sStd0, pStd0, sk0, fp0;

	cout << stars << endl;
	cout << "Data Set 0 - Char (empty)" << endl << endl;

	set0.setFileName("bogusFile.txt");
	set0.readDataFile();

	set0.getLimits(min0, max0);
	med0 = set0.getMedian();
	sum0 = set0.getSum();
	ave0 = set0.getAverage();
	pStd0 = set0.populationStandardDeviation();
	sStd0 = set0.sampleStandardDeviation();
	sk0 = set0.skew();
	fp0 = set0.FPcoeff();

	if (set0.getSetSize() > 0) {
		cout << endl << endl;
		cout << "Statistical Results" << endl;
		cout << "   Minimum:            " << min0 << endl;
		cout << "   Maximum:            " << max0 << endl;
		cout << "   Median:             " << med0 << endl;
		cout << "   Sum:                " << sum0 << endl;
		cout << "   Average:            " << ave0 << endl;
		cout << "   Population Std Dev: " << pStd0 << endl;
		cout << "   Sample Std Dev:     " << sStd0 << endl;
		cout << "   Skew:               " << sk0 << endl;
		cout << "   FP Coefficent:      " << fp0 << endl;
		cout << endl;
		set0.benfordsGraph();
	} else {
		cout << endl;
		cout << "main: Error, set size invalid." << endl;
	}

	cout << endl;

// **********************************************************
//  Some tests for the statsType class for integer type.

	statsType <int> set1;
	int	min1, max1, med1, sum1, ave1;
	int	sStd1, pStd1, sk1, fp1;

	cout << stars << endl;
	cout << "Data Set 1 - Integers" << endl << endl;

	set1.setFileName("dataFile1.txt");
	set1.readDataFile();

	cout << "Data Set 1 -> Unsorted:" << endl;
	set1.printDataSet();

	set1.insertionSort();
	set1.getLimits(min1, max1);
	med1 = set1.getMedian();
	sum1 = set1.getSum();
	ave1 = set1.getAverage();
	pStd1 = set1.populationStandardDeviation();
	sStd1 = set1.sampleStandardDeviation();
	sk1 = set1.skew();
	fp1 = set1.FPcoeff();

	cout << endl << endl << bars << endl;
	cout << "Data Set 1 -> Sorted:" << endl;
	set1.printDataSet();
	cout << endl << endl;

	if (set1.getSetSize() > 0) {
		cout << "Statistical Results" << endl;
		cout << "   Minimum:            " << min1 << endl;
		cout << "   Maximum:            " << max1 << endl;
		cout << "   Median:             " << med1 << endl;
		cout << "   Sum:                " << sum1 << endl;
		cout << "   Average:            " << ave1 << endl;
		cout << "   Population Std Dev: " << pStd1 << endl;
		cout << "   Sample Std Dev:     " << sStd1 << endl;
		cout << "   Skew:               " << sk1 << endl;
		cout << "   FP Coefficent:      " << fp1 << endl;
	} else {
		cout << endl;
		cout << "main: Error, set 1 size invalid." << endl;
	}

	cout << endl;
	set1.benfordsGraph();

	cout << endl;

// **********************************************************
//  Some tests for the statsType class for double type.

	statsType <float> set2;
	float	min2, max2, med2, sum2, ave2;
	float	sStd2, pStd2, sk2, fp2;

	cout << stars << endl;
	cout << "Data Set 2 - float" << endl << endl;

	set2.setFileName("dataFile2.txt");
	set2.readDataFile();

	set2.insertionSort();
	set2.getLimits(min2, max2);
	med2 = set2.getMedian();
	sum2 = set2.getSum();
	ave2 = set2.getAverage();
	pStd2 = set2.populationStandardDeviation();
	sStd2 = set2.sampleStandardDeviation();
	sk2 = set2.skew();
	fp2 = set2.FPcoeff();

	if (set2.getSetSize() > 0) {
		cout << "Statistical Results" << endl;
		cout << "   Minimum:            " << min2 << endl;
		cout << "   Maximum:            " << max2 << endl;
		cout << "   Median:             " << med2 << endl;
		cout << "   Sum:                " << sum2 << endl;
		cout << "   Average:            " << ave2 << endl;
		cout << "   Population Std Dev: " << pStd2 << endl;
		cout << "   Sample Std Dev:     " << sStd2 << endl;
		cout << "   Skew:               " << sk2 << endl;
		cout << "   FP Coefficent:      " << fp2 << endl;
		cout << endl;
		set2.benfordsGraph();
	} else {
		cout << endl;
		cout << "main: Error, set 2 size invalid." << endl;
	}

	cout << endl;

// **********************************************************
//  Some tests for the statsType class for long double type.

	statsType <double> set3;
	double	min3, max3, med3, sum3, ave3;
	double	sStd3, pStd3, sk3, fp3;

	cout << stars << endl;
	cout << "Data Set 3 - double" << endl << endl;

	set3.readFileName();
	set3.readDataFile();

	set3.getLimits(min3, max3);
	med3 = set3.getMedian();
	sum3 = set3.getSum();
	ave3 = set3.getAverage();
	pStd3 = set3.populationStandardDeviation();
	sStd3 = set3.sampleStandardDeviation();
	sk3 = set3.skew();
	fp3 = set3.FPcoeff();

	if (set3.getSetSize() > 0) {
		cout << endl << endl;
		cout << "Statistical Results" << endl;
		cout << "   Minimum:            " << min3 << endl;
		cout << "   Maximum:            " << max3 << endl;
		cout << "   Median:             " << med3 << endl;
		cout << "   Sum:                " << sum3 << endl;
		cout << "   Average:            " << ave3 << endl;
		cout << "   Population Std Dev: " << pStd3 << endl;
		cout << "   Sample Std Dev:     " << sStd3 << endl;
		cout << "   Skew:               " << sk3 << endl;
		cout << "   FP Coefficent:      " << fp3 << endl;
		cout << endl;
		set3.benfordsGraph();
	} else {
		cout << endl;
		cout << "main: Error, set 3 size invalid." << endl;
	}

	cout << endl;

// **********************************************************
//  Some tests for the statsType class for long double type.

	statsType <long long> set4;
	long long	min4, max4, med4, sum4, ave4;
	long long	sStd4, pStd4, sk4, fp4;

	cout << stars << endl;
	cout << "Data Set 4 - long long" << endl << endl;

	set4.readFileName();
	set4.readDataFile();

	set4.getLimits(min4, max4);
	med4 = set4.getMedian();
	sum4 = set4.getSum();
	ave4 = set4.getAverage();
	pStd4 = set4.populationStandardDeviation();
	sStd4 = set4.sampleStandardDeviation();
	sk4 = set4.skew();
	fp4 = set4.FPcoeff();

	if (set4.getSetSize() > 0) {
		cout << endl << endl;
		cout << "Statistical Results" << endl;
		cout << "   Minimum:            " << min4 << endl;
		cout << "   Maximum:            " << max4 << endl;
		cout << "   Median:             " << med4 << endl;
		cout << "   Sum:                " << sum4 << endl;
		cout << "   Average:            " << ave4 << endl;
		cout << "   Population Std Dev: " << pStd4 << endl;
		cout << "   Sample Std Dev:     " << sStd4 << endl;
		cout << "   Skew:               " << sk4 << endl;
		cout << "   FP Coefficent:      " << fp4 << endl;
		cout << endl;
		set4.benfordsGraph();
	} else {
		cout << endl;
		cout << "main: Error, set 4 size invalid." << endl;
	}

	cout << endl;

// **********************************************************
//  Some tests for the statsType class for long double type.

	statsType <long double> set5;
	long double	min5, max5, med5, sum5, ave5;
	long double	sStd5, pStd5, sk5, fp5;

	cout << stars << endl;
	cout << "Data Set 5 - long double" << endl << endl;

	set5.readFileName();
	set5.readDataFile();

	set5.getLimits(min5, max5);
	med5 = set5.getMedian();
	sum5 = set5.getSum();
	ave5 = set5.getAverage();
	pStd5 = set5.populationStandardDeviation();
	sStd5 = set5.sampleStandardDeviation();
	sk5 = set5.skew();
	fp5 = set5.FPcoeff();

	if (set5.getSetSize() > 0) {
		cout << endl << endl;
		cout << "Statistical Results" << endl;
		cout << "   Minimum:            " << min5 << endl;
		cout << "   Maximum:            " << max5 << endl;
		cout << "   Median:             " << med5 << endl;
		cout << "   Sum:                " << sum5 << endl;
		cout << "   Average:            " << ave5 << endl;
		cout << "   Population Std Dev: " << pStd5 << endl;
		cout << "   Sample Std Dev:     " << sStd5 << endl;
		cout << "   Skew:               " << sk5 << endl;
		cout << "   FP Coefficent:      " << fp5 << endl;
		cout << endl;
		set5.benfordsGraph();
	} else {
		cout << endl;
		cout << "main: Error, set 5 size invalid." << endl;
	}

	cout << endl;

// **********************************************************
//  Done, display message and end.

	cout << stars << endl << "Program terminated." << endl;
	cout << endl;

	return 0;
}

// #######################################################################


