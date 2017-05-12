#include <stdio.h>
#include "Listy.h"

void sprawy_z_lista(int *okno, int *pole_x, int *pole_y, int tmp_pole_x, int tmp_pole_y, int plansza[8][8], bool mozliwy_ruch[8][8], lista *glowa, bool stan_wiez_krola[6], bool *czy_lista)
{
	if(*okno<10)
		return;
	if((*pole_x == -1) || (*pole_y == -1) || (tmp_pole_x == -1) || (tmp_pole_y == -1))
		return;
	if(mozliwy_ruch[*pole_x][*pole_y] == 0)
		return;


	bool zmiana = 0;

	if((tmp_pole_x < 7) && (tmp_pole_y == 3) && (plansza[tmp_pole_x][3] == 6) && (plansza[tmp_pole_x+1][2] == 0) && (*pole_x == tmp_pole_x+1) && (*pole_y == 2))
		zmiana = 1;

	if((tmp_pole_x > 0) && (tmp_pole_y == 3) && (plansza[tmp_pole_x][3] == 6) && (plansza[tmp_pole_x-1][2] == 0) && (*pole_x == tmp_pole_x-1) && (*pole_y == 2))
		zmiana = 1;

	if((tmp_pole_x < 7) && (tmp_pole_y == 4) && (plansza[tmp_pole_x][4] == 16) && (plansza[tmp_pole_x+1][5] == 0) && (*pole_x == tmp_pole_x+1) && (*pole_y == 5))
		zmiana = 1;

	if((tmp_pole_x > 0) && (tmp_pole_y == 4) && (plansza[tmp_pole_x][4] == 16) && (plansza[tmp_pole_x-1][5] == 0) && (*pole_x == tmp_pole_x-1) && (*pole_y == 5))
		zmiana = 1;

	if((tmp_pole_x == 4) && (tmp_pole_y == 7) && (plansza[4][7] == 1) && (stan_wiez_krola[0] == 0))
		zmiana = 1;

	if((tmp_pole_x == 0) && (tmp_pole_y == 7) && (plansza[0][7] == 3) && (stan_wiez_krola[1] == 0))
		zmiana = 1;

	if((tmp_pole_x == 7) && (tmp_pole_y == 7) && (plansza[7][7] == 3) && (stan_wiez_krola[2] == 0))
		zmiana = 1;

	if((tmp_pole_x == 4) && (tmp_pole_y == 0) && (plansza[4][0] == 11) && (stan_wiez_krola[3] == 0))
		zmiana = 1;

	if((tmp_pole_x == 0) && (tmp_pole_y == 0) && (plansza[0][0] == 13) && (stan_wiez_krola[4] == 0))
		zmiana = 1;

	if((tmp_pole_x == 7) && (tmp_pole_y == 0) && (plansza[7][0] == 13) && (stan_wiez_krola[5] == 0))
		zmiana = 1;

	if((plansza[tmp_pole_x][tmp_pole_y] == 6) && (tmp_pole_y == 1) && (*pole_y == 0))
		zmiana = 1;

	if((plansza[tmp_pole_x][tmp_pole_y] == 16) && (tmp_pole_y == 6) && (*pole_y == 7))
		zmiana = 1;



		lista *tmp;
		tmp = new lista;
		tmp->prev = glowa;
		tmp->next = NULL;
		tmp->pole_x = *pole_x;
		tmp->pole_y = *pole_y;
		tmp->prev_pole_x = tmp_pole_x;
		tmp->prev_pole_y = tmp_pole_y;
		tmp->zbity = plansza[*pole_x][*pole_y];
		tmp->zmiana_stanu = zmiana;
		glowa->next = tmp;

	*czy_lista = 1;
}

