EverGrandeCity_DemoStarter_MapScripts::
	.byte 0

Demo_Mart::
	lock
	faceplayer
	compare VAR_MEW, 1
	goto_if_eq Demo_Mart_2
	compare VAR_DEMOSHOP, 0
	goto_if_eq Demo_Mart_6
Demo_Mart_5:
	message Demo_Mart_Text_0
	waitmessage
	pokemart Demo_MartItems
	msgbox Demo_Mart_Text_1
Demo_Mart_1:
	release
	end

Demo_Mart_2:
	msgbox MartBattery
	waitmessage
	setvar VAR_MEW, 2
	goto Demo_Mart_1

Demo_Mart_6:
	addmoney 150000
	setvar VAR_DEMOSHOP, 1
	goto Demo_Mart_5


Demo_Sign::
	lock
	msgbox Demo_Sign_Text_0
	waitmessage
	release
	end


	.align 2
Demo_MartItems:
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_MAX_ELIXER
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MEGA_RING
	.2byte ITEM_GALLADITE
	.2byte ITEM_GARCHOMPITE
	.2byte ITEM_TYRANITARITE
	.2byte ITEM_METAGROSSITE
	.2byte ITEM_VENUSAURITE
	.2byte ITEM_NONE

Ness_EventScript_Demo::
	lockall
	applymovement 27, Common_Movement_FacePlayer
	msgbox NessStrategy
	waitmessage
	releaseall
	end


Nurse_EventScript_Demo::
	lock
	applymovement 1, Common_Movement_FacePlayer
	msgbox NursePick
	release
	end


NurseGive_EventScript_Demo1::
	lockall
	applymovement 1, NurseGive_1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, playerFace1
	waitmovement 0
	msgbox NurseGive_Ready
	call GivePlayerGod
	msgbox NurseGive_GoGetem
	applymovement 1, NurseBack_1
	waitmovement 0
	setvar VAR_DEMO_STATE, 2
	releaseall
	end


NurseGive_EventScript_Demo2::
	lockall
	applymovement 1, NurseGive_2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, playerFace1
	waitmovement 0
	msgbox NurseGive_Ready
	call GivePlayerGod
	msgbox NurseGive_GoGetem
	applymovement 1, NurseBack_2
	waitmovement 0
	setvar VAR_DEMO_STATE, 2
	releaseall
	end


SetFlags_EventScript_Demo::
	setvar VAR_DEWFORD_TOWN_STATE, 1
	compare VAR_DEMO_STATE, 0
	goto_if_eq SetFlags_EventScript_Demo_1
	return

SetFlags_EventScript_Demo_1:
	setvar VAR_DEMO_STATE, 1
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setflag FLAG_SYS_POKEMON_GET
	return


playerFace1:
	face_right
	step_end

playerBack:
	walk_down
	step_end

NurseGive_1:
	face_left
	step_end

NurseGive_2:
	face_left
	walk_left
	step_end

NurseBack_1:
	face_down
	step_end

NurseBack_2:
	walk_right
	face_down
	step_end

GivePlayerGod::
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	playfanfare MUS_OBTAIN_ITEM
	msgbox GivePlayerGod_Text_0
	waitmessage
	msgbox GivePlayerGod_Text_1
	giveitem ITEM_MAX_REVIVE, amount = 5
	giveitem ITEM_HYPER_POTION, amount = 10
	giveitem ITEM_FULL_RESTORE, amount = 10
	return


NurseStop_EventScript_Demo1::
	lockall
	applymovement 1, NurseGive_1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, playerFace1
	waitmovement 0
	msgbox NurseStop_Text
	applymovement OBJ_EVENT_ID_PLAYER, playerBack
	waitmovement 0
	applymovement 1, NurseBack_1
	waitmovement 0
	releaseall
	end


NurseStop_EventScript_Demo2::
	lockall
	applymovement 1, NurseGive_2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, playerFace1
	waitmovement 0
	msgbox NurseStop_Text
	applymovement OBJ_EVENT_ID_PLAYER, playerBack
	waitmovement 0
	applymovement 1, NurseBack_2
	waitmovement 0
	releaseall
	end


EverGradeCity_DemoStarter_OnTransition::
	setrespawn HEAL_LOCATION_EVERGRANDECITY_DEMOSTARTER
	end


NicknamePartyMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
	call Common_EventScript_TransferredToPC
	return

NicknameBoxMon_2:
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


EventScript_VipRoom::
	lockall
	msgbox EventScript_VipRoom_Text_0
	waitmessage
	releaseall
	end


Pokeball_EventScript_Demo1::
	lockall
	showmonpic SPECIES_INFERNAPE, 10, 3
	msgbox Pokeball_EventScript_Demo1_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo1_2
	hidemonpic
Pokeball_EventScript_Demo1_1:
	releaseall
	end

