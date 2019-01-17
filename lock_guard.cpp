/*adopt_lock_t это грубо говоря флаг который указывает lock_guard`у,
что передаваемый mutex уже захвачен и не нужно вызывать вызыватьт метод lock,
в противном случае будет повторный захват mutex`а и неопределенное поведение*/

template <typename T>
class lock_guard
{
    T& mutex;

public:
    explicit lock_guard(T& mut)
        : mutex(mut)
    {
        mutex.lock();
    }
//adopt_lock_t с std или без???
    lock_guard(T& mut, std::adopt_lock_t t)
        : mutex(mut)
    {
    }

    ~lock_guard()
    {
        mutex.unlock();
    }

    lock_guard(const lock_guard&) = delete;
    lock_guard& operator=(const lock_guard&) = delete;
};
