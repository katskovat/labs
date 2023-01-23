#include "Header.h" 

char IStrategy::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices)
{
    return 0;
};

char StrategyRand::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) {
    char answer;
    srand(int(time(NULL)));
    int tmp = rand() % 2;
    if (tmp == 0) {
        answer = 'C';
    }
    else
    {
        answer = 'D';
    }

    if (game_type == 1) {
        std::cout << answer << " ";
        return answer;
    }
    else {
        return answer;
    }
};

char StrategyAlwaysC::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) {
    char answer;
    answer = 'C';
    if (game_type == 1) {
        std::cout << answer << " ";
        return answer;
    }
    else {
        return answer;
    }
};

char StrategyAlwaysD::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) {
    char answer;
    answer = 'D';
    if (game_type == 1) {
        std::cout << answer << " ";
        return answer;
    }
    else {
        return answer;
    }
};

char StrategyWinRound::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) {
    int max = 0;
    if ((max < _score[0]) && (p != 0))max = _score[0];
    if ((max < _score[1]) && (p != 1))max = _score[1];
    if ((max < _score[2]) && (p != 2))max = _score[2];
    int ownscore = _score[p];

    char answer;
    if (ownscore <= max)
        answer = 'D';
    else {
        StrategyRand strategy1;
        answer = strategy1.Getchoice(0, -1, _score, _roundes, _roundechoices);
    }

    if (game_type == 1) {
        std::cout << answer << " ";
        return answer;
    }
    else {
        return answer;
    }
};

char StrategyTeamplay::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) {
    char answer = 0;
    if (moveCounter < 12) {
        switch (moveCounter)
        {
        case 0:
            answer = 'C';
        case 1:
            answer = 'D';
        case 2:
            answer = 'C';
        case 3:
            answer = 'C';
        case 4:
            answer = 'C';
        case 5:
            answer = 'D';
        case 6:
            answer = 'D';
        case 7:
            answer = 'C';
        case 8:
            answer = 'D';
        case 9:
            answer = 'C';
        case 10:
            answer = 'D';
        case 11:
            answer = 'C';
        }
    }
    else if ((moveCounter >= 12) && (vectorEqualityFlag == -1)) {
        for (int i = 0; i < 12; i++) {
            std::vector<char> a = _roundes[i];
            acc0.push_back(a[0]);
            acc1.push_back(a[1]);
            acc2.push_back(a[2]);
        }
        v0v1 = (acc0 == acc1);
        v0v2 = (acc0 == acc2);
        v1v2 = (acc1 == acc2);
        if (v0v1 == true)game_type = 1;
        else if (v0v2 == true)game_type = 2;
        else if (v1v2 == true)game_type = 3;
        else
            game_type = 0;
    }

    if ((vectorEqualityFlag > 0) && (vectorEqualityFlag != -1)) {
        if (vectorEqualityFlag == 1) {
            if (p == 0) {
                if (_score[0] >= _score[1]) answer = 'D';
                else answer = 'C';
            }
            if (p == 1) {
                if (_score[0] > _score[1]) answer = 'C';
                else answer = 'D';
            }
        }
        else if (vectorEqualityFlag == 2) {
            if (p == 0) {
                if (_score[0] >= _score[2]) answer = 'D';
                else answer = 'C';
            }
            if (p == 2) {
                if (_score[0] > _score[2]) answer = 'C';
                else answer = 'D';
            }
        }
        else if (vectorEqualityFlag == 3) {
            if (p == 1) {
                if (_score[1] >= _score[2]) answer = 'D';
                else answer = 'C';
            }
            if (p == 2) {
                if (_score[1] >= _score[2]) answer = 'C';
                else answer = 'D';
            }
        }
    }
    else if (vectorEqualityFlag == 0) answer = 'D';
    if (game_type == 1)
    {
        std::cout << answer << " ";
    }

    moveCounter++;
    return answer;
};

char StrategyRevengeful::Getchoice(short game_type, int p, std::vector<int> _score, std::vector<std::vector<char>> _roundes, std::vector<char> _roundechoices) {
    char answer = 0;
    if (((_roundechoices[0] == 'D') && (p != 0)) || ((_roundechoices[1] == 'D') && (p != 1)) || ((_roundechoices[2] == 'D') && (p != 2))) {
        int tmp = rand() % 3;
        if (tmp == 2)
            answer = 'C';
        else
            answer = 'D';
    }
    else
    {
        answer = 'C';
    }

    if (game_type == 1)
    {
        std::cout << answer << " ";
    }
    return answer;
};