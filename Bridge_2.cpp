class Messager {
protected:
	MessagerImp * messagerImp_m;
public:
	virtual void Login() = 0;
	virtual void SendMessage() = 0;
	virtual void SendPicture() = 0;

	Messager(MessagerImp *messagerImp) : messagerImp_m(messagerImp) {}
	virtual ~Messager() {}
};

class MessagerImp {
public:
	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~MessagerImp() {}
};

//平台实现
class PCMessagerImp : public MessagerImp {
public:
	virtual void PlaySound() {
		//*****
	}
	virtual void DrawShape() {
		//******
	}
	virtual void WriteText() {
		//******
	}
	virtual void Connet() {
		//******
	}
};

class MobileMessagerImp : public MessagerImp {
public:
	virtual void PlaySound() {
		//=====
	}
	virtual void DrawShape() {
		//=====
	}
	virtual void WriteText() {
		//=====
	}
	virtual void Connet() {
		//=====
	}
};


//业务抽象
class MessagerLite : public Messager{
	
public:
	MessagerLite(MessagerImp *messagerImp):Messager(messagerImp){}
	virtual void Login() {
		messagerImp->Connect();
		//.....
	}
	virtual void SendMessage() {
		messagerImp->WriteText();
		//....
	}
	virtual void SendPicture() {
		messagerImp->DrawShape();
		//....
	}
};

class MessagerPerfect : public Messager{
public:
	MessagerPerfect(MessagerImp *messagerImp) :Messager(messagerImp) {}
	virtual void Login() {
		messagerImp->PlaySound();
		//*******
		messagerImp->Connect();
		//.....
	}
	virtual void SendMessage() {
		messagerImp->PlaySound();
		//*******
		messagerImp->WriteText();
		//....
	}
	virtual void SendPicture() {
		messagerImp->PlaySound();
		//*******
		messagerImp->DrawShape();
		//....
	}
};

void Process() {
	//运行时装配
	MessagerImp messagerImp = new PCMessagerImp();
	Messager * m = new Messager(MessagerImp);
	m->Login();
}

//如平台实现有n个，业务抽象有m个
//类的数目： 1+n+m