#include "Funkcje.h"
#include "Szach.h"

void ruch(int *okno,int *pole_x, int *pole_y, int tmp_pole_x, int tmp_pole_y, int plansza[8][8], bool mozliwy_ruch[8][8], int pionki_biale[16][2], int pionki_czarne[16][2] ,bool *kolor_ruchu, bool stan_wiez_krola[6])
{
	if(*okno<10)
		return;
	if((*pole_x == -1) || (*pole_y == -1) || (tmp_pole_x == -1) || (tmp_pole_y == -1))
		return;
	if(mozliwy_ruch[*pole_x][*pole_y] == 0)
		return;


if((tmp_pole_y == 3) && (plansza[tmp_pole_x][tmp_pole_y] == 6) && (*pole_x == tmp_pole_x-1) && (plansza[tmp_pole_x-1][2] == 0) && (*pole_y == 2))
{
	plansza[*pole_x][2] = 6;
	plansza[*pole_x][3] = 0;
	plansza[tmp_pole_x][tmp_pole_y] = 0;
	for(int i=0;i<16;i++)
	{
			if((pionki_biale[i][0] == tmp_pole_x) && (pionki_biale[i][1] == tmp_pole_y))
			{
				pionki_biale[i][0] = *pole_x;
				pionki_biale[i][1] = *pole_y;
			}
			if((pionki_czarne[i][0] == *pole_x) && (pionki_czarne[i][1] == *pole_y+1))
			{
				pionki_czarne[i][0] = -1;
				pionki_czarne[i][1] = -1;
			}
	}

}
else if((tmp_pole_y == 3) && (plansza[tmp_pole_x][tmp_pole_y] == 6) && (*pole_x == tmp_pole_x+1) && (plansza[tmp_pole_x+1][2] == 0) && (*pole_y == 2))
{
	plansza[*pole_x][2] = 6;
	plansza[*pole_x][3] = 0;
	plansza[tmp_pole_x][tmp_pole_y] = 0;
	for(int i=0;i<16;i++)
	{
			if((pionki_biale[i][0] == tmp_pole_x) && (pionki_biale[i][1] == tmp_pole_y))
			{
				pionki_biale[i][0] = *pole_x;
				pionki_biale[i][1] = *pole_y;
			}
			if((pionki_czarne[i][0] == *pole_x) && (pionki_czarne[i][1] == *pole_y+1))
			{
				pionki_czarne[i][0] = -1;
				pionki_czarne[i][1] = -1;
			}
	}
}
else if((tmp_pole_y == 4) && (plansza[tmp_pole_x][tmp_pole_y] == 16) && (plansza[tmp_pole_x-1][2] == 0) && (*pole_y == 5) && (*pole_x == tmp_pole_x-1))
{
	plansza[*pole_x][5] = 16;
	plansza[*pole_x][4] = 0;
	plansza[tmp_pole_x][tmp_pole_y] = 0;
	for(int i=0;i<16;i++)
	{
		if((pionki_czarne[i][0] == tmp_pole_x) && (pionki_czarne[i][1] == tmp_pole_y))
		{
			pionki_czarne[i][0] = *pole_x;
			pionki_czarne[i][1] = *pole_y;
		}
		if((pionki_biale[i][0] == *pole_x) && (pionki_biale[i][1] == *pole_y-1))
		{
			pionki_biale[i][0] = -1;
			pionki_biale[i][1] = -1;
		}

	}

}
else if((tmp_pole_y == 4) && (plansza[tmp_pole_x][tmp_pole_y] == 16) && (plansza[tmp_pole_x+1][2] == 0) && (*pole_y == 5) && (*pole_x == tmp_pole_x+1))
{
	plansza[*pole_x][5] = 16;
	plansza[*pole_x][4] = 0;
	plansza[tmp_pole_x][tmp_pole_y] = 0;
	for(int i=0;i<16;i++)
	{
		if((pionki_czarne[i][0] == tmp_pole_x) && (pionki_czarne[i][1] == tmp_pole_y))
		{
			pionki_czarne[i][0] = *pole_x;
			pionki_czarne[i][1] = *pole_y;
		}
		if((pionki_biale[i][0] == *pole_x) && (pionki_biale[i][1] == *pole_y-1))
		{
			pionki_biale[i][0] = -1;
			pionki_biale[i][1] = -1;
		}

	}
}
else if((plansza[tmp_pole_x][tmp_pole_y] == 1) && (tmp_pole_x == 4) && (tmp_pole_y == 7) && ((*pole_x == 2) || (*pole_x == 6)))
{
	if((*pole_x == 2) && (*pole_y == 7) && (stan_wiez_krola[0] == 0) && (stan_wiez_krola[1] == 0))
	{
		stan_wiez_krola[0] = 1;
		stan_wiez_krola[1] = 1;
		pionki_biale[0][0] = 2;
		pionki_biale[0][1] = 7;
		pionki_biale[1][0] = 3;
		pionki_biale[1][1] = 7;

		plansza[2][7] = 1;
		plansza[3][7] = 3;
		plansza[0][7] = 0;
		plansza[4][7] = 0;
	}
	if((*pole_x == 6) && (*pole_y == 7) && (stan_wiez_krola[0] == 0) && (stan_wiez_krola[2] == 0))
	{
		stan_wiez_krola[0] = 1;
		stan_wiez_krola[2] = 1;
		pionki_biale[0][0] = 6;
		pionki_biale[0][1] = 7;
		pionki_biale[2][0] = 5;
		pionki_biale[2][1] = 7;


		plansza[6][7] = 1;
		plansza[5][7] = 3;
		plansza[7][7] = 0;
		plansza[4][7] = 0;
	}

}
else if((plansza[tmp_pole_x][tmp_pole_y] == 11) && (tmp_pole_x == 4) && (tmp_pole_y == 0) && ((*pole_x == 2) || (*pole_x == 6)))
{
	if((*pole_x == 2) && (*pole_y == 0) && (stan_wiez_krola[3] == 0) && (stan_wiez_krola[4] == 0))
	{
		stan_wiez_krola[3] = 1;
		stan_wiez_krola[4] = 1;
		pionki_czarne[0][0] = 2;
		pionki_czarne[0][1] = 0;
		pionki_czarne[1][0] = 3;
		pionki_czarne[1][1] = 0;


		plansza[2][0] = 11;
		plansza[3][0] = 13;
		plansza[0][0] = 0;
		plansza[4][0] = 0;
	}
	if((*pole_x == 6) && (*pole_y == 0) && (stan_wiez_krola[3] == 0) && (stan_wiez_krola[5] == 0))
	{
		stan_wiez_krola[3] = 1;
		stan_wiez_krola[5] = 1;
		pionki_czarne[0][0] = 6;
		pionki_czarne[0][1] = 0;
		pionki_czarne[2][0] = 5;
		pionki_czarne[2][1] = 0;


		plansza[6][0] = 11;
		plansza[5][0] = 13;
		plansza[7][0] = 0;
		plansza[4][0] = 0;
	}

}
else
{
	for(int i=0;i<16;i++)
	{
		if(*kolor_ruchu == 0)
		{
			if((pionki_biale[i][0] == tmp_pole_x) && (pionki_biale[i][1] == tmp_pole_y))
			{
				pionki_biale[i][0] = *pole_x;
				pionki_biale[i][1] = *pole_y;
			}
			if((pionki_czarne[i][0] == *pole_x) && (pionki_czarne[i][1] == *pole_y))
			{
				pionki_czarne[i][0] = -1;
				pionki_czarne[i][1] = -1;
			}

		}
		if(*kolor_ruchu == 1)
		{
			if((pionki_czarne[i][0] == tmp_pole_x) && (pionki_czarne[i][1] == tmp_pole_y))
			{
				pionki_czarne[i][0] = *pole_x;
				pionki_czarne[i][1] = *pole_y;
			}
			if((pionki_biale[i][0] == *pole_x) && (pionki_biale[i][1] == *pole_y))
			{
				pionki_biale[i][0] = -1;
				pionki_biale[i][1] = -1;
			}

		}
	}
	plansza[*pole_x][*pole_y] = plansza[tmp_pole_x][tmp_pole_y];
	plansza[tmp_pole_x][tmp_pole_y] = 0;

}


	if((tmp_pole_x == 4) && (tmp_pole_y == 7) && (stan_wiez_krola[0] == 0))
		stan_wiez_krola[0] = 1;

	if((tmp_pole_x == 0) && (tmp_pole_y == 7) && (stan_wiez_krola[1] == 0))
		stan_wiez_krola[1] = 1;

	if((tmp_pole_x == 7) && (tmp_pole_y == 7) && (stan_wiez_krola[2] == 0))
		stan_wiez_krola[2] = 1;

	if((tmp_pole_x == 4) && (tmp_pole_y == 0) && (stan_wiez_krola[3] == 0))
		stan_wiez_krola[3] = 1;

	if((tmp_pole_x == 0) && (tmp_pole_y == 0) && (stan_wiez_krola[4] == 0))
		stan_wiez_krola[4] = 1;

	if((tmp_pole_x == 7) && (tmp_pole_y == 0) && (stan_wiez_krola[5] == 0))
		stan_wiez_krola[5] = 1;

	*kolor_ruchu = !*kolor_ruchu;
	


	

}

