class Element {
public:
	virtual void Func1() = 0;
	virtual ~Element(){}
};

class ElementA :public Element {
public:
	void Func1() override {
		//....
	}

};

class ElementB :public Element {
public: 
	void Func1() override {
		//....
	}
};

//������Ҫ���Func2,Func3��������������඼��Ҫ����