Pokeball_EventScript_Demo1_2:
	givemon SPECIES_INFERNAPE, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, speedEv = 252, atkEv = 256, move1 = MOVE_FLAMETHROWER, move2 = MOVE_CLOSE_COMBAT, move3 = MOVE_U_TURN, move4 = MOVE_THUNDER_PUNCH
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo1_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo1_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo1_1

Pokeball_EventScript_Demo1_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo1_Text_1
	call NicknamePartyMon
	removeobject 2
	setflag FLAG_POKEBALL_1
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo1_1

Pokeball_EventScript_Demo1_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo1_Text_1
	call NicknameBoxMon
	removeobject 2
	setflag FLAG_POKEBALL_1
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo1_1


Pokeball_EventScript_Demo2::
	lockall
	showmonpic SPECIES_AZUMARILL, 10, 3
	msgbox Pokeball_EventScript_Demo2_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo2_2
	hidemonpic
Pokeball_EventScript_Demo2_1:
	releaseall
	end

Pokeball_EventScript_Demo2_2:
	givemon SPECIES_AZUMARILL, 55, item = ITEM_NONE, ball = ITEM_POKE_BALL, hpEv = 100, atkEv = 252, defEv = 0, speedEv = 152, spAtkEv = 0, spDefEv = 0, move1 = MOVE_LIQUIDATION, move2 = MOVE_PLAY_ROUGH, move3 = MOVE_AQUA_JET, move4 = MOVE_ICE_PUNCH
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo2_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo2_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo2_1

Pokeball_EventScript_Demo2_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo2_Text_1
	call NicknamePartyMon
	removeobject 3
	setflag FLAG_POKEBALL_2
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo2_1

Pokeball_EventScript_Demo2_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo2_Text_1
	call NicknameBoxMon
	removeobject 3
	setflag FLAG_POKEBALL_2
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo2_1


Pokeball_EventScript_Demo3::
	lockall
	showmonpic SPECIES_MAGNEZONE, 10, 3
	msgbox Pokeball_EventScript_Demo3_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo3_2
	hidemonpic
Pokeball_EventScript_Demo3_1:
	releaseall
	end

Pokeball_EventScript_Demo3_2:
	givemon SPECIES_MAGNEZONE, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 100, atkEv = 0, defEv = 0, speedEv = 152, spAtkEv = 256, spDefEv = 0, move1 = MOVE_THUNDERBOLT, move2 = MOVE_BODY_PRESS, move3 = MOVE_FLASH_CANNON, move4 = MOVE_THUNDER_WAVE
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo3_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo3_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo3_1

Pokeball_EventScript_Demo3_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo3_Text_1
	call NicknamePartyMon
	removeobject 4
	setflag FLAG_POKEBALL_3
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo3_1

Pokeball_EventScript_Demo3_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo3_Text_1
	call NicknameBoxMon
	removeobject 4
	setflag FLAG_POKEBALL_3
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo3_1


Pokeball_EventScript_Demo4::
	lockall
	showmonpic SPECIES_METAGROSS, 10, 3
	msgbox Pokeball_EventScript_Demo4_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo4_2
	hidemonpic
Pokeball_EventScript_Demo4_1:
	releaseall
	end

Pokeball_EventScript_Demo4_2:
	givemon SPECIES_METAGROSS, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 232, atkEv = 60, defEv = 0, speedEv = 176, spAtkEv = 0, spDefEv = 40, move1 = MOVE_BULLET_PUNCH, move2 = MOVE_ZEN_HEADBUTT, move3 = MOVE_REST, move4 = MOVE_ROCK_SLIDE
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo4_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo4_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo4_1

Pokeball_EventScript_Demo4_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo4_Text_1
	call NicknamePartyMon
	removeobject 5
	setflag FLAG_POKEBALL_4
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo4_1

Pokeball_EventScript_Demo4_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo4_Text_1
	call NicknameBoxMon
	removeobject 5
	setflag FLAG_POKEBALL_4
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo4_1


Pokeball_EventScript_Demo5::
	lockall
	showmonpic SPECIES_UMBREON, 10, 3
	msgbox Pokeball_EventScript_Demo5_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo5_2
	hidemonpic
Pokeball_EventScript_Demo5_1:
	releaseall
	end

Pokeball_EventScript_Demo5_2:
	givemon SPECIES_UMBREON, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 252, atkEv = 0, defEv = 4, speedEv = 0, spAtkEv = 0, spDefEv = 252, move1 = MOVE_THROAT_CHOP, move2 = MOVE_SHADOW_BALL, move3 = MOVE_ALLURING_VOICE, move4 = MOVE_TOXIC
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo5_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo5_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo5_1

Pokeball_EventScript_Demo5_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo5_Text_1
	call NicknamePartyMon
	removeobject 6
	setflag FLAG_POKEBALL_5
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo5_1