void dostepne_ruchy(int *okno, bool *kolor_ruchu, int *szach, int *pole_x, int *pole_y, int plansza[8][8], bool mozliwy_ruch[8][8], int pionki_biale[16][2], int pionki_czarne[16][2], bool czy_szach[8][8], bool czyszczenie)
{
	if(*okno<10)
		return;

	if(czyszczenie == 1)
	{
	for(int i = 0; i<=7; i++)
	{for(int j = 0; j<=7; j++)
	mozliwy_ruch[i][j]=0;}
	}


	if((*pole_x == -1) || (*pole_y == -1))
		return;



	if(plansza[*pole_x][*pole_y] == 0)
		return;

	if((*kolor_ruchu == 0) && (plansza[*pole_x][*pole_y]>10))
		return;

	if((*kolor_ruchu == 1) && (plansza[*pole_x][*pole_y]<10))
		return;

	if(plansza[*pole_x][*pole_y] == 6)						//pion bialy <-------------------------------------------------------------------------------------------------------------------------------------------------
	{
		if(*szach == 0)
		{
			if(plansza[*pole_x][*pole_y-1] == 0)
			{
				if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 2) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					{
						if((*pole_y == 6) && plansza[*pole_x][*pole_y-2] == 0)
							mozliwy_ruch[*pole_x][*pole_y-2] = 1;
						mozliwy_ruch[*pole_x][*pole_y-1] = 1;
					}
			}
			if(*pole_x > 0)
			{
				if((plansza[*pole_x-1][*pole_y-1] > 10) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 1) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0)))
					mozliwy_ruch[*pole_x-1][*pole_y-1] = 1;
			}
			if(*pole_x < 7)
			{
				if((plansza[*pole_x+1][*pole_y-1] > 10) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 3) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0)))
					mozliwy_ruch[*pole_x+1][*pole_y-1] = 1;
			}
		return;
		}
		else if(*szach == 1)
		{
			if(plansza[*pole_x][*pole_y-1] == 0)
			{
				if((czy_szach[*pole_x][*pole_y-1] == 1) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 2)))
					mozliwy_ruch[*pole_x][*pole_y-1] = 1;
				if((czy_szach[*pole_x][*pole_y-2] == 1) && (*pole_y == 6) && (plansza[*pole_x][*pole_y-2] == 0) && (plansza[*pole_x][*pole_y-1] == 0) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 2)))
					mozliwy_ruch[*pole_x][*pole_y-2] = 1;
			}
			if(*pole_x > 0)
			{
				if((plansza[*pole_x-1][*pole_y-1] > 10) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 1) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0)) && (czy_szach[*pole_x-1][*pole_y-1] == 1))
					mozliwy_ruch[*pole_x-1][*pole_y-1] = 1;
			}
			if(*pole_x < 7)
			{
				if((plansza[*pole_x+1][*pole_y-1] > 10) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 3) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0)) && (czy_szach[*pole_x+1][*pole_y-1] == 1))
					mozliwy_ruch[*pole_x+1][*pole_y-1] = 1;
			}
		return;
		}
		else
		return;			//koniec bialy pion <------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	}
	if(plansza[*pole_x][*pole_y] == 5)		//konik <----------------------------------------------------------------------------------------------------------------------------------------------------------------------
	{
		if(*szach == 0)
		{
			if(czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0)
			{
				int x=*pole_x;
				int y=*pole_y;
				if((x-2>=0) && (y-1>=0) && ((plansza[x-2][y-1] == 0) || (plansza[x-2][y-1] > 10)) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x-2][y-1] = 1;
				if((x-1>=0) && (y-2>=0) && ((plansza[x-1][y-2] == 0) || (plansza[x-1][y-2] > 10)) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x-1][y-2] = 1;
				if((x+1<=7) && (y-2>=0) && ((plansza[x+1][y-2] == 0) || (plansza[x+1][y-2] > 10)) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x+1][y-2] = 1;
				if((x+2<=7) && (y-1>=0) && ((plansza[x+2][y-1] == 0) || (plansza[x+2][y-1] > 10)) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x+2][y-1] = 1;
				if((x+2<=7) && (y+1<=7) && ((plansza[x+2][y+1] == 0) || (plansza[x+2][y+1] > 10)) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x+2][y+1] = 1;
				if((x+1<=7) && (y+2<=7) && ((plansza[x+1][y+2] == 0) || (plansza[x+1][y+2] > 10)) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x+1][y+2] = 1;
				if((x-1>=0) && (y+2<=7) && ((plansza[x-1][y+2] == 0) || (plansza[x-1][y+2] > 10)) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x-1][y+2] = 1;
				if((x-2>=0) && (y+1<=7) && ((plansza[x-2][y+1] == 0) || (plansza[x-2][y+1] > 10)) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x-2][y+1] = 1;

			}
		return;
		}
		else if(*szach == 1)
		{
			if(czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0)
			{
				int x=*pole_x;
				int y=*pole_y;
				if((x-2>=0) && (y-1>=0) && ((plansza[x-2][y-1] == 0) || (plansza[x-2][y-1] > 10)) && (czy_szach[x-2][y-1] == 1) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x-2][y-1] = 1;
				if((x-1>=0) && (y-2>=0) && ((plansza[x-1][y-2] == 0) || (plansza[x-1][y-2] > 10)) && (czy_szach[x-1][y-2] == 1) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x-1][y-2] = 1;
				if((x+1<=7) && (y-2>=0) && ((plansza[x+1][y-2] == 0) || (plansza[x+1][y-2] > 10)) && (czy_szach[x+1][y-2] == 1) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x+1][y-2] = 1;
				if((x+2<=7) && (y-1>=0) && ((plansza[x+2][y-1] == 0) || (plansza[x+2][y-1] > 10)) && (czy_szach[x+2][y-1] == 1) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x+2][y-1] = 1;
				if((x+2<=7) && (y+1<=7) && ((plansza[x+2][y+1] == 0) || (plansza[x+2][y+1] > 10)) && (czy_szach[x+2][y+1] == 1) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x+2][y+1] = 1;
				if((x+1<=7) && (y+2<=7) && ((plansza[x+1][y+2] == 0) || (plansza[x+1][y+2] > 10)) && (czy_szach[x+1][y+2] == 1) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x+1][y+2] = 1;
				if((x-1>=0) && (y+2<=7) && ((plansza[x-1][y+2] == 0) || (plansza[x-1][y+2] > 10)) && (czy_szach[x-1][y+2] == 1) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x-1][y+2] = 1;
				if((x-2>=0) && (y+1<=7) && ((plansza[x-2][y+1] == 0) || (plansza[x-2][y+1] > 10)) && (czy_szach[x-2][y+1] == 1) && (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0))
					mozliwy_ruch[x-2][y+1] = 1;

			}
		return;
		}
		else
		return;		//koniec konik <---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	}
	if((plansza[*pole_x][*pole_y] == 4) || (plansza[*pole_x][*pole_y] == 2))	//goniec/hetman <--------------------------------------------------------------------------------------------------------------------------
	{
		if(*szach == 0)
		{
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 1))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x<7) && (y<7))
				{
					x++;
					y++;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
				x=*pole_x;
				y=*pole_y;
				while((x>0) && (y>0))
				{
					x--;
					y--;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 3))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x>0) && (y<7))
				{
					x--;
					y++;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
				x=*pole_x;
				y=*pole_y;
				while((x<7) && (y>0))
				{
					x++;
					y--;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 5))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x>0) && (y>0))
				{
					x--;
					y--;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}


				x=*pole_x;
				y=*pole_y;
				while((x<7) && (y<7))
				{
					x++;
					y++;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 7))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x<7) && (y>0))
				{
					x++;
					y--;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
				x=*pole_x;
				y=*pole_y;
				while((x>0) && (y<7))
				{
					x--;
					y++;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}

		}
		else if(*szach == 1)
		{
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 1))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x>0) && (y>0))
				{
					x--;
					y--;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						{if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;}
				}
			}
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 3))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x<7) && (y>0))
				{
					x++;
					y--;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 5))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x<7) && (y<7))
				{
					x++;
					y++;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 7))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x>0) && (y<7))
				{
					x--;
					y++;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}

		}

	}						//koniec goniec/hetman <-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


	if((plansza[*pole_x][*pole_y] == 3) || (plansza[*pole_x][*pole_y] == 2))		//wieza/hetman <-----------------------------------------------------------------------------------------------------------------------
	{
		if(*szach == 0)
		{
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 2))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(y<7)
				{
					y++;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}

				x=*pole_x;
				y=*pole_y;
				while(y>0)
				{
					y--;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 6))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(y>0)
				{
					y--;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}

				x=*pole_x;
				y=*pole_y;
				while(y<7)
				{
					y++;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 4))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(x>0)
				{
					x--;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}

				x=*pole_x;
				y=*pole_y;
				while(x<7)
				{
					x++;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 8))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(x<7)
				{
					x++;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}

				x=*pole_x;
				y=*pole_y;
				while(x>0)
				{
					x--;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
		return;
		}
		else if(*szach == 1)
		{
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 2))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(y>0)
				{
					y--;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 6))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(y<7)
				{
					y++;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 4))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(x<7)
				{
					x++;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 8))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(x>0)
				{
					x--;
					if((plansza[x][y] < 10) && (plansza[x][y] !=0))
						break;
					else if(plansza[x][y] > 10)
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}
		return;
		}
	}


	if(plansza[*pole_x][*pole_y] == 1)
	{
		int x=*pole_x;
		int y=*pole_y;

		if((x>0) && (y>0) && ((plansza[x-1][y-1] == 0) || (plansza[x-1][y-1] > 10)))
		{
				int pom_n = plansza[x-1][y-1];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_biale[0][0] = x-1;
				pionki_biale[0][1] = y-1;
				plansza[x-1][y-1] = 1;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x-1][y-1] = 1;	
				plansza[x-1][y-1] = pom_n;
				plansza[x][y] = 1;
				pionki_biale[0][0] = x;
				pionki_biale[0][1] = y;
				*szach = pom_szach;
		}
		if((y>0) && ((plansza[x][y-1] == 0) || (plansza[x][y-1] > 10)))
		{
				int pom_n = plansza[x][y-1];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_biale[0][0] = x;
				pionki_biale[0][1] = y-1;
				plansza[x][y-1] = 1;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x][y-1] = 1;	
				plansza[x][y-1] = pom_n;
				plansza[x][y] = 1;
				pionki_biale[0][0] = x;
				pionki_biale[0][1] = y;
				*szach = pom_szach;
		}
		if((x<7) && (y>0) && ((plansza[x+1][y-1] == 0) || (plansza[x+1][y-1] > 10)))
		{
				int pom_n = plansza[x+1][y-1];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_biale[0][0] = x+1;
				pionki_biale[0][1] = y-1;
				plansza[x+1][y-1] = 1;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x+1][y-1] = 1;	
				plansza[x+1][y-1] = pom_n;
				plansza[x][y] = 1;
				pionki_biale[0][0] = x;
				pionki_biale[0][1] = y;
				*szach = pom_szach;
		}
		if((x<7) && ((plansza[x+1][y] == 0) || (plansza[x+1][y] > 10)))
		{
				int pom_n = plansza[x+1][y];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_biale[0][0] = x+1;
				pionki_biale[0][1] = y;
				plansza[x+1][y] = 1;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x+1][y] = 1;	
				plansza[x+1][y] = pom_n;
				plansza[x][y] = 1;
				pionki_biale[0][0] = x;
				pionki_biale[0][1] = y;
				*szach = pom_szach;
		}
		if((x<7) && (y<7) && ((plansza[x+1][y+1] == 0) || (plansza[x+1][y+1] > 10)))
		{
				int pom_n = plansza[x+1][y+1];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_biale[0][0] = x+1;
				pionki_biale[0][1] = y+1;
				plansza[x+1][y+1] = 1;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x+1][y+1] = 1;	
				plansza[x+1][y+1] = pom_n;
				plansza[x][y] = 1;
				pionki_biale[0][0] = x;
				pionki_biale[0][1] = y;
				*szach = pom_szach;
		}
		if((y<7) && ((plansza[x][y+1] == 0) || (plansza[x][y+1] > 10)))
		{
				int pom_n = plansza[x][y+1];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_biale[0][0] = x;
				pionki_biale[0][1] = y+1;
				plansza[x][y+1] = 1;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x][y+1] = 1;	
				plansza[x][y+1] = pom_n;
				plansza[x][y] = 1;
				pionki_biale[0][0] = x;
				pionki_biale[0][1] = y;
				*szach = pom_szach;
		}
		if((x>0) && (y<7) && ((plansza[x-1][y+1] == 0) || (plansza[x-1][y+1] > 10)))
		{
				int pom_n = plansza[x-1][y+1];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_biale[0][0] = x-1;
				pionki_biale[0][1] = y+1;
				plansza[x-1][y+1] = 1;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x-1][y+1] = 1;	
				plansza[x-1][y+1] = pom_n;
				plansza[x][y] = 1;
				pionki_biale[0][0] = x;
				pionki_biale[0][1] = y;
				*szach = pom_szach;
		}
		if((x>0) && ((plansza[x-1][y] == 0) || (plansza[x-1][y] > 10)))
		{
				int pom_n = plansza[x-1][y];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_biale[0][0] = x-1;
				pionki_biale[0][1] = y;
				plansza[x-1][y] = 1;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x-1][y] = 1;	
				plansza[x-1][y] = pom_n;
				plansza[x][y] = 1;
				pionki_biale[0][0] = x;
				pionki_biale[0][1] = y;
				*szach = pom_szach;
		}
	}





















	if(plansza[*pole_x][*pole_y] == 16)						//pion czarny <-------------------------------------------------------------------------------------------------------------------------------------------------
	{
		if(*szach == 0)
		{
			if(plansza[*pole_x][*pole_y+1] == 0)
			{
				if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 6) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					{
						if((*pole_y == 1) && plansza[*pole_x][*pole_y+2] == 0)
							mozliwy_ruch[*pole_x][*pole_y+2] = 1;
						mozliwy_ruch[*pole_x][*pole_y+1] = 1;
					}
			}
			if(*pole_x > 0)
			{
				if((plansza[*pole_x-1][*pole_y+1] < 10) && (plansza[*pole_x-1][*pole_y+1] != 0) && ((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 7) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0)))
					mozliwy_ruch[*pole_x-1][*pole_y+1] = 1;
			}
			if(*pole_x < 7)
			{
				if((plansza[*pole_x+1][*pole_y+1] < 10) && (plansza[*pole_x+1][*pole_y+1] != 0) && ((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 5) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0)))
					mozliwy_ruch[*pole_x+1][*pole_y+1] = 1;
			}
		return;
		}
		else if(*szach == 1)
		{
			if(plansza[*pole_x][*pole_y+1] == 0)
			{
				if((czy_szach[*pole_x][*pole_y+1] == 1) && ((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 6)))
					mozliwy_ruch[*pole_x][*pole_y+1] = 1;
				if((czy_szach[*pole_x][*pole_y+2] == 1) && (*pole_y == 6) && (plansza[*pole_x][*pole_y+2] == 0) && (plansza[*pole_x][*pole_y+1] == 0) && ((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 6)))
					mozliwy_ruch[*pole_x][*pole_y+2] = 1;
			}
			if(*pole_x > 0)
			{
				if((plansza[*pole_x-1][*pole_y+1] < 10) && (plansza[*pole_x-1][*pole_y+1] != 0) && ((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 7) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0)) && (czy_szach[*pole_x-1][*pole_y+1] == 1))
					mozliwy_ruch[*pole_x-1][*pole_y+1] = 1;
			}
			if(*pole_x < 7)
			{
				if((plansza[*pole_x+1][*pole_y+1] < 10) && (plansza[*pole_x-1][*pole_y+1] != 0) && ((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 5) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0)) && (czy_szach[*pole_x+1][*pole_y+1] == 1))
					mozliwy_ruch[*pole_x+1][*pole_y+1] = 1;
			}
		return;
		}
		else
		return;			//koniec czarny pion <------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	}
	if(plansza[*pole_x][*pole_y] == 15)		//konik <----------------------------------------------------------------------------------------------------------------------------------------------------------------------
	{
		if(*szach == 0)
		{
			if(czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0)
			{
				int x=*pole_x;
				int y=*pole_y;
				if((x-2>=0) && (y-1>=0) && ((plansza[x-2][y-1] == 0) || (plansza[x-2][y-1] < 10)) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x-2][y-1] = 1;
				if((x-1>=0) && (y-2>=0) && ((plansza[x-1][y-2] == 0) || (plansza[x-1][y-2] < 10)) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x-1][y-2] = 1;
				if((x+1<=7) && (y-2>=0) && ((plansza[x+1][y-2] == 0) || (plansza[x+1][y-2] < 10)) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x+1][y-2] = 1;
				if((x+2<=7) && (y-1>=0) && ((plansza[x+2][y-1] == 0) || (plansza[x+2][y-1] < 10)) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x+2][y-1] = 1;
				if((x+2<=7) && (y+1<=7) && ((plansza[x+2][y+1] == 0) || (plansza[x+2][y+1] < 10)) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x+2][y+1] = 1;
				if((x+1<=7) && (y+2<=7) && ((plansza[x+1][y+2] == 0) || (plansza[x+1][y+2] < 10)) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x+1][y+2] = 1;
				if((x-1>=0) && (y+2<=7) && ((plansza[x-1][y+2] == 0) || (plansza[x-1][y+2] < 10)) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x-1][y+2] = 1;
				if((x-2>=0) && (y+1<=7) && ((plansza[x-2][y+1] == 0) || (plansza[x-2][y+1] < 10)) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x-2][y+1] = 1;

			}
		return;
		}
		else if(*szach == 1)
		{
			if(czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0)
			{
				int x=*pole_x;
				int y=*pole_y;
				if((x-2>=0) && (y-1>=0) && ((plansza[x-2][y-1] == 0) || (plansza[x-2][y-1] < 10)) && (czy_szach[x-2][y-1] == 1) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x-2][y-1] = 1;
				if((x-1>=0) && (y-2>=0) && ((plansza[x-1][y-2] == 0) || (plansza[x-1][y-2] < 10)) && (czy_szach[x-1][y-2] == 1) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x-1][y-2] = 1;
				if((x+1<=7) && (y-2>=0) && ((plansza[x+1][y-2] == 0) || (plansza[x+1][y-2] < 10)) && (czy_szach[x+1][y-2] == 1) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x+1][y-2] = 1;
				if((x+2<=7) && (y-1>=0) && ((plansza[x+2][y-1] == 0) || (plansza[x+2][y-1] < 10)) && (czy_szach[x+2][y-1] == 1) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x+2][y-1] = 1;
				if((x+2<=7) && (y+1<=7) && ((plansza[x+2][y+1] == 0) || (plansza[x+2][y+1] < 10)) && (czy_szach[x+2][y+1] == 1) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x+2][y+1] = 1;
				if((x+1<=7) && (y+2<=7) && ((plansza[x+1][y+2] == 0) || (plansza[x+1][y+2] < 10)) && (czy_szach[x+1][y+2] == 1) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x+1][y+2] = 1;
				if((x-1>=0) && (y+2<=7) && ((plansza[x-1][y+2] == 0) || (plansza[x-1][y+2] < 10)) && (czy_szach[x-1][y+2] == 1) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x-1][y+2] = 1;
				if((x-2>=0) && (y+1<=7) && ((plansza[x-2][y+1] == 0) || (plansza[x-2][y+1] < 10)) && (czy_szach[x-2][y+1] == 1) && (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0))
					mozliwy_ruch[x-2][y+1] = 1;

			}
		return;
		}
		else
		return;		//koniec konik <---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	}
	if((plansza[*pole_x][*pole_y] == 14) || (plansza[*pole_x][*pole_y] == 12))	//goniec/hetman <--------------------------------------------------------------------------------------------------------------------------
	{
		if(*szach == 0)
		{
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 1))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x<7) && (y<7))
				{
					x++;
					y++;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}

				x=*pole_x;
				y=*pole_y;
				while((x>0) && (y>0))
				{
					x--;
					y--;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 3))
			{
				int x=*pole_x;
				int y=*pole_y;
					while((x>0) && (y<7))
				{
					x--;
					y++;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}

				x=*pole_x;
				y=*pole_y;
				while((x<7) && (y>0))
				{
					x++;
					y--;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 5))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x>0) && (y>0))
				{
					x--;
					y--;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}

				x=*pole_x;
				y=*pole_y;
				while((x<7) && (y<7))
				{
					x++;
					y++;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 7))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x<7) && (y>0))
				{
					x++;
					y--;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}

				x=*pole_x;
				y=*pole_y;
				while((x>0) && (y<7))
				{
					x--;
					y++;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}

		}
		else if(*szach == 1)
		{
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 1))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x>0) && (y>0))
				{
					x--;
					y--;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						{if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;}
				}
			}
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 3))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x<7) && (y>0))
				{
					x++;
					y--;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 5))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x<7) && (y<7))
				{
					x++;
					y++;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 7))
			{
				int x=*pole_x;
				int y=*pole_y;
				while((x>0) && (y<7))
				{
					x--;
					y++;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}

		}

	}						//koniec goniec/hetman <-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


	if((plansza[*pole_x][*pole_y] == 13) || (plansza[*pole_x][*pole_y] == 12))		//wieza/hetman <-----------------------------------------------------------------------------------------------------------------------
	{
		if(*szach == 0)
		{
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 2))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(y<7)
				{
					y++;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}

				x=*pole_x;
				y=*pole_y;
				while(y>0)
				{
					y--;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 6))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(y>0)
				{
					y--;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}

				x=*pole_x;
				y=*pole_y;
				while(y<7)
				{
					y++;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 4))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(x>0)
				{
					x--;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}

				x=*pole_x;
				y=*pole_y;
				while(x<7)
				{
					x++;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 8))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(x<7)
				{
					x++;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}

				x=*pole_x;
				y=*pole_y;
				while(x>0)
				{
					x--;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else
						mozliwy_ruch[x][y] = 1;
				}
			}
		return;
		}
		else if(*szach == 1)
		{
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 2))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(y>0)
				{
					y--;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 6))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(y<7)
				{
					y++;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 4))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(x<7)
				{
					x++;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}
			if((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 8))
			{
				int x=*pole_x;
				int y=*pole_y;
				while(x>0)
				{
					x--;
					if(plansza[x][y] > 10)
						break;
					else if((plansza[x][y] < 10) && (plansza[x][y] !=0))
					{
						if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
						break;
					}
					else if(czy_szach[x][y] == 1)
						mozliwy_ruch[x][y] = 1;
				}
			}
		return;
		}
	
	}


		if(plansza[*pole_x][*pole_y] == 11)
	{
		int x=*pole_x;
		int y=*pole_y;
		

		if((x>0) && (y>0) && ((plansza[x-1][y-1] == 0) || (plansza[x-1][y-1] < 10)))
		{
				int pom_n = plansza[x-1][y-1];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_czarne[0][0] = x-1;
				pionki_czarne[0][1] = y-1;
				plansza[x-1][y-1] = 11;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x-1][y-1] = 1;	
				plansza[x-1][y-1] = pom_n;
				plansza[x][y] = 11;
				pionki_czarne[0][0] = x;
				pionki_czarne[0][1] = y;
				*szach = pom_szach;
		}
		if((y>0) && ((plansza[x][y-1] == 0) || (plansza[x][y-1] < 10)))
		{
				int pom_n = plansza[x][y-1];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_czarne[0][0] = x;
				pionki_czarne[0][1] = y-1;
				plansza[x][y-1] = 11;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x][y-1] = 1;	
				plansza[x][y-1] = pom_n;
				plansza[x][y] = 11;
				pionki_czarne[0][0] = x;
				pionki_czarne[0][1] = y;
				*szach = pom_szach;
		}
		if((x<7) && (y>0) && ((plansza[x+1][y-1] == 0) || (plansza[x+1][y-1] < 10)))
		{
				int pom_n = plansza[x+1][y-1];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_czarne[0][0] = x+1;
				pionki_czarne[0][1] = y-1;
				plansza[x+1][y-1] = 11;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x+1][y-1] = 1;	
				plansza[x+1][y-1] = pom_n;
				plansza[x][y] = 11;
				pionki_czarne[0][0] = x;
				pionki_czarne[0][1] = y;
				*szach = pom_szach;
		}
		if((x<7) && ((plansza[x+1][y] == 0) || (plansza[x+1][y] < 10)))
		{
				int pom_n = plansza[x+1][y];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_czarne[0][0] = x+1;
				pionki_czarne[0][1] = y;
				plansza[x+1][y] = 11;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x+1][y] = 1;	
				plansza[x+1][y] = pom_n;
				plansza[x][y] = 11;
				pionki_czarne[0][0] = x;
				pionki_czarne[0][1] = y;
				*szach = pom_szach;
		}
		if((x<7) && (y<7) && ((plansza[x+1][y+1] == 0) || (plansza[x+1][y+1] < 10)))
		{
				int pom_n = plansza[x+1][y+1];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_czarne[0][0] = x+1;
				pionki_czarne[0][1] = y+1;
				plansza[x+1][y+1] = 11;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x+1][y+1] = 1;	
				plansza[x+1][y+1] = pom_n;
				plansza[x][y] = 11;
				pionki_czarne[0][0] = x;
				pionki_czarne[0][1] = y;
				*szach = pom_szach;
		}
		if((y<7) && ((plansza[x][y+1] == 0) || (plansza[x][y+1] < 10)))
		{
				int pom_n = plansza[x][y+1];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_czarne[0][0] = x;
				pionki_czarne[0][1] = y+1;
				plansza[x][y+1] = 11;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x][y+1] = 1;	
				plansza[x][y+1] = pom_n;
				plansza[x][y] = 11;
				pionki_czarne[0][0] = x;
				pionki_czarne[0][1] = y;
				*szach = pom_szach;
		}
		if((x>0) && (y<7) && ((plansza[x-1][y+1] == 0) || (plansza[x-1][y+1] < 10)))
		{
				int pom_n = plansza[x-1][y+1];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_czarne[0][0] = x-1;
				pionki_czarne[0][1] = y+1;
				plansza[x-1][y+1] = 11;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x-1][y+1] = 1;	
				plansza[x-1][y+1] = pom_n;
				plansza[x][y] = 11;
				pionki_czarne[0][0] = x;
				pionki_czarne[0][1] = y;
				*szach = pom_szach;
		}
		if((x>0) && ((plansza[x-1][y] == 0) || (plansza[x-1][y] < 10)))
		{
				int pom_n = plansza[x-1][y];
				int pom_szach = *szach;
				bool pom_czy_szach[8][8];
				for(int i = 0; i<=7; i++)
				{
					for(int j=0;j<=7;j++)
						pom_czy_szach[i][j] = 0;
				}
				plansza[x][y] = 0;
				pionki_czarne[0][0] = x-1;
				pionki_czarne[0][1] = y;
				plansza[x-1][y] = 11;
				plansza[x][y] = 0;
				sprawdzenie_szachu(okno,plansza,pom_czy_szach,pionki_czarne,pionki_biale,kolor_ruchu,szach);
				if(*szach == 0)
					mozliwy_ruch[x-1][y] = 1;	
				plansza[x-1][y] = pom_n;
				plansza[x][y] = 11;
				pionki_czarne[0][0] = x;
				pionki_czarne[0][1] = y;
				*szach = pom_szach;
		}
	}
}

