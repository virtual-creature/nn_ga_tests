/*
 * ThresholdFunctionSigma.h
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#ifndef NN_THRESHOLDFUNCTIONSIGMA_H_
#define NN_THRESHOLDFUNCTIONSIGMA_H_

#include "ThresholdFunction.h"
#include <vector>
using namespace std;

class ThresholdFunctionSigma: public ThresholdFunction
{
public:
	ThresholdFunctionSigma();
	virtual ~ThresholdFunctionSigma();

	double calculate(double value, vector<double> & params);
	vector<double> & getDefaultParams();

private:

	vector<double> m_DefaultParams;
};

#endif /* NN_THRESHOLDFUNCTIONSIGMA_H_ */
