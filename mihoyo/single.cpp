
#include <iostream>
#include <mutex>

using std::cin;
using std::cout;

class Game {
    static Game* instance_;
    static std::mutex mutex_;
    Game(){  };

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;    
public:
    int num = 10;
    static Game* getInstance() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (instance_ == nullptr) {
            instance_ = new Game();
        }
        return instance_;
    }
    void play() {
        cout << "play game\n";
    }
};

Game* Game::instance_ = nullptr;
std::mutex Game::mutex_;

signed main() {
    Game *k = new Game();
    Game *g = Game::getInstance();
    Game *m = Game::getInstance();
    m->play();
    m->num += 10;

    g->play();
    // cout << g->num << std::endl;
    cout << g->num << std::endl;

}