void roszada(int *okno, bool *kolor_ruchu, int *szach, int *pole_x, int *pole_y, int plansza[8][8], bool mozliwy_ruch[8][8], int pionki_biale[16][2], int pionki_czarne[16][2], bool czy_szach[8][8], bool stan_wiez_krola[6])
{
	if(*okno<10)
		return;
	
	if(*szach>0)
		return;

	if(*pole_x != 4)
		return;

	if((*kolor_ruchu == 0) && ((*pole_y != 7) || (plansza[*pole_x][*pole_y] != 1) || (stan_wiez_krola[0] != 0)))
		return;

	if((*kolor_ruchu == 1) && ((*pole_y != 0) || (plansza[*pole_x][*pole_y] != 11) || (stan_wiez_krola[3] != 0)))
		return;

	bool tablica_pom[8][8];

	int x,y;


	if(*pole_y == 7)
	{
		x = pionki_czarne[0][0];
		pionki_czarne[0][0] = 100;
		y = pionki_czarne[0][1];
		pionki_czarne[0][1] = -1;

		if((stan_wiez_krola[1] == 0) && (plansza[1][7] == 0) && (plansza[2][7] == 0) && (plansza[3][7] == 0))
		{
			for(int i=0;i<=7;i++)
			{
				for(int j=0;j<=7;j++)
					tablica_pom[i][j] = 0;
			}

			*kolor_ruchu = 1;
			for(int i = 0; i<=15; i++)
			{
				*pole_x = pionki_czarne[i][0];
				*pole_y = pionki_czarne[i][1];
				dostepne_ruchy(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,tablica_pom,pionki_biale,pionki_czarne,czy_szach,0);
			}

			if((tablica_pom[3][7] == 0) && (tablica_pom[2][7] == 0))
				mozliwy_ruch[2][7] = 1;

		}
		else if((stan_wiez_krola[2] == 0) && (plansza[6][7] == 0) && (plansza[5][7] == 0))
		{
			for(int i=0;i<=7;i++)
			{
				for(int j=0;j<=7;j++)
					tablica_pom[i][j] = 0;
			}

			*kolor_ruchu = 1;
			for(int i = 0; i<=15; i++)
			{
				*pole_x = pionki_czarne[i][0];
				*pole_y = pionki_czarne[i][1];
				dostepne_ruchy(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,tablica_pom,pionki_biale,pionki_czarne,czy_szach,0);
			}

			if((tablica_pom[5][7] == 0) && (tablica_pom[6][7] == 0))
				mozliwy_ruch[6][7] = 1;

		}
		*pole_y = 7;
		*pole_x = 4;
		*szach = 0;
		*kolor_ruchu = 0;
		pionki_czarne[0][0] = x;
		pionki_czarne[0][1] = y;
	}
	else if(*pole_y == 0)
	{
		x = pionki_biale[0][0];
		pionki_biale[0][0] = 100;
		y = pionki_biale[0][1];
		pionki_biale[0][1] = -1;

		if((stan_wiez_krola[4] == 0) && (plansza[1][0] == 0) && (plansza[2][0] == 0) && (plansza[3][0] == 0))
		{
			for(int i=0;i<=7;i++)
			{
				for(int j=0;j<=7;j++)
					tablica_pom[i][j] = 0;
			}

			*kolor_ruchu = 0;
			for(int i = 0; i<=15; i++)
			{
				*pole_x = pionki_biale[i][0];
				*pole_y = pionki_biale[i][1];
				dostepne_ruchy(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,tablica_pom,pionki_biale,pionki_czarne,czy_szach,0);
			}

			if((tablica_pom[3][0] == 0) && (tablica_pom[2][0] == 0))
				mozliwy_ruch[2][0] = 1;

		}
		else if((stan_wiez_krola[5] == 0) && (plansza[6][0] == 0) && (plansza[5][0] == 0))
		{
			for(int i=0;i<=7;i++)
			{
				for(int j=0;j<=7;j++)
					tablica_pom[i][j] = 0;
			}

			*kolor_ruchu = 0;
			for(int i = 0; i<=15; i++)
			{
				*pole_x = pionki_biale[i][0];
				*pole_y = pionki_biale[i][1];
				dostepne_ruchy(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,tablica_pom,pionki_biale,pionki_czarne,czy_szach,0);
			}

			if((tablica_pom[5][0] == 0) && (tablica_pom[6][0] == 0))
				mozliwy_ruch[6][0] = 1;

		}
		*pole_y = 0;
		*pole_x = 4;
		*szach = 0;
		*kolor_ruchu = 1;
		pionki_biale[0][0] = x;
		pionki_biale[0][1] = y;
	}
}

