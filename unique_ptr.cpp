
template <typename T>
class unique_ptr {
	T * ptr_;
public:
	unique_ptr() 
        { ptr_ = nullptr; }
	~unique_ptr() {if(ptr_) delete ptr_; }

	unique_ptr(unique_ptr<T> && Uptr)
	{ std::swap(Uptr.ptr_, ptr_); }

	unique_ptr<T> & operator=(unique_ptr<T> && Uptr)
	{ 
		std::swap(Uptr.ptr_, ptr_);
		return *this;
	}

	void reset(T * ptr = nullptr) 
	{ ptr_ = ptr; }

	T * release() 
	{
		ptr_ = nullptr;
		return ptr_;
	}
	void swap(unique_ptr<T> &other) 
	{ std::swap(other.ptr_, ptr_); }
	unique_ptr(unique_ptr& ptr) = delete;
	unique_ptr& operator = (unique_ptr&) = delete;

	T* operator->() 
	{ return ptr_; }

	T & operator * () 
	{ return *ptr_; }

	operator bool() const 
	{
		if (ptr_) return true;
		return false;
	}

	T * get() 
	{ return ptr_; }
};

template<typename T, typename... Args> 
unique_ptr<T> make_unique(Args&&... args) 
{ 
return unique_ptr<T>(new T(std::forward<Args>(args)...)); 
}


int main() 
{
	int *A = new int(5);
	unique_ptr<int> ptr;
	ptr.reset(A);
	std::cout << *ptr;
}
