#include "Header.h"

class AbstractCreator
{
public:
    virtual IStrategy* create() const = 0;
};

template <class C>
class StrategyCreator : public AbstractCreator
{
public:
    virtual IStrategy* create() const { return new C(); }
};

class StrategyFactory
{
protected:
    typedef std::map<int, AbstractCreator*> FactoryMap;
    FactoryMap _factory;

public:

    template <class C>
    void add(const int& id)
    {
        typename FactoryMap::iterator it = _factory.find(id);
        if (it == _factory.end())
            _factory[id] = new StrategyCreator<C>();
    }

    IStrategy* create(const int& id)
    {
        typename FactoryMap::iterator it = _factory.find(id);
        if (it != _factory.end())
            return it->second->create();
        return 0;
    }
    ~StrategyFactory() {

    };
};


int main(int argc, char* argv[])
{
    StrategyFactory factory;
    factory.add<StrategyRand>(1);
    factory.add<StrategyAlwaysC>(2);
    factory.add<StrategyAlwaysD>(3);
    factory.add<StrategyWinRound>(4);
    factory.add<StrategyTeamplay>(5);
    factory.add<StrategyRevengeful>(6);
    int playerscount = 0;
    short game_type = 0;
    typedef std::map<int, IStrategy*> Players;//1ое число номер игрока 2ое номер стратегии 
    Players players;//стратегии 
    int game_steps_number;
    if (argc == 1) {
        std::cout << "choice players and game mode (D-detailed, F-fast, T-tournament, E-to exit)\n";
        while (game_type == 0) {
            char tmp[256];
            std::cin >> tmp;
            switch (tmp[0])
            {
            case 'D':
                game_type = 1;
                break;
            case 'F':
                game_type = 2;
                break;
            case 'T':
                game_type = 3;
                break;
            case 'E':
                return 0;
            default:
                int tmp2 = atoi(tmp);
                typename Players::iterator it = players.find(playerscount);
                if (it == players.end())
                    players[playerscount] = factory.create(tmp2);
                game_type = 0;
                playerscount++;
            }
        }
        std::cout << "steps count: ";
        std::cin >> game_steps_number;

        Game(game_type, players, game_steps_number, playerscount);

    }
    else {
        for (int i = 1; i < argc - 1; i++) {
            char tmp = *argv[i];
            switch (tmp)
            {
            case 'D'://68 
                game_type = 1;
                break;
            case 'F'://70 
                game_type = 2;
                break;
            case 'T'://84 
                game_type = 3;
                break;
            case 'E'://69 
                return 0;
            default:
                int tmp2 = atoi(&tmp);
                typename Players::iterator it = players.find(playerscount);
                if (it == players.end())
                    players[playerscount] = factory.create(tmp2);
                game_type = 0;
                playerscount++;
            }
        }
        game_steps_number = atoi(argv[argc - 1]);

        Game(game_type, players, game_steps_number, playerscount);
    }
}