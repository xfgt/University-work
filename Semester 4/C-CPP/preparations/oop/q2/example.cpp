#include <iostream>
#include <memory>


class A {
	public:
		
		A()		:	m_n(++m_object_id) {}

		~A()	{ std::cout << m_n; }

		
	private:

		const int m_n;
		static int m_object_id;
};

int A::m_object_id = 0;

// При всяко инстанциране на А обект, се увеличава moid+1 и се присвоява към mn, а при изтриване се принтира mn




int main(){


	A* const p = new A[2];
	A* const q = reinterpret_cast<A* const>(new char[2 * sizeof(A)]);


	new (q) A;
	new (q+1) A;


	q->~A();
	q[1].~A();

	delete[] reinterpret_cast<char*>(q);
	delete[] p;

	std::cout << std::endl;




	return 0;
}
