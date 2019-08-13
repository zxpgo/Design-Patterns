#include <algorithm>

using namespace std;

class Component {
public:
	virtual void process() = 0;
	virutal ~Component() {}
};

//���ڵ�
class Composite : public Component {
	string name;
	lis<Component *> elements;
public:
	Composite(const string & s) : name(s) {}
	void add(Component * element) {
		elements.push_back(element);
	}
	void remove(Component * element) {
		elements.remove(element);
	}

	void process() {
		//����ǰ�ڵ�
		//����Ҷ�ӽڵ�
		for (auto &e : elements) {
			e->process(); //��̬����
		}
	}
};

//Ҷ�ӽڵ�
class Leaf :public Component {
	string name;
public:
	Leaf(string s):name(s){}
	void process() {
		//����ǰ�ڵ�
	}
};

void Invoke(Component & c) {
	//...
	c.process();
	//...
}

int main()
{
	Composite root(root);
	Composite treeNode1("treeNode1");
	Composite treeNode2("treeNode2");
	Composite treeNode3("treeNode3");
	Composite treeNode4("treeNode4");
	Leaf leat1("left1");
	Leaf leat2("left2");

	root.add(&treeNode1);
	treeNode1.add(&treeNode2);
	treeNode2.add(&leat1);
	
	root.add(&treeNode3);
	treeNode3.add(&treeNode4);
	treeNode4.add(&leat2);

	Invoke(root);
	Invoke(leat2);
	Invoke(treeNode3);
}