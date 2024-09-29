ConcertHall_MapScripts::
	.byte 0

IntroNPC1_EventScript_ConcertHall::
	lock
	applymovement 2, Common_Movement_FacePlayer
	msgbox Intro
	release
	end


faceup:
	face_up
	step_end

IntroSign_ConcertHall::
	lock
	msgbox IntroSign
	release
	end


IntroNPC2_EventScript_ConcertHall::
	lock
	applymovement 4, Common_Movement_FacePlayer
	msgbox IntroChild
	applymovement 4, lookup
	waitmovement 0
	release
	end


IntroNPC3_EventScript_ConcertHall::
	lock
	applymovement 5, Common_Movement_FacePlayer
	msgbox IntroBrenae
	applymovement 5, lookup
	waitmovement 0
	release
	end


IntroNPC4_EventScript_ConcertHall::
	lock
	compare VAR_EVER_GRANDE_CITY_STATE, 0
	goto_if_eq IntroNPC4_EventScript_ConcertHall_2
IntroNPC4_EventScript_ConcertHall_1:
	applymovement 3, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_EVER_GRANDE_CITY_STATE, 0
	goto_if_eq IntroNPC4_EventScript_ConcertHall_5
	applymovement 3, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OutroFront
IntroNPC4_EventScript_ConcertHall_4:
	release
	end

IntroNPC4_EventScript_ConcertHall_2:
	applymovement 3, emote
	playse SE_PIN
	waitse
	waitmovement 0
	goto IntroNPC4_EventScript_ConcertHall_1

IntroNPC4_EventScript_ConcertHall_5:
	applymovement OBJ_EVENT_ID_PLAYER, playerFace
	waitmovement 0
	msgbox IntroFront
	applymovement 3, moveaway
	waitmovement 0
	setvar VAR_EVER_GRANDE_CITY_STATE, 1
	goto IntroNPC4_EventScript_ConcertHall_4


playerFace:
	face_left
	step_end

emote:
	emote_exclamation_mark
	step_end

lookup:
	face_up
	step_end

moveaway:
	walk_left
	face_right
	step_end

IntroChallanger_EventScript_ConcertHall::
	lock
	applymovement 6, Common_Movement_FacePlayer
	msgbox IntroChallanger
	release
	end


SusBoy_EventScript_ConcertHall::
	lock
	applymovement 11, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_MEW, 3
	goto_if_eq SusBoy_EventScript_ConcertHall_2
	msgbox Aiden_TruckBoxes
	waitmessage
SusBoy_EventScript_ConcertHall_1:
	release
	end

SusBoy_EventScript_ConcertHall_2:
	msgbox Aiden_PokemonBox
	waitmessage
	goto SusBoy_EventScript_ConcertHall_1


Empty_EventScript_ConcertHall::
	lockall
	msgbox Empty_EventScript_ConcertHall_Text_0
	waitmessage
	releaseall
	end


NotEmpty_EventScript_ConcertHall::
	lockall
	compare VAR_RARE_BOX, 1
	goto_if_eq NotEmpty_EventScript_ConcertHall_2
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_RARE_CANDY, 1
	waitmessage
	setvar VAR_RARE_BOX, 1
NotEmpty_EventScript_ConcertHall_1:
	releaseall
	end

NotEmpty_EventScript_ConcertHall_2:
	msgbox Empty_EventScript_ConcertHall_Text_0
	waitmessage
	goto NotEmpty_EventScript_ConcertHall_1


Pokeball_EventScript_ConcertHall::
	compare VAR_MEW, 2
	goto_if_eq Pokeball_EventScript_ConcertHall_1
	msgbox Pokeball_EventScript_ConcertHall_Text_3
	waitmessage
	releaseall
	end

Pokeball_EventScript_ConcertHall_1:
	lockall
	msgbox Pokeball_EventScript_ConcertHall_Text_0
	waitmessage
	showmonpic SPECIES_MEW, 10, 3
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	msgbox Pokeball_EventScript_ConcertHall_Text_1
	waitmessage
	givemon SPECIES_MEW, 60, item = ITEM_LIFE_ORB, ball = ITEM_CHERISH_BALL, hpEv = 252, atkEv = 0, defEv = 4, speedEv = 252, spAtkEv = 0, spDefEv = 0, move1 = MOVE_AURA_SPHERE, move2 = MOVE_PSYCHIC, move3 = MOVE_TRANSFORM, move4 = MOVE_LIGHT_SCREEN
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Pokeball_EventScript_ConcertHall_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Pokeball_EventScript_ConcertHall_6
Pokeball_EventScript_ConcertHall_4:
	setvar VAR_DEWFORD_TOWN_STATE, 1
	compare VAR_DEMO_STATE, 0
	goto_if_eq Pokeball_EventScript_ConcertHall_10
Pokeball_EventScript_ConcertHall_9:
	setvar VAR_MEW, 3
	releaseall
	end

Pokeball_EventScript_ConcertHall_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_ConcertHall_Text_2
	call NicknamePartyMon
	goto Pokeball_EventScript_ConcertHall_4

Pokeball_EventScript_ConcertHall_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Pokeball_EventScript_ConcertHall_Text_2
	call NicknameBoxMon
	goto Pokeball_EventScript_ConcertHall_4

Pokeball_EventScript_ConcertHall_10:
	setvar VAR_DEMO_STATE, 1
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setflag FLAG_SYS_POKEMON_GET
	goto Pokeball_EventScript_ConcertHall_9


