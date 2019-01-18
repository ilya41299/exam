// не компилируется , писал по стандарту, вообще хз 
template <class T>
class my_opt {
public:
	constexpr my_opt() noexcept
		:_Dummy{}, ok{ false }
	{}
	constexpr my_opt(std::nullopt_t) noexcept:
		my_opt()
	{}
	constexpr my_opt(const my_opt& other) = default;
	constexpr my_opt(my_opt&& other) noexcept = default;
	my_opt<T>& operator=(const my_opt<T>& other) = default;
	my_opt<T>& operator=(my_opt<T>&& other) = default;
	~my_opt() = default;
	T& operator*()
	{
		return std::addressof(this->_get());
	}
	T* operator->()
	{
		return this->_get();
	}
	operator bool() const
	{
		return ok;
	}
	T& value()
	{
		if (!ok)
		{
			throw(std::bad_optional_access);
			// ??
		}
		else
		{
			return this->_get();
		}
	}

	template <class U>
	T value_or(U&& default_value)
	{
		if (ok)
			return this->_get;
		else
		{
			return static_cast<T>(std::forward<U>(default_value));
		}
	}

private:
	constexpr T& _get() & noexcept
	{
		return (this->_Value);
	}
	union
	{
		char _Dummy;
		std::remove_const_t<T> _Value;
	};
	bool ok;
};