Pokeball_EventScript_Demo5_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo5_Text_1
	call NicknameBoxMon
	removeobject 6
	setflag FLAG_POKEBALL_5
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo5_1


Pokeball_EventScript_Demo6::
	lockall
	showmonpic SPECIES_SCOLIPEDE, 10, 3
	msgbox Pokeball_EventScript_Demo6_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo6_2
	hidemonpic
Pokeball_EventScript_Demo6_1:
	releaseall
	end

Pokeball_EventScript_Demo6_2:
	givemon SPECIES_SCOLIPEDE, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 0, atkEv = 252, defEv = 4, speedEv = 0, spAtkEv = 0, spDefEv = 252, move1 = MOVE_TOXIC_SPIKES, move2 = MOVE_STOMPING_TANTRUM, move3 = MOVE_X_SCISSOR, move4 = MOVE_SWORDS_DANCE
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo6_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo6_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo6_1

Pokeball_EventScript_Demo6_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo6_Text_1
	call NicknamePartyMon
	removeobject 7
	setflag FLAG_POKEBALL_6
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo6_1

Pokeball_EventScript_Demo6_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo6_Text_1
	call NicknameBoxMon
	removeobject 7
	setflag FLAG_POKEBALL_6
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo6_1


Pokeball_EventScript_Demo7::
	lockall
	showmonpic SPECIES_EMPOLEON, 10, 3
	msgbox Pokeball_EventScript_Demo7_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo7_2
	hidemonpic
Pokeball_EventScript_Demo7_1:
	releaseall
	end

Pokeball_EventScript_Demo7_2:
	givemon SPECIES_EMPOLEON, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 252, atkEv = 0, defEv = 76, speedEv = 180, spAtkEv = 0, spDefEv = 0, move1 = MOVE_ICE_BEAM, move2 = MOVE_SURF, move3 = MOVE_FLASH_CANNON, move4 = MOVE_ROOST
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo7_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo7_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo7_1

Pokeball_EventScript_Demo7_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo7_Text_1
	call NicknamePartyMon
	removeobject 8
	setflag FLAG_POKEBALL_7
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo7_1

Pokeball_EventScript_Demo7_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo7_Text_1
	call NicknameBoxMon
	removeobject 8
	setflag FLAG_POKEBALL_7
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo7_1


Pokeball_EventScript_Demo8::
	lockall
	showmonpic SPECIES_EELEKTROSS, 10, 3
	msgbox Pokeball_EventScript_Demo8_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo8_2
	hidemonpic
Pokeball_EventScript_Demo8_1:
	releaseall
	end

Pokeball_EventScript_Demo8_2:
	givemon SPECIES_EELEKTROSS, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 252, atkEv = 4, defEv = 0, speedEv = 0, spAtkEv = 252, spDefEv = 0, move1 = MOVE_THUNDER_PUNCH, move2 = MOVE_GIGA_DRAIN, move3 = MOVE_DRAIN_PUNCH, move4 = MOVE_LIQUIDATION
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo8_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo8_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo8_1

Pokeball_EventScript_Demo8_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo8_Text_1
	call NicknamePartyMon
	removeobject 9
	setflag FLAG_POKEBALL_8
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo8_1

Pokeball_EventScript_Demo8_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo8_Text_1
	call NicknameBoxMon
	removeobject 9
	setflag FLAG_POKEBALL_8
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo8_1


Pokeball_EventScript_Demo9::
	lockall
	showmonpic SPECIES_FERROTHORN, 10, 3
	msgbox Pokeball_EventScript_Demo9_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo9_2
	hidemonpic
Pokeball_EventScript_Demo9_1:
	releaseall
	end

Pokeball_EventScript_Demo9_2:
	givemon SPECIES_FERROTHORN, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 252, atkEv = 0, defEv = 24, speedEv = 0, spAtkEv = 0, spDefEv = 232, move1 = MOVE_GYRO_BALL, move2 = MOVE_SPIKES, move3 = MOVE_RAPID_SPIN, move4 = MOVE_POWER_WHIP
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo9_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo9_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo9_1

Pokeball_EventScript_Demo9_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo9_Text_1
	call NicknamePartyMon
	removeobject 10
	setflag FLAG_POKEBALL_9
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo9_1

Pokeball_EventScript_Demo9_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo9_Text_1
	call NicknameBoxMon
	removeobject 10
	setflag FLAG_POKEBALL_9
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo9_1


Pokeball_EventScript_Demo10::
	lockall
	showmonpic SPECIES_AEGISLASH, 10, 3
	msgbox Pokeball_EventScript_Demo10_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo10_2
	hidemonpic
Pokeball_EventScript_Demo10_1:
	releaseall
	end

