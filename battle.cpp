// include allegro libraries
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

#include "battleScreen.h"
#include "enemyShip.h"
#include "boss.h"

#include <time.h>
#include <stdlib.h>
#include <iostream>

BattleScreen::BattleScreen(Ship* ship) {
	this->ship = ship;
	userName = this->ship->getShipName();
	enemyHP = 280;
	userHP = 754;

	al_init_font_addon();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_ttf_addon();

	// Colors
	black = al_map_rgb(0,0,0);
	lime = al_map_rgb(10,230,30);
	red = al_map_rgb(255,0,0);
	white = al_map_rgb(255,255,255);

	// font
	font = al_load_ttf_font("PressStart2P.ttf", 10, 0);

	// image
	battleBG = al_load_bitmap("mermaid-2-blue-water.jpg");

	if(!battleBG)
		std::cerr << "Failed to load image. Use full path instead." << std::endl;
}

BattleScreen::~BattleScreen() {
	al_destroy_event_queue(eventQueue);
	al_destroy_timer(timer);
}

void BattleScreen::draw() { 
	// Background Image
	al_draw_bitmap(battleBG, 0, 0, 0);

	// Attack description box
	al_draw_filled_rectangle(0, SCREEN_HEIGHT - 150, SCREEN_WIDTH, SCREEN_HEIGHT, black);
	al_draw_filled_rounded_rectangle(5, SCREEN_HEIGHT - 155, SCREEN_WIDTH - 300, SCREEN_HEIGHT - 5, 10, 10, white);
	al_draw_rounded_rectangle(10, SCREEN_HEIGHT - 150, SCREEN_WIDTH - 305, SCREEN_HEIGHT - 10, 5, 5, black, 2);

	// Menu box
	al_draw_filled_rounded_rectangle(SCREEN_WIDTH - 295, SCREEN_HEIGHT - 155, SCREEN_WIDTH - 5, SCREEN_HEIGHT - 5, 10, 10, white);
	al_draw_rounded_rectangle(SCREEN_WIDTH - 290, SCREEN_HEIGHT - 150, SCREEN_WIDTH - 10, SCREEN_HEIGHT - 10, 5, 5, black, 2);
	// Col 1
	al_draw_text(font, black, SCREEN_WIDTH - 255, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, "ATTACK");
	al_draw_text(font, black, SCREEN_WIDTH - 255, SCREEN_HEIGHT - 85, ALLEGRO_ALIGN_LEFT, "REPAIR");
	al_draw_text(font, black, SCREEN_WIDTH - 255, SCREEN_HEIGHT - 45, ALLEGRO_ALIGN_LEFT, "FLEE");

	// Col 2
	al_draw_text(font, black, SCREEN_WIDTH - 130, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, "EXIT GAME");
	al_draw_text(font, black, SCREEN_WIDTH - 130, SCREEN_HEIGHT - 85, ALLEGRO_ALIGN_LEFT, "BUTTS");

	

	al_flip_display();
}

