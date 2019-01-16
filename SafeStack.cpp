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
		std::unique_lock<std::mutex> lg(Mutex, std::defer_lock);
		if (lg.try_lock()) 
		{
			Stack.pop();
			return true;
		}
		return false;
	}
};
