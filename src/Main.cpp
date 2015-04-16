//////////////////////////////////////
// Application Entry Point
//////////////////////////////////////
#include "./OPengine.h"
#include "./include/Game/Game.h"

//////////////////////////////////////
// Application Methods
//////////////////////////////////////

void ApplicationInit() {

	OPloadersAddDefault();

	OPchar* assetDir = NULL;
#ifdef OPIFEX_ASSETS
	assetDir = OPIFEX_ASSETS;
#endif
	OPcmanInit(assetDir);

	OPrenderInit();

	OPgamePadSetDeadzones(0.15);

	OPgameStateChange(&GAME_STATE);

}

int ApplicationUpdate(OPtimer* timer) {
	OPcmanUpdate(timer);
	OPinputSystemUpdate(timer);

	if (OPkeyboardWasPressed(OPKEY_ESCAPE) || 
		OPgamePadWasPressed(OPgamePadGet(OPGAMEPAD_ONE), OPGAMEPADBUTTON_BACK) || 
		OPgamePadWasPressed(OPgamePadGet(OPGAMEPAD_TWO), OPGAMEPADBUTTON_BACK)) return 1;

	ActiveState->Update(timer);

	return 0;
}

void ApplicationDestroy() {
	ActiveState->Exit(NULL);
}

//////////////////////////////////////
// Application Entry Point
//////////////////////////////////////
OP_MAIN {
	OPlog("Starting up OPengine");

	OPinitialize = ApplicationInit;
	OPupdate = ApplicationUpdate;
	OPdestroy = ApplicationDestroy;

	OP_MAIN_START
	OP_MAIN_END
	OP_MAIN_SUCCESS
}