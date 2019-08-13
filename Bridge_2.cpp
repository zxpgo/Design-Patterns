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

//ƽ̨ʵ��
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


//ҵ�����
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
	//����ʱװ��
	MessagerImp messagerImp = new PCMessagerImp();
	Messager * m = new Messager(MessagerImp);
	m->Login();
}

//��ƽ̨ʵ����n����ҵ�������m��
//�����Ŀ�� 1+n+m