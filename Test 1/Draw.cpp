#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "Draw.h"

void draw_menu(int *okno, bool *fullscreen, int *pos_x, int *pos_y, int szerokosc, int wysokosc, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font36)
{
	if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6-14) && (*pos_y <= wysokosc/6+50))
		al_draw_filled_rectangle(szerokosc/3, wysokosc/6-14, szerokosc*2/3, wysokosc/6+50, al_map_rgb(0,50,100));
	if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6*2-14) && (*pos_y <= wysokosc/6*2+50))
		al_draw_filled_rectangle(szerokosc/3, wysokosc/6*2-14, szerokosc*2/3, wysokosc/6*2+50, al_map_rgb(0,50,100));
	if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6*3-14) && (*pos_y <= wysokosc/6*3+50))
		al_draw_filled_rectangle(szerokosc/3, wysokosc/6*3-14, szerokosc*2/3, wysokosc/6*3+50, al_map_rgb(0,50,100));
	if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6*4-14) && (*pos_y <= wysokosc/6*4+50))
		al_draw_filled_rectangle(szerokosc/3, wysokosc/6*4-14, szerokosc*2/3, wysokosc/6*4+50, al_map_rgb(0,50,100));

	switch(*okno)
	{
	case 1:
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6 , ALLEGRO_ALIGN_CENTRE, "NEW GAME");
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6*2, ALLEGRO_ALIGN_CENTRE, "LOAD GAME");
	if(*fullscreen == 0)
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6*3, ALLEGRO_ALIGN_CENTRE, "FULLSCREEN");
	else
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6*3, ALLEGRO_ALIGN_CENTRE, "WINDOW");
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6*4, ALLEGRO_ALIGN_CENTRE, "QUIT");
	break;
	case 2:
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6 , ALLEGRO_ALIGN_CENTRE, "SAVE GAME");
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6*2, ALLEGRO_ALIGN_CENTRE, "BACK");
	if(*fullscreen == 0)
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6*3, ALLEGRO_ALIGN_CENTRE, "FULLSCREEN");
	else
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6*3, ALLEGRO_ALIGN_CENTRE, "WINDOW");
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6*4, ALLEGRO_ALIGN_CENTRE, "QUIT GAME");
	break;
	case 3:
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6 , ALLEGRO_ALIGN_CENTRE, "1P WHITE");
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6*2, ALLEGRO_ALIGN_CENTRE, "1P BLACK");
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6*3, ALLEGRO_ALIGN_CENTRE, "2 PLAYERS");
	al_draw_text(font36, al_map_rgb(255, 255, 255), szerokosc/2, wysokosc/6*4, ALLEGRO_ALIGN_CENTRE, "BACK");
	}

	al_draw_rectangle(szerokosc/3, wysokosc/6-14, szerokosc*2/3, wysokosc/6+50, al_map_rgb(0,0,0),3);
	al_draw_rectangle(szerokosc/3, wysokosc/6*2-14, szerokosc*2/3, wysokosc/6*2+50, al_map_rgb(0,0,0),3);
	al_draw_rectangle(szerokosc/3, wysokosc/6*3-14, szerokosc*2/3, wysokosc/6*3+50, al_map_rgb(0,0,0),3);
	al_draw_rectangle(szerokosc/3, wysokosc/6*4-14, szerokosc*2/3, wysokosc/6*4+50, al_map_rgb(0,0,0),3);
}

