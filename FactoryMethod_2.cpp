//位置支持不同文件类型的分隔
//抽象基类
//通过工厂基类来解决new抽象基类的问题

class SplitterFactory {//工厂基类
public:
	virtual ISplitter * CreateSplitter() = 0;
	virtual ~SplitterFactory() {}
};

class ISplitter {//抽象类
public:
	virtual void split() = 0;
	virtual ~ISplitter() {}
};

class BinarySplitter : public ISplitter {

};
class TxtSplitter : public ISplitter {

};

class PictureSplitter : public ISplitter {

};

class VideoSplitter : public ISplitter {

};
//具体工厂
class BinarySplitterFacory: public SplitterFactory{
public:
	virtual ISplitter * CreateSplitter() {
		return new BinarySplitter();
	}
};

...//每个具体类都一个具体工厂

class MainForm : public Form
{
	TextBox * txtFilePath;
	TextBox * txtFileNumber;
	SplitterFactory * factory; //工厂

public:
	MainForm(SplitterFactory * factory) { //传入具体的工厂
		this->factory = factory;
	}
	void Button1_Click() {
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText()).c_str();

		//ISplitter * splitter = new ISplitter(filePath, number, this); //但是抽象接口不能new，new的对象必须是具体的类 
		//依赖具体类

		ISplitter * splitter = factory->CreateSplitter(); //多态new
		splitter->split();
	}

};