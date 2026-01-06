#pragma once
#include<iostream>
#include<vector>

class Matrix;
namespace mat
{
    Matrix trans(Matrix);//求转置矩阵
    Matrix GaussianElimination(Matrix);//高斯消元法
    double det(Matrix);//求行列式
    std::pair<Matrix, Matrix> LUdecomp(const Matrix&);//LU分解
    int rank(Matrix);//求秩
    Matrix col_aug(Matrix,Matrix);//列增广矩阵
    Matrix row_aug(Matrix,Matrix);//行增广矩阵
    std::pair<Matrix, Matrix> QRdecomp(Matrix);//QR分解
    std::vector<std::vector<long double>> solution(Matrix A,Matrix B);
    Matrix orthx(Matrix);
}

//定义矩阵
 class Matrix
 {
    friend std::istream &operator>>(std::istream &is, Matrix &m);
    friend Matrix mat::GaussianElimination(Matrix A);
    friend int mat::rank(Matrix);

    private:
    int rows,cols;
    std::vector<std::vector<long double>>matrix;
    
    public:
    Matrix():rows(0),cols(0){}
    Matrix(int r,int c):rows(r), cols(c), matrix(r, std::vector<long double>(c, 0)){}

    Matrix(int size):rows(size), cols(size), matrix(size, std::vector<long double>(size, 0))
    {
        for(int i=0;i<rows;i++)
        {
            matrix[i][i]=1;
        }
    }

    int getrow() const{return rows;}//返回行数
    int getcol() const{return cols;}//返回列数
    long double getvalue(int row,int col) const
    {
        if(row>=rows||col>=cols)
            throw std::invalid_argument("out of range!");
        else
        return matrix[row][col];
    }
    std::vector<std::vector<long double>> getmat() const{return matrix;}
    void set(int row,int col,long double value){matrix[row][col]=value;}
    Matrix getrow(int row)//返回某行
    {
        if(row>=rows)
        throw std::invalid_argument("out of range!");
        else
        {
            Matrix b(1,cols);
            for(int j=0;j<cols;j++)
            {
                b.set(0,j,matrix[row][j]);
            }
            return b;
        }
    }
    Matrix getcol(int col)//返回某列
    {
        if(col>=cols)
        throw std::invalid_argument("out of range!");
        else
        {
            Matrix b(rows,1);
            for(int i=0;i<rows;i++)
            {
                b.set(i,0,matrix[i][col]);
            }
            return b;
        }
    }
    
    Matrix& operator=(const Matrix& other)//=重载必须为成员函数
    {
        // 检查自赋值
        if (this == &other)
        {
            return *this;
        }

        // 检查矩阵规模是否相同
        if (rows != other.rows || cols != other.cols)
        {
            throw 10;
        }

        // 复制数据
        matrix = other.matrix;

        return *this;
    }

 };


//重载运算符
std::istream &operator>>(std::istream &is, Matrix &m)
{
    for(int i=0;i<m.getrow();i++)
        {
            for(int j=0;j<m.getcol();j++)
            {
                std::cin>>m.matrix[i][j];
            }
        }
    return is;
}

std::ostream & operator<<(std::ostream &os, const Matrix &m)
{
    for(int i=0;i<m.getrow();i++)
        {
            for(int j=0;j<m.getcol();j++)
            {
                os<<m.getvalue(i,j)<<' ';
            }
            os<<std::endl;
        }
    return os;
}

Matrix operator+(const Matrix A, const Matrix B)
{
     if (A.getrow() == B.getrow() && A.getcol() == B.getcol())
     {
         Matrix C(A.getrow(), B.getcol());
         for (int i = 0; i < C.getrow(); i++)
         {
             for (int j = 0; j < C.getcol(); j++)
             {
                 C.set(i,j,A.getvalue(i,j) + B.getvalue(i,j));
             }
         }
         return C;
     }
     else
     {
       throw std::invalid_argument("+():size not match!");
     }
}

Matrix operator-(const Matrix A,const Matrix B)
    {
        if(A.getrow()==B.getrow()&&A.getcol()==B.getcol())
        {
            Matrix C(A.getrow(),B.getcol());
            for(int i=0;i<C.getrow();i++)
            {
                for(int j=0;j<C.getcol();j++)
                {
                    C.set(i,j,A.getvalue(i,j)-B.getvalue(i,j));
                }
            }
            return C;

        }
        else
        {
           throw std::invalid_argument("-():size not match!");
        }
    }

Matrix operator*(const long double a,const Matrix B)//矩阵数乘
    {
        Matrix C(B.getrow(),B.getcol());
            for(int i=0;i<C.getrow();i++)
            {
                for(int j=0;j<C.getcol();j++)
                {
                    C.set(i,j,a*B.getvalue(i,j));
                }
            }
            return C;
    }

Matrix operator*(const Matrix A,const long double b)//矩阵数乘
    {
        Matrix C(A.getrow(),A.getcol());
            for(int i=0;i<C.getrow();i++)
            {
                for(int j=0;j<C.getcol();j++)
                {
                    C.set(i,j,b*A.getvalue(i,j));
                }
            }
            return C;
    }

Matrix operator/(const Matrix A,const long double b)//矩阵数除
    {
        if(b==0)
          throw std::invalid_argument("/():the divisor is 0!");
        else{
        Matrix C(A.getrow(),A.getcol());
            for(int i=0;i<C.getrow();i++)
            {
                for(int j=0;j<C.getcol();j++)
                {
                    C.set(i,j,A.getvalue(i,j)/b);
                }
            }
            return C;
        }
    }

long double operator/(const Matrix A,const Matrix B)
{
    if(A.getcol()>1||A.getrow()>1||B.getcol()>1||B.getrow()>1)
    throw std::invalid_argument("not a number!");
    return A.getvalue(0,0)/B.getvalue(0,0);
}
Matrix operator*(const Matrix A,const Matrix B)//矩阵乘法
    {
        if(A.getcol()==B.getrow())
        {
            Matrix C(A.getrow(),B.getcol());
            for(int i=0;i<C.getrow();i++)
            {
                for(int j=0;j<C.getcol();j++)
                {
                    for(int k=0;k<A.getcol();k++)
                    {
                        C.set(i,j,C.getvalue(i,j)+A.getvalue(i,k)*B.getvalue(k,j));
                    }
                }
            }
            return C;
        }
        else
        {
           throw std::invalid_argument("*():size not match!");
        }
    }



bool operator==(const Matrix A,const Matrix B)//判断矩阵是否相等
{
    if(A.getrow()==B.getrow()&&A.getcol()==B.getcol())
    {
        for(int i=0;i<B.getrow();i++)
        {
            for(int j=0;j<B.getcol();j++)
            {
                switch(A.getvalue(i,j)==B.getvalue(i,j))
                {
                    case 0:
                        return false;
                    case 1:
                        continue;    
                }
            }
        }
        return true;
    }
    else
    return false;
}