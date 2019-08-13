//这种设计在C++中已经过时,虚函数表的成本比较大，编译器不采用
//有了泛型编程的迭代器，面向对象的迭代器就不采用了
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
	for (iter.first(); !iter.isDone(); iter.next()) {//此处虚函数表的成本比较大
		cout << iter.current() << endl;
	}
}