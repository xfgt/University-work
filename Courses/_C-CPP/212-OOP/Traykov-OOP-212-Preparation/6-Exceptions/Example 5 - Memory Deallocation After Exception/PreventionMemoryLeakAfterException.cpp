
class DataArray{				// ��������� �� ����
public:
	DataArray(int s);
	~DataArray();
	void init(int s);
private:
	int * data;
};

DataArray::DataArray(int s){	// ��������� �� �����������
	data = new int[s];
	try{
		init(s);	// ���� ������� �������� ����������
	}
	catch(...){
		delete [] data;
		data = nullptr;
		throw;	// �������� ���������� �� ������������
	}
}
DataArray::~DataArray(){		// ��������� �� ����������
	delete [] data;
}