void bicie_w_przelocie(int *okno, bool *kolor_ruchu, int *szach, int *pole_x, int *pole_y, int plansza[8][8], bool mozliwy_ruch[8][8], int pionki_biale[16][2], int pionki_czarne[16][2], bool czy_szach[8][8], lista *glowa)
{
	if(*okno<10)
		return;
	
	if((*pole_y != 4) && (*pole_y != 3))
		return;

	if((*kolor_ruchu == 0) && (plansza[*pole_x][*pole_y] != 6))
		return;

	if((*kolor_ruchu == 1) && (plansza[*pole_x][*pole_y] != 16))
		return;

	if((*pole_y == 3) && (plansza[*pole_x][*pole_y] == 6))
	{
		if(*szach == 0)
		{
			if((*pole_x>0) && (plansza[*pole_x-1][*pole_y] == 16))
			{
				if((glowa->pole_x == *pole_x-1) && (glowa->pole_y == 3) && (glowa->prev_pole_x == *pole_x-1) && (glowa->prev_pole_y == 1) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 1) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 5) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0)))
					{
						mozliwy_ruch[*pole_x-1][2] = 1;
						return;
					}

			}
			if((*pole_x<7) && (plansza[*pole_x+1][*pole_y] == 16))
			{
				if((glowa->pole_x == *pole_x+1) && (glowa->pole_y == 3) && (glowa->prev_pole_x == *pole_x+1) && (glowa->prev_pole_y == 1) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 3) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 7) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0)))
					{
						mozliwy_ruch[*pole_x+1][2] = 1;
						return;
					}
			}
		}
		else if(*szach == 1)
		{
			if((*pole_x>0) && (plansza[*pole_x-1][*pole_y] == 16) && (czy_szach[*pole_x-1][2] == 1))
			{
				if((glowa->pole_x == *pole_x-1) && (glowa->pole_y == 3) && (glowa->prev_pole_x == *pole_x-1) && (glowa->prev_pole_y == 1) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 1) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 5) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0)))
					{
						mozliwy_ruch[*pole_x-1][2] = 1;
						return;
					}

			}
			if((*pole_x<7) && (plansza[*pole_x+1][*pole_y] == 16) && (czy_szach[*pole_x+1][2] == 1))
			{
				if((glowa->pole_x == *pole_x+1) && (glowa->pole_y == 3) && (glowa->prev_pole_x == *pole_x+1) && (glowa->prev_pole_y == 1) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 3) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 7) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0)))
					{
						mozliwy_ruch[*pole_x+1][2] = 1;
						return;
					}
			}
		}
		return;
	}
	else if((*pole_y == 4) && (plansza[*pole_x][*pole_y] == 16))
	{
		if(*szach == 0)
		{
			if((*pole_x>0) && (plansza[*pole_x-1][*pole_y] == 6))
			{
				if((glowa->pole_x == *pole_x-1) && (glowa->pole_y == 4) && (glowa->prev_pole_x == *pole_x-1) && (glowa->prev_pole_y == 6) && ((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 3) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 7) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0)))
					{
						mozliwy_ruch[*pole_x-1][5] = 1;
						return;
					}

			}
			if((*pole_x<7) && (plansza[*pole_x+1][*pole_y] == 6))
			{
				if((glowa->pole_x == *pole_x+1) && (glowa->pole_y == 4) && (glowa->prev_pole_x == *pole_x+1) && (glowa->prev_pole_y == 6) && ((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 1) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 5) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0)))
					{
						mozliwy_ruch[*pole_x+1][5] = 1;
						return;
					}
			}
		}
		else if(*szach == 1)
		{
			if((*pole_x>0) && (plansza[*pole_x-1][*pole_y] == 6) && (czy_szach[*pole_x-1][5] == 1))
			{
				if((glowa->pole_x == *pole_x-1) && (glowa->pole_y == 4) && (glowa->prev_pole_x == *pole_x-1) && (glowa->prev_pole_y == 6) && ((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 3) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 7) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0)))
					{
						mozliwy_ruch[*pole_x-1][5] = 1;
						return;
					}

			}
			if((*pole_x<7) && (plansza[*pole_x+1][*pole_y] == 6) && (czy_szach[*pole_x+1][5] == 1))
			{
				if((glowa->pole_x == *pole_x+1) && (glowa->pole_y == 4) && (glowa->prev_pole_x == *pole_x+1) && (glowa->prev_pole_y == 6) && ((czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 1) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 5) || (czy_moge_czarne(pole_x,pole_y,plansza,pionki_czarne) == 0)))
					{
						mozliwy_ruch[*pole_x+1][5] = 1;
						return;
					}
			}
		}

	}

}

