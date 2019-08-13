//λ��֧�ֲ�ͬ�ļ����͵ķָ�
//�������
//ͨ���������������new������������

class SplitterFactory {//��������
public:
	virtual ISplitter * CreateSplitter() = 0;
	virtual ~SplitterFactory() {}
};

class ISplitter {//������
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
//���幤��
class BinarySplitterFacory: public SplitterFactory{
public:
	virtual ISplitter * CreateSplitter() {
		return new BinarySplitter();
	}
};

...//ÿ�������඼һ�����幤��

class MainForm : public Form
{
	TextBox * txtFilePath;
	TextBox * txtFileNumber;
	SplitterFactory * factory; //����

public:
	MainForm(SplitterFactory * factory) { //�������Ĺ���
		this->factory = factory;
	}
	void Button1_Click() {
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText()).c_str();

		//ISplitter * splitter = new ISplitter(filePath, number, this); //���ǳ���ӿڲ���new��new�Ķ�������Ǿ������ 
		//����������

		ISplitter * splitter = factory->CreateSplitter(); //��̬new
		splitter->split();
	}

};