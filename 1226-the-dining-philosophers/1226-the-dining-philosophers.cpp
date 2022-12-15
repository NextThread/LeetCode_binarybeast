class DiningPhilosophers {
    mutex mtx; // 5 philosophers share 1 single mutex
public:
    DiningPhilosophers() {
    }
    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) 
    {
        mtx.lock();
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        mtx.unlock();
    }
};