#include"Matrix_core.hpp"
#include"Matrix_LU.hpp"
#include"Matrix_rank.hpp"
#include"Row_augment.hpp"
#include"Matrix_transposition.hpp"
#include"LinearEqaSlv.hpp"
#include"Matrix_QR.hpp"
#include<tuple>
#include<stdio.h>


int main()
{
    //int m,n,p,q;
    std::vector<std::vector<long double>>result;
    //std::cin>>m>>n;
    Matrix A(2,2);
    std::cin>>A;
    //std::cin>>p>>q;
    Matrix B(2,1);
    std::cin>>B;
    //auto qr=mat::QRdecomp(A);
    //Matrix Q=std::get<0>(qr);
   // Matrix R=std::get<1>(qr);
    //std::cout<<Q<<std::endl<<R;
    result=mat::solution(A,B);
    for(size_t i=0;i<result.size();i++)
    {
        std::printf("solution of group %zu is:",i);
        for(size_t j=0;j<result[i].size();j++)
        {
            std::cout<<result[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}


