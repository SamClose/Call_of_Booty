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
	//enemyName = "";
	enemyHP = 280;
	userHP = 754;
	this->ship->setHealth(userHP + ship->getHealth());
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
	if(!font) {
		std::cerr << "Failed to load font PressStart2P" << std::endl;
	}

	// image
	battleBG = al_load_bitmap("mermaid-2-blue-water.jpg");
	if(!battleBG)
		std::cerr << "Failed to load image. Use full path instead." << std::endl;

	player = al_load_bitmap("shipProfile.png");
	pirate = al_load_bitmap("enemyProfile.png");
	serpent = al_load_bitmap("nessy.png");

	// draw or don't draw
	attackMenu = false;
	done = false;
	drawn = false;
	enemyTurn = false;
	entered = false;
	redraw = true;
	repairMenu = false;
	userTurn = false;

	// Switch cases
	attkIter = -1;
	iter = -1;
	repaIter = -1;
}

BattleScreen::~BattleScreen() {
	al_destroy_event_queue(eventQueue);
	al_destroy_timer(timer);
}

int BattleScreen::shipBattle() {
	// create an EnemyShip object
	EnemyShip *enemy = new EnemyShip();
	enemy->setInventory();
	enemy->setHealth(enemyHP + enemy->getHealth());
	// randomly create a name
	std::string enemyNames[] = {"Bojangles", "Hook", "Lil' John", "Davy Jones", "Cpt. Bewb Bosa", "BlackBeard", "WhiteBeard", "RedBeard", "Cpt. Jack Swallows" };
	srand(time(NULL));
	int name = rand()%9;
	// assign appropriate sprite
	this->enemyName = enemyNames[name].c_str();

	timer = al_create_timer(1.0/FPS);
	eventQueue = al_create_event_queue();
	al_install_keyboard();
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));

	int num;

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
				if(iter == 0 && attkIter == -1)
					userTurn = false;
				if(iter == 1 && repaIter == -1)
					entered = false;
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
					attkIter = -1;
					repaIter = -1;
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
					attkIter = -1;
					repaIter = -1;
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
					attkIter = -1;
					repaIter = -1;
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
					attkIter = -1;
					repaIter = -1;
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

			// Checks Health Bars
			if(enemyHP == 62) {
				userTurn = false;
				enemyTurn = false;
				// go back to map
				return 1;
			}
			else if (enemyHP > 280)
				enemyHP = 280;

			if(userHP == 528) {
				userTurn = false;
				enemyTurn = false;
				// go to Game Over screen
				return -1;
			}
			else if (userHP > 754)
				userHP = 754;

			// Background Image
			al_draw_bitmap(battleBG, 0, 0, 0);

			// enemyShip
			al_draw_bitmap(pirate, SCREEN_WIDTH - 350, 30, 0);

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

			// Battle Controls
			if(iter == -1) {
				al_draw_text(font, black, 40, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, "HOW TO BATTLE: ARROW PAD to move cursor.");
				al_draw_text(font, black, 40, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, "ENTER to select, END to deselect/reset.");
				al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, "Press DOWN key to start.");
				al_flip_display();
			}

			update();

			if(drawn) {
				Item item1 = ship->getInventory()->getCannonballItem();
				Item item2 = ship->getInventory()->getScatterShotItem();
				Item item3 = ship->getInventory()->getChainShotItem();
				Item item4 = ship->getInventory()->getExplosiveCannonballItem();
				switch(iter) {
				case 0: // Attack Menu
					al_draw_filled_triangle(SCREEN_WIDTH - 280, SCREEN_HEIGHT - 130,
						SCREEN_WIDTH - 280, SCREEN_HEIGHT - 110, 
						SCREEN_WIDTH - 260, SCREEN_HEIGHT - 120, black);
					al_draw_text(font, black, 45, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, item1.getItemName());
					al_draw_text(font, black, 45, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, item2.getItemName());
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, item3.getItemName());
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, item4.getItemName());
					if(attackMenu) {
						switch(attkIter) {
						case 0:	
							al_draw_filled_triangle(20, SCREEN_HEIGHT - 130,
								20, SCREEN_HEIGHT - 110,
								40, SCREEN_HEIGHT - 120, black);
							break;
						case 1:
							al_draw_filled_triangle(20, SCREEN_HEIGHT - 100,
								20, SCREEN_HEIGHT - 80,
								40, SCREEN_HEIGHT - 90, black);
							break;
						case 2:
							al_draw_filled_triangle(215, SCREEN_HEIGHT - 130,
								215, SCREEN_HEIGHT - 110,
								235, SCREEN_HEIGHT - 120, black);
							break;
						case 3:
							al_draw_filled_triangle(215, SCREEN_HEIGHT - 100,
								215, SCREEN_HEIGHT - 80,
								235, SCREEN_HEIGHT - 90, black);
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
							std::cout << std::endl << "User Cannonball " << ship->cannonball() << std::endl;
							enemyTurn = true;
							break;
						case 1: // Scatter Shot
							if (entered) {
								enemyHP -= ship->scatterShot();
								if(enemyHP < 62)
									enemyHP = 62;	
								entered = false; // stops constant attack
							}
							std::cout << std::endl << "User Scatter Shot " << ship->scatterShot() << std::endl;
							enemyTurn = true;
							break;
						case 2: // Chain Shot
							if (entered) {
								enemyHP -= ship->chainShot();
								if(enemyHP < 62)
									enemyHP = 62;
								entered = false; // stops constant attack
							}
							std::cout << std::endl << "User ChainShot " << ship->chainShot() << std::endl;
							enemyTurn = true;
							break;
						case 3: // Explosive Cannonball
							if (entered) {
								enemyHP -= ship->explosiveCannonball();
								if(enemyHP < 62)
									enemyHP = 62;
								entered = false; // stops constant attack
							}
							std::cout << std::endl << "User Explosive Cannonball " << ship->explosiveCannonball() << std::endl;
							enemyTurn = true;
							break;
						}
						update();
						al_flip_display();
						al_rest(.5);
						userTurn = false;
						enemyTurn = true;
					}
					if(enemyTurn && enemyHP != 62) {
						Item item1 = enemy->getInventory()->getWood();
						Item item2 = enemy->getInventory()->getTools();
						Item item3 = enemy->getInventory()->getRope();
						srand(time(NULL));
						int n = rand()%3;
						switch(n) {
						case 0: // Cannonball
							userHP -= enemy->cannonball();
							std::cout << std::endl << "Enemy Cannonball " << enemy->cannonball() << std::endl;
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, black, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "Enemy is firing cannonballs!");
							break;
						case 1: // Chain Shot
							userHP -= enemy->chainShot();
							std::cout << std::endl << "Enemy Chain Shot " << enemy->chainShot() << std::endl;
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, black, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "Enemy's chain shot didn't do much.");
							break;
						case 2: // Scatter Shot
							userHP -= enemy->scatterShot();
							std::cout << std::endl << "Enemy Scatter Shot " << enemy->scatterShot() << std::endl;
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, black, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "Scatter shot caused some holes in your ship.");
							break;
							// Healing
						case 3:
							enemyHP += enemy->useItem(item1);
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, black, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "Enemy repaired ship!");
							std::cout << "Enemy Healed " << enemyHP << std::endl;
							break;
						case 4:
							enemyHP += enemy->useItem(item2);
							std::cout << std::endl << "Enemy Healed " << enemyHP << std::endl;
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, black, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "Enemy repaired ship!");
							break;
						case 5:
							enemyHP += enemy->useItem(item3);
							std::cout << std::endl << "Enemy Healed " << enemyHP << std::endl;
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, black, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "Enemy repaired ship!");
							break;
						}
						if(enemyHP > 280)
							enemyHP = 280;
						ship->setHealth(userHP);
						std::cout << std::endl << "Enemy HP: " << enemyHP << "/280" << std::endl;
						std::cout << "User HP: " << userHP << "/754" << std::endl;
						update();
						al_flip_display();
						al_rest(1);
						enemyTurn = false;
					}
					else if(!userTurn && !enemyTurn) {
						al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
						al_draw_text(font, black, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "USER TURN! Select an attack.");
						update();
					}
					break;
				case 1: // Repair Menu
					al_draw_filled_triangle(SCREEN_WIDTH - 280, SCREEN_HEIGHT - 90,
						SCREEN_WIDTH - 280, SCREEN_HEIGHT - 70, 
						SCREEN_WIDTH - 260, SCREEN_HEIGHT - 80, black);
					// Ship Repairs
					al_draw_text(font, black, 45, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getWood().getItemName());
					al_draw_text(font, black, 45, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getRope().getItemName());
					al_draw_text(font, black, 45, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getTools().getItemName());
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
							al_draw_filled_triangle(20, SCREEN_HEIGHT - 130,
								20, SCREEN_HEIGHT - 110,
								40, SCREEN_HEIGHT - 120, black);
							if(entered) {
								userHP += ship->useItem(item1);
								if(userHP > 754)
									userHP = 754;
								entered = false;
								userTurn = false;
								enemyTurn = true;
								iter = 0;
							}
							break;
						case 1: // rope
							al_draw_filled_triangle(20, SCREEN_HEIGHT - 100,
								20, SCREEN_HEIGHT - 80,
								40, SCREEN_HEIGHT - 90, black);
							if(entered) {
								userHP += ship->useItem(item2);
								if(userHP > 754)
									userHP = 754;
								entered = false;
								enemyTurn = true;
								iter = 0;
								attkIter = 0;
							}
							break;
						case 2: // tools
							al_draw_filled_triangle(20, SCREEN_HEIGHT - 70,
								20, SCREEN_HEIGHT - 50,
								40, SCREEN_HEIGHT - 60, black);
							if(entered) {
								userHP += ship->useItem(item3);
								if(userHP > 754)
									userHP = 754;
								entered = false;
								enemyTurn = true;
								iter = 0;
								attkIter = 0;
							}
							break;
						case 3: // food
							al_draw_filled_triangle(215, SCREEN_HEIGHT - 130,
								215, SCREEN_HEIGHT - 110,
								235, SCREEN_HEIGHT - 120, black);
							if(entered) {
								userHP += ship->useItem(item4);
								if(userHP > 754)
									userHP = 754;
								entered = false;
								enemyTurn = true;
								iter = 0;
								attkIter = 0;
							}
							break;
						case 4: // water
							al_draw_filled_triangle(215, SCREEN_HEIGHT - 100,
								215, SCREEN_HEIGHT - 80,
								235, SCREEN_HEIGHT - 90, black);
							if(entered) {
								userHP += ship->useItem(item5);
								if(userHP > 754)
									userHP = 754;
								entered = false;
								enemyTurn = true;
								iter = 0;
								attkIter = 0;
							}
							break;
						case 5: // booze
							al_draw_filled_triangle(215, SCREEN_HEIGHT - 70,
								215, SCREEN_HEIGHT - 50,
								235, SCREEN_HEIGHT - 60, black);
							if(entered) {
								userHP += ship->useItem(item6);
								if(userHP > 754)
									userHP = 754;
								entered = false;
								enemyTurn = true;
								iter = 0;
								attkIter = 0;
							}
							break;
						}
					}
					break;
				case 2: // Flee
					al_draw_filled_triangle(SCREEN_WIDTH - 280, SCREEN_HEIGHT - 50,
						SCREEN_WIDTH - 280, SCREEN_HEIGHT - 30, 
						SCREEN_WIDTH - 260, SCREEN_HEIGHT - 40, black);
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
					al_draw_filled_triangle(SCREEN_WIDTH - 155, SCREEN_HEIGHT - 130,
						SCREEN_WIDTH - 155, SCREEN_HEIGHT - 110, 
						SCREEN_WIDTH - 135, SCREEN_HEIGHT - 120, black);
					if (entered)
						return 0;
					break;
				case 4: // How to play
					al_draw_filled_triangle(SCREEN_WIDTH - 155, SCREEN_HEIGHT - 90,
						SCREEN_WIDTH - 155, SCREEN_HEIGHT - 70, 
						SCREEN_WIDTH - 135, SCREEN_HEIGHT - 80, black);
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, "HOW TO BATTLE: WASD keys to move cursor.");
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, "ENTER to select, END to deselect/reset.");
					break;
				}	
				al_flip_display();
			}
		}
	}
	return 1;
}