Pokeball_EventScript_Demo10_2:
	givemon SPECIES_AEGISLASH, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 252, atkEv = 0, defEv = 0, speedEv = 0, spAtkEv = 4, spDefEv = 252, move1 = MOVE_FLASH_CANNON, move2 = MOVE_SHADOW_BALL, move3 = MOVE_NIGHT_SLASH, move4 = MOVE_SACRED_SWORD
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo10_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo10_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo10_1

Pokeball_EventScript_Demo10_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo10_Text_1
	call NicknamePartyMon
	removeobject 11
	setflag FLAG_POKEBALL_10
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo10_1

Pokeball_EventScript_Demo10_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo10_Text_1
	call NicknameBoxMon
	removeobject 11
	setflag FLAG_POKEBALL_10
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo10_1


Pokeball_EventScript_Demo11::
	lockall
	showmonpic SPECIES_TALONFLAME, 10, 3
	msgbox Pokeball_EventScript_Demo11_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo11_2
	hidemonpic
Pokeball_EventScript_Demo11_1:
	releaseall
	end

Pokeball_EventScript_Demo11_2:
	givemon SPECIES_TALONFLAME, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 252, atkEv = 0, defEv = 0, speedEv = 252, spAtkEv = 4, spDefEv = 0, move1 = MOVE_ACROBATICS, move2 = MOVE_HEAT_WAVE, move3 = MOVE_ROOST, move4 = MOVE_SWORDS_DANCE
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo11_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo11_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo11_1

Pokeball_EventScript_Demo11_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo11_Text_1
	call NicknamePartyMon
	removeobject 12
	setflag FLAG_POKEBALL_11
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo11_1

Pokeball_EventScript_Demo11_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo11_Text_1
	call NicknameBoxMon
	removeobject 12
	setflag FLAG_POKEBALL_11
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo11_1


Pokeball_EventScript_Demo12::
	lockall
	showmonpic SPECIES_GALLADE, 10, 3
	msgbox Pokeball_EventScript_Demo12_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo12_2
	hidemonpic
Pokeball_EventScript_Demo12_1:
	releaseall
	end

Pokeball_EventScript_Demo12_2:
	givemon SPECIES_GALLADE, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 0, atkEv = 252, defEv = 4, speedEv = 0, spAtkEv = 0, spDefEv = 252, move1 = MOVE_ICE_PUNCH, move2 = MOVE_CLOSE_COMBAT, move3 = MOVE_PSYCHO_CUT, move4 = MOVE_PAIN_SPLIT
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo12_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo12_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo12_1

Pokeball_EventScript_Demo12_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo12_Text_1
	call NicknamePartyMon
	removeobject 13
	setflag FLAG_POKEBALL_12
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo12_1

Pokeball_EventScript_Demo12_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo12_Text_1
	call NicknameBoxMon
	removeobject 13
	setflag FLAG_POKEBALL_12
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo12_1


Pokeball_EventScript_Demo13::
	lockall
	showmonpic SPECIES_VENUSAUR, 10, 3
	msgbox Pokeball_EventScript_Demo13_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo13_2
	hidemonpic
Pokeball_EventScript_Demo13_1:
	releaseall
	end

Pokeball_EventScript_Demo13_2:
	givemon SPECIES_VENUSAUR, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 100, atkEv = 0, defEv = 4, speedEv = 152, spAtkEv = 252, spDefEv = 0, move1 = MOVE_GIGA_DRAIN, move2 = MOVE_SLUDGE_BOMB, move3 = MOVE_EARTH_POWER, move4 = MOVE_TOXIC
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo13_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo13_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo13_1

Pokeball_EventScript_Demo13_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo13_Text_1
	call NicknamePartyMon
	removeobject 15
	setflag FLAG_POKEBALL_13
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo13_1

Pokeball_EventScript_Demo13_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo13_Text_1
	call NicknameBoxMon
	removeobject 15
	setflag FLAG_POKEBALL_13
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo13_1


Pokeball_EventScript_Demo14::
	lockall
	showmonpic SPECIES_LYCANROC_DUSK, 10, 3
	msgbox Pokeball_EventScript_Demo14_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo14_2
	hidemonpic
Pokeball_EventScript_Demo14_1:
	releaseall
	end

Pokeball_EventScript_Demo14_2:
	givemon SPECIES_LYCANROC_DUSK, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 0, atkEv = 252, defEv = 4, speedEv = 252, spAtkEv = 0, spDefEv = 0, move1 = MOVE_DRILL_RUN, move2 = MOVE_ACCELEROCK, move3 = MOVE_PSYCHIC_FANGS, move4 = MOVE_STEALTH_ROCK
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo14_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo14_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo14_1

Pokeball_EventScript_Demo14_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo14_Text_1
	call NicknamePartyMon
	removeobject 16
	setflag FLAG_POKEBALL_14
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo14_1

