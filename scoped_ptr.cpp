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

	 // TODO make_scoped
};
