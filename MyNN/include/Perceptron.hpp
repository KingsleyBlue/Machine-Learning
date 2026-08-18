#pragma once
#include<Matrix/Matrix_core.hpp>

class Perceptron
{
    private:
        Vector weight;
        long double bias;
        long double learning_rate;

    public:
        Perceptron(int, long double lr=0.05);
        void train_sample(const Vector&, int, const int);
        void fit(const Matrix&, const Vector&, const int);
        auto predict(const Vector&) const -> int;
        auto predict(const Matrix&) const -> Vector;
};