Pokeball_EventScript_Demo14_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo14_Text_1
	call NicknameBoxMon
	removeobject 16
	setflag FLAG_POKEBALL_14
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo14_1


Pokeball_EventScript_Demo15::
	lockall
	showmonpic SPECIES_HATTERENE, 10, 3
	msgbox Pokeball_EventScript_Demo15_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo15_2
	hidemonpic
Pokeball_EventScript_Demo15_1:
	releaseall
	end

Pokeball_EventScript_Demo15_2:
	givemon SPECIES_HATTERENE, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 252, atkEv = 0, defEv = 204, speedEv = 52, spAtkEv = 0, spDefEv = 0, move1 = MOVE_DRAINING_KISS, move2 = MOVE_PSYSHOCK, move3 = MOVE_MYSTICAL_FIRE, move4 = MOVE_TRICK_ROOM
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo15_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo15_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo15_1

Pokeball_EventScript_Demo15_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo15_Text_1
	call NicknamePartyMon
	removeobject 17
	setflag FLAG_POKEBALL_15
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo15_1

Pokeball_EventScript_Demo15_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo15_Text_1
	call NicknameBoxMon
	removeobject 17
	setflag FLAG_POKEBALL_15
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo15_1


Pokeball_EventScript_Demo16::
	lockall
	showmonpic SPECIES_KINGDRA, 10, 3
	msgbox Pokeball_EventScript_Demo16_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo16_2
	hidemonpic
Pokeball_EventScript_Demo16_1:
	releaseall
	end

Pokeball_EventScript_Demo16_2:
	givemon SPECIES_KINGDRA, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 0, atkEv = 0, defEv = 0, speedEv = 252, spAtkEv = 252, spDefEv = 4, move1 = MOVE_WATERFALL, move2 = MOVE_DRAGON_DANCE, move3 = MOVE_IRON_HEAD, move4 = MOVE_ICE_BEAM
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo16_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo16_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo16_1

Pokeball_EventScript_Demo16_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo16_Text_1
	call NicknamePartyMon
	removeobject 18
	setflag FLAG_POKEBALL_16
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo16_1

Pokeball_EventScript_Demo16_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo16_Text_1
	call NicknameBoxMon
	removeobject 18
	setflag FLAG_POKEBALL_16
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo16_1


Pokeball_EventScript_Demo17::
	lockall
	showmonpic SPECIES_ARCANINE, 10, 3
	msgbox Pokeball_EventScript_Demo17_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo17_2
	hidemonpic
Pokeball_EventScript_Demo17_1:
	releaseall
	end

Pokeball_EventScript_Demo17_2:
	givemon SPECIES_ARCANINE, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 160, atkEv = 252, defEv = 0, speedEv = 96, spAtkEv = 0, spDefEv = 0, move1 = MOVE_EXTREME_SPEED, move2 = MOVE_FLAMETHROWER, move3 = MOVE_CRUNCH, move4 = MOVE_SCORCHING_SANDS
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo17_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo17_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo17_1

Pokeball_EventScript_Demo17_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo17_Text_1
	call NicknamePartyMon
	removeobject 19
	setflag FLAG_POKEBALL_17
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo17_1

Pokeball_EventScript_Demo17_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo17_Text_1
	call NicknameBoxMon
	removeobject 19
	setflag FLAG_POKEBALL_17
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo17_1


Pokeball_EventScript_Demo18::
	lockall
	showmonpic SPECIES_TYRANITAR, 10, 3
	msgbox Pokeball_EventScript_Demo18_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo18_2
	hidemonpic
Pokeball_EventScript_Demo18_1:
	releaseall
	end

Pokeball_EventScript_Demo18_2:
	givemon SPECIES_TYRANITAR, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 252, atkEv = 4, defEv = 0, speedEv = 40, spAtkEv = 0, spDefEv = 212, move1 = MOVE_STEALTH_ROCK, move2 = MOVE_EARTHQUAKE, move3 = MOVE_FOUL_PLAY, move4 = MOVE_STONE_EDGE
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo18_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo18_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo18_1

Pokeball_EventScript_Demo18_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo18_Text_1
	call NicknamePartyMon
	removeobject 20
	setflag FLAG_POKEBALL_18
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo18_1

Pokeball_EventScript_Demo18_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo18_Text_1
	call NicknameBoxMon
	removeobject 20
	setflag FLAG_POKEBALL_18
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo18_1


Pokeball_EventScript_Demo19::
	lockall
	showmonpic SPECIES_NIDOQUEEN, 10, 3
	msgbox Pokeball_EventScript_Demo19_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo19_2
	hidemonpic
Pokeball_EventScript_Demo19_1:
	releaseall
	end

