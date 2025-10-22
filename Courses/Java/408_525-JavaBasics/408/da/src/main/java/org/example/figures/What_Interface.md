# Бележки за абстрактни класове, наследяване и интерфейси


`abstract class` - no instances;

`interface` - "what", behaviour;
> Кога правим interface?\
> 
> "Какво би могло да се прави без да знаем как?"\
> Факта, че в интерфейса няма данни въобще. (инстанционни)


_implemetns_ <interface>;\
`public abstract class X implements I`

`default` - abstract method (inside an interface) to have a body;\
<"by default" implementation> for those who didn't `@Override`;

`static`:\
The static keyword in Java is used to indicate that a member (variable or method) belongs to the class itself rather than to any specific instance of the class.\ 
This means that static members are shared among all instances and can be accessed without creating an object of the class.

Възможно за разлика от други базови класове, един клас може да имплементира множество интерфейси.
`public class Triangle extends Figure implements Cloneable, Comparable`

Не можем обаче да наследяваме множество класове както в C++.
> C++\
`class Triangle : public A, Public C ... { }`