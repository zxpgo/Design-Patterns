class Singleton{
private:
	Singleton();
	Singleton(const Singleton & other);
public:
	static Singleton * getInstance();
	static Singleton * m_instance;
};

Singleton * Singleton::m_instance = nullptr;


//线程非安全版本
Singleton * Singleton::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	return m_instance;
}

//多线程安全版本,但锁的代价过高
Singleton * Singleton::getInstance() {
	Lock lock;
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	return m_instance;
}

//多线程安全版本，代价较小，但是内存读写reorder不安全
//m_instancee= new Singleton();在指令级别，可以分为三个步骤： 分配内存空间，调用构造函数初始化内存空间，
//将内存地址赋给m_instance
//而reorder的顺序可能是：分配内存空间，将内存地址赋给m_instance,调用构造函数初始化内存空间
//线程A执行到将内存空间赋给m_instance,切换到线程B，此时m_instance不为nullptr，所以可以返回m_instance，但此时还是无效的
Singleton * Singleton::getInstance() {
	if (m_instance == nullptr) { //双检查锁
		Lock lock;
		if (m_instance == nullptr){
			m_instance = new Singleton();
		}
	}
	return m_instance;
}


//C++ 11版本之后的跨平台的实现(volatile)

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