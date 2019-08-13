class Singleton{
private:
	Singleton();
	Singleton(const Singleton & other);
public:
	static Singleton * getInstance();
	static Singleton * m_instance;
};

Singleton * Singleton::m_instance = nullptr;


//�̷߳ǰ�ȫ�汾
Singleton * Singleton::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	return m_instance;
}

//���̰߳�ȫ�汾,�����Ĵ��۹���
Singleton * Singleton::getInstance() {
	Lock lock;
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	return m_instance;
}

//���̰߳�ȫ�汾�����۽�С�������ڴ��дreorder����ȫ
//m_instancee= new Singleton();��ָ��𣬿��Է�Ϊ�������裺 �����ڴ�ռ䣬���ù��캯����ʼ���ڴ�ռ䣬
//���ڴ��ַ����m_instance
//��reorder��˳������ǣ������ڴ�ռ䣬���ڴ��ַ����m_instance,���ù��캯����ʼ���ڴ�ռ�
//�߳�Aִ�е����ڴ�ռ丳��m_instance,�л����߳�B����ʱm_instance��Ϊnullptr�����Կ��Է���m_instance������ʱ������Ч��
Singleton * Singleton::getInstance() {
	if (m_instance == nullptr) { //˫�����
		Lock lock;
		if (m_instance == nullptr){
			m_instance = new Singleton();
		}
	}
	return m_instance;
}


//C++ 11�汾֮��Ŀ�ƽ̨��ʵ��(volatile)

std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton * Singleton::getInstance() {
	Singleton * tmp = m_instance.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);
	if (tmp == nullptr) {
		tmp = new Singleton;
		std::atomic_thread_fence(std::memory_order_release);
		m_instance.store(tmp, std::memory_order_relaxed);
	}
	return tmp;
}