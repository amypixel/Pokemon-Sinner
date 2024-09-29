EverGrandeCity_PhoebesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PhoebesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PhoebesRoom_OnFrame
	.byte 0

EverGrandeCity_PhoebesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_PhoebesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 1, EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 2
	releaseall
	end

EverGrandeCity_PhoebesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 2, EverGrandeCity_PhoebesRoom_EventScript_CloseDoor
	end

EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_PhoebesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_PhoebesRoom_EventScript_Phoebe::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PhoebesRoom_EventScript_Phoebe_2
EverGrandeCity_PhoebesRoom_EventScript_Phoebe_1:
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox Emily_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PHOEBE, Emily_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_Phoebe_2:
	goto EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech
	goto EverGrandeCity_PhoebesRoom_EventScript_Phoebe_1


EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech::
	msgbox Emily_Text_PostBattleSpeech, MSGBOX_DEFAULT
	addmoney 120000
	playfanfare MUS_OBTAIN_ITEM
	msgbox EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech_Text_0
	waitmessage
	releaseall
	end


EverGrandeCity_PhoebesRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox Emily_Text_PostBattleSpeech, MSGBOX_DEFAULT
	releaseall
	end


EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech_Text_0:
	.string "Player received 120,000$"

Emily_Text_IntroSpeech::
	.string "EMILY: Hi, I'm Emily. \p"
	.string "I'll be the one shredding on\n"
	.string "guitar, mandolin and flute.\p"
	.string "…\p"
	.string "Don't waste my time! \p"
	.string "Justice for fat riffs!\p"
	.string "$"

Emily_Text_Defeat::
	.string "Second best…$"

Emily_Text_PostBattleSpeech::
	.string "EMILY: You know, I hate to lose \n"
	.string "but that was fun!\p"
	.string "You definitely get the importance of \n"
	.string "fat riffs.\p"
	.string "With that energy you'll have the \n"
	.string "world at your feet.\p"
	.string "Go on, I'll see you soon.\p"
	.string "You better sing along with every \n"
	.string "guitar solo!$"
