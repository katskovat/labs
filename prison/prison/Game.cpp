#include "Header.h" 

int Game(short game_type, std::map<int, IStrategy*> players, int game_steps_number, int playerscount) {

    Score score;
    std::vector<std::vector<char>> roundschoices(game_steps_number); //вектор векторов ходов 
    if (game_type == 3) { //турнир
        int* players_of_this_rounde = new int[playerscount];
        for (int i = 0; i < playerscount; i++)players_of_this_rounde[i] = i + 1;
        int players_count_in_single_game = 3;
        for (int i = 0; i < players_count_in_single_game; i++) 
            std::cout << players_of_this_rounde[i] << " ";
        std::cout << "\n";
        score = Simulator(game_steps_number, game_type, players_of_this_rounde[0], players_of_this_rounde[1], players_of_this_rounde[2], score, roundschoices, players);
        if (playerscount >= players_count_in_single_game)
        {
            while (PlayersOfNewRounde(players_of_this_rounde, playerscount, players_count_in_single_game)) {
                for (int i = 0; i < players_count_in_single_game; i++) std::cout << players_of_this_rounde[i] << " ";
                std::cout << "\n";
                score = Simulator(game_steps_number, game_type, players_of_this_rounde[0], players_of_this_rounde[1], players_of_this_rounde[2], score, roundschoices, players);
            }
        }
        score.ShowBestGlobalScore();
        return 0;
    }
    else if ((game_type == 1) || (game_type == 2)) {
        score = Simulator(game_steps_number, game_type, 0, 1, 2, score, roundschoices, players);
        score.ShowBestGlobalScore();
        return 0;
    }
    return -1;

}