//λ��֧�ֲ�ͬ�ļ����͵ķָ�
//�������
//ͨ���������������new������������


class ISplitter {//������
public:
	virtual void split() = 0;
	virtual ~ISplitter() {}

	virtual ISplitter * clone() = 0; //ͨ����¡�Լ�����������
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
	ISplitter * prototype; //ԭ�Ͷ���

public:
	MainForm(ISplitter * prototype) { //�������Ĺ���
		this->prototype = prototype;
	}
	void Button1_Click() {
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText()).c_str();

		ISplitter * splitter = prototype->clone(); //��¡ԭ�͵õ�һ���¶���

		splitter->split();
	}
};