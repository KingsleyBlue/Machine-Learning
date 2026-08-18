#include"Perceptron.hpp"

Perceptron::Perceptron(int dim, long double lr):weight(dim), bias(0), learning_rate(lr){}
void Perceptron::train_sample(const Vector& x, int label, const int epoch)
{
    for(int i=1;i<=epoch;++i)
    {
        if(label*(mat::dot(x,weight)+bias)>0)
            break;
        weight=weight+learning_rate*label*x;
        bias+=learning_rate*label;
    }
}

void Perceptron::fit(const Matrix& x, const Vector& label, const int epoch)
{
    for(int i=0;i<epoch;i++)
    {
        for(int j=0;j<x.getcol();j++)
        {
            Vector xi=x.getcol(j);
            if(label[j]*(mat::dot(xi,weight)+bias)<=0)
            {
                weight=weight+learning_rate*label[j]*xi;
                bias+=learning_rate*label[j];
            }
        }
    }
}

auto Perceptron::predict(const Vector& x) const -> int
{
    return (mat::dot(x,weight)+bias)>0? 1:-1;
}

auto Perceptron::predict(const Matrix& x) const -> Vector
{
    Vector label(x.getcol());
    for(int i=0;i<x.getcol();i++)
    {
        Vector xi=x.getcol(i);
        label[i]=(mat::dot(xi,weight)+bias)>0? 1:-1;
    }
    return label;
}