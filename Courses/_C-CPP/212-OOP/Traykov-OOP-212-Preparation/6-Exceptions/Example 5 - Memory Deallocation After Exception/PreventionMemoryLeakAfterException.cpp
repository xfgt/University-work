
class DataArray{				// дефиниция на клас
public:
	DataArray(int s);
	~DataArray();
	void init(int s);
private:
	int * data;
};

DataArray::DataArray(int s){	// Дефиниция за конструктор
	data = new int[s];
	try{
		init(s);	// тази функция изхвърля изключение
	}
	catch(...){
		delete [] data;
		data = nullptr;
		throw;	// повторно изхвърляне на изключението
	}
}
DataArray::~DataArray(){		// Дефиниция за деструктор
	delete [] data;
}
