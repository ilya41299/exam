#include <mutex>
#include <queue>
#include <thread>

template <typename T>
class SafeQueue
{
    std::mutex Mutex;
    std::queue<T> Queue;

public:
    SafeQueue()
    {
    }
    T Pop()
    {
        std::lock_guard<std::mutex> lg(Mutex);
        T temp = Queue.front();
        Queue.pop();
        return temp;
    }
    void Push(const T& Value)
    {
        std::lock_guard<std::mutex> lg(Mutex);
        Queue.push(Value);
    }
    bool TryPop()
    {
        std::unique_lock<std::mutex> lg(Mutex, std::defer_lock);
        if (lg.try_lock())
        {
            Queue.pop();
            lg.unlock();
            return true;
        }
        return false;
    }
};
