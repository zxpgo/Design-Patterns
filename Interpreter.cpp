#include <map>
#include <stack>

class Expression {
public:
	virtual int interpreter(map<char, int> var) = 0;
	virtual ~Expression() {}
};

//�������ʽ
class VarExpression :public Expression {
	char key;
public:
	VarExpression(const char & key) {
		this->key = key;
	}
	int interpreter(map<char, int> var) override {
		return var[key];
	}
};

//���ű��ʽ
class SymbolExpression :public Expression {
	//�����������������
protected:
	Expression * left;
	Expression * right;
public:
	SymbolExpression(Expression * left, Expression * right) :
		left(left), right(right) {

	}
};

//�ӷ�����
class AddExpression :public SymbolExpression {
public:
	AddExpression(Expression *left, Expression * right)
		: SymbolExpression(left, right) {

	}

	int interpreter(map<char, int> var) {
		return left->interpreter(var) + right->interpreter(var);
	}
};

//��������
class  SubExpression :public SymbolExpression {
public:
	SubExpression(Expression * left, Expression * right) :SymbolExpression(left, right) {

	}
	int interpreter(map<char, int> var) {
		return left->interpreter(var) - right->interpreter(var);
	}
};

Expression * analyse(stirng expstr){
	stack<Expression *> expStack;
	Expression * left = nullptr;
	Expression * right = nullptr;
	for (int i = 0; i < expstr.size(); i++) {
		switch (expstr[i])
		{
		case: '+' :
			//�ӷ�����
			left = expStack.top();
			right = new VarExpression(expStr[++i]);
			expStack.push(new AddExpression(left, right));
			break;
		case '-':
			//��������
			left = expStack.top();
			right = new VarExpression(expStr[++i]);
			expStack.push(new SubExpression(left, rihgt));
			break;
		default:
			//�������ʽ
			expStack.push(new VarExpression(expStr[i]));
			
		}
	}
	Expression * expression = expStack.top();
	return expression;
}

void release(Expression * expression) {
	//�ͷű��ʽ���Ľڵ��ڴ�
}

int main(int argc, const char * argv[]) {
	string expStr = "a+b-c+d";
	map<char, int> var;
	var.insert(make_pair('a', 5));
	var.insert(make_pair('b', 2));
	var.insert(make_pair('c', 1));
	var.insert(make_pair('d', 6));

	Expression * expression = analyse(expStr);

	int resutlt = expression->interpreter(var);

	cout << resutlt << endl;

	release(expression);

	return 0;
}