#include <mutex>


template <class Mutex>
class unique_lock
{
	Mutex m_;
public:
	unique_lock() {}

	~unique_lock()
	{
		m_.unlock();
	}

	unique_lock(unique_lock&& other) noexcept
	{
		m_ = other.m_;
	}

	explicit unique_lock(Mutex & m) : m_(m)
	{
		m_.lock();
	}
	unique_lock(Mutex& m, std::defer_lock_t t) noexcept {}

	unique_lock(Mutex& m, std::adopt_lock_t t) :m_(m) {}
	void lock()
	{ m_.lock(); }

	void unlock()
	{ m_.unlock();}

	unique_lock<Mutex>& operator=(unique_lock<Mutex>&& other) 
	{ m_ = other.m_; }
};
