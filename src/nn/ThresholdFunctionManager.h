/*
 * ThresholdFunctionManager.h
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#ifndef NN_THRESHOLDFUNCTIONMANAGER_H_
#define NN_THRESHOLDFUNCTIONMANAGER_H_

#include "ThresholdFunctionSigma.h"

class ThresholdFunctionManager {
public:
	ThresholdFunctionManager();
	virtual ~ThresholdFunctionManager();

	ThresholdFunction * getRandomFunction();

	static ThresholdFunctionManager & getInstance();

	vector<ThresholdFunction *> m_AllFunctions;
};

#endif /* NN_THRESHOLDFUNCTIONMANAGER_H_ */
