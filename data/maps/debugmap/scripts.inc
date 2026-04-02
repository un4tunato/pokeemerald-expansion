debugmap_MapScripts::
	.byte 0

script_debugsetup::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, script_debugdone
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq script_debugfullparty
	givemon SPECIES_WOOBAT, 10, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_B_DASH
	addmoney 50000
	special SetUnlockedPokedexFlags
	playfanfare MUS_OBTAIN_ITEM
	msgbox text_debugsetupfinish, MSGBOX_DEFAULT
	waitfanfare
	release
	end

script_debugfullparty::
	msgbox text_debugfullparty, MSGBOX_DEFAULT
	release
	end

script_debugdone::
	msgbox text_debugsetupfinish, MSGBOX_DEFAULT
	release
	end

text_debugsetupfinish:
	.string "Test setup complete?$"

text_debugfullparty:
	.string "Party full.$"

script_trainer_battleguy::
	trainerbattle_single TRAINER_BATTLEGUY, text_bguyintro, text_bguywin
	end

text_bguyintro:
	.string "Hey! Fight me!$"

text_bguywin:
	.string "Tough break."
