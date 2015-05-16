/*
 * IterartionListener.h
 *
 *  Created on: 28 апр. 2015
 *      Author: vadim
 */

#ifndef GA_ITERARTIONLISTENER_H_
#define GA_ITERARTIONLISTENER_H_

class GeneticAlgorithm;

class IterartionListener
{
public:

	virtual ~IterartionListener(){}
    virtual void update( GeneticAlgorithm * environment ) = 0;

};

#endif /* GA_ITERARTIONLISTENER_H_ */
