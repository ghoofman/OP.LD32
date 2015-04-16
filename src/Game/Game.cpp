#include "./include/Game/Game.h"


struct GameData {

};

GameData _game;

void GameInit(OPgameState* gameState) {

}

OPint GameUpdate(OPtimer* timer) {
	OPrenderClear(0.2, 0.2, 0.2);

	OPrenderPresent();
	return 0;
}

OPint GameExit(OPgameState* gameState) {
	return 0;
}

OPgameState GAME_STATE = {
	GameInit,
	GameUpdate,
	GameExit
};