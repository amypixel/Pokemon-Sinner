EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_Drake_2
EverGrandeCity_DrakesRoom_EventScript_Drake_1:
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_Drake_2:
	goto EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	goto EverGrandeCity_DrakesRoom_EventScript_Drake_1


EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	addmoney 180000
	playfanfare MUS_OBTAIN_ITEM
	msgbox EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech_Text_0
	waitmessage
	releaseall
	end


EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	releaseall
	end


EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech_Text_0:
	.string "Player received 180,000$"

EverGrandeCity_DrakesRoom_Text_IntroSpeech::
	.string "GEORGIA: Hey love, I'm Georgia and \n"
	.string "I'll be playing killer basslines.\p"
	.string "But you knew that already, didn't\n"
	.string "you?\p"
	.string "Now show me, are you more of a sailor\n"
	.string "or a nightingale?\p"
	.string "Let's find out!$"

EverGrandeCity_DrakesRoom_Text_Defeat::
	.string "Nothing matters…$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech::
	.string "GEORGIA: Oh my god that was so good!\n"
	.string "I feel like we're a lot alike.\p"
	.string "You sure seem to understand us.\p"
	.string "One more and we're away, see\n"
	.string "you soon my sweet!\p"
	.string "Go onwards!\n"
	.string "Abi is waiting!$"
