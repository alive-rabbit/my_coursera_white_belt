#include <iostream>
#include <set>
#include <map>
#include <vector>

int GreatestCommonDivisor(int a, int b) 
{
    if (b == 0) 
    {
        return a;
    }
    else 
    {
        return GreatestCommonDivisor(b, a % b);
    }
}

class Rational 
{
public:
    Rational() 
    {  // дробь по умолчанию — 0/1
        numerator = 0;
        denominator = 1;
    }
    Rational(int new_numerator, int new_denominator) 
    {
        const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
        // сократим дробь, разделив числитель и знаменатель на их НОД
        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;
        // знаменатель должен быть положительным
        if (denominator < 0) 
        {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    int Numerator() const 
    {
        return numerator;
    }

    int Denominator() const 
    {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

// поскольку дроби сокращены, достаточно сравнить числители и знаменатели
bool operator == (const Rational& lhs, const Rational& rhs) 
{
    return lhs.Numerator() == rhs.Numerator() &&
        lhs.Denominator() == rhs.Denominator();
}

// используем обычную формулу сложения дробей, основанную на приведении слагаемых к общему знаменателю
Rational operator + (const Rational& lhs, const Rational& rhs) 
{
    return 
    {
        lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

// вычитание реализуем аналогично сложению
// дублирования кода можно было избежать, определив для класса Rational операцию унарного минуса: тогда разность lhs и rhs можно было бы вычислить           как lhs + (-rhs)
Rational operator - (const Rational& lhs, const Rational& rhs) 
{
    return 
    {
        lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator * (const Rational& lhs, const Rational& rhs) 
{
    return 
    {
        lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

// деление равносильно умножению на обратную («перевёрнутую») дробь
Rational operator / (const Rational& lhs, const Rational& rhs) 
{
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

std::istream& operator >> (std::istream& is, Rational& r) 
{
    int n, d;
    char c;

    if (is) 
    {
        is >> n >> c >> d;
        if (is) 
        {
            if (c == '/') 
            {
                r = Rational(n, d);
            }
            else 
            {
                is.setstate(std::ios_base::failbit);
            }
        }
    }

    return is;
}

std::ostream& operator << (std::ostream& os, const Rational& r)
{
    return os << r.Numerator() << '/' << r.Denominator();
}

// чтобы сравнить lhs с rhs, сравним их разность с нулём, что равносильно сравнению с нулём числителя
bool operator < (const Rational& lhs, const Rational& rhs) 
{
    return (lhs - rhs).Numerator() < 0;
}


int main() 
{
    {
        const std::set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) 
        {
            std::cout << "Wrong amount of items in the set" << std::endl;
            return 1;
        }

        std::vector<Rational> v;
        for (auto x : rs) 
        {
            v.push_back(x);
        }
        if (v != std::vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) 
        {
            std::cout << "Rationals comparison works incorrectly" << std::endl;
            return 2;
        }
    }

    {
        std::map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) 
        {
            std::cout << "Wrong amount of items in the map" << std::endl;
            return 3;
        }
    }

    std::cout << "OK" << std::endl;
    return 0;
}