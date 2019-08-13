class Messager {
public: 
	virtual void Login() = 0;
	virtual void SendMessage() = 0;
	virtual void SendPicture() = 0;

	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~Messager(){}
};

//平台实现
class PCMessagerBase : public Message {
public:
	virtual void PlaySoun() {
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

class MobileMessagerBase : public Message {
public:
	virtual void PlaySoun() {
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
class PCMessaerLite : public Messager {
public:
	virtual void Login() {
		PCMessagerBase::Connect();
		//.....
	}
	virtual void SendMessage() {
		PCMessagerBase::WriteText();
		//....
	}
	virtual void SendPicture() {
		PCMessagerBase::DrawShape();
		//....
	}
};

class PCMessaerPerfect : public PCMessagerBase {
public:
	virtual void Login() {
		PCMessagerBase::PlaySound();
		//*******
		PCMessagerBase::Connect();
		//.....
	}
	virtual void SendMessage() {
		PCMessagerBase::PlaySound();
		//*******
		PCMessagerBase::WriteText();
		//....
	}
	virtual void SendPicture() {
		PCMessagerBase::PlaySound();
		//*******
		PCMessagerBase::DrawShape();
		//....
	}
};


class MobileMessaerLite : public MobileMessagerBase {
public:
	virtual void Login() {
		MobileMessagerBase::Connect();
		//.....
	}
	virtual void SendMessage() {
		MobileMessagerBase::WriteText();
		//....
	}
	virtual void SendPicture() {
		MobileMessagerBase::DrawShape();
		//....
	}
};

class MobileMessaerPerfect : public MobileMessagerBase {
public:
	virtual void Login() {
		MobileMessagerBase::PlaySound();
		//*******
		MobileMessagerBase::Connect();
		//.....
	}
	virtual void SendMessage() {
		MobileMessagerBase::PlaySound();
		//*******
		MobileMessagerBase::WriteText();
		//....
	}
	virtual void SendPicture() {
		MobileMessagerBase::PlaySound();
		//*******
		MobileMessagerBase::DrawShape();
		//....
	}
};

void Process() {
	//编译时装配
	Messager * m =
		new MobileMessaerPerfect();

}