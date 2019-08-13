//Ŀ��ӿ�(�½ӿ�)
class ITarget {
public:
	virtual void process() = 0;
};


//�����ӿ�(�Ͻӿ�)
class IAdaptee {
public:
	virtual void foo(int data) = 0;
	virtual int bar() = 0;
};

//��������
class OldClass : public IAdaptee{
public:
	//....
};


//����������
class Adapter public ITarget{//�̳�
protected:
	IAdaptee * pAdaptee;//���
public:
	Adapter(IAdaptee * pAdaptee) {
		this->pAdaptee = pAdaptee;
	}
	virtual void process() {
		int data = pAdaptee->bar();
		pAdaptee->foo(data);
	}
};


//����������������ʹ�ã����Ȳ���
class Adapter public ITarget, protected OldClass {//��̳�
public:
	Adapter(IAdaptee * pAdaptee) {
		this->pAdaptee = pAdaptee;
	}
	virtual void process() {
		int data = pAdaptee->bar();
		pAdaptee->foo(data);
	}
};

int main() {
	IAdaptee * pAdaptee = new OldClass();
	
	ITarget * pTarget = new Adapter(pAdaptee);
	pTarget->process();
}