Pokeball_EventScript_Demo19_2:
	givemon SPECIES_NIDOQUEEN, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 248, atkEv = 0, defEv = 172, speedEv = 88, spAtkEv = 0, spDefEv = 0, move1 = MOVE_EARTHQUAKE, move2 = MOVE_POISON_JAB, move3 = MOVE_CRUNCH, move4 = MOVE_ICE_BEAM
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo19_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo19_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo19_1

Pokeball_EventScript_Demo19_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo19_Text_1
	call NicknamePartyMon
	removeobject 21
	setflag FLAG_POKEBALL_19
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo19_1

Pokeball_EventScript_Demo19_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo19_Text_1
	call NicknameBoxMon
	removeobject 21
	setflag FLAG_POKEBALL_19
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo19_1


Pokeball_EventScript_Demo20::
	lockall
	showmonpic SPECIES_LUXRAY, 10, 3
	msgbox Pokeball_EventScript_Demo20_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo20_2
	hidemonpic
Pokeball_EventScript_Demo20_1:
	releaseall
	end

Pokeball_EventScript_Demo20_2:
	givemon SPECIES_LUXRAY, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 252, atkEv = 4, defEv = 0, speedEv = 0, spAtkEv = 252, spDefEv = 0, move1 = MOVE_PLAY_ROUGH, move2 = MOVE_THROAT_CHOP, move3 = MOVE_PSYCHIC_FANGS, move4 = MOVE_THUNDERBOLT
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo20_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo20_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo20_1

Pokeball_EventScript_Demo20_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo20_Text_1
	call NicknamePartyMon
	removeobject 22
	setflag FLAG_POKEBALL_20
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo20_1

Pokeball_EventScript_Demo20_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo20_Text_1
	call NicknameBoxMon
	removeobject 22
	setflag FLAG_POKEBALL_20
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo20_1


Pokeball_EventScript_Demo21::
	lockall
	showmonpic SPECIES_HAWLUCHA, 10, 3
	msgbox Pokeball_EventScript_Demo21_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo21_2
	hidemonpic
Pokeball_EventScript_Demo21_1:
	releaseall
	end

Pokeball_EventScript_Demo21_2:
	givemon SPECIES_HAWLUCHA, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 0, atkEv = 252, defEv = 0, speedEv = 252, spAtkEv = 0, spDefEv = 4, move1 = MOVE_ACROBATICS, move2 = MOVE_SWORDS_DANCE, move3 = MOVE_THUNDER_PUNCH, move4 = MOVE_CROSS_CHOP
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo21_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo21_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo21_1

Pokeball_EventScript_Demo21_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo21_Text_1
	call NicknamePartyMon
	removeobject 23
	setflag FLAG_POKEBALL_21
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo21_1

Pokeball_EventScript_Demo21_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo21_Text_1
	call NicknameBoxMon
	removeobject 23
	setflag FLAG_POKEBALL_21
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo21_1


Pokeball_EventScript_Demo22::
	lockall
	showmonpic SPECIES_LANTURN, 10, 3
	msgbox Pokeball_EventScript_Demo22_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo22_2
	hidemonpic
Pokeball_EventScript_Demo22_1:
	releaseall
	end

Pokeball_EventScript_Demo22_2:
	givemon SPECIES_LANTURN, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 252, atkEv = 4, defEv = 0, speedEv = 0, spAtkEv = 252, spDefEv = 0, move1 = MOVE_THUNDERBOLT, move2 = MOVE_SCALD, move3 = MOVE_AQUA_RING, move4 = MOVE_DAZZLING_GLEAM
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo22_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo22_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo22_1

Pokeball_EventScript_Demo22_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo22_Text_1
	call NicknamePartyMon
	removeobject 24
	setflag FLAG_POKEBALL_22
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo22_1

Pokeball_EventScript_Demo22_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo22_Text_1
	call NicknameBoxMon
	removeobject 24
	setflag FLAG_POKEBALL_22
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo22_1


Pokeball_EventScript_Demo23::
	lockall
	showmonpic SPECIES_EXEGGUTOR, 10, 3
	msgbox Pokeball_EventScript_Demo23_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo23_2
	hidemonpic
Pokeball_EventScript_Demo23_1:
	releaseall
	end

Pokeball_EventScript_Demo23_2:
	givemon SPECIES_EXEGGUTOR, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 252, atkEv = 4, defEv = 0, speedEv = 0, spAtkEv = 252, spDefEv = 0, move1 = MOVE_LEECH_SEED, move2 = MOVE_ENERGY_BALL, move3 = MOVE_PSYCHIC, move4 = MOVE_ANCIENT_POWER
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo23_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo23_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo23_1

Pokeball_EventScript_Demo23_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo23_Text_1
	call NicknamePartyMon
	removeobject 25
	setflag FLAG_POKEBALL_23
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo23_1

