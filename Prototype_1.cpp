//位置支持不同文件类型的分隔
//抽象基类
//通过工厂基类来解决new抽象基类的问题


class ISplitter {//抽象类
public:
	virtual void split() = 0;
	virtual ~ISplitter() {}

	virtual ISplitter * clone() = 0; //通过克隆自己来创建对象
};

class BinarySplitter : public ISplitter {
public:
	virtual ISplitter * clone() {
		return new BinarySplitter(*this);
	}
};
class TxtSplitter : public ISplitter {
public:
	virtual ISplitter * clone() {
		return new TxtSplitter(*this);
	}
};

class PictureSplitter : public ISplitter {
public:
	virtual ISplitter * clone() {
		return new PictureSplitter(*this);
	}
};

class VideoSplitter : public ISplitter {
public:
	virtual ISplitter * clone() {
		return new VideoSplitter(*this);
	}
};



class MainForm : public Form
{
	TextBox * txtFilePath;
	TextBox * txtFileNumber;
	ISplitter * prototype; //原型对象

public:
	MainForm(ISplitter * prototype) { //传入具体的工厂
		this->prototype = prototype;
	}
	void Button1_Click() {
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText()).c_str();

		ISplitter * splitter = prototype->clone(); //克隆原型得到一个新对象

		splitter->split();
	}
};