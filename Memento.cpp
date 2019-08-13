class Memento {
	string state;
	//...与Orginator对应
public:
	Memento(const string & s) : state(s) {}
	string getState() const { return state; }
	void setState(const string & s) { state = s; }
};

class Orginator {
	string state;
	//...保存的变量
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
	
	//捕获对象状态，存储到备忘录
	Memento mem = orginator.createMemento(); //

	//..修改orginator状态

	//恢复对象状态
	orginator.setMemento();
}