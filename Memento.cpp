class Memento {
	string state;
	//...��Orginator��Ӧ
public:
	Memento(const string & s) : state(s) {}
	string getState() const { return state; }
	void setState(const string & s) { state = s; }
};

class Orginator {
	string state;
	//...����ı���
public:
	Originator(){}
	Memento createMemento() {
		Memento m(state);
		return m;
	}
	void setMemento(const Memento & m) {
		state = m.getState();
	}
};

int main() {
	Orginator orginator;
	
	//�������״̬���洢������¼
	Memento mem = orginator.createMemento(); //

	//..�޸�orginator״̬

	//�ָ�����״̬
	orginator.setMemento();
}