#include"Matrix_core.hpp"
#include"Matrix_LU.hpp"
#include"Matrix_rank.hpp"
#include"Row_augment.hpp"
#include"Matrix_transposition.hpp"
#include"LinearEqaSlv.hpp"
#include"Matrix_QR.hpp"
#include"Matrix_reverse.hpp"
#include<tuple>
#include<cstdio>
#include<stdlib.h>


int main()
{
   Matrix A(2,2);
    std::cin>>A;
    system("cls");
    std::cout<<mat::reverse(A);
    system("pause");
    return 0;
}


