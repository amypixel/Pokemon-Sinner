EverGrandeCity_SidneysRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
	.byte 0

EverGrandeCity_SidneysRoom_OnTransition:
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	end

EverGrandeCity_SidneysRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 1, EverGrandeCity_SidneysRoom_EventScript_CloseDoor
	end

EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_SidneysRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_SidneysRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_SidneysRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

EverGrandeCity_SidneysRoom_EventScript_Sidney::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_Sidney_2
EverGrandeCity_SidneysRoom_EventScript_Sidney_1:
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox Aurora_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIDNEY, Aurora_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_Sidney_2:
	goto EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
	goto EverGrandeCity_SidneysRoom_EventScript_Sidney_1


EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech::
	msgbox Aurora_Text_PostBattleSpeech
	releaseall
	end


EverGrandeCity_SidneysRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox Aurora_Text_PostBattleSpeech
	addmoney 100000
	playfanfare MUS_OBTAIN_ITEM
	msgbox EverGrandeCity_SidneysRoom_EventScript_Defeated_Text_0
	waitmessage
	releaseall
	end


EverGrandeCity_SidneysRoom_EventScript_Defeated_Text_0:
	.string "Player received 100,000$"

Aurora_Text_IntroSpeech::
	.string "AURORA: Hey there! I'm Aurora of\n"
	.string "The Last Dinner Party!\p"
	.string "I'll be on vocals and keys tonight. \p"
	.string "You look like you really want that\n"
	.string "free ticket huh?\p"
	.string "Well, you'll have to show us that\n"
	.string "you have the guts to handle\l"
	.string "our show!\p"
	.string "So put up a fight!$"

Aurora_Text_Defeat::
	.string "Give me the strength…$"

Aurora_Text_PostBattleSpeech::
	.string "AURORA: That was something!\p"
	.string "If anyone could win this thing,\n"
	.string "it probably would be you!\p"
	.string "Go ahead, go meet the others,\n"
	.string "though I have to warn you.\p"
	.string "One wrong move and they'll\n"
	.string "tear you apart.\p"
	.string "Good luck!$"