Turn_Back_Cave::
	lock
	msgbox Turn_Back_Cave_Text_0
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, playerBack1
	waitmovement 0
	release
	end


playerBack1:
	walk_down
	step_end

Nora_EventScript_ConcertHall::
	lock
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	applymovement 7, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_MEW, 2
	goto_if_eq Nora_EventScript_ConcertHall_2
	compare VAR_MEW, 1
	goto_if_eq Nora_EventScript_ConcertHall_3
	compare VAR_MEW, 0
	goto_if_eq Nora_EventScript_ConcertHall_4
Nora_EventScript_ConcertHall_1:
	releaseall
	end

Nora_EventScript_ConcertHall_2:
	msgbox NoraNoBattery
	waitmessage
	compare VAR_TEMP_3, 11
	goto_if_eq Nora_EventScript_ConcertHall_9
	compare VAR_TEMP_3, 10
	goto_if_eq Nora_EventScript_ConcertHall_10
	compare VAR_TEMP_3, 9
	goto_if_eq Nora_EventScript_ConcertHall_11
Nora_EventScript_ConcertHall_8:
	waitmovement 0
	removeobject 7
	removeobject 12
	removeobject 13
	removeobject 14
	removeobject 15
	setflag FLAG_MEW
	goto Nora_EventScript_ConcertHall_1

Nora_EventScript_ConcertHall_3:
	lock
	msgbox Nora_EventScript_ConcertHall_Text_0
	waitmessage
	goto Nora_EventScript_ConcertHall_1

Nora_EventScript_ConcertHall_4:
	lock
	msgbox NoraHelp
	waitmessage
	setvar VAR_MEW, 1
	goto Nora_EventScript_ConcertHall_1

Nora_EventScript_ConcertHall_9:
	applymovement 7, Nora_Run_Right
	goto Nora_EventScript_ConcertHall_8

Nora_EventScript_ConcertHall_10:
	applymovement 7, Nora_Run_Down
	goto Nora_EventScript_ConcertHall_8

Nora_EventScript_ConcertHall_11:
	applymovement 7, Nora_Run_Down
	goto Nora_EventScript_ConcertHall_8


Nora_Run_Down:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Nora_Run_Right:
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Empty_EventScript_ConcertHall_Text_0:
	.string "It's empty!$"

Pokeball_EventScript_ConcertHall_Text_0:
	.string "Huh? There's something in this box$"

Pokeball_EventScript_ConcertHall_Text_1:
	.string "It's a strange Pokémon!$"

Pokeball_EventScript_ConcertHall_Text_2:
	.string "Received Mew!$"

Pokeball_EventScript_ConcertHall_Text_3:
	.string "It's empty.$"

Turn_Back_Cave_Text_0:
	.string "Maybe I shouldn't wander around\n"
	.string "without Pokemon$"

Nora_EventScript_ConcertHall_Text_0:
	.string "NORA: Thanks! I'll wait right here!$"

Intro::
	.string "RACHEL: Wait… did you just hop off the \n"
	.string "band's truck? How did you even get on \l"
	.string "there?\p"
	.string "… … … What?\p"
	.string "You don't even have a ticket! \p"
	.string "Ohh I see! You're one of those Pokémon \n"
	.string "Trainers, looking to battle the band \l"
	.string "for a free ticket eh? \p"
	.string "Well good luck to you, I hear they're \n"
	.string "ruthless!\p"
	.string "I hope they play Second Best…$"

IntroSign::
	.string "Ever Grande City Concert Hall\p"
	.string "NEXT SHOW: The Last Dinner Party $"

OutroFront::
	.string "What are you doing out here?\p"
	.string "Show starts soon, get on in!$"

IntroChild::
	.string "YAPGOB: I've been here since 10am!\p I'm finally getting barricade!$"

IntroBrenae::
	.string "BRENAE: I bought my ticket months ago!\p"
	.string "I'm so nervous, I'm going to throw up…$"

IntroFront::
	.string "STEFF: Hey I was here first! \p"
	.string "Oh wait, you don't have a ticket? \p"
	.string "Ah you're here for the challenge! \p"
	.string "Alright then, go ahead! \p"
	.string "Good luck!$"

IntroChallanger::
	.string "NINA: You're going to face the band? \p"
	.string "Watch out for Emily… I got shredded…$"

Aiden_PokemonBox::
	.string "AIDEN: Huh? \p"
	.string "You got a POKéMON from that box?? \p"
	.string "If I'd known what was in there \n"
	.string "I wouldn't have tipped you off…$"

Aiden_TruckBoxes::
	.string "AIDEN: I came all the way from \n"
	.string "Finland! \p"
	.string "Also, the transport crew just left \n"
	.string "for lunch. \p"
	.string "Looks like a bunch of boxes by the \n"
	.string "trucks are up for grabs. \p"
	.string "I already swiped some cool stuff out of \n"
	.string "one of them. \p"
	.string "There's more I haven't touched, you \n"
	.string "should check them out, see if there's \l"
	.string "anything left.$"

NoraHelp::
	.string "NORA: Oh hey! Are you here for the \n"
	.string "show? Mind if I grab a quick photo? \p"
	.string "…\p"
	.string "Oh darn! My camera just died. \p"
	.string "Hey, do you think you could check the\n"
	.string "shop, ask if they have any batteries? \p"
	.string "If not, I'll have to drive my truck \n"
	.string "back to get one!$"

NoraNoBattery::
	.string "NORA: They didn't have any? \p"
	.string "I'll have to drive to another store \n"
	.string "real quick then. \p"
	.string "Thanks anyways, enjoy the show!$"
