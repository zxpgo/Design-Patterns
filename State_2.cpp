//添加新的状态，不要再每个operation添加else if

class NetworkState {
public:
	Networkstate * pNext; 

	virtual void Operation1() = 0;
	virtual void Operation2() = 0;
	virtual void Operation3() = 0;

	virtual ~NetworkState() {}
};

class OpenState : public NetworkState {
	static NetworkState * m_instance;
public:
	static NetworkState * getInstance() {
		if (m_instance == nullptr)
			m_instance = new OpenState();
		return m_instance;
	}

	void Operation1() {
		//........
		pNext = CloseState::getInstance();
	}

	void Operation2() {
		//********
		pNext = ConnectState::getInstance();
	}

	void Operation3() {
		//$$$$$$
		pNext = OpenState::getInstance():
	}

};

class CloseState : public NetworkState {
	//...
};

class ConnectState : public NetworkState {
	//...
};

class NetworkProcessor {
	NetworkState * pState;
public:
	NetworkProcessor(NetworkState * state){
		this->state = pState;
	}
	void Operation1() {
		//...
		pState->Operation1();
		pState = pState->pNext;
	}
	void Operation2() {
		//...
		pState->Operation2();
		pState = pState->pNext;
	}
	void Operation3() {
		//...
		pState->Operation3();
		pState = pState->pNext;
	}	
};