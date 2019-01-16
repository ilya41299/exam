#include <atomic>
template <typename T>
class shared_ptr
{
private:
    std::atomic_uint* count;
    T* ptr_;

public:
    shared_ptr()
    {
        count = nullptr;
        ptr_ = nullptr;
    }
    // проверяет, указывает ли указатель на объект
    operator bool() const
    {
        if (ptr_ != nullptr)
            return true;
        else
            return false;
    }
    // возвращает количество объектов shared_ptr, которые ссылаются на тот же
    // управляемый объект
    std::size_t use_count() const
    {
        return *count;
    }
    explicit shared_ptr(T* ptr)
    {
        ptr_ = ptr;
        if (ptr_)
            count = new std::atomic_uint(1);
        else
            count = nullptr;
    }

    ~shared_ptr()
    {
        if (count && --*count == 0)
        {
            delete ptr_;
            delete count;
        }
    }

    shared_ptr(shared_ptr&& other)
    {
        if (other != *this)
        {
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
            count = other.count;
            other.count = nullptr;
        }
    }

    shared_ptr& operator=(shared_ptr&& other)
    {
        if (other != *this)
        {
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
            count = other.count;
            other.count = nullptr;
        }
        return *this;
    }


    shared_ptr(shared_ptr const& other)
    {
        ptr_ = other.ptr_;
        count = other.count;
        if (other.count)
            ++*count;
    }

    shared_ptr operator=(shared_ptr const& other)
    {
        if (&other != this)
        {
            shared_ptr(other).swap(*this);
        }
        return *this;
    }

    T* release() 
	{
		if (count && --*count)
		{
			T * point = new T;
			point = ptr_;
			count = nullptr;
			ptr_ = nullptr;
			return point;
		}
		
		T * point = ptr_;
		delete ptr_;
		delete count;
		count = nullptr;
		ptr_ = nullptr;
	    return point;
	}*/

    void swap(shared_ptr& shared)
    {
        std::swap(shared.ptr_, ptr_);
        std::swap(shared.count, count);
    }

    void reset(T* ptr = nullptr)
    {
        shared_ptr(ptr).swap(*this);
    }

    T& operator*() const
    { return *ptr_; }

    T* operator->() const
    { return ptr_; }

    T* get() const
    {return ptr_;}
};


int main()
{
    shared_ptr<int> My_ptr1(new int(3));
    std::cout << My_ptr1.use_count();
    shared_ptr<int> My_ptr2 = My_ptr1;
    std::cout << My_ptr1.use_count();
    //12
    return 0;
}
