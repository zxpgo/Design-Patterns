//���Թ۲���ģʽ�Ĵ���
//ԭʼ�汾��ֻ�зָ�һ���ļ�
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

//λ��֧�ֲ�ͬ�ļ����͵ķָ�
//�������
//���Ǵ������⣬��������޷�new

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

		BinarySplitter * splitter = new BinarySplitter(filePath, number, this); //�����ھ�����

		//ISplitter * splitter = new ISplitter(filePath, number, this); //���ǳ���ӿڲ���new��new�Ķ�������Ǿ������ 
		//����������

		splitter->split();
	}

};