bool BattleScreen::shipBattle() {
	// create an EnemyShip object
	EnemyShip *enemy = new EnemyShip();
	enemy->setInventory();
	// randomly create a name
	std::string enemyNames[] = {"Bojangles", "Hook", "Lil' John", "Davy Jones", "Cpt. Bewb Bosa" };
	srand(time(NULL));
	int name = rand()%5;
	// assign appropriate sprite
	this->enemyName = enemyNames[name].c_str();

	timer = al_create_timer(1.0/FPS);
	eventQueue = al_create_event_queue();
	al_install_keyboard();
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));

	// draw or don't draw
	bool attackMenu = false;
	bool done = false;
	bool drawn = false;
	bool enemyTurn = false;
	bool entered = false;
	bool redraw = true;
	bool repairMenu = false;
	bool userTurn = false;

	// Switch cases
	int attkIter = -1;
	int iter = -1;
	int num;
	int repaIter = -1;

	al_start_timer(timer);
	while(!done) {
		ALLEGRO_EVENT action;
		al_wait_for_event(eventQueue, &action);
		if(action.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if(action.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(action.keyboard.keycode) {
			case ALLEGRO_KEY_ENTER: // selection
				entered = !entered;
				userTurn = !userTurn;
				break;
			case ALLEGRO_KEY_END: // resets cursor
				iter = -1;
				attkIter = -1;
				repaIter = -1;
				attackMenu = false;
				repairMenu = false;
				drawn = false;
				break;
				// Arrow keys move cursor
			case ALLEGRO_KEY_UP:
				if (!attackMenu && !repairMenu) {
					entered = false;
					userTurn = false;
					iter--;
					if(iter < 0)
						iter = 0;
				}
				if (attackMenu) {
					entered = false;
					userTurn = false;
					attkIter--;
					if(attkIter < 0)
						attkIter = 0;
				}
				if (repairMenu) {
					entered = false;
					userTurn = false;
					repaIter--;
					if (repaIter < 0)
						repaIter = 0;
				}
				drawn = true;
				break;
			case ALLEGRO_KEY_DOWN:
				if (!attackMenu && !repairMenu) {
					entered = false;
					userTurn = false;
					iter++;
					if (iter > 5)
						iter = 5;
					if (iter == 5)
						iter = 0;
				}
				if (attackMenu) {
					entered = false;
					userTurn = false;
					attkIter++;
					if (attkIter > 4)
						attkIter = 4;
					if (attkIter == 4)
						attkIter = 0;
				}
				if (repairMenu) {
					entered = false;
					userTurn = false;
					repaIter++;
					if (repaIter > 6)
						repaIter = 6;
					if (repaIter == 6)
						repaIter = 0;
				}
				drawn = true;
				break;
			case ALLEGRO_KEY_LEFT:
				if (!attackMenu && !repairMenu) {
					entered = false;
					userTurn = false;
					if (iter == 0) {
						attkIter = 0;
						attackMenu = true;
					}
					else if (iter == 1) {
						repaIter = 0;
						repairMenu = true;
					}
					else if (iter == 3)
						iter = 0;
					else if (iter == 4)
						iter = 1;
				}
				if (attackMenu) {
					entered = false;
					userTurn = false;
					if (attkIter == 2)
						attkIter = 0;
					else if (attkIter == 3)
						attkIter = 1;
				}
				if (repairMenu) {
					entered = false;
					userTurn = false;
					if (repaIter == 3)
						repaIter = 0;
					else if (repaIter == 4)
						repaIter = 1;
					else if (repaIter == 5)
						repaIter = 2;
				}
				drawn = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				if (iter == -1)
					iter = 3;
				if (!attackMenu && !repairMenu) {
					entered = false;
					userTurn = false;
					if (iter == 0)
						iter = 3;
					if (iter == 1 || iter == 2)
						iter = 4;
				}
				if (attackMenu) {
					entered = false;
					userTurn = false;
					if (attkIter == 0)
						attkIter = 2;
					else if (attkIter == 1)
						attkIter = 3;
					else if (attkIter == 2 || attkIter == 3) {
						attackMenu = false;
						iter = 0;
						attkIter = -1;
					}
				}
				if (repairMenu) {
					entered = false;
					userTurn = false;
					if (repaIter == 0)
						repaIter = 3;
					else if (repaIter == 1)
						repaIter = 4;
					else if (repaIter == 2)
						repaIter = 5;
					else if (repaIter >= 3 || repaIter <= 5) {
						repairMenu = false;
						iter = 1;
						repaIter = -1;
					}
				}
				drawn = true;
				break;
			}
		}
		if (redraw && al_is_event_queue_empty(eventQueue)) {
			redraw = false;

			draw();

			if(entered) {
				al_draw_filled_rectangle(0, SCREEN_HEIGHT - 180, SCREEN_WIDTH, SCREEN_HEIGHT - 165, white);
				al_draw_text(font, red, 260, SCREEN_HEIGHT - 176, ALLEGRO_ALIGN_CENTER, "Tip: If ENTERED! Press ENTER again."); 
				al_draw_text(font, black, 5, SCREEN_HEIGHT - 176, ALLEGRO_ALIGN_LEFT, "ENTERED!");
			}
			else {
				al_draw_filled_rectangle(0, SCREEN_HEIGHT - 180, SCREEN_WIDTH, SCREEN_HEIGHT - 165, white);
				al_draw_text(font, black, 5, SCREEN_HEIGHT - 176, ALLEGRO_ALIGN_LEFT, "NOT ENTERED!");
			}

			update();

			// Battle Screen Controls
			if(iter == -1) {
				al_draw_text(font, black, 40, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, "HOW TO BATTLE: ARROW PAD to move cursor.");
				al_draw_text(font, black, 40, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, "ENTER to select, END to deselect/reset.");
				al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, "Press DOWN key to start.");
			}

			if(drawn) {
				int trix1, trix2, trix3, triy1, triy2, triy3;
				Item item1 = ship->getInventory()->getCannonballItem();
				Item item2 = ship->getInventory()->getScatterShotItem();
				Item item3 = ship->getInventory()->getChainShotItem();
				Item item4 = ship->getInventory()->getExplosiveCannonballItem();
				switch(iter) {
				case 0: // Attack Menu
					trix1 = SCREEN_WIDTH - 280;
					trix2 = trix1;
					trix3 = SCREEN_WIDTH - 260;
					triy1 = SCREEN_HEIGHT - 130;
					triy2 = triy1 + 20;
					triy3 = SCREEN_HEIGHT - 120;
					al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, item1.getItemName());
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, item2.getItemName());
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, item3.getItemName());
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, item4.getItemName());
					if(attackMenu) {
						switch(attkIter) {
						case 0:
							trix1 = 20;
							trix2 = trix1;
							trix3 = 40;
							triy1 = SCREEN_HEIGHT - 130;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 120;	
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							break;
						case 1:
							trix1 = 20;
							trix2 = trix1;
							trix3 = 40;
							triy1 = SCREEN_HEIGHT - 100;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 90;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							break;
						case 2:
							trix1 = 215;
							trix2 = trix1;
							trix3 = 235;
							triy1 = SCREEN_HEIGHT - 130;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 120;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							break;
						case 3:
							trix1 = 215;
							trix2 = trix1;
							trix3 = 235;
							triy1 = SCREEN_HEIGHT - 100;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 90;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							break;
						}
					}

					if(userTurn && userHP != 528) {
						switch(attkIter) {
						case 0: // CannonBalls
							if (entered) {
								enemyHP -= enemyHP*(ship->cannonball()/100);
								if(enemyHP < 62)
									enemyHP = 62;
								entered = false; // stops constant attack
							}
							al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, "Firing Cannonballs!");
							enemyTurn = true;
							break;
						case 1: // Scatter Shot
							if (entered) {
								enemyHP -= enemyHP*(ship->scatterShot()/100);
								if(enemyHP < 62)
									enemyHP = 62;
								entered = false; // stops constant attack
							}
							al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, "SCATTERSHOT, FIRE!!!");
							al_draw_text(font, black, 40, SCREEN_HEIGHT - 45, ALLEGRO_ALIGN_LEFT, "Bojangles: HOMG STAAAHHHHP EEEET!!");
							al_draw_text(font, black, 40, SCREEN_HEIGHT - 30, ALLEGRO_ALIGN_LEFT, "  YOU'RE BLOWING HOLES IN MY SHIP!");
							enemyTurn = true;
							break;
						case 2: // Chain Shot
							if (entered) {
								enemyHP -= enemyHP*(ship->chainShot()/100);
								if(enemyHP < 62)
									enemyHP = 62;
								entered = false; // stops constant attack
							}
							al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, "Firing chain balls!");
							al_draw_text(font, black, 40, SCREEN_HEIGHT - 45, ALLEGRO_ALIGN_LEFT, "They slowed down the enemy!");
							al_draw_text(font, black, 40, SCREEN_HEIGHT - 30, ALLEGRO_ALIGN_LEFT, "Bojangles: YOU SON OF A BUTT!");
							enemyTurn = true;
							break;
						case 3: // Explosive Cannonball
							if (entered) {
								enemyHP -= ship->explosiveCannonball();
								if(enemyHP < 62)
									enemyHP = 62;
								entered = false; // stops constant attack
							}
							al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, "BOOM goes the dynamite!");
							enemyTurn = true;
							break;
						}
						al_draw_bitmap(battleBG, 0, 0, 0);
						draw();
						update();
						al_rest(1);
						userTurn = false;
						enemyTurn = true;
						al_flip_display();
					}
					if(enemyTurn && enemyHP != 62) {
						Item item1 = enemy->getInventory()->getWood();
						Item item2 = enemy->getInventory()->getTools();
						Item item3 = enemy->getInventory()->getRope();
						srand(time(NULL));
						int n = rand()%6;
						switch(n) {
						case 0: // Cannonball
							userHP -= userHP*(enemy->cannonball()/100);
							break;
						case 1: // Chain Shot
							userHP -= userHP*(enemy->chainShot()/100);
							break;
						case 2: // Scatter Shot
							userHP -= userHP*(enemy->scatterShot()/100);
							break;
							// Healing
						case 3:
							enemy->useItem(item1);
							break;
						case 4:
							enemy->useItem(item2);
							break;
						case 5:
							enemy->useItem(item3);
							break;
						}
						update();
						al_rest(2);
						enemyTurn = false;
					}
					else {
						al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
						al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "ENEMY ATTACKED!");
						update();
					}
					break;
				case 1: // Repair Menu
					trix1 = SCREEN_WIDTH - 280;
					trix2 = trix1;
					trix3 = SCREEN_WIDTH - 260;
					triy1 = SCREEN_HEIGHT - 90;
					triy2 = triy1 + 20;
					triy3 = SCREEN_HEIGHT - 80;
					al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
					// Ship Repairs
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getWood().getItemName());
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getRope().getItemName());
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getTools().getItemName());
					// Crew repairs
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getFood().getItemName());
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getWater().getItemName());
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getBooze().getItemName());
					if(repairMenu) {
						Item item1 = ship->getInventory()->getWood();
						Item item2 = ship->getInventory()->getRope();
						Item item3 = ship->getInventory()->getTools();
						Item item4 = ship->getInventory()->getFood();
						Item item5 = ship->getInventory()->getWater();
						Item item6 = ship->getInventory()->getBooze();
						switch(repaIter) {
						case 0: // wood
							trix1 = 20;
							trix2 = trix1;
							trix3 = 40;
							triy1 = SCREEN_HEIGHT - 130;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 120;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							if(entered) {
								userHP += ship->getInventory()->useItem(item1);
								if(userHP > 754)
									userHP = 754;
								entered = false;
							}
							break;
						case 1: // rope
							trix1 = 20;
							trix2 = trix1;
							trix3 = 20;
							triy1 = SCREEN_HEIGHT - 100;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 90;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							if(entered) {
								userHP += ship->getInventory()->useItem(item2);
								if(userHP > 754)
									userHP = 754;
								entered = false;
							}
							break;
						case 2: // tools
							trix1 = 20;
							trix2 = trix1;
							trix3 = 40;
							triy1 = SCREEN_HEIGHT - 70;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 60;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							if(entered) {
								userHP += ship->getInventory()->useItem(item3);
								if(userHP > 754)
									userHP = 754;
								entered = false;
							}
							break;
						case 3: // food
							trix1 = 215;
							trix2 = trix1;
							trix3 = 235;
							triy1 = SCREEN_HEIGHT - 130;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 120;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							if(entered) {
								userHP += ship->getInventory()->useItem(item4);
								if(userHP > 754)
									userHP = 754;
								entered = false;
							}
							break;
						case 4: // water
							trix1 = 215;
							trix2 = trix1;
							trix3 = 235;
							triy1 = SCREEN_HEIGHT - 100;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 90;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							if(entered) {
								userHP += ship->getInventory()->useItem(item5);
								if(userHP > 754)
									userHP = 754;
								entered = false;
							}
							break;
						case 5: // booze
							trix1 = 215;
							trix2 = trix1;
							trix3 = 235;
							triy1 = SCREEN_HEIGHT - 70;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 60;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							if(entered) {

								userHP += ship->getInventory()->useItem(item6);
								if(userHP > 754)
									userHP = 754;
								entered = false;
							}
							break;
						}
					}
					break;
				case 2: // Flee
					trix1 = SCREEN_WIDTH - 280;
					trix2 = trix1;
					trix3 = SCREEN_WIDTH - 260;
					triy1 = SCREEN_HEIGHT - 50;
					triy2 = triy1 + 20;
					triy3 = SCREEN_HEIGHT - 40;
					al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
					srand(time(NULL));
					num = 1 + rand()%10;
					if(entered) {
						if(num <= 5) {
							// ends loop go back to map
							return true;
						}
						else {
							entered = false; // breaks out of this if
							enemyTurn = true;
							iter = 0;
						}
					}
					break;
				case 3: // Exits Game or you could have it go back to main menu
					trix1 = SCREEN_WIDTH - 280 + 125;
					trix2 = trix1;
					trix3 = SCREEN_WIDTH - 260 + 125;
					triy1 = SCREEN_HEIGHT - 130;
					triy2 = triy1 + 20;
					triy3 = SCREEN_HEIGHT - 120;
					al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
					if (entered)
						done = true;
					break;
				case 4: // How to play
					trix1 = SCREEN_WIDTH - 280 + 125;
					trix2 = trix1;
					trix3 = SCREEN_WIDTH - 260 + 125;
					triy1 = SCREEN_HEIGHT - 90;
					triy2 = triy1 + 20;
					triy3 = SCREEN_HEIGHT - 80;
					al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, "HOW TO BATTLE: ARROW PAD to move cursor.");
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, "ENTER to select, END to deselect/reset.");
					break;
				}	
				al_flip_display();
			}
		}
	}
	if(enemyHP == 62) {
		userTurn = false;
		enemyTurn = false;
		// go back to map
		return true;
	}
	if(userHP == 528) {
		userTurn = false;
		enemyTurn = false;
		// go to Game Over screen
		return false;
	}
	return true;
}

