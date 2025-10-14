typedef std::set<int, Reverse<int, LessThan<int> > > Set;


std::set<X, COMPLEX>
         /       \
     some type    \
                   ,
                COMPLEX -> Reverse< int, LessThan<int> >
                               |
                                \
                                 '-> Rtype, Templated Class of R type


LessThan<T>:
    template<typename T>
    class LessThan  {


    };


Reverse<X, Y>
    template <typename T, class LT>
    class Reverse{

    };