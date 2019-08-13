
class ISubject {
public:
	virtual void process();
};

//Proxy�����
class SubjectProxy : public ISubject {
	//RealSubject realSubject;
public:
	virtual void process() {
		//��RealSubject��һ�ּ�ӷ���
	}
};

class ClientApp {
	ISubject * subject;
public:
	ClientApp() {
		subject = new SubjectProxy();
	}
	void doTask() {
		//....
		subject->process();
		//....
	}
};