//来自观察者模式的代码
//原始版本，只有分隔一种文件
class MainForm : public Form, public IProgress
{
	TextBox * txtFilePath;
	TextBox * txtFileNumber;

public:
	void Button1_Click() {
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText()).c_str();

		FileSplitter * splitter = new FileSplitter(filePath, number, this);

		splitter->split();
	}

};

class FileSplitter {

public:

	void split() {
		//...
	}
};

//位置支持不同文件类型的分隔
//抽象基类
//但是存在问题，抽象基类无法new

class ISplitter {
public: 
	virtual void split() = 0;
	virtual ~ISplitter() {}
};

class BinarySplitter : public ISplitter{

};
class TxtSplitter : public ISplitter{

};

class PictureSplitter : public ISplitter{

};

class VideoSplitter : public ISplitter{

};


class MainForm : public Form, public IProgress
{
	TextBox * txtFilePath;
	TextBox * txtFileNumber;
	ProgressBar * progressBar;

public:
	void Button1_Click() {
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText()).c_str();

		BinarySplitter * splitter = new BinarySplitter(filePath, number, this); //依赖于具体类

		//ISplitter * splitter = new ISplitter(filePath, number, this); //但是抽象接口不能new，new的对象必须是具体的类 
		//依赖具体类

		splitter->split();
	}

};