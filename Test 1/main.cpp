#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "Draw.h"
#include "Szach.h"
#include "Funkcje.h"

#define Wysokosc 600
#define Szerokosc 800




//	pionki : 1 - krol, 2 - hetman, 3 - wieza, 4 - goniec, 5 - konik, 6 - pion
//	1* - czarne
//	plansza od 0 do 7 w prawo x
//  plansza od 0 do 7 w dol y
// *kolor do wczytywania gier zapisanych/nowych 1 - 1 gracz biale, 2 - 1 gracz czarne, 3 - 2 graczy, 4 - wczytana gra


int main(void)
{
	int *okno;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL ;
	ALLEGRO_EVENT ev;
	ALLEGRO_MONITOR_INFO info;

	bool *done;
	int *pos_x;
	int *pos_y;
	int tmp_pole_x;
	int tmp_pole_y;
	bool *down;
	bool *fullscreen;
	bool mozliwy_ruch[8][8];
	bool *undo;
	bool *redo;
	int *kolor;
	int *szach;
	int plansza[8][8];
	int *pole_y;
	int *pole_x;
	bool *kolor_ruchu;			// 0 - biale, 1 - czarne
	bool tmp_kolor_ruchu;
	int pionki_biale[16][2];
	int pionki_czarne[16][2];
	bool czy_szach[8][8];
	lista *glowa;
	lista *tmp;
	lista *tmp2;
	bool *czy_lista;
	bool *koniec;
	bool *czy_undo;
	int *komputer;
	FILE *plik;
	int k;

	bool stan_wiez_krola[6]; // 0 - krol bialy, 1 - wieza biala x=0, 2 - wieza biala x=7, 3 - krol czarny, 4 - wieza czarna x=0, 5 - wiez czarna x=7

	okno = new int;
	*okno = 1;
	done = new bool;
	*done = false;
	pos_x = new int;
	*pos_x = Szerokosc / 2;
	pos_y = new int;
	*pos_y = Wysokosc / 2;
	down = new bool;
	*down = false;
	fullscreen = new bool;
	*fullscreen = false;
	undo = new bool;
	*undo = 0;
	redo = new bool;
	*redo = 0;
	kolor = new int;
	*kolor = -1;
	szach = new int;
	*szach = 0;
	pole_y = new int;
	*pole_y = -1;
	pole_x = new int;
	*pole_x = -1;
	kolor_ruchu = new bool;
	*kolor_ruchu = 0;
	czy_lista = new bool;
	*czy_lista = 0;
	koniec = new bool;
	*koniec = 0;
	czy_undo = new bool;
	*czy_undo = 0;
	komputer = new int;
	*komputer = -1;

	
	glowa = NULL;
	tmp = glowa;
	tmp2 = tmp;





//1 - king, 2 - queen, 3 - rook, 4 - bishop, 5 - knight, 6 - pawn, 1x - black

	if(!al_init()) 
	{
		al_show_native_message_box(NULL, NULL, NULL, 
			"failed to initialize allegro!", NULL, NULL);                   
		return -1;
	}

	al_set_new_display_flags(ALLEGRO_WINDOWED);
	display = al_create_display(Szerokosc, Wysokosc);

	if(!display) 
	{
		al_show_native_message_box(NULL, NULL, NULL, 
			"failed to initialize display!", NULL, NULL);
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_mouse();
	al_init_image_addon();

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());

	ALLEGRO_FONT *font36 = al_load_font("classic_test_tt.ttf", 36, 0);

	al_set_window_title(display, "Szachy");
	al_set_mouse_xy(display, Szerokosc/2, Wysokosc/2);



	ALLEGRO_BITMAP *kingw = al_load_bitmap("1.png");
	ALLEGRO_BITMAP *queenw = al_load_bitmap("2.png");
	ALLEGRO_BITMAP *rookw = al_load_bitmap("3.png");
	ALLEGRO_BITMAP *bishopw = al_load_bitmap("4.png");
	ALLEGRO_BITMAP *knightw = al_load_bitmap("5.png");
	ALLEGRO_BITMAP *pawnw = al_load_bitmap("6.png");
	ALLEGRO_BITMAP *kingb = al_load_bitmap("11.png");
	ALLEGRO_BITMAP *queenb = al_load_bitmap("12.png");
	ALLEGRO_BITMAP *rookb = al_load_bitmap("13.png");
	ALLEGRO_BITMAP *bishopb = al_load_bitmap("14.png");
	ALLEGRO_BITMAP *knightb = al_load_bitmap("15.png");
	ALLEGRO_BITMAP *pawnb = al_load_bitmap("16.png");


int	width = Szerokosc;
int height = Wysokosc;

al_get_monitor_info(0, &info);




while(!*done)
{
		al_wait_for_event(event_queue, &ev);


menu(okno,done,down,fullscreen,kolor,width,height,pos_x,pos_y,ev,event_queue,display,font36);
if((*kolor == 1) || (*kolor == 2) || (*kolor == 3) || (*kolor == 4))
{
	if(*kolor == 4)
		plik = fopen("plansza.txt","rt");
	else
		plik = fopen("new_plansza.txt","rt");
	for(int i = 0; i<=7; i++)
	{
		for(int j = 0; j<=7; j++)
			{
				fscanf(plik,"%d",&plansza[j][i]);
				czy_szach[j][i] = 0;
			}
	}
	fclose(plik);

	if(*kolor == 4)
		plik = fopen("pionki.txt","rt");
	else
		plik = fopen("new_pionki.txt","rt");

	for(int i = 0; i<=15; i++)
	{
		fscanf(plik,"%d",&pionki_biale[i][0]);
		fscanf(plik,"%d",&pionki_biale[i][1]);
	}
	for(int i = 0; i<=15; i++)
	{
		fscanf(plik,"%d",&pionki_czarne[i][0]);
		fscanf(plik,"%d",&pionki_czarne[i][1]);
	}
	fclose(plik);

	if(*kolor == 4)
	{
		plik = fopen("stan.txt","rt");
		fscanf(plik,"%d",kolor_ruchu);
		fscanf(plik,"%d",komputer);
		fscanf(plik,"%d",szach);

		for(int  i=0; i<=5; i++)
		{
			fscanf(plik,"%d",&k);
			stan_wiez_krola[i] = k;
		}
		fclose(plik);
		if(*szach != 0)
		{
			plik = fopen("szach.txt","rt");
			for(int i = 0; i<=7; i++)
			{
				for(int j = 0; j<=7; j++)
				{
					fscanf(plik,"%d",&k);
					czy_szach[j][i] = k;
				}
			}
			fclose(plik);
		}
	}
	else
	{
	for(int  i=0; i<=5; i++)
		stan_wiez_krola[i] = 0;
	*kolor_ruchu = 0;
	*szach = 0;
	if(*kolor == 1)
		*komputer = 2;
	if(*kolor == 2)
		*komputer = 1;
	if(*kolor == 3)
		*komputer = 0;
	}

	*kolor = *kolor + 10;	
	*pole_x = -1;
	*pole_y = -1;
	*koniec = 0;
	while(tmp != NULL)
	{
		tmp2 = tmp->prev;
		delete(tmp);
		tmp = tmp2;
	}
	glowa = new lista;
	glowa->next = NULL;
	glowa->prev = NULL;
	glowa->pole_x = -1;
	glowa->pole_y = -1;
	glowa->prev_pole_x = -1;
	glowa->prev_pole_y = -1;
	glowa->zbity = 0;
	glowa->zmiana_stanu = 0;
	tmp = glowa;
	tmp2 = tmp;
}

if(*kolor>20)
{
	plik = fopen("plansza.txt","wt");
	for(int i = 0;i<=7;i++)
	{
		for(int j = 0;j<=7;j++)
		{
			fprintf(plik,"%d ",plansza[j][i]);
		}
		fprintf(plik,"\n");
	}
	fclose(plik);
	plik = fopen("szach.txt","wt");
	for(int i = 0;i<=7;i++)
	{
		for(int j = 0;j<=7;j++)
			fprintf(plik,"%d ",czy_szach[j][i]);
		fprintf(plik,"\n");
	}
	fclose(plik);
	plik = fopen("pionki.txt","wt");
	for(int i = 0; i<=15; i++)
	{
		fprintf(plik,"%d ",pionki_biale[i][0]);
		fprintf(plik,"%d\n",pionki_biale[i][1]);
	}
	fprintf(plik,"\n");
	for(int i = 0; i<=15; i++)
	{
		fprintf(plik,"%d ",pionki_czarne[i][0]);
		fprintf(plik,"%d\n",pionki_czarne[i][1]);
	}
	fclose(plik);
	plik = fopen("stan.txt","wt");
		fprintf(plik,"%d\n",*kolor_ruchu);
		fprintf(plik,"%d\n",*komputer);
		fprintf(plik,"%d\n",*szach);

		for(int  i=0; i<=5; i++)
			fprintf(plik,"%d ",stan_wiez_krola[i]);

		fclose(plik);
	*kolor = *kolor - 10;

}


draw_board(okno,done,down,undo,redo,szach,width,height,pos_x,pos_y,ev,event_queue,display,font36);

tmp_pole_x = *pole_x;
tmp_pole_y = *pole_y;
tmp_kolor_ruchu = *kolor_ruchu;



wybrane_pole(okno,width,height,pos_x,pos_y,pole_x,pole_y,ev,event_queue);
if((*komputer == 1) && (*kolor_ruchu == 0) && (*okno>9))
{
	int r;
	if(*szach<=2)
	{
	while(mozliwy_ruch[*pole_x][*pole_y] == 0)
	{
		r = rand()%16;
		*pole_x = pionki_biale[r][0];
		*pole_y = pionki_biale[r][1];
		tmp_pole_x = *pole_x;
		tmp_pole_y = *pole_y;
		komp(okno,komputer,kolor_ruchu,pole_x,pole_y,szach,plansza,czy_szach,mozliwy_ruch,pionki_biale,pionki_czarne,stan_wiez_krola,glowa);
	}
	}
}
if((*komputer == 2) && (*kolor_ruchu == 1) && (*okno>9))
{
	int r;
	if(*szach<=2)
	{
	while(mozliwy_ruch[*pole_x][*pole_y] == 0)
	{
		r = rand()%16;
		*pole_x = pionki_czarne[r][0];
		*pole_y = pionki_czarne[r][1];
		tmp_pole_x = *pole_x;
		tmp_pole_y = *pole_y;
		komp(okno,komputer,kolor_ruchu,pole_x,pole_y,szach,plansza,czy_szach,mozliwy_ruch,pionki_biale,pionki_czarne,stan_wiez_krola,glowa);
	}
	}
}
sprawy_z_lista(okno,pole_x,pole_y,tmp_pole_x,tmp_pole_y,plansza,mozliwy_ruch,glowa,stan_wiez_krola,czy_lista);
if(*czy_lista == 1)
{
	while(tmp != glowa)
	{
		tmp2 = tmp->prev;
		delete(tmp);
		tmp = tmp2;
	}
	if(glowa->next != NULL)
		glowa = glowa->next;
	*czy_lista = 0;
	tmp = glowa;
}
ruch(okno,pole_x,pole_y,tmp_pole_x,tmp_pole_y,plansza,mozliwy_ruch,pionki_biale,pionki_czarne,kolor_ruchu,stan_wiez_krola); // dla struktur zrobic (undo redo)
if(plansza[*pole_x][0] == 6)
	plansza[*pole_x][0] = 2;
if(plansza[*pole_x][7] == 16)
	plansza[*pole_x][7] = 12;
if(tmp_kolor_ruchu != *kolor_ruchu)
{sprawdzenie_szachu(okno,plansza,czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
szach_mat(okno,plansza,czy_szach,kolor_ruchu,pionki_czarne,pionki_biale,szach,pole_x,pole_y);
}
dostepne_ruchy(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,mozliwy_ruch,pionki_biale,pionki_czarne,czy_szach,1);
roszada(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,mozliwy_ruch,pionki_biale,pionki_czarne,czy_szach,stan_wiez_krola);
bicie_w_przelocie(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,mozliwy_ruch,pionki_biale,pionki_czarne,czy_szach,glowa);

if((*undo == 1) && (*komputer>0))
{
	for(int i = 0;i<=1;i++)
	{
	*undo = 1;
	do_undo(okno,plansza,pionki_biale,pionki_czarne,kolor_ruchu,glowa,undo,koniec,stan_wiez_krola);
	if(glowa->prev != NULL)
		glowa = glowa->prev;
	*undo = 0;
	*pole_x = glowa->pole_x;
	*pole_y = glowa->pole_y;
	sprawdzenie_szachu(okno,plansza,czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
	szach_mat(okno,plansza,czy_szach,kolor_ruchu,pionki_czarne,pionki_biale,szach,pole_x,pole_y);
	*czy_undo = 1;
	}
}
else if(*undo == 1)
{
	do_undo(okno,plansza,pionki_biale,pionki_czarne,kolor_ruchu,glowa,undo,koniec,stan_wiez_krola);
	if(glowa->prev != NULL)
		glowa = glowa->prev;
	*undo = 0;
	*pole_x = glowa->pole_x;
	*pole_y = glowa->pole_y;
	sprawdzenie_szachu(okno,plansza,czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
	szach_mat(okno,plansza,czy_szach,kolor_ruchu,pionki_czarne,pionki_biale,szach,pole_x,pole_y);
	*czy_undo = 1;
}
if((*redo == 1) && (*komputer>0))
{
	for(int i = 0;i<=1;i++)
	{
	*redo = 1;
	if(glowa->next != NULL)
	{
		glowa = glowa->next;
	}
	do_redo(okno,plansza,pionki_biale,pionki_czarne,kolor_ruchu,glowa,redo,czy_undo,stan_wiez_krola);
	sprawdzenie_szachu(okno,plansza,czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
	*pole_x = glowa->pole_x;
	*pole_y = glowa->pole_y;
	szach_mat(okno,plansza,czy_szach,kolor_ruchu,pionki_czarne,pionki_biale,szach,pole_x,pole_y);
	*redo = 0;
	}
}
else if(*redo == 1)
{
	if(glowa->next != NULL)
	{
		glowa = glowa->next;
	}
	do_redo(okno,plansza,pionki_biale,pionki_czarne,kolor_ruchu,glowa,redo,czy_undo,stan_wiez_krola);
	sprawdzenie_szachu(okno,plansza,czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
	*pole_x = glowa->pole_x;
	*pole_y = glowa->pole_y;
	szach_mat(okno,plansza,czy_szach,kolor_ruchu,pionki_czarne,pionki_biale,szach,pole_x,pole_y);
	*redo = 0;
}
draw_tips(okno,width,height,mozliwy_ruch);
draw_chess_pieces(okno,width,height,pos_x,pos_y,plansza,ev,event_queue,display,font36,kingw,queenw,rookw,bishopw,knightw,pawnw,kingb,queenb,rookb,bishopb,knightb,pawnb);
if(*fullscreen == 1)
{height = info.y2 - info.y1;
width = info.x2 - info.x1;}
else
{height = Wysokosc;
width = Szerokosc;}



}


	al_destroy_bitmap(kingw);
	al_destroy_bitmap(queenw);
	al_destroy_bitmap(rookw);
	al_destroy_bitmap(bishopw);
	al_destroy_bitmap(knightw);
	al_destroy_bitmap(pawnw);
	al_destroy_bitmap(kingb);
	al_destroy_bitmap(queenb);
	al_destroy_bitmap(rookb);
	al_destroy_bitmap(bishopb);
	al_destroy_bitmap(knightb);
	al_destroy_bitmap(pawnb);
	al_destroy_event_queue(event_queue);
	al_destroy_font(font36);
	al_destroy_display(display);
	
	if(done != NULL)
	delete(done);
	if(pos_x != NULL)
	delete(pos_x);
	if(pos_y != NULL)
	delete(pos_y);
	if(down != NULL)
	delete(down);
	if(fullscreen != NULL)
	delete(fullscreen);
	if(undo != NULL)
	delete(undo);
	if(redo != NULL)
	delete(redo);
	if(kolor != NULL)
	delete(kolor);
	if(szach != NULL)
	delete(szach);
	if(pole_y != NULL)
	delete(pole_y);
	if(pole_x != NULL)
	delete(pole_x);	
	if(glowa != NULL)
	delete(glowa);
	if(czy_lista != NULL)
	delete(czy_lista);
	if(koniec != NULL)
	delete(koniec);
	if(czy_undo != NULL)
	delete(czy_undo);
	if(komputer != NULL)
	delete(komputer);




	return 0;
}