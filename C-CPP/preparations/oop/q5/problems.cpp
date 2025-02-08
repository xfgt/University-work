
class Foo{
	public: virtual ~Foo(){}
};

class Bar : public Foo {};

int main(int argc, char** argv){

	Foo* f = new Bar();
	delete f;
	f = 0;
	delete f;

	Foo* fa = new Bar[10];
//	delete [] fa;
	fa = 0;
	delete fa;


	return 0;
}