void komp(int *okno, int *komputer, bool *kolor_ruchu, int *pole_x, int *pole_y, int *szach, int plansza[8][8], bool czy_szach[8][8], bool mozliwy_ruch[8][8], int pionki_biale[16][2], int pionki_czarne[16][2], bool stan_wiez_krola[6], lista *glowa)
{
	if(*okno<10)
		return;
	if(((*komputer == 2) && (*kolor_ruchu == 0)) || ((*komputer == 1) && (*kolor_ruchu == 1)))
		return;
	if(*komputer<1)
		return;
	if((*pole_x == -1) || (*pole_y == -1))
		return;

	dostepne_ruchy(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,mozliwy_ruch,pionki_biale,pionki_czarne,czy_szach,1);
	bicie_w_przelocie(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,mozliwy_ruch,pionki_biale,pionki_czarne,czy_szach,glowa);
	roszada(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,mozliwy_ruch,pionki_biale,pionki_czarne,czy_szach,stan_wiez_krola);
	if(*kolor_ruchu == 0)
	{
		for(int i = 0; i<=7; i++)
				{
					for(int j = 0; j<=7; j++)
					{
						if(mozliwy_ruch[i][j] == 1)
						{
							*pole_x = i;
							*pole_y = j;
							return;
						}
					}
				}
	}
	else
	{
		for(int i = 7; i>=0; i--)
				{
					for(int j = 7; j>=0; j--)
					{
						if(mozliwy_ruch[i][j] == 1)
						{
							*pole_x = i;
							*pole_y = j;
							return;
						}
					}
				}
	}
	


}
	/*if(plansza[*pole_x][*pole_y] == 6)
		{
			dostepne_ruchy(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,mozliwy_ruch,pionki_biale,pionki_czarne,czy_szach,1);
			bicie_w_przelocie(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,mozliwy_ruch,pionki_biale,pionki_czarne,czy_szach,glowa);
			if(*szach == 0)
			{
				if((mozliwy_ruch[*pole_x-1][*pole_y-1] == 1) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 1)))
				{
					*pole_x = *pole_x-1;
					*pole_y = *pole_y-1;
					return;
				}
				if((mozliwy_ruch[*pole_x+1][*pole_y-1] == 1) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 3)))
				{
					*pole_x = *pole_x+1;
					*pole_y = *pole_y-1;
					return;
				}
				if((mozliwy_ruch[*pole_x][*pole_y-2] == 1) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 2)))				{
					*pole_x = *pole_x;
					*pole_y = *pole_y-2;
					return;
				}
				if((mozliwy_ruch[*pole_x][*pole_y-1] == 1) && ((czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 0) || (czy_moge_biale(pole_x,pole_y,plansza,pionki_biale) == 2)))
				{
					*pole_x = *pole_x;
					*pole_y = *pole_y-1;
					return;
				}
			}
		}
	if((*szach == 1) || (*szach == 2))
	{
		if(*szach == 1)
		{
			dostepne_ruchy(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,mozliwy_ruch,pionki_biale,pionki_czarne,czy_szach,1);
			bicie_w_przelocie(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,mozliwy_ruch,pionki_biale,pionki_czarne,czy_szach,glowa);
			for(int i = 0; i<=7; i++)
			{
				for(int j = 0; j<=7; j++)
				{
					if((czy_szach[i][j] == 1) && (mozliwy_ruch[i][j] == 1))
					{
						*pole_x = i;
						*pole_y = j;
						return;
					}
				}
			}
		}
		if((plansza[*pole_x][*pole_y] == 1) || (plansza[*pole_x][*pole_y] == 11))
		{
			if(mozliwy_ruch[*pole_x-1][*pole_y-1] == 1)
			{
				*pole_x = *pole_x - 1;
				*pole_x = *pole_y - 1;
				return;
			}
			if(mozliwy_ruch[*pole_x][*pole_y-1] == 1)
			{
				*pole_x = *pole_x;
				*pole_x = *pole_y - 1;
				return;
			}
			if(mozliwy_ruch[*pole_x + 1][*pole_y-1] == 1)
			{
				*pole_x = *pole_x + 1;
				*pole_x = *pole_y - 1;
				return;
			}
			if(mozliwy_ruch[*pole_x + 1][*pole_y] == 1)
			{
				*pole_x = *pole_x + 1;
				*pole_x = *pole_y;
				return;
			}
			if(mozliwy_ruch[*pole_x + 1][*pole_y + 1] == 1)
			{
				*pole_x = *pole_x + 1;
				*pole_x = *pole_y + 1;
				return;
			}
			if(mozliwy_ruch[*pole_x][*pole_y + 1] == 1)
			{
				*pole_x = *pole_x;
				*pole_x = *pole_y + 1;
				return;
			}
			if(mozliwy_ruch[*pole_x-1][*pole_y+1] == 1)
			{
				*pole_x = *pole_x - 1;
				*pole_x = *pole_y + 1;
				return;
			}
			if(mozliwy_ruch[*pole_x-1][*pole_y] == 1)
			{
				*pole_x = *pole_x - 1;
				*pole_x = *pole_y;
				return;
			}
		}

	}
	return;


}*/