void do_undo(int *okno, int plansza[8][8], int pionki_biale[16][2], int pionki_czarne[16][2], bool *kolor_ruchu, lista *glowa, bool *undo, bool *koniec, bool stan_wiez_krola[6])
{
	
	if(*okno<10)
		return;
	if(*undo == 0)
		return;
	if(glowa->pole_x == -1)
		return;
	if((glowa->prev == NULL) && (*koniec == 1))
		return;
	if(glowa->prev == NULL)
		*koniec = 1;
	else
		*koniec = 0;

	if(glowa->zmiana_stanu == 1)
	{
		if((glowa->prev_pole_y == 3) && (glowa->pole_y == 2) && (glowa->pole_x == glowa->prev_pole_x-1) && (plansza[glowa->pole_x][2] == 6))
		{
			plansza[glowa->pole_x][3] = 16;
			plansza[glowa->prev_pole_x][3] = 6;
			plansza[glowa->pole_x][2] = 0;

			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == glowa->pole_x) && (pionki_biale[i][1] == glowa->pole_y))
				{
					pionki_biale[i][0] = glowa->prev_pole_x;
					pionki_biale[i][1] = glowa->prev_pole_y;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == -1) && (pionki_czarne[i][1] == -1))
				{
					pionki_czarne[i][0] = glowa->pole_x;
					pionki_czarne[i][1] = glowa->pole_y+1;
					break;
				}
			}
	
		}
		else if((glowa->prev_pole_y == 3) && (glowa->pole_y == 2) && (glowa->pole_x == glowa->prev_pole_x+1) && (plansza[glowa->pole_x][2] == 6))
		{
			plansza[glowa->pole_x][3] = 16;
			plansza[glowa->prev_pole_x][3] = 6;
			plansza[glowa->pole_x][2] = 0;

			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == glowa->pole_x) && (pionki_biale[i][1] == glowa->pole_y))
				{
					pionki_biale[i][0] = glowa->prev_pole_x;
					pionki_biale[i][1] = glowa->prev_pole_y;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == -1) && (pionki_czarne[i][1] == -1))
				{
					pionki_czarne[i][0] = glowa->pole_x;
					pionki_czarne[i][1] = glowa->pole_y+1;
					break;
				}
			}

		}
		else if((glowa->prev_pole_y == 4) && (glowa->pole_y == 5) && (glowa->pole_x == glowa->prev_pole_x-1) && (plansza[glowa->pole_x][5] == 16))
		{
			plansza[glowa->pole_x][4] = 6;
			plansza[glowa->prev_pole_x][4] = 16;
			plansza[glowa->pole_x][5] = 0;

			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == -1) && (pionki_biale[i][1] == -1))
				{
					pionki_biale[i][0] = glowa->pole_x;
					pionki_biale[i][1] = glowa->pole_y-1;
					break;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == glowa->pole_x) && (pionki_czarne[i][1] == glowa->pole_y))
				{
					pionki_czarne[i][0] = glowa->prev_pole_x;
					pionki_czarne[i][1] = glowa->prev_pole_y;

				}
			}

		}
		else if((glowa->prev_pole_y == 4) && (glowa->pole_y == 5) && (glowa->pole_x == glowa->prev_pole_x+1) && (plansza[glowa->pole_x][5] == 16))
		{
			plansza[glowa->pole_x][4] = 6;
			plansza[glowa->prev_pole_x][4] = 16;
			plansza[glowa->pole_x][5] = 0;
			
			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == -1) && (pionki_biale[i][1] == -1))
				{
					pionki_biale[i][0] = glowa->pole_x;
					pionki_biale[i][1] = glowa->pole_y-1;
					break;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == glowa->pole_x) && (pionki_czarne[i][1] == glowa->pole_y))
				{
					pionki_czarne[i][0] = glowa->prev_pole_x;
					pionki_czarne[i][1] = glowa->prev_pole_y;

				}
			}

		}
		

		else if((glowa->prev_pole_x == 4) && (glowa->prev_pole_y == 7) && (glowa->pole_x == 2) && (glowa->pole_y == 7) && (plansza[2][7] == 1))
		{
			plansza[0][7] = 3;
			plansza[4][7] = 1;
			plansza[2][7] = 0;
			plansza[3][7] = 0;
			stan_wiez_krola[0] = 0;
			stan_wiez_krola[1] = 0;
			pionki_biale[0][0] = 4;
			pionki_biale[0][1] = 7;
			pionki_biale[1][0] = 0;
			pionki_biale[1][1] = 7;
		}
		else if((glowa->prev_pole_x == 4) && (glowa->prev_pole_y == 7) && (glowa->pole_x == 6) && (glowa->pole_y == 7) && (plansza[6][7] == 1))
		{
			plansza[7][7] = 3;
			plansza[4][7] = 1;
			plansza[6][7] = 0;
			plansza[5][7] = 0;
			stan_wiez_krola[0] = 0;
			stan_wiez_krola[2] = 0;
			pionki_biale[0][0] = 4;
			pionki_biale[0][1] = 7;
			pionki_biale[2][0] = 7;
			pionki_biale[2][1] = 7;
		}
		else if((glowa->prev_pole_x == 4) && (glowa->prev_pole_y == 0) && (glowa->pole_x == 2) && (glowa->pole_y == 0) && (plansza[2][0] == 11))
		{
			plansza[0][0] = 13;
			plansza[4][0] = 11;
			plansza[2][0] = 0;
			plansza[3][0] = 0;
			stan_wiez_krola[3] = 0;
			stan_wiez_krola[4] = 0;
			pionki_czarne[0][0] = 4;
			pionki_czarne[0][1] = 0;
			pionki_czarne[1][0] = 0;
			pionki_czarne[1][1] = 0;
		}
		else if((glowa->prev_pole_x == 4) && (glowa->prev_pole_y == 0) && (glowa->pole_x == 6) && (glowa->pole_y == 0) && (plansza[6][0] == 11))
		{
			plansza[7][0] = 13;
			plansza[4][0] = 11;
			plansza[6][0] = 0;
			plansza[5][0] = 0;
			stan_wiez_krola[3] = 0;
			stan_wiez_krola[5] = 0;
			pionki_czarne[0][0] = 4;
			pionki_czarne[0][1] = 0;
			pionki_czarne[2][0] = 7;
			pionki_czarne[2][1] = 0;
		}
		else if((glowa->prev_pole_y == 1) && (glowa->pole_y == 0) && (plansza[glowa->pole_x][0] == 2))
		{
			plansza[glowa->prev_pole_x][glowa->prev_pole_y] = 6;
			plansza[glowa->pole_x][glowa->pole_y] = glowa->zbity;

			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == glowa->pole_x) && (pionki_biale[i][1] == glowa->pole_y))
				{
					pionki_biale[i][0] = glowa->prev_pole_x;
					pionki_biale[i][1] = glowa->prev_pole_y;
					break;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == -1) && (pionki_czarne[i][1] == -1) && (glowa->zbity != 0))
				{
					pionki_czarne[i][0] = glowa->pole_x;
					pionki_czarne[i][1] = glowa->pole_y;
					break;
				}
			}

		}
		else if((glowa->prev_pole_y == 6) && (glowa->pole_y == 7) && (plansza[glowa->pole_x][7] == 12))
		{
			plansza[glowa->prev_pole_x][glowa->prev_pole_y] = 16;
			plansza[glowa->pole_x][glowa->pole_y] = glowa->zbity;

			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == glowa->pole_x) && (pionki_czarne[i][1] == glowa->pole_y))
				{
					pionki_czarne[i][0] = glowa->prev_pole_x;
					pionki_czarne[i][1] = glowa->prev_pole_y;
					break;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == -1) && (pionki_biale[i][1] == -1) && (glowa->zbity != 0))
				{
					pionki_biale[i][0] = glowa->pole_x;
					pionki_biale[i][1] = glowa->pole_y;
					break;
				}
			}
		}
		else
		{
			if(glowa->prev_pole_y == 7)
			{
				if(glowa->prev_pole_x == 4)
				{
					stan_wiez_krola[0] = 0;
					pionki_biale[0][0] = 4;
					pionki_biale[0][1] = 7;
				}
				else if(glowa->prev_pole_x == 0)
				{
					stan_wiez_krola[1] = 0;
					pionki_biale[1][0] = 0;
					pionki_biale[1][1] = 7;
				}
				else if(glowa->prev_pole_x == 7)
				{
					stan_wiez_krola[2] = 0;
					pionki_biale[2][0] = 7;
					pionki_biale[2][1] = 7;
				}

			}
			else if(glowa->prev_pole_y == 0)
			{
				if(glowa->prev_pole_x == 4)
				{
					stan_wiez_krola[3] = 0;
					pionki_czarne[0][0] = 4;
					pionki_czarne[0][1] = 0;
				}
				else if(glowa->prev_pole_x == 0)
				{
					stan_wiez_krola[4] = 0;
					pionki_czarne[1][0] = 0;
					pionki_czarne[1][1] = 0;
				}
				else if(glowa->prev_pole_x == 7)
				{
					stan_wiez_krola[5] = 0;
					pionki_czarne[2][0] = 7;
					pionki_czarne[2][1] = 0;
				}

			}
			plansza[glowa->prev_pole_x][glowa->prev_pole_y] = plansza[glowa->pole_x][glowa->pole_y];
			plansza[glowa->pole_x][glowa->pole_y] = glowa->zbity;
		}

	}
	else
	{
		plansza[glowa->prev_pole_x][glowa->prev_pole_y] = plansza[glowa->pole_x][glowa->pole_y];
		plansza[glowa->pole_x][glowa->pole_y] = glowa->zbity;
		
		if(*kolor_ruchu == 1)
		{
			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == glowa->pole_x) && (pionki_biale[i][1] == glowa->pole_y))
				{
					pionki_biale[i][0] = glowa->prev_pole_x;
					pionki_biale[i][1] = glowa->prev_pole_y;
					break;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == -1) && (pionki_czarne[i][1] == -1) && (glowa->zbity != 0))
				{
					pionki_czarne[i][0] = glowa->pole_x;
					pionki_czarne[i][1] = glowa->pole_y;
					break;
				}
			}
			
		}
		if(*kolor_ruchu == 0)
		{
			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == glowa->pole_x) && (pionki_czarne[i][1] == glowa->pole_y))
				{
					pionki_czarne[i][0] = glowa->prev_pole_x;
					pionki_czarne[i][1] = glowa->prev_pole_y;
					break;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == -1) && (pionki_biale[i][1] == -1) && (glowa->zbity != 0))
				{
					pionki_biale[i][0] = glowa->pole_x;
					pionki_biale[i][1] = glowa->pole_y;
					break;
				}
			}

		}
	}

	*kolor_ruchu = !*kolor_ruchu;
}

