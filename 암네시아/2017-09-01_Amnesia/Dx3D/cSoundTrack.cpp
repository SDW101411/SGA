#include "stdafx.h"
#include "cSoundTrack.h"

cSoundTrack::cSoundTrack()
{	
}

cSoundTrack::~cSoundTrack()
{
}

void cSoundTrack::Insert()
{
	SOUNDMANAGER->addSound("15_event_elevator", "15_event_elevator.ogg", true, true);
	SOUNDMANAGER->addSound("game_menu", "game_menu.ogg", true, true);
	SOUNDMANAGER->addSound("dan_brute", "dan_brute.ogg", true, true);
	SOUNDMANAGER->addSound("ui_use_oil", "ui_use_oil.ogg", false, false);
	SOUNDMANAGER->addSound("ui_use_health", "ui_use_health.ogg", false, false);
	SOUNDMANAGER->addSound("journal_open", "journal_open.ogg", false, false);
	SOUNDMANAGER->addSound("journal_close", "journal_close.ogg", false, false);
	SOUNDMANAGER->addSound("ui_lantern_on", "ui_lantern_on.ogg", false, false);
	SOUNDMANAGER->addSound("ui_lantern_off", "ui_lantern_off.ogg", false, false);
	SOUNDMANAGER->addSound("player_falldamage1", "player_falldamage1.ogg", false, false);
	SOUNDMANAGER->addSound("player_falldamage2", "player_falldamage2.ogg", false, false);
	SOUNDMANAGER->addSound("player_falldamage3", "player_falldamage3.ogg", false, false);
	SOUNDMANAGER->addSound("pick_potion", "pick_potion.ogg", false, false);
	SOUNDMANAGER->addSound("pick_generic", "pick_generic.ogg", false, false);
	SOUNDMANAGER->addSound("ui_use_tinderbox", "ui_use_tinderbox.ogg", false, false);
}