bool BattleScreen::bossBattle() {
	// create Boss object
	Boss Nessy = Boss();
	Nessy.setBossName("Nessy");

	// assign appropriate sprite have it idle

	timer = al_create_timer(1.0/FPS);

	ALLEGRO_EVENT_QUEUE *eventQueue = al_create_event_queue();
	al_install_keyboard();
	al_register_event_source(eventQueue, al_get_keyboard_event_source());

	// draw or don't draw
	bool attackMenu = false;
	bool done = false;
	bool drawn = false;
	bool enemyTurn = false;
	bool entered = false;
	bool redraw = true;
	bool repairMenu = false;
	bool userTurn = false;

	// Switch cases
	int attkIter = -1;
	int iter = -1;
	int repaIter = -1;

	al_start_timer(timer);

	while(!done) {
		ALLEGRO_EVENT action;
		al_wait_for_event(eventQueue, &action);
		if(action.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		if(action.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(action.keyboard.keycode) {
			case ALLEGRO_KEY_ENTER: // selection
				entered = !entered;
				userTurn = !userTurn;
				break;
			case ALLEGRO_KEY_END: // resets cursor
				iter = -1;
				attkIter = -1;
				repaIter = -1;
				attackMenu = false;
				repairMenu = false;
				drawn = false;
				break;
				// Arrow keys move cursor
			case ALLEGRO_KEY_UP:
				if (!attackMenu && !repairMenu) {
					entered = false;
					userTurn = false;
					iter--;
					if(iter < 0)
						iter = 0;
				}
				if (attackMenu) {
					entered = false;
					userTurn = false;
					attkIter--;
					if(attkIter < 0)
						attkIter = 0;
				}
				if (repairMenu) {
					entered = false;
					userTurn = false;
					repaIter--;
					if (repaIter < 0)
						repaIter = 0;
				}
				drawn = true;
				break;
			case ALLEGRO_KEY_DOWN:
				if (!attackMenu && !repairMenu) {
					entered = false;
					userTurn = false;
					iter++;
					if (iter > 5)
						iter = 5;
					if (iter == 5)
						iter = 0;
				}
				if (attackMenu) {
					entered = false;
					userTurn = false;
					attkIter++;
					if (attkIter > 4)
						attkIter = 4;
					if(attkIter == 4)
						attkIter = 0;
				}
				if (repairMenu) {
					entered = false;
					userTurn = false;
					repaIter++;
					if (repaIter > 6)
						repaIter = 6;
					if(repaIter == 6)
						repaIter = 0;
				}
				drawn = true;
				break;
			case ALLEGRO_KEY_LEFT:
				if (!attackMenu && !repairMenu) {
					entered = false;
					userTurn = false;
					if (iter == 0) {
						attkIter = 0;
						attackMenu = true;
					}
					else if (iter == 1) {
						repaIter = 0;
						repairMenu = true;
					}
					else if (iter == 3)
						iter = 0;
					else if (iter == 4)
						iter = 1;
				}
				if (attackMenu) {
					entered = false;
					userTurn = false;
					if (attkIter == 2)
						attkIter = 0;
					else if (attkIter == 3)
						attkIter = 1;
				}
				if (repairMenu) {
					entered = false;
					userTurn = false;
					if (repaIter == 3)
						repaIter = 0;
					else if (repaIter == 4)
						repaIter = 1;
					else if (repaIter == 5)
						repaIter = 2;
				}
				drawn = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				if(iter == -1)
					iter = 3;
				if (!attackMenu && !repairMenu) {
					entered = false;
					userTurn = false;
					if (iter == 0)
						iter = 3;
					if (iter == 1 || iter == 2)
						iter = 4;
				}
				if (attackMenu) {
					entered = false;
					userTurn = false;
					if (attkIter == 0)
						attkIter = 2;
					else if (attkIter == 1)
						attkIter = 3;
					else if (attkIter == 2 || attkIter == 3) {
						attackMenu = false;
						iter = 0;
						attkIter = -1;
					}
				}
				if (repairMenu) {
					entered = false;
					userTurn = false;
					if (repaIter == 0)
						repaIter = 3;
					else if (repaIter == 1)
						repaIter = 4;
					else if (repaIter == 2)
						repaIter = 5;
					else if (repaIter >= 3 || repaIter <= 5) {
						repairMenu = false;
						iter = 1;
						repaIter = -1;
					}
				}
				drawn = true;
				break;
			}
		}
		if(redraw && al_is_event_queue_empty(eventQueue)) {
			redraw = false;
			al_draw_bitmap(battleBG, 0, 0, 0);
			draw();

			// notifies if it has been selected
			if(entered) {
				al_draw_filled_rectangle(0, SCREEN_HEIGHT - 159, SCREEN_WIDTH, SCREEN_HEIGHT - 173, white);
				al_draw_text(font, red, SCREEN_WIDTH/2, SCREEN_HEIGHT - 170, ALLEGRO_ALIGN_CENTER, "Tip: If ENTERED! Press ENTER again."); 
				al_draw_text(font, black, 5, SCREEN_HEIGHT - 170, ALLEGRO_ALIGN_LEFT, "ENTERED!");
			}
			else {
				al_draw_filled_rectangle(0, SCREEN_HEIGHT - 159, SCREEN_WIDTH, SCREEN_HEIGHT - 173, white);
				al_draw_text(font, black, 5, SCREEN_HEIGHT - 170, ALLEGRO_ALIGN_LEFT, "NOT ENTERED!");
			}

			update();

			// Battle Screen Controls
			if(iter == -1) {
				al_draw_text(font, black, 40, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, "HOW TO BATTLE: ARROW PAD to move cursor.");
				al_draw_text(font, black, 40, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, "ENTER to select, END to deselect/reset.");
				al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, "Press DOWN key to start.");
			}

			if(drawn) {
				int trix1, trix2, trix3, triy1, triy2, triy3;
				switch(iter) {
				case 0: // Attack Menu
					trix1 = SCREEN_WIDTH - 280;
					trix2 = trix1;
					trix3 = SCREEN_WIDTH - 260;
					triy1 = SCREEN_HEIGHT - 130;
					triy2 = triy1 + 20;
					triy3 = SCREEN_HEIGHT - 120;
					al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
					// options: conditional statements to change text display but it would be easier if it was a const char *
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getCannonballItem().getItemName());
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getScatterShotItem().getItemName());
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getChainShotItem().getItemName());
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getExplosiveCannonballItem().getItemName());
					if(attackMenu) {
						switch(attkIter) {
						case 0:
							trix1 = 20;
							trix2 = trix1;
							trix3 = 40;
							triy1 = SCREEN_HEIGHT - 130;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 120;	
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							break;
						case 1:
							trix1 = 20;
							trix2 = trix1;
							trix3 = 40;
							triy1 = SCREEN_HEIGHT - 100;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 90;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							break;
						case 2:
							trix1 = 215;
							trix2 = trix1;
							trix3 = 235;
							triy1 = SCREEN_HEIGHT - 130;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 120;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							break;
						case 3:
							trix1 = 215;
							trix2 = trix1;
							trix3 = 235;
							triy1 = SCREEN_HEIGHT - 100;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 90;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							break;
						}
					}

					if(userTurn && userHP != 528) {
						switch(attkIter) {
						case 0: // CannonBalls
							if (entered) {
								enemyHP -= ship->cannonball();
								if(enemyHP < 62)
									enemyHP = 62;
								entered = false; // stops constant attack
							}
							al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, "Firing Cannonballs!");
							break;
						case 1: // Scatter Shot
							if (entered) {
								enemyHP -= ship->scatterShot();
								if(enemyHP < 62)
									enemyHP = 62;
								entered = false; // stops constant attack
							}
							al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, "SCATTERSHOT, FIRE!!!");
							break;
						case 2: // Chain Shot
							if (entered) {
								enemyHP -= ship->chainShot();
								if(enemyHP < 62)
									enemyHP = 62;
								entered = false; // stops constant attack
							}
							al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, "Firing chain balls!");
							break;
						case 3: // Explosive Cannonball
							if (entered) {
								enemyHP -= ship->explosiveCannonball();
								if(enemyHP < 62)
									enemyHP = 62;
								entered = false; // stops constant attack
							}
							al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, "BOOM goes the dynamite!");
							break;
						}
						update();
						al_rest(1);
						userTurn = false;
						enemyTurn = true;
					}
					// Allows Enemy to Attack
					if (enemyTurn && enemyHP != 62) {
						srand(time(NULL));
						int n = rand()%6;
						switch(n) {
						case 0:
							userHP -= userHP*(Nessy.bite()/100);
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "BOSS USED BITE!");
							break;
						case 1:
							userHP -= userHP*(Nessy.slime()/100);
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "BOSS USED SLIME!");
							break;
						case 2:
							userHP -= userHP*(Nessy.fireBlast()/100);
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "BOSS USED FIREBLAST!");
							break;
						case 3:
							userHP -= userHP*(Nessy.waterBlast()/100);
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "BOSS USED WATERBLAST!");
							break;
						case 4:
							Nessy.defend(ship->getAttack());
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "BOSS USED DEFEND!");
							break;
						case 5:
							Nessy.tidalWave();
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "BOSS USED TIDALWAVE!");
							break;
						}
						al_draw_bitmap(battleBG, 0, 0, 0);
						draw();
						update();
						al_rest(2);
						enemyTurn = false;
					}
					else {
						al_draw_bitmap(battleBG, 0, 0, 0);
						draw();
						al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
						al_draw_text(font, black, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "USER TURN! Select an attack.");
						update();
					}
					break;
				case 1: // Repair Menu
					trix1 = SCREEN_WIDTH - 280;
					trix2 = trix1;
					trix3 = SCREEN_WIDTH - 260;
					triy1 = SCREEN_HEIGHT - 90;
					triy2 = triy1 + 20;
					triy3 = SCREEN_HEIGHT - 80;
					al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
					// Ship Repairs
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getWood().getItemName());
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getRope().getItemName());
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getTools().getItemName());
					// Crew repairs
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getFood().getItemName());
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getWater().getItemName());
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getBooze().getItemName());
					if(repairMenu) {
						Item item1 = ship->getInventory()->getWood();
						Item item2 = ship->getInventory()->getRope();
						Item item3 = ship->getInventory()->getTools();
						Item item4 = ship->getInventory()->getFood();
						Item item5 = ship->getInventory()->getWater();
						Item item6 = ship->getInventory()->getBooze();
						switch(repaIter) {
						case 0: // wood
							trix1 = 20;
							trix2 = trix1;
							trix3 = 40;
							triy1 = SCREEN_HEIGHT - 130;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 120;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							if (entered) {
								userHP += ship->getInventory()->useItem(item1);
								if (userHP > 754)
									userHP = 754;
								entered = false;
							}
							break;
						case 1: // rope
							trix1 = 20;
							trix2 = trix1;
							trix3 = 20;
							triy1 = SCREEN_HEIGHT - 100;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 90;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							if (entered) {
								userHP += ship->getInventory()->useItem(item2);
								if (userHP > 754)
									userHP = 754;
								entered = false;
							}
							break;
						case 2: // tools
							trix1 = 20;
							trix2 = trix1;
							trix3 = 40;
							triy1 = SCREEN_HEIGHT - 70;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 60;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							if (entered) {
								userHP += ship->getInventory()->useItem(item3);
								if (userHP > 754)
									userHP = 754;
								entered = false;
							}
							break;
						case 3: // food
							trix1 = 215;
							trix2 = trix1;
							trix3 = 235;
							triy1 = SCREEN_HEIGHT - 130;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 120;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							if (entered) {
								userHP += ship->getInventory()->useItem(item4);
								if (userHP > 754)
									userHP = 754;
								entered = false;
							}
							break;
						case 4: // water
							trix1 = 215;
							trix2 = trix1;
							trix3 = 235;
							triy1 = SCREEN_HEIGHT - 100;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 90;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							if (entered) {
								userHP += ship->getInventory()->useItem(item5);
								if (userHP > 754)
									userHP = 754;
								entered = false;
							}
							break;
						case 5: // booze
							trix1 = 215;
							trix2 = trix1;
							trix3 = 235;
							triy1 = SCREEN_HEIGHT - 70;
							triy2 = triy1 + 20;
							triy3 = SCREEN_HEIGHT - 60;
							al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
							if (entered) {
								userHP += ship->getInventory()->useItem(item6);
								if (userHP > 754)
									userHP = 754;
								entered = false;
							}
							break;
						}
					}
					break;
				case 2: // Flee
					trix1 = SCREEN_WIDTH - 280;
					trix2 = trix1;
					trix3 = SCREEN_WIDTH - 260;
					triy1 = SCREEN_HEIGHT - 50;
					triy2 = triy1 + 20;
					triy3 = SCREEN_HEIGHT - 40;
					al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
					int num;
					srand(time(NULL));
					num = 1 + rand()%10;
					if(entered) {
						if(num <= 5) {
							// ends loop go back to map
							return true;
						}
						else {
							entered = false; // breaks out of this if
							enemyTurn = true;
							iter = 0;
						}
					}
					break;
				case 3: // Exits back to main menu
					trix1 = SCREEN_WIDTH - 280 + 125;
					trix2 = trix1;
					trix3 = SCREEN_WIDTH - 260 + 125;
					triy1 = SCREEN_HEIGHT - 130;
					triy2 = triy1 + 20;
					triy3 = SCREEN_HEIGHT - 120;
					al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
					if (entered)
						done = true;
					break;
				case 4:
					trix1 = SCREEN_WIDTH - 280 + 125;
					trix2 = trix1;
					trix3 = SCREEN_WIDTH - 260 + 125;
					triy1 = SCREEN_HEIGHT - 90;
					triy2 = triy1 + 20;
					triy3 = SCREEN_HEIGHT - 80;
					al_draw_filled_triangle(trix1, triy1, trix2, triy2, trix3, triy3, black);
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, "HOW TO BATTLE: ARROW PAD to move cursor.");
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, "ENTER to select, END to deselect/reset.");
					break;
				}
				al_flip_display();
			}
		}
	}
	if(enemyHP == 62) {
		userTurn = false;
		enemyTurn = false;
		// go back to map
		return true;
	}
	if(userHP == 528) {
		userTurn = false;
		enemyTurn = false;
		// go to Game Over screen
		return false;
	}
	return true;
}


