#include "Perceptron.hpp"
#include<stdlib.h>
#include<iostream>
int main()
{
    Perceptron model(3);

    Vector train(3);
    train[0]=-1;
    train[1]=1;
    train[2]=2;
    model.train_sample(train,-1,10);
    Vector x(3);

    std::cout<<model.predict(x);
    system("pause");
    return 0;

}