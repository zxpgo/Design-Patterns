class ISubject {
public:
	virtual void process();
};

class RealSubject : public ISubject {
public:
	virtual void process() {
		//...
	}
};

class ClientApp {
	ISubject * subject;
public:
	ClientApp() {
		subject = new RealSubject();
	}
	void doTask() {
		//....
		subject->process();
		//....
	}
};

