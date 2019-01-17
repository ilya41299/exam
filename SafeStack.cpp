#include <mutex>
#include <stack>
#include <thread>

template <typename T>
class  SafeStack
{
	std::mutex Mutex;
	std::stack<T> Stack;
public:
	SafeStack() {}
	T Pop()
	{
		std::lock_guard<std::mutex> lg(Mutex);
		if (Stack.empty()) throw std::logic_error "empty stack";
		T temp = Stack.top();
		Stack.pop();
		return temp;

	}
	void Push(const T& Value)
	{
		std::lock_guard<std::mutex> lg(Mutex);
		Stack.push(Value);
	}
	bool TryPop()
	{
		std::defer_lock_t t;
		std::unique_lock<std::mutex> lg(Mutex, t);
		if (lg.try_lock() && !Stack.empty())
		{
			Stack.pop();
			return true;
		}
		return false;
	}
};