void draw_board(int *okno, bool *done, bool *down, bool *undo, bool *redo, int *szach, int szerokosc, int wysokosc, int *pos_x, int *pos_y, ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font36)
{
		if(*okno<10)
			return;

		*down = false;
	al_clear_to_color(al_map_rgb(120,80,50));

	if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
		*done = true;

	else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		*pos_x = ev.mouse.x;
		*pos_y = ev.mouse.y;
	}
	else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		if(ev.mouse.button & 1)
		*down = true;
	}


	char litery = 'A';


	for(int i = 0; i <= 7; i++)
	{
		for(int j = 0; j <= 7; j++)
		{
			if((i+j)%2 == 0)
				al_draw_filled_rectangle(25+((wysokosc-75)/8)*j, 25+((wysokosc-75)/8)*i, 25+((wysokosc-75)/8)*(j+1), 25+((wysokosc-75)/8)*(i+1),al_map_rgb(200,200,200));
			else
				al_draw_filled_rectangle(25+((wysokosc-75)/8)*j, 25+((wysokosc-75)/8)*i, 25+((wysokosc-75)/8)*(j+1), 25+((wysokosc-75)/8)*(i+1),al_map_rgb(100,100,100));
			if(i==0)	
				al_draw_textf(font36, al_map_rgb(255, 255, 255), wysokosc-40, 25-(wysokosc-75)/32+((wysokosc-75)/8)*((7-j)*2+1)/2 , ALLEGRO_ALIGN_CENTRE, "%d", j+1);

		}
		al_draw_textf(font36, al_map_rgb(255, 255, 255), 25+((wysokosc-75)/8)*(i*2+1)/2, wysokosc-50, ALLEGRO_ALIGN_CENTRE, "%c",litery);
		
		litery++;

	}

	if((*pos_x >= wysokosc) && (*pos_x <= szerokosc-25) && (*pos_y >= wysokosc/7-14) && (*pos_y <= wysokosc/7+50))
		al_draw_filled_rectangle(wysokosc, wysokosc/7-14, szerokosc-25, wysokosc/7+50, al_map_rgb(0,50,100));

	if((*pos_x >= wysokosc) && (*pos_x <= szerokosc-25) && (*pos_y >= wysokosc/7*3-14) && (*pos_y <= wysokosc/7*3+50))
		al_draw_filled_rectangle(wysokosc, wysokosc/7*3-14, szerokosc-25, wysokosc/7*3+50, al_map_rgb(0,50,100));

	if((*pos_x >= wysokosc) && (*pos_x <= szerokosc-25) && (*pos_y >= wysokosc/7*4-14) && (*pos_y <= wysokosc/7*4+50))
		al_draw_filled_rectangle(wysokosc, wysokosc/7*4-14, szerokosc-25, wysokosc/7*4+50, al_map_rgb(0,50,100));

	if((*pos_x >= wysokosc) && (*pos_x <= szerokosc-25) && (*pos_y >= wysokosc/7*5-14) && (*pos_y <= wysokosc/7*5+50))
		al_draw_filled_rectangle(wysokosc, wysokosc/7*5-14, szerokosc-25, wysokosc/7*5+50, al_map_rgb(0,50,100));





	al_draw_text(font36, al_map_rgb(255, 255, 255), (wysokosc+szerokosc-25)/2, wysokosc/7, ALLEGRO_ALIGN_CENTRE, "MENU");
	if((*szach > 0) && (*szach < 10))
	al_draw_text(font36, al_map_rgb(255, 255, 255), (wysokosc+szerokosc-25)/2, wysokosc/7*2, ALLEGRO_ALIGN_CENTRE, "CHECK");
	if(*szach > 16)
	al_draw_text(font36, al_map_rgb(255, 255, 255), (wysokosc+szerokosc-25)/2, wysokosc/7*2, ALLEGRO_ALIGN_CENTRE, "MATE");
	al_draw_text(font36, al_map_rgb(255, 255, 255), (wysokosc+szerokosc-25)/2, wysokosc/7*3, ALLEGRO_ALIGN_CENTRE, "UNDO");
	al_draw_text(font36, al_map_rgb(255, 255, 255), (wysokosc+szerokosc-25)/2, wysokosc/7*4, ALLEGRO_ALIGN_CENTRE, "REDO");
	al_draw_text(font36, al_map_rgb(255, 255, 255), (wysokosc+szerokosc-25)/2, wysokosc/7*5, ALLEGRO_ALIGN_CENTRE, "QUIT");


	al_draw_rectangle(wysokosc, wysokosc/7-14, szerokosc-25, wysokosc/7+50, al_map_rgb(0,0,0),3);
	al_draw_rectangle(wysokosc, wysokosc/7*3-14, szerokosc-25, wysokosc/7*3+50, al_map_rgb(0,0,0),3);
	al_draw_rectangle(wysokosc, wysokosc/7*4-14, szerokosc-25, wysokosc/7*4+50, al_map_rgb(0,0,0),3);
	al_draw_rectangle(wysokosc, wysokosc/7*5-14, szerokosc-25, wysokosc/7*5+50, al_map_rgb(0,0,0),3);



		if((*pos_x >= wysokosc) && (*pos_x <= szerokosc-25) && (*pos_y >= wysokosc/7-14) && (*pos_y <= wysokosc/7+50) && (*down == true))
			*okno = 2;
		if((*pos_x >= wysokosc) && (*pos_x <= szerokosc-25) && (*pos_y >= wysokosc/7*5-14) && (*pos_y <= wysokosc/7*5+50) && (*down == true))
			*done = true;
		if((*pos_x >= wysokosc) && (*pos_x <= szerokosc-25) && (*pos_y >= wysokosc/7*3-14) && (*pos_y <= wysokosc/7*3+50) && (*down == true))
			*undo = 1;
		if((*pos_x >= wysokosc) && (*pos_x <= szerokosc-25) && (*pos_y >= wysokosc/7*4-14) && (*pos_y <= wysokosc/7*4+50) && (*down == true))
			*redo = 1;


}

