#pragma once
#include"Matrix_core.hpp"

long double mat::dot(Matrix A,Matrix B)
{
    if(A.getrow()==1&&B.getcol()==1&&A.getcol()==B.getrow())
    {
        long double result=0;
        for(int p=0;p<A.getcol();p++)
        {
            result+=A.getvalue(0,p)*B.getvalue(p,0);
        }
        return result;
    }
    else
    throw std::invalid_argument("cannot dot!");
}
