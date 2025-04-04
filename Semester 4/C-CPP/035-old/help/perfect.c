/*
	ТОВА Е ПОМОЩЕН КОД ОТ КНИГАТА "++Алгоритми;" 
	Глава 1, част 1.1.4 "Мерсенови и съвършени числа", стр 56/717
*/



#include <stdio.h>
#define MN 10
unsigned mPrimes[MN] = { 2, 3, 5, 7, 13, 17, 19, 31, 61, 89 };
unsigned k, number[200];

void print(void)
{
    unsigned i;
    for (i = k; i > 0; i--)
        printf("%u", number[i-1]);
    printf("\n");
}
void doubleN(void)
{
    print(); // ТУК САМО ИЗКРАВАМ ВСИЧКИ МНОЖИТЕЛИ ОТ МАСИВА "number";
    unsigned i, carry = 0, temp;
    for (i = 0; i < k; i++) {
        temp = number[i] * 2 + carry;

        number[i] = temp % 10;
        carry = temp / 10;

    }
    if (carry > 0)
        number[k++] = carry;
}
void perfect(unsigned s, unsigned m)
{

    unsigned i;
    k = 1; number[0] = 1;
    for (i = 0; i < m; i++)
        doubleN(); /* това са делители от вида 2^i */

    number[0]--; /* последната цифра със сигурност е измежду {2,4,8,6} */

    for (i = 0; i < m - 1; i++)
        doubleN();

    printf("%2u-to savarshenno chislo e = ", s);
    print(); /* отпечатва поредното число */
}
int main() {
    unsigned i;
    for (i = 1; i <= MN; i++)
        perfect(i, mPrimes[i - 1]); // { 2, 3, 5, 7, 13, 17, 19, 31, 61, 89 }
    return 0;
}