void do_redo(int *okno, int plansza[8][8], int pionki_biale[16][2], int pionki_czarne[16][2], bool *kolor_ruchu, lista *glowa, bool *redo, bool *czy_undo, bool stan_wiez_krola[6])
{
	
	if(*okno<10)
		return;
	if(*redo == 0)
		return;
	if(glowa->pole_x == -1)
		return;
	if((glowa->next == NULL) && (*czy_undo == 0))
		return;
	if(glowa->next == NULL)
		*czy_undo = 0;



	if(glowa->zmiana_stanu == 1)
	{
		if((glowa->prev_pole_y == 3) && (glowa->pole_y == 2) && (glowa->pole_x == glowa->prev_pole_x-1) && (plansza[glowa->prev_pole_x][3] == 6))
		{
			plansza[glowa->pole_x][2] = 6;
			plansza[glowa->prev_pole_x][3] = 0;
			plansza[glowa->pole_x][3] = 0;

			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == glowa->prev_pole_x) && (pionki_biale[i][1] == glowa->prev_pole_y))
				{
					pionki_biale[i][0] = glowa->pole_x;
					pionki_biale[i][1] = glowa->pole_y;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == glowa->pole_x) && (pionki_czarne[i][1] == glowa->pole_y+1))
				{
					pionki_czarne[i][0] = -1;
					pionki_czarne[i][1] = -1;
					break;
				}
			}
	
		}
		else if((glowa->prev_pole_y == 3) && (glowa->pole_y == 2) && (glowa->pole_x == glowa->prev_pole_x+1) && (plansza[glowa->prev_pole_x][3] == 6))
		{
			plansza[glowa->pole_x][2] = 6;
			plansza[glowa->prev_pole_x][3] = 0;
			plansza[glowa->pole_x][3] = 0;

			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == glowa->prev_pole_x) && (pionki_biale[i][1] == glowa->prev_pole_y))
				{
					pionki_biale[i][0] = glowa->pole_x;
					pionki_biale[i][1] = glowa->pole_y;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == glowa->pole_x) && (pionki_czarne[i][1] == glowa->pole_y+1))
				{
					pionki_czarne[i][0] = -1;
					pionki_czarne[i][1] = -1;
					break;
				}
			}
	
		}
		else if((glowa->prev_pole_y == 4) && (glowa->pole_y == 5) && (glowa->pole_x == glowa->prev_pole_x-1) && (plansza[glowa->prev_pole_x][4] == 16))
		{
			plansza[glowa->pole_x][5] = 16;
			plansza[glowa->prev_pole_x][4] = 0;
			plansza[glowa->pole_x][4] = 0;

			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == glowa->prev_pole_x) && (pionki_czarne[i][1] == glowa->prev_pole_y))
				{
					pionki_czarne[i][0] = glowa->pole_x;
					pionki_czarne[i][1] = glowa->pole_y;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == glowa->pole_x) && (pionki_biale[i][1] == glowa->pole_y-1))
				{
					pionki_biale[i][0] = -1;
					pionki_biale[i][1] = -1;
					break;
				}
			}
	
		}
		else if((glowa->prev_pole_y == 4) && (glowa->pole_y == 5) && (glowa->pole_x == glowa->prev_pole_x+1) && (plansza[glowa->prev_pole_x][4] == 16))
		{
			plansza[glowa->pole_x][5] = 16;
			plansza[glowa->prev_pole_x][4] = 0;
			plansza[glowa->pole_x][4] = 0;

			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == glowa->prev_pole_x) && (pionki_czarne[i][1] == glowa->prev_pole_y))
				{
					pionki_czarne[i][0] = glowa->pole_x;
					pionki_czarne[i][1] = glowa->pole_y;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == glowa->pole_x) && (pionki_biale[i][1] == glowa->pole_y-1))
				{
					pionki_biale[i][0] = -1;
					pionki_biale[i][1] = -1;
					break;
				}
			}
	
		}


		else if((glowa->prev_pole_x == 4) && (glowa->prev_pole_y == 7) && (glowa->pole_x == 2) && (glowa->pole_y == 7) && (plansza[4][7] == 1))
		{
			plansza[0][7] = 0;
			plansza[4][7] = 0;
			plansza[2][7] = 1;
			plansza[3][7] = 3;
			stan_wiez_krola[0] = 1;
			stan_wiez_krola[1] = 1;
			pionki_biale[0][0] = 2;
			pionki_biale[0][1] = 7;
			pionki_biale[1][0] = 3;
			pionki_biale[1][1] = 7;
		}
		else if((glowa->prev_pole_x == 4) && (glowa->prev_pole_y == 7) && (glowa->pole_x == 6) && (glowa->pole_y == 7) && (plansza[4][7] == 1))
		{
			plansza[7][7] = 0;
			plansza[4][7] = 0;
			plansza[6][7] = 1;
			plansza[5][7] = 3;
			stan_wiez_krola[0] = 1;
			stan_wiez_krola[2] = 1;
			pionki_biale[0][0] = 6;
			pionki_biale[0][1] = 7;
			pionki_biale[2][0] = 5;
			pionki_biale[2][1] = 7;
		}
		else if((glowa->prev_pole_x == 4) && (glowa->prev_pole_y == 0) && (glowa->pole_x == 2) && (glowa->pole_y == 0) && (plansza[4][0] == 11))
		{
			plansza[0][0] = 0;
			plansza[4][0] = 0;
			plansza[2][0] = 11;
			plansza[3][0] = 13;
			stan_wiez_krola[3] = 1;
			stan_wiez_krola[4] = 1;
			pionki_czarne[0][0] = 2;
			pionki_czarne[0][1] = 0;
			pionki_czarne[1][0] = 3;
			pionki_czarne[1][1] = 0;
		}
		else if((glowa->prev_pole_x == 4) && (glowa->prev_pole_y == 0) && (glowa->pole_x == 6) && (glowa->pole_y == 0) && (plansza[4][0] == 11))
		{
			plansza[7][0] = 0;
			plansza[4][0] = 0;
			plansza[6][0] = 11;
			plansza[5][0] = 13;
			stan_wiez_krola[3] = 1;
			stan_wiez_krola[5] = 1;
			pionki_czarne[0][0] = 6;
			pionki_czarne[0][1] = 0;
			pionki_czarne[2][0] = 5;
			pionki_czarne[2][1] = 0;
		}


		else if((glowa->prev_pole_y == 1) && (glowa->pole_y == 0) && (plansza[glowa->pole_x][1] == 6))
		{
			plansza[glowa->prev_pole_x][glowa->prev_pole_y] = 0;
			plansza[glowa->pole_x][glowa->pole_y] = 2;

			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == glowa->prev_pole_x) && (pionki_biale[i][1] == glowa->prev_pole_y))
				{
					pionki_biale[i][0] = glowa->pole_x;
					pionki_biale[i][1] = glowa->pole_y;
					break;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == glowa->pole_x) && (pionki_czarne[i][1] == glowa->pole_x) && (glowa->zbity != 0))
				{
					pionki_czarne[i][0] = -1;
					pionki_czarne[i][1] = -1;
					break;
				}
			}

		}
		else if((glowa->prev_pole_y == 6) && (glowa->pole_y == 7) && (plansza[glowa->pole_x][6] == 16))
		{
			plansza[glowa->prev_pole_x][glowa->prev_pole_y] = 0;
			plansza[glowa->pole_x][glowa->pole_y] = 12;

			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == glowa->prev_pole_x) && (pionki_czarne[i][1] == glowa->prev_pole_y))
				{
					pionki_czarne[i][0] = glowa->pole_x;
					pionki_czarne[i][1] = glowa->pole_y;
					break;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == glowa->pole_x) && (pionki_biale[i][1] == glowa->pole_y) && (glowa->zbity != 0))
				{
					pionki_biale[i][0] = -1;
					pionki_biale[i][1] = -1;
					break;
				}
			}
		}
		else
		{
			if(glowa->prev_pole_y == 7)
			{
				if(glowa->prev_pole_x == 4)
				{
					stan_wiez_krola[0] = 1;
					pionki_biale[0][0] = glowa->pole_x;
					pionki_biale[0][1] = glowa->pole_y;
				}
				else if(glowa->prev_pole_x == 0)
				{
					stan_wiez_krola[1] = 1;
					pionki_biale[1][0] = glowa->pole_x;
					pionki_biale[1][1] = glowa->pole_y;
				}
				else if(glowa->prev_pole_x == 7)
				{
					stan_wiez_krola[2] = 1;
					pionki_biale[2][0] = glowa->pole_x;
					pionki_biale[2][1] = glowa->pole_y;
				}

			}
			else if(glowa->prev_pole_y == 0)
			{
				if(glowa->prev_pole_x == 4)
				{
					stan_wiez_krola[3] = 1;
					pionki_czarne[0][0] = glowa->pole_x;
					pionki_czarne[0][1] = glowa->pole_y;
				}
				else if(glowa->prev_pole_x == 0)
				{
					stan_wiez_krola[4] = 1;
					pionki_czarne[1][0] = glowa->pole_x;
					pionki_czarne[1][1] = glowa->pole_y;
				}
				else if(glowa->prev_pole_x == 7)
				{
					stan_wiez_krola[5] = 1;
					pionki_czarne[2][0] = glowa->pole_x;
					pionki_czarne[2][1] = glowa->pole_y;
				}

			}
			plansza[glowa->pole_x][glowa->pole_y] = plansza[glowa->prev_pole_x][glowa->prev_pole_y];
			plansza[glowa->prev_pole_x][glowa->prev_pole_y] = 0;
		}

	}
	else
	{
		plansza[glowa->pole_x][glowa->pole_y] = plansza[glowa->prev_pole_x][glowa->prev_pole_y];
		plansza[glowa->prev_pole_x][glowa->prev_pole_y] = 0;
		
		if(*kolor_ruchu == 1)
		{
			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == glowa->prev_pole_x) && (pionki_biale[i][1] == glowa->prev_pole_y))
				{
					pionki_biale[i][0] = glowa->pole_x;
					pionki_biale[i][1] = glowa->pole_y;
					break;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == glowa->pole_x) && (pionki_czarne[i][1] == glowa->pole_y) && (glowa->zbity != 0))
				{
					pionki_czarne[i][0] = -1;
					pionki_czarne[i][1] = -1;
					break;
				}
			}
			
		}
		if(*kolor_ruchu == 0)
		{
			for(int i=0;i<16;i++)
			{
				if((pionki_czarne[i][0] == glowa->prev_pole_x) && (pionki_czarne[i][1] == glowa->prev_pole_y))
				{
					pionki_czarne[i][0] = glowa->pole_x;
					pionki_czarne[i][1] = glowa->pole_y;
					break;
				}
			}
			for(int i=0;i<16;i++)
			{
				if((pionki_biale[i][0] == glowa->pole_x) && (pionki_biale[i][1] == glowa->pole_y) && (glowa->zbity != 0))
				{
					pionki_biale[i][0] = -1;
					pionki_biale[i][1] = -1;
					break;
				}
			}

		}
	}
	*kolor_ruchu = !*kolor_ruchu;
	*redo = 0;
}
