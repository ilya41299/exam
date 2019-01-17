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
        if(Queue.empty()) throw std::logic_error "empty_Queue";
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
        std::defer_lock t;
        std::unique_lock<std::mutex> lg(Mutex, t);
        if (lg.try_lock() && !Queue.empty())
        {
            Queue.pop();
            return true;
        }
        return false;
    }
};
