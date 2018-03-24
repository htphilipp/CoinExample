#pragma once

#ifndef LOGPROB_H
#define LOGPROB_H

//#include "logprob_global.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <string>

//The purpose of this class is to provide a container for log(probability) distributions
//that has built in log normalization - i.e. normalization without putting it in non-log form
// and thus, hopefully, more efficient.
// to do this, the maximum log of the probability is needed.

class LogProb
{

public:
    std::vector< double>    prb;
    void    norm();  //normalize the distribtuion with prbmax (maximum log(prob) value).
    void    normfull(); // sam as above, but also find prbmax.
    void    setmax(double); // set the maximum log(probability).
    double  findmax(); // find the max log(prob).
    double  getmax(); //returns present prbmax.
private:
    double  prbmax; // the maximum probability.

public:
    LogProb();

};

#endif // LOGPROB_H
