#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator)
{
    if(numerator == 0 && denominator == 0){
        int newNumerator, newDenominator;
        cout <<"What is the numerator: ";
        cin >> newNumerator;
        cout << "What is the denominator: ";
        cin >> newDenominator;

        _numerator = newNumerator;
        _denominator = newDenominator;
    }else{
        _numerator = numerator;
        _denominator = denominator;
    }
    

}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    //making each fraction have the same denominator
    int unsimplifiedFrac1Top = (_numerator * frac._denominator);
    int unsimplifiedFrac2Top = (frac._numerator * _denominator);
    int unsimplifiedBottom = (_denominator * frac._denominator);

    //add the fraction by adding the numerators but leaving the denominator
    int newFracTop = unsimplifiedFrac1Top + unsimplifiedFrac2Top;
    int newFracBottom = unsimplifiedBottom;

    fractions::Fraction newFrac(newFracTop, newFracBottom);

    newFrac.simplify();
    

    
    return newFrac;
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    int unsimplifiedFrac1Top = (_numerator * frac._denominator);
    int unsimplifiedFrac2Top = (frac._numerator * _denominator);
    int unsimplifiedBottom = (_denominator * frac._denominator);

    int newFracTop = unsimplifiedFrac1Top - unsimplifiedFrac2Top;
    int newFracBottom = unsimplifiedBottom;

    fractions::Fraction newFrac(newFracTop, newFracBottom);

    newFrac.simplify();

    
    return newFrac;
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    
    int top = _numerator * frac._numerator;
    int bottom = _denominator * frac._denominator;
    fractions::Fraction newFrac(top, bottom);
    newFrac.simplify();

    return newFrac;
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    int top = _numerator * frac._denominator;
    int bottom = _denominator * frac._numerator;
    fractions::Fraction newFrac(top, bottom);
    newFrac.simplify();


    
    return newFrac;
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    int gcd = fractions::Fraction::gcd(frac._numerator, frac._denominator);
    frac._numerator = frac._numerator / gcd;
    frac._denominator = frac._denominator /gcd;

    return Fraction(0, 1);
}

void fractions::Fraction::simplify()
{
    int gcd = fractions::Fraction::gcd(_numerator, _denominator);
    _numerator = _numerator / gcd;
    _denominator = _denominator /gcd;
}

int fractions::Fraction::gcd(int a, int b)
{
    int max;
    //finding out what the greatest number the gdc could possibly be
    if(a > b) max = a;
    if(a < b) max = b;

    int gcd;
    for(int i = 1; i <= max; i++){
        if(a % i == 0 && b % i == 0){
            gcd = i;
        }
    }

    return gcd;
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    if(_numerator == frac._numerator && _denominator == frac._denominator){
        return true;
    }else{
        return false;
    }
    
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    os << frac._numerator << "/" << frac._denominator;
    return os;
}