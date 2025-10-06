#include <iostream>
#include <math.h>

using namespace std;

class Double {
	double d;
public:
	Double(double d=0.):d(d){}
    //Сравнение: двата обекта са равни при
	//достатъчно малка разлика помежду им.
	bool operator==(const Double & b)const
	{
	    double l=fabs(d);
	    double r=fabs(b.d);
	    double m = l>r ? l : r;
	    double res= fabs(d-b.d);

	    return m==0.? true : res/m<1.e-14;
	}

	//Оператор "не равно", получен като
	//отрицание на сравнението за равенство.
	bool operator!=(const Double & b)const
	{ return !(*this == b); }

 	friend ostream& operator<<(ostream& os, const Double & b)
 	{ return os<<b.d; }

 	//Комбинирани оператори за присвояване
	//Връща се по адрес модифицираният ляв операнд.
	Double& operator+=(const Double & b)
	{
	    d+=b.d;
	    return *this;
	}
	Double& operator-=(const Double & b)
	{
	    d-=b.d;
	    return *this;
	}
	Double& operator*=(const Double & b)
	{
	    d*=b.d;
	    return *this;
	}
	Double& operator/=(const Double & b)
	{
	    d/=b.d;
	    return *this;
	}

	Double& operator++()
	{ d++; return *this; }

    Double& operator--()
    { d--; return *this; }

    Double operator++(int)
    {d++;return Double(d-1);}

    Double operator--(int)
    {d--;return Double(d+1);}


 };

//Предефиниране на бинарни операции с използване на
//вече дефинираните комбинирани присвоявания.
Double operator+(const Double & a, const Double & b)
{
    Double res=a;
    return res+=b;
}
Double operator-(const Double & a, const Double & b)
{
    Double res=a;
    return res-=b;
}
Double operator*(const Double & a, const Double & b)
{
    Double res=a;
    return res*=b;
}
Double operator/(const Double & a, const Double & b)
{
    Double res=a;
    return res/=b;
}


int main()
{
    double a = 2.;
    double b = sqrt(2.)*sqrt(2.);
    if(a == b)
        cout<<"a and b are equal: "<<a<<" "<<b<<endl;
    else
        cout<<"a and b are NOT equal: "<<a<<" "<<b<<endl;

    Double c(2.);
    Double d(b);
    if(c == d)
        cout<<"c and d are equal"<<endl;
    else
        cout<<"c and d are NOT equal"<<endl;


    return 0;
}
