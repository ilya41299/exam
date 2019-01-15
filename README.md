# exam

Реализуйте потокобезопасную очередь с блокировкой на основе std::queue.
 
template <class T>
class SafeQueue {
public:
	T Pop();
	void Push(const T& value);
	bool TryPop(T& value);
};
Реализуйте потокобезопасный стек с блокировкой std::stack.
 
template <class T>
class SafeStack {
public:
	T Pop();
	void Push(const T& value);
	bool TryPop(T& value);
};
Реализуйте шаблонный класс unique_ptr. Реализуйте функцию make_unique.
 
template <class T>
class unique_ptr {
public:
	unique_ptr();
	~unique_ptr();
    unique_ptr(unique_ptr<T>&&);
	unique_ptr<T>& operator=(unique_ptr<T>&&);
	void reset(T* ptr=nullptr);
	T* release();
	void swap();
	T* operator->();
	T& operator*();
	operator bool() const;
	T* get();
};
Реализуйте шаблонный класс scoped_ptr. Реализуйте make_scoped.
 
template <class T>
class scoped_ptr {
public:
	scoped_ptr(T*);
	~scoped_ptr();
	T* operator->();
	T& operator*();
	T* get();
};
Реализуйте шаблонный класс shared_ptr без счетчика слабых ссылок.
 
template <class T>
class shared_ptr {
public:
	shared_ptr();
	~shared_ptr();
	shared_ptr(shared_ptr<T>&&);
	shared_ptr<T>& operator=(shared_ptr<T>&&);
	shared_ptr(const shared_ptr<T>&);
	shared_ptr<T>& operator=(const shared_ptr<T>&);
	void reset(T* ptr=nullptr);
	T* release();
	void swap();
	T* operator->();
	T& operator*();
	operator bool() const;
	T* get();
};
 
Реализуйте класс unique_guard.
 
template <class Mutex>
class unique_lock {
public:
	unique_lock();
	~unique_lock();
	unique_lock( unique_lock&& other ) noexcept;
	explicit unique_lock(Mutex & m );
	unique_lock(Mutex& m, std::defer_lock_t t ) noexcept;
	unique_lock(Mutex& m, std::adopt_lock_t t );
	void lock();
	void unlock();
	unique_lock<Mute>& operator=(unique_lock<Mute>&&);
};
Реализуйте класс lock_guard
Реализуйте шаблонный класс optional. Реализуйте функцию make_optional
 
template <class T>
class optional {
public:
	constexpr optional() noexcept;
	constexpr optional( std::nullopt_t ) noexcept;
	constexpr optional( const optional& other );
	constexpr optional( optional&& other ) noexcept;
	optional<T>& operator=(const optional<T>&);
	optional<T>& operator=(optional<T>&&);
    T& operator*();
	T* operator->();
	operator bool() const;
	T& value();
 
	template <class U>
	T value_or(U&& default_value);
};
Реализуйте класс any и функцию any_cast.
 
class any {
public:
	any();
	any(const any&);
	
	template <class ValueType>
	any(ValueType&& other);
	any& operator=(const optional<T>&);
	const std::type_info& type() const noexcept;
};
 
template<class ValueType>
ValueType any_cast(const any& operand);
 
template<class ValueType>
ValueType* any_cast(any* operand) noexcept;
 
Реализуйте пользовательский аллокатор, который служит для отладочных целей. Аллокатор должен выводить в поток вывода адреса выделяемой и освобождаемой памяти.
 
template<class OutStream>
class DebugAlloc {
public:
	DebugAlloc(OutStream&);
	//остальные методы класса, которые необходимы для реализации аллокатора
};
 
Реализуйте алгоритм параллельной сортировки с использованием алгоритма сортировки из стандартной библиотеки.
 
template<class IT>
void MultiThreadingSort(IT first, IT last);
 
Реализуйте многопоточный алгоритм умножения матриц с использованием std::async
 
template <class T>
using Matrix = std::vector<std::vector<T>>;
 
template <class T>
Matrix<T> mult(const Matrix<T>&, const Matrix& /*можно вводить дополнительные аргументы в случае необходимости*/);
 
Дана неубывающая последовательность чисел. Нужно найти 2 числа этой последовательности, сумма которых равна определенному числу. Сложность алгоритма по времени – , где  –размер последовательности.
template <typename Iterator, typename T>
std::pair<bool, std::pair<Iterator, Iterator>> find_two_elements_with_sum( Iterator first, Iterator last, T c );
 
 
Реализовать функцию слияния двух отсортированных массивов со сложностью , где ,  – размеры исходных массивов.
template <typename Iterator1, typename Iterator2>
Iterator2 merge( Iterator1 first1, Iterator1 last1, Iterator1 first2, Iterator1 last2, Iterator2 output );
 
Реализуйте класс string. Класс должен содержать
·               Конструктор копирования
·               Конструктор перемещения
·               Оператор копирования
·               Оператор перемещения
·                Конструктор от const char*
·               Деструктор
·               operator[]
·               Метод append
·               Метод replace
string& replace (iterator first, iterator last, const string& str);
// Заменяет часть строки, указанную диапазоном [first, last), на новую строку str.
 
Реализуйте шаблонный класс vector. Класс должен содержать
·               Конструктор копирования
·               Конструктор перемещения
·               Оператор копирования
·               Оператор перемещения
·               Деструктор
·               Метод добавления элемента в конец (push_back)
·               operator[]
·               Метод вставки элемента в произвольное место в массиве
 
 

