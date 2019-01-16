
template <typename T>
class unique_ptr {

	T * ptr_;
public:
	unique_ptr() {
		if (!ptr_) {
			ptr_ = new T;
		}
	}
	~unique_ptr() {if(ptr_) delete ptr_; }

	unique_ptr(unique_ptr<T> && ptr)
	{ std::swap(ptr, ptr_); }

	unique_ptr<T> & operator=(unique_ptr<T> && ptr)
	{ std::swap(ptr, ptr_); }

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

	//,????
  unique make_unique() 
	{

	}
};

int main() 
{
	int *A = new int(5);
	unique_ptr<int> ptr;
	ptr.reset(A);
	std::cout << *ptr;
}
