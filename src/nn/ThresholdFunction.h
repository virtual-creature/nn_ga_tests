/*
 * ThresholdFunction.h
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#ifndef NN_THRESHOLDFUNCTION_H_
#define NN_THRESHOLDFUNCTION_H_

#include <vector>
using namespace std;

class ThresholdFunction
{
public:
	virtual ~ThresholdFunction(){};

	virtual double calculate(double value, vector<double> & params) = 0;
	virtual vector<double> & getDefaultParams() = 0;
};

#endif /* NN_THRESHOLDFUNCTION_H_ */