void draw_tips(int *okno, int szerokosc, int wysokosc, bool mozliwy_ruch[8][8])
{
	if(*okno<10)
		return;


	for(int i = 0; i <= 7; i++)
	{
		for(int j = 0; j <= 7; j++)
		{
			if(mozliwy_ruch[i][j] == 1)
			{
			if((i+j)%2 == 0)
				al_draw_filled_rectangle(25+((wysokosc-75)/8)*i, 25+((wysokosc-75)/8)*j, 25+((wysokosc-75)/8)*(i+1), 25+((wysokosc-75)/8)*(j+1),al_map_rgb(250,250,150));
			else
				al_draw_filled_rectangle(25+((wysokosc-75)/8)*i, 25+((wysokosc-75)/8)*j, 25+((wysokosc-75)/8)*(i+1), 25+((wysokosc-75)/8)*(j+1),al_map_rgb(150,150,50));
			}

		}


	}


}

void draw_chess_pieces(int *okno, int szerokosc, int wysokosc, int *pos_x, int *pos_y, int tab[8][8], ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font36, ALLEGRO_BITMAP *kingw, ALLEGRO_BITMAP *queenw, ALLEGRO_BITMAP *rookw, ALLEGRO_BITMAP *bishopw, ALLEGRO_BITMAP *knightw, ALLEGRO_BITMAP *pawnw, ALLEGRO_BITMAP *kingb, ALLEGRO_BITMAP *queenb, ALLEGRO_BITMAP *rookb, ALLEGRO_BITMAP *bishopb, ALLEGRO_BITMAP *knightb, ALLEGRO_BITMAP *pawnb)
{
	if(*okno<10)
		return;

	for(int i = 0; i<=7; i++)
	{
		for(int j = 0; j<=7; j++)
		{
			switch(tab[j][i])
			{
			case 0:
				break;
			case 1:
				{
					al_draw_scaled_bitmap(kingw, 0, 0, 300, 294, 25+((wysokosc-75)/8)*((j+1)*2-1)/2-(wysokosc-75)/16, 25+((wysokosc-75)/8)*(i*2+1)/2-(wysokosc-75)/16, (wysokosc-75)/8, (wysokosc-75)/8, 0);
					break;
				}
			case 2:
				{
					al_draw_scaled_bitmap(queenw, 0, 0, 300, 282, 25+((wysokosc-75)/8)*((j+1)*2-1)/2-(wysokosc-75)/16, 25+((wysokosc-75)/8)*(i*2+1)/2-(wysokosc-75)/16, (wysokosc-75)/8, (wysokosc-75)/8, 0);
					break;
				}
			case 3:
				{
					al_draw_scaled_bitmap(rookw, 0, 0, 258, 299, 25+((wysokosc-75)/8)*((j+1)*2-1)/2-(wysokosc-75)/16, 25+((wysokosc-75)/8)*(i*2+1)/2-(wysokosc-75)/16, (wysokosc-75)/8, (wysokosc-75)/8, 0);
					break;
				}
			case 4:
				{
					al_draw_scaled_bitmap(bishopw, 0, 0, 288, 298, 25+((wysokosc-75)/8)*((j+1)*2-1)/2-(wysokosc-75)/16, 25+((wysokosc-75)/8)*(i*2+1)/2-(wysokosc-75)/16, (wysokosc-75)/8, (wysokosc-75)/8, 0);
					break;
				}
			case 5:
				{
					al_draw_scaled_bitmap(knightw, 0, 0, 300, 298, 25+((wysokosc-75)/8)*((j+1)*2-1)/2-(wysokosc-75)/16, 25+((wysokosc-75)/8)*(i*2+1)/2-(wysokosc-75)/16, (wysokosc-75)/8, (wysokosc-75)/8, 0);
					break;
				}
			case 6:
				{
					al_draw_scaled_bitmap(pawnw, 0, 0, 228, 300, 25+((wysokosc-75)/8)*((j+1)*2-1)/2-(wysokosc-75)/16, 25+((wysokosc-75)/8)*(i*2+1)/2-(wysokosc-75)/16, (wysokosc-75)/8, (wysokosc-75)/8, 0);
					break;
				}
			case 11:
				{
					al_draw_scaled_bitmap(kingb, 0, 0, 300, 295, 25+((wysokosc-75)/8)*((j+1)*2-1)/2-(wysokosc-75)/16, 25+((wysokosc-75)/8)*(i*2+1)/2-(wysokosc-75)/16, (wysokosc-75)/8, (wysokosc-75)/8, 0);
					break;
				}
			case 12:
				{
					al_draw_scaled_bitmap(queenb, 0, 0, 300, 281, 25+((wysokosc-75)/8)*((j+1)*2-1)/2-(wysokosc-75)/16, 25+((wysokosc-75)/8)*(i*2+1)/2-(wysokosc-75)/16, (wysokosc-75)/8, (wysokosc-75)/8, 0);
					break;
				}
			case 13:
				{
					al_draw_scaled_bitmap(rookb, 0, 0, 255, 297, 25+((wysokosc-75)/8)*((j+1)*2-1)/2-(wysokosc-75)/16, 25+((wysokosc-75)/8)*(i*2+1)/2-(wysokosc-75)/16, (wysokosc-75)/8, (wysokosc-75)/8, 0);
					break;
				}
			case 14:
				{
					al_draw_scaled_bitmap(bishopb, 0, 0, 285, 297, 25+((wysokosc-75)/8)*((j+1)*2-1)/2-(wysokosc-75)/16, 25+((wysokosc-75)/8)*(i*2+1)/2-(wysokosc-75)/16, (wysokosc-75)/8, (wysokosc-75)/8, 0);
					break;
				}
			case 15:
				{
					al_draw_scaled_bitmap(knightb, 0, 0, 300, 296, 25+((wysokosc-75)/8)*((j+1)*2-1)/2-(wysokosc-75)/16, 25+((wysokosc-75)/8)*(i*2+1)/2-(wysokosc-75)/16, (wysokosc-75)/8, (wysokosc-75)/8, 0);
					break;
				}
			case 16:
				{
					al_draw_scaled_bitmap(pawnb, 0, 0, 228, 299, 25+((wysokosc-75)/8)*((j+1)*2-1)/2-(wysokosc-75)/16, 25+((wysokosc-75)/8)*(i*2+1)/2-(wysokosc-75)/16, (wysokosc-75)/8, (wysokosc-75)/8, 0);
					break;
				}
			}

		}
	}
	al_flip_display();
}

