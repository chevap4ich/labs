<<<<<<< HEAD
#pragma once
#include <iostream>

class Fraction {
public:
    Fraction(int _numerator, int _denominator);
    Fraction(Fraction &other);
    int getNumerator() const;
    int getDenominator() const;
    void reduceFraction();
    Fraction addition(Fraction &other) const;
    Fraction multiplication (Fraction &other) const;
    Fraction division (Fraction &other) const;
    Fraction operator+(Fraction &other) const;
    Fraction operator*(Fraction &other) const;
    Fraction operator/(Fraction &other) const;
    int Fraction::digitsCount() const;
    ~Fraction(){}

private:
    int numerator;
    int denominator;    
};

std::ostream& operator<<(std::ostream &out, const Fraction &f);
=======
#pragma once
#include <iostream>

class Fraction {
public:
    Fraction(int _numerator, int _denominator);
    Fraction(Fraction &other);
    int getNumerator() const;
    int getDenominator() const;
    void reduceFraction();
    Fraction addition(Fraction &other) const;
    Fraction multiplication (Fraction &other) const;
    Fraction division (Fraction &other) const;
    Fraction operator+(Fraction &other) const;
    Fraction operator*(Fraction &other) const;
    Fraction operator/(Fraction &other) const;
    int Fraction::digitsCount() const;
    ~Fraction(){}

private:
    int numerator;
    int denominator;    
};

std::ostream& operator<<(std::ostream &out, const Fraction &f);
>>>>>>> dda2ceb4080dc983b96e9b0d61f1618717e340ee