int BattleScreen::bossBattle() {
	// create Boss object
	Boss Nessy = Boss();
	Nessy.setBossName("Nessy");
	this->enemyName = Nessy.getBossName();
	enemyHP = Nessy.getHealth();

	timer = al_create_timer(1.0/FPS);
	ALLEGRO_EVENT_QUEUE *eventQueue = al_create_event_queue();
	al_install_keyboard();
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));

	int num;
	
	// Idle boss sprite animation
	int currentIdleFrame = 0;
	int idleFrameCount = 0;
	int idleFrameDelay = 5;

	al_start_timer(timer);
	while(!done) {
		ALLEGRO_EVENT action;
		al_wait_for_event(eventQueue, &action);
		if(action.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			if(++idleFrameCount >= idleFrameDelay) {
				if(++currentIdleFrame >= 6)
					currentIdleFrame = 0;
				idleFrameCount = 0;
			}
		}
		if(action.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(action.keyboard.keycode) {
			case ALLEGRO_KEY_ENTER: // selection
				entered = !entered;
				userTurn = !userTurn;
				if(iter == 0 && attkIter == -1)
					userTurn = false;
				if(iter == 1 && repaIter == -1)
					entered = false;
				break;
			case ALLEGRO_KEY_END: // resets cursor
				iter = -1;
				attkIter = -1;
				repaIter = -1;
				attackMenu = false;
				repairMenu = false;
				drawn = false;
				break;
				// WASD keys move cursor
			case ALLEGRO_KEY_UP:
				if (!attackMenu && !repairMenu) {
					entered = false;
					userTurn = false;
					attkIter = -1;
					repaIter = -1;
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
					attkIter = -1;
					repaIter = -1;
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
					attkIter = -1;
					repaIter = -1;
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
					attkIter = -1;
					repaIter = -1;
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

			// Checks Health Bars
			if(enemyHP == 62) {
				userTurn = false;
				enemyTurn = false;
				// go back to map
				return 1;
			}
			else if (enemyHP > 280)
				enemyHP = 280;

			if(userHP == 528) {
				userTurn = false;
				enemyTurn = false;
				// go to Game Over screen
				return -1;
			}
			else if (userHP > 754)
				userHP = 754;

			// Background Image
			al_draw_bitmap(battleBG, 0, 0, 0);

			// Nessy's beautiful mug
			al_draw_bitmap_region(serpent, currentIdleFrame*240, 0, 240, 200, SCREEN_WIDTH - 350, 30, NULL);

			draw();

			// notifies if it has been selected
			if(entered) {
				al_draw_filled_rectangle(0, SCREEN_HEIGHT - 180, SCREEN_WIDTH, SCREEN_HEIGHT - 165, white);
				al_draw_text(font, red, 260, SCREEN_HEIGHT - 176, ALLEGRO_ALIGN_CENTER, "Tip: If ENTERED! Press ENTER again."); 
				al_draw_text(font, black, 5, SCREEN_HEIGHT - 176, ALLEGRO_ALIGN_LEFT, "ENTERED!");
			}
			else {
				al_draw_filled_rectangle(0, SCREEN_HEIGHT - 180, SCREEN_WIDTH, SCREEN_HEIGHT - 165, white);
				al_draw_text(font, black, 5, SCREEN_HEIGHT - 176, ALLEGRO_ALIGN_LEFT, "NOT ENTERED!");
			}

			// Battle Screen Controls
			if(iter == -1) {
				al_draw_text(font, black, 40, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, "HOW TO BATTLE: ARROW PAD to move cursor.");
				al_draw_text(font, black, 40, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, "ENTER to select, END to deselect/reset.");
				al_draw_text(font, black, 40, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, "Press DOWN key to start.");
				al_flip_display();
			}

			if(drawn) {
				switch(iter) {
				case 0: // Attack Menu
					al_draw_filled_triangle(SCREEN_WIDTH - 280, SCREEN_HEIGHT - 130,
						SCREEN_WIDTH - 280, SCREEN_HEIGHT - 110, 
						SCREEN_WIDTH - 260, SCREEN_HEIGHT - 120, black);
					al_draw_text(font, black, 45, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getCannonballItem().getItemName());
					al_draw_text(font, black, 45, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getScatterShotItem().getItemName());
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getChainShotItem().getItemName());
					al_draw_text(font, black, 240, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getExplosiveCannonballItem().getItemName());
					if(attackMenu) {
						switch(attkIter) {
						case 0:	
							al_draw_filled_triangle(20, SCREEN_HEIGHT - 130,
								20, SCREEN_HEIGHT - 110,
								40, SCREEN_HEIGHT - 120, black);
							break;
						case 1:
							al_draw_filled_triangle(20, SCREEN_HEIGHT - 100,
								20, SCREEN_HEIGHT - 80,
								40, SCREEN_HEIGHT - 90, black);
							break;
						case 2:
							al_draw_filled_triangle(215, SCREEN_HEIGHT - 130,
								215, SCREEN_HEIGHT - 110,
								235, SCREEN_HEIGHT - 120, black);
							break;
						case 3:
							al_draw_filled_triangle(215, SCREEN_HEIGHT - 100,
								215, SCREEN_HEIGHT - 80,
								235, SCREEN_HEIGHT - 90, black);
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
							std::cout << std::endl << "User Cannonball " << ship->cannonball() << std::endl;
							enemyTurn = true;
							break;
						case 1: // Scatter Shot
							if (entered) {
								enemyHP -= ship->scatterShot();
								if(enemyHP < 62)
									enemyHP = 62;	
								entered = false; // stops constant attack
							}
							std::cout << std::endl << "User Scatter Shot " << ship->scatterShot() << std::endl;
							enemyTurn = true;
							break;
						case 2: // Chain Shot
							if (entered) {
								enemyHP -= ship->chainShot();
								if(enemyHP < 62)
									enemyHP = 62;
								entered = false; // stops constant attack
							}
							std::cout << std::endl << "User ChainShot " << ship->chainShot() << std::endl;
							enemyTurn = true;
							break;
						case 3: // Explosive Cannonball
							if (entered) {
								enemyHP -= ship->explosiveCannonball();
								if(enemyHP < 62)
									enemyHP = 62;
								entered = false; // stops constant attack
							}
							std::cout << std::endl << "User Explosive Cannonball " << ship->explosiveCannonball() << std::endl;
							enemyTurn = true;
							break;
						}
						update();
						al_rest(0.5);
						userTurn = false;
						enemyTurn = true;
					}
					// Allows Enemy to Attack
					if (enemyTurn && enemyHP != 62) {
						srand(time(NULL));
						int n = rand()%6;
						switch(n) {
						case 0:
							userHP -= Nessy.bite();
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "BOSS USED BITE!");
							break;
						case 1:
							userHP -= Nessy.slime();
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "BOSS USED SLIME!");
							break;
						case 2:
							userHP -= Nessy.fireBlast();
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "BOSS USED FIREBLAST!");
							break;
						case 3:
							userHP -= Nessy.waterBlast();
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "BOSS USED WATERBLAST!");
							break;
						case 4:
							enemyHP += Nessy.defend(ship->getAttack());
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "BOSS USED DEFEND!");
							break;
						case 5:
							enemyHP += Nessy.tidalWave();
							al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
							al_draw_text(font, red, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "BOSS USED TIDALWAVE!");
							break;
						}
						if(enemyHP > 280)
							enemyHP = 280;
						ship->setHealth(userHP);
						std::cout << std::endl << "Enemy HP: " << enemyHP << "/280" << std::endl;
						std::cout << "User HP: " << userHP << "/754" << std::endl;
						update();
						al_flip_display();
						al_rest(1);
						enemyTurn = false;
					}
					else {
						al_draw_filled_rectangle(0, SCREEN_HEIGHT - 200, SCREEN_WIDTH, SCREEN_HEIGHT - 185, white);
						al_draw_text(font, black, 5, SCREEN_HEIGHT - 196, ALLEGRO_ALIGN_LEFT, "USER TURN! Select an attack.");
						update();
					}
					break;
				case 1: // Repair Menu
					al_draw_filled_triangle(SCREEN_WIDTH - 280, SCREEN_HEIGHT - 90,
						SCREEN_WIDTH - 280, SCREEN_HEIGHT - 70, 
						SCREEN_WIDTH - 260, SCREEN_HEIGHT - 80, black);
					// Ship Repairs
					al_draw_text(font, black, 45, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getWood().getItemName());
					al_draw_text(font, black, 45, SCREEN_HEIGHT - 65, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getRope().getItemName());
					al_draw_text(font, black, 45, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, ship->getInventory()->getTools().getItemName());
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
							al_draw_filled_triangle(20, SCREEN_HEIGHT - 130,
								20, SCREEN_HEIGHT - 110,
								40, SCREEN_HEIGHT - 120, black);
							if(entered) {
								userHP += ship->useItem(item1);
								if(userHP > 754)
									userHP = 754;
								entered = false;
								userTurn = false;
								enemyTurn = true;
								iter = 0;
							}
							break;
						case 1: // rope
							al_draw_filled_triangle(20, SCREEN_HEIGHT - 100,
								20, SCREEN_HEIGHT - 80,
								40, SCREEN_HEIGHT - 90, black);
							if(entered) {
								userHP += ship->useItem(item2);
								if(userHP > 754)
									userHP = 754;
								entered = false;
								enemyTurn = true;
								iter = 0;
								attkIter = 0;
							}
							break;
						case 2: // tools
							al_draw_filled_triangle(20, SCREEN_HEIGHT - 70,
								20, SCREEN_HEIGHT - 50,
								40, SCREEN_HEIGHT - 60, black);
							if(entered) {
								userHP += ship->useItem(item3);
								if(userHP > 754)
									userHP = 754;
								entered = false;
								enemyTurn = true;
								iter = 0;
								attkIter = 0;
							}
							break;
						case 3: // food
							al_draw_filled_triangle(215, SCREEN_HEIGHT - 130,
								215, SCREEN_HEIGHT - 110,
								235, SCREEN_HEIGHT - 120, black);
							if(entered) {
								userHP += ship->useItem(item4);
								if(userHP > 754)
									userHP = 754;
								entered = false;
								enemyTurn = true;
								iter = 0;
								attkIter = 0;
							}
							break;
						case 4: // water
							al_draw_filled_triangle(215, SCREEN_HEIGHT - 100,
								215, SCREEN_HEIGHT - 80,
								235, SCREEN_HEIGHT - 90, black);
							if(entered) {
								userHP += ship->useItem(item5);
								if(userHP > 754)
									userHP = 754;
								entered = false;
								enemyTurn = true;
								iter = 0;
								attkIter = 0;
							}
							break;
						case 5: // booze
							al_draw_filled_triangle(215, SCREEN_HEIGHT - 70,
								215, SCREEN_HEIGHT - 50,
								235, SCREEN_HEIGHT - 60, black);
							if(entered) {
								userHP += ship->useItem(item6);
								if(userHP > 754)
									userHP = 754;
								entered = false;
								enemyTurn = true;
								iter = 0;
								attkIter = 0;
							}
							break;
						}
					}
					break;
				case 2: // Flee
					al_draw_filled_triangle(SCREEN_WIDTH - 280, SCREEN_HEIGHT - 50,
						SCREEN_WIDTH - 280, SCREEN_HEIGHT - 30, 
						SCREEN_WIDTH - 260, SCREEN_HEIGHT - 40, black);
					srand(time(NULL));
					num = 1 + rand()%10;
					if(entered) {
						if(num <= 5) {
							// ends loop go back to map
							return 1;
						}
						else {
							entered = false; // breaks out of this if
							enemyTurn = true;
							iter = 0;
						}
					}
					break;
				case 3: // Exits Game or you could have it go back to main menu
					al_draw_filled_triangle(SCREEN_WIDTH - 155, SCREEN_HEIGHT - 130,
						SCREEN_WIDTH - 155, SCREEN_HEIGHT - 110, 
						SCREEN_WIDTH - 135, SCREEN_HEIGHT - 120, black);
					if (entered)
						return 0;
					break;
				case 4: // How to play
					al_draw_filled_triangle(SCREEN_WIDTH - 155, SCREEN_HEIGHT - 90,
						SCREEN_WIDTH - 155, SCREEN_HEIGHT - 70, 
						SCREEN_WIDTH - 135, SCREEN_HEIGHT - 80, black);
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 125, ALLEGRO_ALIGN_LEFT, "HOW TO BATTLE: ARROW PAD to move cursor.");
					al_draw_text(font, black, 40, SCREEN_HEIGHT - 95, ALLEGRO_ALIGN_LEFT, "ENTER to select, END to deselect/reset.");
					break;
				}
				al_flip_display();
			}
		}
	}
	return 1;
}

