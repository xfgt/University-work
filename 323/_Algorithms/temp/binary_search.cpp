#include <iostream>

int main()
{

    //дихотомия

    // разделяме масив на 2 и средата на 2

    int a[20] = { 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16, 17, 18, 19, 20 };

    int x;
    std::cin >> x;

    int start = 0;
    int eend = 19;

    int mid;

    // започва цикъл


    /*
        ако a[mid] == x - спирам
        ако eend < start - спирам
        вътре махаме "лошата" половина

    */
    mid = (start + eend)  / 2;
    while(a[mid] != x && eend >= start){    //  де Морган
         std::cout << a[mid] << std::endl;

         if(a[mid] < x){
            // махам всичко от start до mid
            start = mid+1;

         } else {
            // местим другия край
            eend = mid -1;
         }
        mid = (start + eend)  / 2;
    }
    if(eend >= start)
        std::cout << "Намира се на: " << mid << std::endl;
    else
        std::cout << "Няма го!\n";



    // ако са разбъркани - "котва"

    // log(n) за сегашния алгоритъм


    return 0;
}
