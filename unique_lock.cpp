#include <mutex>
template <class Mutex>
class unique_lock
{
	Mutex *m_;
	bool is_lock;
public:
	unique_lock() 
	{
		m_ = nullptr;
		is_lock = false;
	}

	~unique_lock()
	{
		if (is_lock) 
		{
			(*m_).unlock();
			is_lock = false;
			m_ = nullptr;
		}
	}

	unique_lock(unique_lock&& other) noexcept : m_(other.m_)
	{
		other.m_ = nullptr;
		is_lock = other.is_lock;
		other.is_lock = false;
	}

	explicit unique_lock(Mutex & m) 
	{
		m_ = &m;
		(*m_).lock();
		is_lock = true;
	}
	unique_lock(Mutex& m, std::defer_lock_t t) noexcept 
	{
		m_ = &m;
		is_lock = false;
	}

	unique_lock(Mutex& m, std::adopt_lock_t t) 
	{
		m_ = &m;
		is_lock = true;
	}

	void lock()
	{
		(*m_).lock();
		is_lock = true;
	}

	void unlock()
	{
		(*m_).unlock();
		is_lock = false;
	}

	unique_lock<Mutex>& operator=(unique_lock<Mutex>&& other) 
	{
		(*m_)=other.m_;
		is_lock = other.is_lock;
		return * this;
	}
};


int main()
{
	std::mutex m;
	std::defer_lock_t t;
	unique_lock<std::mutex> l1(m);
	
	unique_lock<std::mutex> l2(std::move(l1));

	return 0;
}