void BattleScreen::draw() { 
	// Ship
	al_draw_bitmap(player, 50, SCREEN_HEIGHT - 440, 0);

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
	al_draw_text(font, black, SCREEN_WIDTH - 130, SCREEN_HEIGHT - 85, ALLEGRO_ALIGN_LEFT, "HOW TO PLAY");

	al_flip_display();
}

void BattleScreen::update() {
	// Enemy HP box
	al_draw_filled_rounded_rectangle(20, 20, 300, 75, 5, 3, white);
	al_draw_rounded_rectangle(20, 20, 300, 75, 5, 3, black, 3);
	al_draw_text(font, black, 35, 35, ALLEGRO_ALIGN_LEFT, enemyName);

	// Enemy HP Bar
	al_draw_filled_rectangle(35, 50, 280, 60, black);
	al_draw_filled_rectangle(35, 50, enemyHP, 60, lime);
	al_draw_filled_rectangle(35, 50, 62, 60, black);
	al_draw_rounded_rectangle(35, 50, 280, 60, 2, 2, black, 2);
	al_draw_text(font, white, 40, 51, ALLEGRO_ALIGN_LEFT, "HP");

	// Main Character HP Box
	al_draw_filled_rounded_rectangle(SCREEN_WIDTH - 315, SCREEN_HEIGHT - 225, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 170, 5, 3, white);
	al_draw_rounded_rectangle(SCREEN_WIDTH - 315, SCREEN_HEIGHT - 225, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 170, 5, 3, black, 3);
	al_draw_text(font, black, SCREEN_WIDTH - 300, SCREEN_HEIGHT - 210, ALLEGRO_ALIGN_LEFT, userName);

	// Main Character HP Bar
	al_draw_filled_rectangle(SCREEN_WIDTH - 300, SCREEN_HEIGHT - 195, SCREEN_WIDTH - 45, SCREEN_HEIGHT - 185, black);
	al_draw_filled_rectangle(SCREEN_WIDTH - 300, SCREEN_HEIGHT - 195, userHP, SCREEN_HEIGHT - 185, lime);
	al_draw_filled_rectangle(SCREEN_WIDTH - 300, SCREEN_HEIGHT - 195, SCREEN_WIDTH - 272, SCREEN_HEIGHT - 185, black);
	al_draw_rounded_rectangle(SCREEN_WIDTH - 300, SCREEN_HEIGHT - 195, SCREEN_WIDTH - 45, SCREEN_HEIGHT - 185, 2, 2, black, 2);
	al_draw_text(font, white, SCREEN_WIDTH - 295, SCREEN_HEIGHT - 194, ALLEGRO_ALIGN_LEFT, "HP");

	al_flip_display();
}
