//���������C++���Ѿ���ʱ,�麯�����ĳɱ��Ƚϴ󣬱�����������
//���˷��ͱ�̵ĵ��������������ĵ������Ͳ�������
template<typename T>
class Iterator {
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() const = 0;
	virtual T& current() = 0;
};

template<typename T>
class MyCollection{
public:
	Iterator<T> GetIterator() {
		//...
	}
	
};

template<typename T>
class CollectionIterator : public Iterator<T> {
	MyCollection<T> mc;
public:
	CollectionIterator(const MyCollection<T> & c):mc(c){}

	void first() override {

	}

	void next() override {

	}

	bool isDone() override {

	}

	T& current() override {

	}
};

void MyAlgorithm() {
	MyCollection<int> mc;
	Iterator<int> iter = mc.GetIterator();
	for (iter.first(); !iter.isDone(); iter.next()) {//�˴��麯�����ĳɱ��Ƚϴ�
		cout << iter.current() << endl;
	}
}