void BattleScreen::update() {
	// Enemy HP box
	al_draw_filled_rounded_rectangle(20, 20, 300, 75, 5, 3, white);
	al_draw_rounded_rectangle(20, 20, 300, 75, 5, 3, black, 3);
	// can assign a name and convert to const char *
	al_draw_text(font, black, 35, 35, ALLEGRO_ALIGN_LEFT, enemyName);

	// Enemy HP Bar
	al_draw_filled_rectangle(35, 50, 280, 60, black);
	al_draw_filled_rectangle(35, 50, enemyHP, 60, lime);
	al_draw_filled_rectangle(35, 50, 62, 60, black);
	al_draw_rounded_rectangle(35, 50, 265, 60, 2, 2, black, 2);
	al_draw_text(font, white, 40, 51, ALLEGRO_ALIGN_LEFT, "HP");

	// Main Character HP Box
	al_draw_filled_rounded_rectangle(SCREEN_WIDTH - 300, SCREEN_HEIGHT - 225, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 170, 5, 3, white);
	al_draw_rounded_rectangle(SCREEN_WIDTH - 300, SCREEN_HEIGHT - 225, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 170, 5, 3, black, 3);
	// can assign a name and convert to const char *
	al_draw_text(font, black, SCREEN_WIDTH - 285, SCREEN_HEIGHT - 210, ALLEGRO_ALIGN_LEFT, userName);
	// Main Character HP Bar
	al_draw_filled_rectangle(SCREEN_WIDTH - 285, SCREEN_HEIGHT - 195, SCREEN_WIDTH - 35, SCREEN_HEIGHT - 185, black);
	al_draw_filled_rectangle(SCREEN_WIDTH - 285, SCREEN_HEIGHT - 195, userHP, SCREEN_HEIGHT - 185, lime);
	al_draw_filled_rectangle(SCREEN_WIDTH - 285, SCREEN_HEIGHT - 195, SCREEN_WIDTH - 257, SCREEN_HEIGHT - 185, black);
	al_draw_rounded_rectangle(SCREEN_WIDTH - 285, SCREEN_HEIGHT - 195, SCREEN_WIDTH - 35, SCREEN_HEIGHT - 185, 2, 2, black, 2);
	al_draw_text(font, white, SCREEN_WIDTH - 280, SCREEN_HEIGHT - 194, ALLEGRO_ALIGN_LEFT, "HP");
}
/* End of battle.cpp */
