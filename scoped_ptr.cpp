template <typename T>
class scoped_ptr 
{
	T * ptr_;
	scoped_ptr(const scoped_ptr & ptr) = delete;
	const scoped_ptr & operator =(const scoped_ptr &ptr) = delete;
public:
	scoped_ptr(T* ptr) 
	{ ptr_ = ptr; }

	~scoped_ptr() 
	{ delete ptr_; }

	T* operator -> () 
	{ return ptr_; }

	T & operator * ()
	{ return *ptr_; }

	T * get() 
	{ return ptr_; }
};

template<typename T, typename... Args> 
scoped_ptr<T> make_scoped(Args&&... args) 
{ 
return scoped_ptr<T>(new T(std::forward<Args>(args)...)); 
}

int main()
{
	int *A = new int (5);
	scoped_ptr<int> ptr = A;
	std::cout << *ptr;
}
