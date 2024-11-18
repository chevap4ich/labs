#include "fraction.h"
#include <string>

int GCD(int a, int b) {
    if (a < b) {
        std::swap(a, b);
    }
    while (a % b != 0) {
        a = a % b;
        std::swap(a, b);
    }
    return b;
}

int LCM(int a, int b){
    return (a *b) / GCD(a, b);
}

int digitsCount(const int integerPart){
    std::string str = std::to_string(abs(integerPart));
    int count = str.length();
    return count;
}

Fraction::Fraction(int _numerator, int _denominator){
    numerator = _numerator;
    denominator = _denominator;
    if (denominator == 0){
        std::cout << "denominator != 0 !!!!" << '\n'; 
    }
    this->reduceFraction();
}

Fraction::Fraction(Fraction &other){
    numerator = other.numerator;
    denominator = other.denominator;
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::reduceFraction(){
    int nod = GCD(numerator, denominator);
    if (nod != 1 && !(numerator < 0 && denominator < 0)){
        numerator = numerator / abs(nod);
        denominator = denominator / abs(nod);
    }
    if (nod != 1 && numerator < 0 && denominator < 0){
        numerator = numerator / nod;
        denominator = denominator / nod;
    }
}

Fraction Fraction::addition(Fraction &other) const {
    int _numerator = (numerator * (LCM(denominator, other.denominator) / denominator) + other.numerator * (LCM(denominator, other.denominator) / other.denominator));
    int _denominator = LCM(denominator, other.denominator);
    return Fraction(_numerator, _denominator);
}

Fraction Fraction::multiplication (Fraction &other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::division(Fraction &other) const {
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

Fraction Fraction::operator+(Fraction &other) const {
    int _numerator = (numerator * (LCM(denominator, other.denominator) / denominator) + other.numerator * (LCM(denominator, other.denominator) / other.denominator));
    int _denominator = LCM(denominator, other.denominator);
    return Fraction(_numerator, _denominator);
}

Fraction Fraction::operator*(Fraction &other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(Fraction &other) const {
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

int Fraction::digitsCount() const {
    std::string str = std::to_string(abs(denominator));
    int countDen;
    countDen = str.length();
    return countDen;
}

std::ostream& operator<<(std::ostream &out, const Fraction &f){
    int integerPart;
    integerPart = f.getNumerator() / f.getDenominator();
    if (!f.getNumerator()){
        out << 0;
        return out;
    }
    if (!integerPart && f.getNumerator() > 0 && f.getDenominator() > 0){
        out << f.getNumerator() << '\n';
        for(int i = 0; i < f.digitsCount(); i++){
            out << "-";
        }
        out << '\n' << f.getDenominator() << '\n';
    }
    else if(!integerPart && (f.getNumerator() < 0 || f.getDenominator() < 0)){
        out << " " << abs(f.getNumerator()) << '\n' << "-";
        for(int i = 0; i < f.digitsCount(); i++){
            out << "-";
        }
        out << '\n' << " " << abs(f.getDenominator()) << '\n';
    }
    else if(f.getNumerator() - f.getDenominator() * integerPart && integerPart > 0){
        for(int i = 0; i < digitsCount(integerPart); i++){
            out << " ";
        }
        out << f.getNumerator() - f.getDenominator() * integerPart << '\n';
        out << integerPart;
        for(int i = 0; i < f.digitsCount(); i++){
            out << "-";
        }
        out << '\n';
        for(int i = 0; i < digitsCount(integerPart); i++){
            out << " ";
        }
        out << f.getDenominator() << '\n';
    }
    else if(f.getNumerator() - f.getDenominator() * integerPart && integerPart < 0){
        for(int i = 0; i < digitsCount(integerPart) + 1; i++){
            out << " ";
        }
        out << abs(f.getNumerator() - f.getDenominator() * integerPart) << '\n';
        out << integerPart;
        for(int i = 0; i < f.digitsCount(); i++){
            out << "-";
        }
        out << '\n';
        for(int i = 0; i < digitsCount(integerPart) + 1; i++){
            out << " ";
        }
        out << abs(f.getDenominator()) << '\n';
    }
    else{
        out << integerPart << '\n';
    }
    return out;
=======
#include "fraction.h"
#include <string>

int GCD(int a, int b) {
    if (a < b) {
        std::swap(a, b);
    }
    while (a % b != 0) {
        a = a % b;
        std::swap(a, b);
    }
    return b;
}

int LCM(int a, int b){
    return (a *b) / GCD(a, b);
}

int digitsCount(const int integerPart){
    std::string str = std::to_string(abs(integerPart));
    int count = str.length();
    return count;
}

Fraction::Fraction(int _numerator, int _denominator){
    numerator = _numerator;
    denominator = _denominator;
    if (denominator == 0){
        std::cout << "denominator != 0 !!!!" << '\n'; 
    }
    this->reduceFraction();
}

Fraction::Fraction(Fraction &other){
    numerator = other.numerator;
    denominator = other.denominator;
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::reduceFraction(){
    int nod = GCD(numerator, denominator);
    if (nod != 1 && !(numerator < 0 && denominator < 0)){
        numerator = numerator / abs(nod);
        denominator = denominator / abs(nod);
    }
    if (nod != 1 && numerator < 0 && denominator < 0){
        numerator = numerator / nod;
        denominator = denominator / nod;
    }
}

Fraction Fraction::addition(Fraction &other) const {
    int _numerator = (numerator * (LCM(denominator, other.denominator) / denominator) + other.numerator * (LCM(denominator, other.denominator) / other.denominator));
    int _denominator = LCM(denominator, other.denominator);
    return Fraction(_numerator, _denominator);
}

Fraction Fraction::multiplication (Fraction &other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::division(Fraction &other) const {
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

Fraction Fraction::operator+(Fraction &other) const {
    int _numerator = (numerator * (LCM(denominator, other.denominator) / denominator) + other.numerator * (LCM(denominator, other.denominator) / other.denominator));
    int _denominator = LCM(denominator, other.denominator);
    return Fraction(_numerator, _denominator);
}

Fraction Fraction::operator*(Fraction &other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(Fraction &other) const {
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

int Fraction::digitsCount() const {
    std::string str = std::to_string(abs(denominator));
    int countDen;
    countDen = str.length();
    return countDen;
}

std::ostream& operator<<(std::ostream &out, const Fraction &f){
    int integerPart;
    integerPart = f.getNumerator() / f.getDenominator();
    if (!f.getNumerator()){
        out << 0;
        return out;
    }
    if (!integerPart && f.getNumerator() > 0 && f.getDenominator() > 0){
        out << f.getNumerator() << '\n';
        for(int i = 0; i < f.digitsCount(); i++){
            out << "-";
        }
        out << '\n' << f.getDenominator() << '\n';
    }
    else if(!integerPart && (f.getNumerator() < 0 || f.getDenominator() < 0)){
        out << " " << abs(f.getNumerator()) << '\n' << "-";
        for(int i = 0; i < f.digitsCount(); i++){
            out << "-";
        }
        out << '\n' << " " << abs(f.getDenominator()) << '\n';
    }
    else if(f.getNumerator() - f.getDenominator() * integerPart && integerPart > 0){
        for(int i = 0; i < digitsCount(integerPart); i++){
            out << " ";
        }
        out << f.getNumerator() - f.getDenominator() * integerPart << '\n';
        out << integerPart;
        for(int i = 0; i < f.digitsCount(); i++){
            out << "-";
        }
        out << '\n';
        for(int i = 0; i < digitsCount(integerPart); i++){
            out << " ";
        }
        out << f.getDenominator() << '\n';
    }
    else if(f.getNumerator() - f.getDenominator() * integerPart && integerPart < 0){
        for(int i = 0; i < digitsCount(integerPart) + 1; i++){
            out << " ";
        }
        out << abs(f.getNumerator() - f.getDenominator() * integerPart) << '\n';
        out << integerPart;
        for(int i = 0; i < f.digitsCount(); i++){
            out << "-";
        }
        out << '\n';
        for(int i = 0; i < digitsCount(integerPart) + 1; i++){
            out << " ";
        }
        out << abs(f.getDenominator()) << '\n';
    }
    else{
        out << integerPart << '\n';
    }
    return out;
}
