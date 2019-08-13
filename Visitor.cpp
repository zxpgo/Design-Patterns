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

//可能需要添加Func2,Func3，这样基类和子类都需要更改