#include "logprob.h"


LogProb::LogProb()
{
    prb.clear();
}

double LogProb::findmax()
{

    if(prb.size()>=1)
    {
        prbmax=prb[0];
        for(auto i=0;i<prb.size();i++)
        {
            //std::cout<<"in "<<i<<std::endl;
            if(prb[i]>prbmax)
            {
                prbmax=prb[i];
            }
        }
    }
    else
    {
        throw   "empty prob vector";
    }
    return prbmax;
}

double LogProb::getmax()
{
    return prbmax;
}

void LogProb::setmax(double pp)
{
    prbmax=pp;
}

void LogProb::norm()
{
    double so=0;
    //findmax();
    for(auto i:prb)
    {
        so+= exp(i-prbmax);
    }

    for(auto i=0;i<prb.size();i++)
    {
        prb[i]=prb[i]-prbmax-log(so);
    }
}

void LogProb::normfull()
{
    double so=0;
    findmax();
    for(auto i:prb)
    {
        so+= exp(i-prbmax);
    }

    for(auto i=0;i<prb.size();i++)
    {
        prb[i]=prb[i]-prbmax-log(so);
    }
}