Pokeball_EventScript_Demo23_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo23_Text_1
	call NicknameBoxMon
	removeobject 25
	setflag FLAG_POKEBALL_23
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo23_1


Pokeball_EventScript_Demo24::
	lockall
	showmonpic SPECIES_GARCHOMP, 10, 3
	msgbox Pokeball_EventScript_Demo24_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokeball_EventScript_Demo24_2
	hidemonpic
Pokeball_EventScript_Demo24_1:
	releaseall
	end

Pokeball_EventScript_Demo24_2:
	givemon SPECIES_GARCHOMP, 55, item = ITEM_NONE, ball = ITEM_MASTER_BALL, hpEv = 0, atkEv = 252, defEv = 4, speedEv = 252, spAtkEv = 0, spDefEv = 0, move1 = MOVE_DRAGON_CLAW, move2 = MOVE_EARTHQUAKE, move3 = MOVE_IRON_HEAD, move4 = MOVE_FIRE_BLAST
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_Demo24_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_Demo24_6
	hidemonpic
	msgbox Pokeball_EventScript_Demo1_Text_2
	goto Pokeball_EventScript_Demo24_1

Pokeball_EventScript_Demo24_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo24_Text_1
	call NicknamePartyMon
	removeobject 26
	setflag FLAG_POKEBALL_24
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo24_1

Pokeball_EventScript_Demo24_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_Demo24_Text_1
	call NicknameBoxMon
	removeobject 26
	setflag FLAG_POKEBALL_24
	call SetFlags_EventScript_Demo
	goto Pokeball_EventScript_Demo24_1


Demo_Mart_Text_0:
	.string "AMY: Welcome to the Merch Stand, what \ncan I get for you?$"

Demo_Mart_Text_1:
	.string "Good luck, babe!$"

Demo_Sign_Text_0:
	.string "Rewards Preview\p"
	.string "Aurora: 100,000\p"
	.string "Emily: 120,000\p"
	.string "Lizzie: 150,000\p"
	.string "Georgia: 180,000\p"
	.string "Abigail: Dinner Guest List!$"

GivePlayerGod_Text_0:
	.string "Received all 8 Gym Badges!$"

GivePlayerGod_Text_1:
	.string "They don't look as cool as my famous\nGob Pins but they'll come in handy.\pAlso take these: $"

NicknamePartyMon_Text_0:
	.string "Give it a nickname?$"

EventScript_VipRoom_Text_0:
	.string "Sorry pal, only VIP's allowed in the\n"
	.string "lounge area.$"

Pokeball_EventScript_Demo1_Text_0:
	.string "Do you want to choose \nFire/Fighting type Infernape?$"

Pokeball_EventScript_Demo1_Text_1:
	.string "Received Infernape!$"

Pokeball_EventScript_Demo1_Text_2:
	.string "No More Room$"

Pokeball_EventScript_Demo2_Text_0:
	.string "Do you want to choose \nWater/Fairy type Azumarill?$"

Pokeball_EventScript_Demo2_Text_1:
	.string "Received Azumarill!$"

Pokeball_EventScript_Demo3_Text_0:
	.string "Do you want to choose \nElectric/Steel type Magnezone?$"

Pokeball_EventScript_Demo3_Text_1:
	.string "Received Magnezone!$"

Pokeball_EventScript_Demo4_Text_0:
	.string "Do you want to choose \nSteel/Psychic type Metagross?$"

Pokeball_EventScript_Demo4_Text_1:
	.string "Received Metagross!$"

Pokeball_EventScript_Demo5_Text_0:
	.string "Do you want to choose \nDark type Umbreon?$"

Pokeball_EventScript_Demo5_Text_1:
	.string "Received Umbreon!$"

Pokeball_EventScript_Demo6_Text_0:
	.string "Do you want to choose \nBug/Poison type Scolipede?$"

Pokeball_EventScript_Demo6_Text_1:
	.string "Received Scolipede!$"

Pokeball_EventScript_Demo7_Text_0:
	.string "Do you want to choose \nWater/Steel type Empoleon?$"

Pokeball_EventScript_Demo7_Text_1:
	.string "Received Empoleon!$"

Pokeball_EventScript_Demo8_Text_0:
	.string "Do you want to choose \nElectric type Eelektross?$"

Pokeball_EventScript_Demo8_Text_1:
	.string "Received Eelektross!$"

Pokeball_EventScript_Demo9_Text_0:
	.string "Do you want to choose \nGrass/Steel type Ferrothorn?$"

Pokeball_EventScript_Demo9_Text_1:
	.string "Received Ferrothorn!$"

Pokeball_EventScript_Demo10_Text_0:
	.string "Do you want to choose \nSteel/Ghost type Aegislash?$"

Pokeball_EventScript_Demo10_Text_1:
	.string "Received Aegislash!$"