void menu(int *okno, bool *done, bool *down, bool *fullscreen, int *kolor, int szerokosc, int wysokosc, int *pos_x, int *pos_y, ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font36)
{
	if(*okno>9)
		return;
		
	
	*down = false;
	al_clear_to_color(al_map_rgb(120,80,50));





	if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
		*done = true;

	else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		*pos_x = ev.mouse.x;
		*pos_y = ev.mouse.y;
	}
	else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		if(ev.mouse.button & 1)
		*down = true;
	}







while(1)
{
	if(*okno == 1)
	{
	if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6*4-14) && (*pos_y <= wysokosc/6*4+50) && (*down == true))
		*done = true;
	if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6*3-14) && (*pos_y <= wysokosc/6*3+50) && (*down == true))
		{*fullscreen = !*fullscreen;
			if(*fullscreen == 1)
			{
				al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, true);
				al_set_display_flag(display, ALLEGRO_WINDOWED, false);
			}
			else
			{
				al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, false);
				al_set_display_flag(display, ALLEGRO_WINDOWED, true);
				al_resize_display(display, 800, 600);
				al_set_window_position(display, szerokosc/2 - 400, wysokosc/2 - 300);
			}
		}
	if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6*2-14) && (*pos_y <= wysokosc/6*2+50) && (*down == true))
		{
			*kolor = 4;
			*okno = 10;
		}
	if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6-14) && (*pos_y <= wysokosc/6+50) && (*down == true))
		*okno = 3;
		break;

	}
	if(*okno == 2)
	{
		if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6-14) && (*pos_y <= wysokosc/6+50) && (*down == true))
			{
				*kolor = *kolor + 10;
			}
		if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6*2-14) && (*pos_y <= wysokosc/6*2+50) && (*down == true))
			*okno = 10;
		if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6*4-14) && (*pos_y <= wysokosc/6*4+50) && (*down == true))
			*okno = 1;
		if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6*3-14) && (*pos_y <= wysokosc/6*3+50) && (*down == true))
		{*fullscreen = !*fullscreen;
			if(*fullscreen == 1)
			{
				al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, true);
				al_set_display_flag(display, ALLEGRO_WINDOWED, false);
			}
			else
			{
				al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, false);
				al_set_display_flag(display, ALLEGRO_WINDOWED, true);
				al_resize_display(display, 800, 600);
				al_set_window_position(display, szerokosc/2 - 400, wysokosc/2 - 300);
			}
		}
		break;
	}
	if(*okno == 3)
	{
		if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6-14) && (*pos_y <= wysokosc/6+50) && (*down == true))
			{
				*okno = 10;
				*kolor = 1;
			}
		if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6*2-14) && (*pos_y <= wysokosc/6*2+50) && (*down == true))
			{
				*okno = 10;
				*kolor = 2;
			}
		if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6*3-14) && (*pos_y <= wysokosc/6*3+50) && (*down == true))
			{
				*okno = 10;
				*kolor = 3;
			}
		if((*pos_x >= szerokosc/3) && (*pos_x <= szerokosc*2/3) && (*pos_y >= wysokosc/6*4-14) && (*pos_y <= wysokosc/6*4+50) && (*down == true))
			*okno = 1;



		


	}
	break;
}
	draw_menu(okno,fullscreen,pos_x,pos_y,szerokosc,wysokosc,display,font36);
	al_flip_display();

}

void wybrane_pole(int *okno, int szerokosc, int wysokosc, int *pos_x, int *pos_y, int *pole_x, int *pole_y, ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *event_queue)
{
	if((*okno<10) || (ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN))
		return;

	*pole_x = -1;
	*pole_y = -1;

	for(int i = 0; i <= 7; i++)
	{
		for(int j = 0; j <= 7; j++)
		{
			if((*pos_x > 25+((wysokosc-75)/8)*j) && (*pos_x <= 25+((wysokosc-75)/8)*(j+1)) && (*pos_y > 25+((wysokosc-75)/8)*i) && (*pos_y <= 25+((wysokosc-75)/8)*(i+1)))
			{
				*pole_x = j;
				*pole_y = i;
				return;
			}

		}


	}
}
