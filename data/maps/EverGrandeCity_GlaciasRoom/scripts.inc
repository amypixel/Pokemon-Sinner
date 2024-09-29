EverGrandeCity_GlaciasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
	.byte 0

EverGrandeCity_GlaciasRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_GlaciasRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 3
	releaseall
	end

EverGrandeCity_GlaciasRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 3, EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
	end

EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_GlaciasRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_GlaciasRoom_EventScript_Glacia::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_Glacia_2
EverGrandeCity_GlaciasRoom_EventScript_Glacia_1:
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

EverGrandeCity_GlaciasRoom_EventScript_Glacia_2:
	goto EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
	goto EverGrandeCity_GlaciasRoom_EventScript_Glacia_1


EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	addmoney 150000
	playfanfare MUS_OBTAIN_ITEM
	msgbox EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech_Text_0
	waitmessage
	releaseall
	end


EverGrandeCity_GlaciasRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	releaseall
	end


EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech_Text_0:
	.string "Player received 150,000$"

EverGrandeCity_GlaciasRoom_Text_IntroSpeech::
	.string "LIZZIE: Hey I'm Lizzie, rhythm \n"
	.string "guitarist, singer, dancer and sinner.\p"
	.string "Running and spinning on stage is\n"
	.string "fun but you know what, I'd leave it\l"
	.string "all for a good battle.\p"
	.string "You look like a sinner too, in a\n"
	.string "good way of course.\p"
	.string "Let's dance, shall we?\n"
	.string "Turn and face me!$"

EverGrandeCity_GlaciasRoom_Text_Defeat::
	.string "Washed the sin from my back…$"

EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech::
	.string "LIZZIE: Hey you're pretty good \n"
	.string "at this!\p"
	.string "Something tells me your face won't\n"
	.string "be forgotten.\p"
	.string "We'll be seeing you around, won't \n"
	.string "we? \p"
	.string "Keep it up, see you at the show!$"