Pokeball_EventScript_Demo11_Text_0:
	.string "Do you want to choose \nFire/Flying type Talonflame?$"

Pokeball_EventScript_Demo11_Text_1:
	.string "Received Talonflame!$"

Pokeball_EventScript_Demo12_Text_0:
	.string "Do you want to choose \nPsychic/Fighting type Gallade ?$"

Pokeball_EventScript_Demo12_Text_1:
	.string "Received Gallade!$"

Pokeball_EventScript_Demo13_Text_0:
	.string "Do you want to choose \nGrass/Poison type Venusaur?$"

Pokeball_EventScript_Demo13_Text_1:
	.string "Received Venusaur!$"

Pokeball_EventScript_Demo14_Text_0:
	.string "Do you want to choose \nRock type Lycanroc?$"

Pokeball_EventScript_Demo14_Text_1:
	.string "Received Lycanroc!$"

Pokeball_EventScript_Demo15_Text_0:
	.string "Do you want to choose \nPsychic/Fairy type Hatterene?$"

Pokeball_EventScript_Demo15_Text_1:
	.string "Received Hatterene!$"

Pokeball_EventScript_Demo16_Text_0:
	.string "Do you want to choose \nWater/Dragon type Kingdra?$"

Pokeball_EventScript_Demo16_Text_1:
	.string "Received Kingdra!$"

Pokeball_EventScript_Demo17_Text_0:
	.string "Do you want to choose \nFire type Arcanine ?$"

Pokeball_EventScript_Demo17_Text_1:
	.string "Received Arcanine!$"

Pokeball_EventScript_Demo18_Text_0:
	.string "Do you want to choose \nRock/Dark type Tyranitar ?$"

Pokeball_EventScript_Demo18_Text_1:
	.string "Received Tyranitar!$"

Pokeball_EventScript_Demo19_Text_0:
	.string "Do you want to choose \nGround/Poison type Nidoqueen?$"

Pokeball_EventScript_Demo19_Text_1:
	.string "Received Nidoqueen!$"

Pokeball_EventScript_Demo20_Text_0:
	.string "Do you want to choose \nElectric type Luxray?$"

Pokeball_EventScript_Demo20_Text_1:
	.string "Received Luxray!$"

Pokeball_EventScript_Demo21_Text_0:
	.string "Do you want to choose \nFighting/Flying type Hawlucha ?$"

Pokeball_EventScript_Demo21_Text_1:
	.string "Received Hawlucha!$"

Pokeball_EventScript_Demo22_Text_0:
	.string "Do you want to choose \nWater/Electric type Lanturn ?$"

Pokeball_EventScript_Demo22_Text_1:
	.string "Received Lanturn!$"

Pokeball_EventScript_Demo23_Text_0:
	.string "Do you want to choose \nGrass/Psychic type Exeggutor ?$"

Pokeball_EventScript_Demo23_Text_1:
	.string "Received Exeggutor!$"

Pokeball_EventScript_Demo24_Text_0:
	.string "Do you want to choose \nDragon/Ground type Garchomp ?$"

Pokeball_EventScript_Demo24_Text_1:
	.string "Received Garchomp!$"

MartBattery::
	.string "AMY: Welcome to the Merch Stand, what \n"
	.string "can I get for you?\p"
	.string "Oh, Nora needs a fresh camera battery? \p"
	.string "Sorry hun, but we don't stock them \n"
	.string "in here!\p"
	.string "You best go tell her we don't have \n"
	.string "any.$"

NessStrategy::
	.string "NESS: Hi! My name's Ness, nice to \n"
	.string "meet you. \p"
	.string "You're here to take on the band too? \p"
	.string "I made it all the way to Lizzie but \n"
	.string "then they stomped me! \p"
	.string "I gotta rethink my strategy…$"

NursePick::
	.string "GOBLIN: Pick your team out of these \n"
	.string "guys over there!\p"
	.string "The band are absolute killers,\n"
	.string "you're gonna need a whooole lotta\l"
	.string "nerve to beat them!$"

NurseGive_Ready::
	.string "GOBLIN: Are you ready to challenge\n"
	.string "The Last Dinner Party?\p"
	.string "I heard they'll invite you to their\n"
	.string "show if you manage to beat them \l"
	.string "all in one go. \p"
	.string "I'm Goblin by the way,\n"
	.string "I'll be at the show too!\p"
	.string "Anyway you'll need these:$"

NurseGive_GoGetem::
	.string "You're all set, go show 'em who's\n"
	.string "the real gunslinger!$"

NurseStop_Text::
	.string "GOBLIN: Are you trying to challenge \n"
	.string "the band to POKéMON battles…\l"
	.string "without POKéMON? \p"
	.string "That won't do!\p"
	.string "Go pick your team out of these guys\n"
	.string "over there.$"
