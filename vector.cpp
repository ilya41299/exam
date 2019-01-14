#include <iostream>

template <typename T>
class vector_t
{
private:
    T* elements_;
    std::size_t size_;
    std::size_t capacity_;

public:
    vector_t()
    {
        elements_ = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    vector_t(vector_t<T> const& other)
    {
        size_ = other.size_;
        capacity_ = other.capacity_;
        if (elements_ != nullptr)
            delete[] elements_;
        elements_ = new T[capacity_];
        for (std::size_t i = 0; i < size_; ++i)
        {
            elements_[i] = other.elements_[i];
        }
    }

    void push_back(T value)
    {
        if (size_ == 0)
        {
            size_ = 1;
            capacity_ = 1;
            elements_ = new T[capacity_];
            elements_[0] = value;
        }
        else if (size_ == capacity_)
        {
            T* mas;
            capacity_ *= 2;
            mas = new T[capacity_];
            for (std::size_t i = 0; i < size_; ++i)
            {
                mas[i] = elements_[i];
            }
            delete[] elements_;
            elements_ = mas;
            elements_[size_] = value;
            ++size_;
        }
        else
        {
            elements_[size_] = value;
            ++size_;
        }
    }

    vector_t(vector_t<T>&& other)
    {
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(elements_, other.elements_);
    }

    vector_t<T>& operator=(vector_t<T> const& other)
    {
        if (this != &other)
        {
            if (elements_ != nullptr)
                delete[] elements_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            elements_ = new T[capacity_];
            for (std::size_t i = 0; i < size_; ++i)
            {
                elements_[i] = other.elements_[i];
            }
        }
        return *this;
    }

    vector_t<T>& operator=(vector_t<T>&& other)
    {
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(elements_, other.elements_);
    }

    T operator[](std::size_t index) const
    {
        return elements_[index];
    }

    ~vector_t()
    {
        if (elements_ != nullptr)
            delete[] elements_;
        size_ = 0;
        capacity_ = 0;
    }

    void insert(std::size_t pos, const T& value)
    {
        if (capacity_ == 0)
            capacity_ = 1;
        while (pos + 1 > capacity_)
        {
            capacity_ *= 2;
        }
        T* mas;
        mas = new T[capacity_];
        ++size_;
        for (std::size_t i = 0; i < capacity_; ++i)
        {
            if (i < pos)
            {
                mas[i] = elements_[i];
            }
            else if (i == pos)
            {
                mas[i] = value;
            }
            else
            {
                mas[i] = elements_[i - 1];
            }
        }
        delete[] elements_;
        elements_ = mas;
    }
};
