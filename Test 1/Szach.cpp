#include "Szach.h"
#include "Funkcje.h"

int czy_moge_biale(int *pole_x, int *pole_y, int plansza[8][8], int pionki[16][2])
{
	int x,y;
	if(*pole_x-pionki[0][0] == *pole_y-pionki[0][1])
	{
		if(*pole_x-pionki[0][0] > 0)
		{
			x=*pole_x;
			y=*pole_y;
			while(x-1>pionki[0][0])
			{
				x--;
				y--;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while((x<7) && (y<7))
			{
				x++;
				y++;
				if((plansza[x][y] != 14) && (plansza[x][y] != 12) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 14) || (plansza[x][y] == 12))
					return 5;
			}
			return 0;
		}
		else
		{
			x=*pole_x;
			y=*pole_y;
			while(x+1<pionki[0][0])
			{
				x++;
				y++;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while((x>0) && (y>0))
			{
				x--;
				y--;
				if((plansza[x][y] != 14) && (plansza[x][y] != 12) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 14) || (plansza[x][y] == 12))
					return 1;
			}
			return 0;
		}
	}		
	else if(*pole_x-pionki[0][0] == -(*pole_y-pionki[0][1]))
	{
		if(*pole_x-pionki[0][0] > 0)
		{
			x=*pole_x;
			y=*pole_y;
			while(x-1>pionki[0][0])
			{
				x--;
				y++;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while((x<7) && (y>0))
			{
				x++;
				y--;
				if((plansza[x][y] != 14) && (plansza[x][y] != 12) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 14) || (plansza[x][y] == 12))
					return 3;
			}
			return 0;
		}
		else
		{
			x=*pole_x;
			y=*pole_y;
			while(x+1<pionki[0][0])
			{
				x++;
				y--;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while((x>0) && (y<7))
			{
				x--;
				y++;
				if((plansza[x][y] != 14) && (plansza[x][y] != 12) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 14) || (plansza[x][y] == 12))
					return 7;
			}
			return 0;
		}
	}
	else if(*pole_x == pionki[0][0])
	{
		if(*pole_y < pionki[0][1])
		{
			x=*pole_x;
			y=*pole_y;
			while(y+1<pionki[0][1])
			{
				y++;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while(y>0)
			{
				y--;
				if((plansza[x][y] != 13) && (plansza[x][y] != 12) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 13) || (plansza[x][y] == 12))
					return 2;
			}
			return 0;
		}
		else
		{
			x=*pole_x;
			y=*pole_y;
			while(y-1>pionki[0][1])
			{
				y--;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while(y<7)
			{
				y++;
				if((plansza[x][y] != 13) && (plansza[x][y] != 12) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 13) || (plansza[x][y] == 12))
					return 6;
			}
			return 0;
		}
	}
	else if(*pole_y == pionki[0][1])
	{
		if(*pole_x < pionki[0][0])
		{
			x=*pole_x;
			y=*pole_y;
			while(x+1<pionki[0][0])
			{
				x++;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while(x>0)
			{
				x--;
				if((plansza[x][y] != 13) && (plansza[x][y] != 12) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 13) || (plansza[x][y] == 12))
					return 8;
			}
			return 0;
		}
		else
		{
			x=*pole_x;
			y=*pole_y;
			while(x-1>pionki[0][0])
			{
				x--;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while(x<7)
			{
				x++;
				if((plansza[x][y] != 13) && (plansza[x][y] != 12) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 13) || (plansza[x][y] == 12))
					return 4;
			}
			return 0;
		}
	}
	
	return 0;
}

int czy_moge_czarne(int *pole_x, int *pole_y, int plansza[8][8], int pionki[16][2])
{
	int x,y;
	if(*pole_x-pionki[0][0] == *pole_y-pionki[0][1])
	{
		if(*pole_x-pionki[0][0] > 0)
		{
			x=*pole_x;
			y=*pole_y;
			while(x-1>pionki[0][0])
			{
				x--;
				y--;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while((x<7) && (y<7))
			{
				x++;
				y++;
				if((plansza[x][y] != 4) && (plansza[x][y] != 2) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 4) || (plansza[x][y] == 2))
					return 5;
			}
			return 0;
		}
		else
		{
			x=*pole_x;
			y=*pole_y;
			while(x+1<pionki[0][0])
			{
				x++;
				y++;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while((x>0) && (y>0))
			{
				x--;
				y--;
				if((plansza[x][y] != 4) && (plansza[x][y] != 2) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 4) || (plansza[x][y] == 2))
					return 1;
			}
			return 0;
		}
	}		
	else if(*pole_x-pionki[0][0] == -(*pole_y-pionki[0][1]))
	{
		if(*pole_x-pionki[0][0] > 0)
		{
			x=*pole_x;
			y=*pole_y;
			while(x-1>pionki[0][0])
			{
				x--;
				y++;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while((x<7) && (y>0))
			{
				x++;
				y--;
				if((plansza[x][y] != 4) && (plansza[x][y] != 2) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 4) || (plansza[x][y] == 2))
					return 3;
			}
			return 0;
		}
		else
		{
			x=*pole_x;
			y=*pole_y;
			while(x+1<pionki[0][0])
			{
				x++;
				y--;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while((x>0) && (y<7))
			{
				x--;
				y++;
				if((plansza[x][y] != 4) && (plansza[x][y] != 2) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 4) || (plansza[x][y] == 2))
					return 7;
			}
			return 0;
		}
	}
	else if(*pole_x == pionki[0][0])
	{
		if(*pole_y < pionki[0][1])
		{
			x=*pole_x;
			y=*pole_y;
			while(y+1<pionki[0][1])
			{
				y++;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while(y>0)
			{
				y--;
				if((plansza[x][y] != 3) && (plansza[x][y] != 2) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 3) || (plansza[x][y] == 2))
					return 2;
			}
			return 0;
		}
		else
		{
			x=*pole_x;
			y=*pole_y;
			while(y-1>pionki[0][1])
			{
				y--;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while(y<7)
			{
				y++;
				if((plansza[x][y] != 3) && (plansza[x][y] != 2) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 3) || (plansza[x][y] == 2))
					return 6;
			}
			return 0;
		}
	}
	else if(*pole_y == pionki[0][1])
	{
		if(*pole_x < pionki[0][0])
		{
			x=*pole_x;
			y=*pole_y;
			while(x+1<pionki[0][0])
			{
				x++;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while(x>0)
			{
				x--;
				if((plansza[x][y] != 3) && (plansza[x][y] != 2) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 3) || (plansza[x][y] == 2))
					return 8;
			}
			return 0;
		}
		else
		{
			x=*pole_x;
			y=*pole_y;
			while(x-1>pionki[0][0])
			{
				x--;
				if(plansza[x][y] != 0)
					return 0;
			}
			x=*pole_x;
			y=*pole_y;
			while(x<7)
			{
				x++;
				if((plansza[x][y] != 3) && (plansza[x][y] != 2) && (plansza[x][y] != 0))
					return 0;
				if((plansza[x][y] == 3) || (plansza[x][y] == 2))
					return 4;
			}
			return 0;
		}
	}
	
	return 0;
}

void sprawdzenie_szachu(int *okno,int plansza[8][8], bool czy_szach[8][8], int pionki_czarne[16][2], int pionki_biale[16][2], bool *kolor_ruchu, int *szach)
{
	if(*okno<10)
		return;
	



	*szach = 0;
	

	for(int i = 0; i<=7; i++)
	{
		for(int j = 0; j<=7; j++)
			czy_szach[i][j] = 0;
	}

	if(*kolor_ruchu == 1)
	{
		int x = pionki_czarne[0][0];
		int y = pionki_czarne[0][1];

		if((y<7) && (plansza[x-1][y+1] == 6))
			{
				*szach=*szach+1;
				czy_szach[x-1][y+1] = 1;
			}
		if((y<7) && (plansza[x+1][y+1] == 6))
			{
				*szach=*szach+1;
				czy_szach[x+1][y+1] = 1;
			}


		if((x-2>=0) && (y-1>=0) && (plansza[x-2][y-1] == 5))
					{
						czy_szach[x-2][y-1] = 1;
						*szach=*szach+1;
					}
		if((x-1>=0) && (y-2>=0) && (plansza[x-1][y-2] == 5))
					{
						czy_szach[x-1][y-2] = 1;
						*szach=*szach+1;
					}
		if((x+1<=7) && (y-2>=0) && (plansza[x+1][y-2] == 5))
					{
						czy_szach[x+1][y-2] = 1;
						*szach=*szach+1;
					}
		if((x+2<=7) && (y-1>=0) && (plansza[x+2][y-1] == 5))
					{
						czy_szach[x+2][y-1] = 1;
						*szach=*szach+1;
					}
		if((x+2<=7) && (y+1<=7) && (plansza[x+2][y+1] == 5))
					{
						czy_szach[x+2][y+1] = 1;
						*szach=*szach+1;
					}
		if((x+1<=7) && (y+2<=7) && (plansza[x+1][y+2] == 5))
					{
						czy_szach[x+1][y+2] = 1;
						*szach=*szach+1;
					}
		if((x-1>=0) && (y+2<=7) && (plansza[x-1][y+2] == 5))
					{
						czy_szach[x-1][y+2] = 1;
						*szach=*szach+1;
					}
		if((x-2>=0) && (y+1<=7) && (plansza[x-2][y+1] == 5))
					{
						czy_szach[x-2][y+1] = 1;
						*szach=*szach+1;
					}


		////////////////////////////////////////////////////////////////////////krol///////////////////


		if((x>0) && (y>0) && (plansza[x-1][y-1] == 1))
					{
						czy_szach[x-1][y-1] = 1;
						*szach = *szach+1;
					}
		if((y>0) && (plansza[x][y-1] == 1))
					{
						czy_szach[x][y-1] = 1;
						*szach = *szach+1;
					}
		if((x<7) && (y>0) && (plansza[x+1][y-1] == 1))
					{
						czy_szach[x+1][y-1] = 1;
						*szach = *szach+1;
					}
		if((x<7) && (plansza[x+1][y] == 1))
					{
						czy_szach[x+1][y] = 1;
						*szach = *szach+1;
					}
		if((x<7) && (y<7) && (plansza[x+1][y+1] == 1))
					{
						czy_szach[x+1][y+1] = 1;
						*szach = *szach+1;
					}
		if((y<7) && (plansza[x][y+1] == 1))
					{
						czy_szach[x][y+1] = 1;
						*szach = *szach+1;
					}
		if((x>0) && (y<7) && (plansza[x-1][y+1] == 1))
					{
						czy_szach[x-1][y+1] = 1;
						*szach = *szach+1;
					}
		if((x>0) && (plansza[x-1][y] == 1))
					{
						czy_szach[x-1][y] = 1;
						*szach = *szach+1;
					}


		x = pionki_czarne[0][0];
		y = pionki_czarne[0][1];
		while((x>0) && (y>0))
		{
			x--;
			y--;
			if(plansza[x][y] > 10)
				break;
			else if((plansza[x][y]<10) && (plansza[x][y] != 0))
			{
				if((plansza[x][y] == 2) || (plansza[x][y] == 4))
				{
					for(int i = 0; i<(pionki_czarne[0][0] - x); i++)
						czy_szach[x+i][y+i] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}

		x = pionki_czarne[0][0];
		y = pionki_czarne[0][1];
		while((x<7) && (y>0))
		{
			x++;
			y--;
			if(plansza[x][y] > 10)
				break;
			else if((plansza[x][y]<10) && (plansza[x][y] != 0))
			{
				if((plansza[x][y] == 2) || (plansza[x][y] == 4))
				{
					for(int i = 0; i<(x - pionki_czarne[0][0]); i++)
						czy_szach[x-i][y+i] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}

		x = pionki_czarne[0][0];
		y = pionki_czarne[0][1];
		while((x<7) && (y<7))
		{
			x++;
			y++;
			if(plansza[x][y] > 10)
				break;
			else if((plansza[x][y]<10) && (plansza[x][y] != 0))
			{
				if((plansza[x][y] == 2) || (plansza[x][y] == 4))
				{
					for(int i = 0; i<(x - pionki_czarne[0][0]); i++)
						czy_szach[x-i][y-i] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}

		x = pionki_czarne[0][0];
		y = pionki_czarne[0][1];
		while((x>0) && (y<7))
		{
			x--;
			y++;
			if(plansza[x][y] > 10)
				break;
			if((plansza[x][y]<10) && (plansza[x][y] != 0))
			{
				if((plansza[x][y] == 2) || (plansza[x][y] == 4))
				{
					for(int i = 0; i<(pionki_czarne[0][0] - x); i++)
						czy_szach[x+i][y-i] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}


		x = pionki_czarne[0][0];
		y = pionki_czarne[0][1];
		while(y>0)
		{
			y--;
			if(plansza[x][y] > 10)
				break;
			if((plansza[x][y]<10) && (plansza[x][y] != 0))
			{
				if((plansza[x][y] == 2) || (plansza[x][y] == 3))
				{
					for(int i = 0; i<(pionki_czarne[0][1] - y); i++)
						czy_szach[x][y+i] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}


		x = pionki_czarne[0][0];
		y = pionki_czarne[0][1];
		while(x<7)
		{
			x++;
			if(plansza[x][y] > 10)
				break;
			if((plansza[x][y]<10) && (plansza[x][y] != 0))
			{
				if((plansza[x][y] == 2) || (plansza[x][y] == 3))
				{
					for(int i = 0; i<(x - pionki_czarne[0][0]); i++)
						czy_szach[x-i][y] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}


		x = pionki_czarne[0][0];
		y = pionki_czarne[0][1];
		while(y<7)
		{
			y++;
			if(plansza[x][y] > 10)
				break;
			if((plansza[x][y]<10) && (plansza[x][y] != 0))
			{
				if((plansza[x][y] == 2) || (plansza[x][y] == 3))
				{
					for(int i = 0; i<(y - pionki_czarne[0][1]); i++)
						czy_szach[x][y-i] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}


		x = pionki_czarne[0][0];
		y = pionki_czarne[0][1];
		while(x>0)
		{
			x--;
			if(plansza[x][y] > 10)
				break;
			if((plansza[x][y]<10) && (plansza[x][y] != 0))
			{
				if((plansza[x][y] == 2) || (plansza[x][y] == 3))
				{
					for(int i = 0; i<(pionki_czarne[0][0] - x); i++)
						czy_szach[x+i][y] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}
	}




	else
	{
		int x = pionki_biale[0][0];
		int y = pionki_biale[0][1];

		if((y>0) && (plansza[x-1][y-1] == 16))
			{
				*szach=*szach+1;
				czy_szach[x-1][y-1] = 1;
			}
		if((y>0) && (plansza[x+1][y-1] == 16))
			{
				*szach=*szach+1;
				czy_szach[x+1][y-1] = 1;
			}


		if((x-2>=0) && (y-1>=0) && (plansza[x-2][y-1] == 15))
					{
						czy_szach[x-2][y-1] = 1;
						*szach=*szach+1;
					}
		if((x-1>=0) && (y-2>=0) && (plansza[x-1][y-2] == 15))
					{
						czy_szach[x-1][y-2] = 1;
						*szach=*szach+1;
					}
		if((x+1<=7) && (y-2>=0) && (plansza[x+1][y-2] == 15))
					{
						czy_szach[x+1][y-2] = 1;
						*szach=*szach+1;
					}
		if((x+2<=7) && (y-1>=0) && (plansza[x+2][y-1] == 15))
					{
						czy_szach[x+2][y-1] = 1;
						*szach=*szach+1;
					}
		if((x+2<=7) && (y+1<=7) && (plansza[x+2][y+1] == 15))
					{
						czy_szach[x+2][y+1] = 1;
						*szach=*szach+1;
					}
		if((x+1<=7) && (y+2<=7) && (plansza[x+1][y+2] == 15))
					{
						czy_szach[x+1][y+2] = 1;
						*szach=*szach+1;
					}
		if((x-1>=0) && (y+2<=7) && (plansza[x-1][y+2] == 15))
					{
						czy_szach[x-1][y+2] = 1;
						*szach=*szach+1;
					}
		if((x-2>=0) && (y+1<=7) && (plansza[x-2][y+1] == 15))
					{
						czy_szach[x-2][y+1] = 1;
						*szach=*szach+1;
					}

		///////////////////////////////////////////////////////////////////krol///////////////////

				if((x>0) && (y>0) && (plansza[x-1][y-1] == 11))
					{
						czy_szach[x-1][y-1] = 1;
						*szach = *szach+1;
					}
		if((y>0) && (plansza[x][y-1] == 11))
					{
						czy_szach[x][y-1] = 1;
						*szach = *szach+1;
					}
		if((x<7) && (y>0) && (plansza[x+1][y-1] == 11))
					{
						czy_szach[x+1][y-1] = 1;
						*szach = *szach+1;
					}
		if((x<7) && (plansza[x+1][y] == 11))
					{
						czy_szach[x+1][y] = 1;
						*szach = *szach+1;
					}
		if((x<7) && (y<7) && (plansza[x+1][y+1] == 11))
					{
						czy_szach[x+1][y+1] = 1;
						*szach = *szach+1;
					}
		if((y<7) && (plansza[x][y+1] == 11))
					{
						czy_szach[x][y+1] = 1;
						*szach = *szach+1;
					}
		if((x>0) && (y<7) && (plansza[x-1][y+1] == 11))
					{
						czy_szach[x-1][y+1] = 1;
						*szach = *szach+1;
					}
		if((x>0) && (plansza[x-1][y] == 11))
					{
						czy_szach[x-1][y] = 1;
						*szach = *szach+1;
					}


		x = pionki_biale[0][0];
		y = pionki_biale[0][1];
		while((x>0) && (y>0))
		{
			x--;
			y--;
			if((plansza[x][y] < 10) && (plansza[x][y] != 0))
				break;
			else if(plansza[x][y] > 10)
			{
				if((plansza[x][y] == 12) || (plansza[x][y] == 14))
				{
					for(int i = 0; i<(pionki_biale[0][0] - x); i++)
						czy_szach[x+i][y+i] = 1;
					*szach = *szach+1;
				}			
				break;
			}

		}

		x = pionki_biale[0][0];
		y = pionki_biale[0][1];
		while((x<7) && (y>0))
		{
			x++;
			y--;
			if((plansza[x][y] < 10) && (plansza[x][y] != 0))
				break;
			else if(plansza[x][y] > 10)
			{
				if((plansza[x][y] == 12) || (plansza[x][y] == 14))
				{
					for(int i = 0; i<(x - pionki_biale[0][0]); i++)
						czy_szach[x-i][y+i] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}

		x = pionki_biale[0][0];
		y = pionki_biale[0][1];
		while((x<7) && (y<7))
		{
			x++;
			y++;
			if((plansza[x][y] < 10) && (plansza[x][y] != 0))
				break;
			else if(plansza[x][y] > 10)
			{
				if((plansza[x][y] == 12) || (plansza[x][y] == 14))
				{
					for(int i = 0; i<(x - pionki_biale[0][0]); i++)
						czy_szach[x-i][y-i] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}

		x = pionki_biale[0][0];
		y = pionki_biale[0][1];
		while((x>0) && (y<7))
		{
			x--;
			y++;
			if((plansza[x][y] < 10) && (plansza[x][y] != 0))
				break;
			else if(plansza[x][y] > 10)
			{
				if((plansza[x][y] == 12) || (plansza[x][y] == 14))
				{
					for(int i = 0; i<(pionki_biale[0][0] - x); i++)
						czy_szach[x+i][y-i] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}


		x = pionki_biale[0][0];
		y = pionki_biale[0][1];
		while(y>0)
		{
			y--;
			if((plansza[x][y] < 10) && (plansza[x][y] != 0))
				break;
			else if(plansza[x][y] > 10)
			{
				if((plansza[x][y] == 12) || (plansza[x][y] == 13))
				{
					for(int i = 0; i<(pionki_biale[0][1] - y); i++)
						czy_szach[x][y+i] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}


		x = pionki_biale[0][0];
		y = pionki_biale[0][1];
		while(x<7)
		{
			x++;
			if((plansza[x][y] < 10) && (plansza[x][y] != 0))
				break;
			else if(plansza[x][y] > 10)
			{
				if((plansza[x][y] == 12) || (plansza[x][y] == 13))
				{
					for(int i = 0; i<(x - pionki_biale[0][0]); i++)
						czy_szach[x-i][y] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}


		x = pionki_biale[0][0];
		y = pionki_biale[0][1];
		while(y<7)
		{
			y++;
			if((plansza[x][y] < 10) && (plansza[x][y] != 0))
				break;
			else if(plansza[x][y] > 10)
			{
				if((plansza[x][y] == 12) || (plansza[x][y] == 13))
				{
					for(int i = 0; i<(y - pionki_biale[0][1]); i++)
						czy_szach[x][y-i] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}


		x = pionki_biale[0][0];
		y = pionki_biale[0][1];
		while(x>0)
		{
			x--;
			if((plansza[x][y] < 10) && (plansza[x][y] != 0))
				break;
			else if(plansza[x][y] > 10)
			{
				if((plansza[x][y] == 12) || (plansza[x][y] == 13))
				{
					for(int i = 0; i<(pionki_biale[0][0] - x); i++)
						czy_szach[x+i][y] = 1;
					*szach = *szach+1;
				}
				break;
			}
		}
		


	}
	

}

void szach_mat(int *okno, int plansza[8][8], bool czy_szach[8][8], bool *kolor_ruchu, int pionki_czarne[16][2], int pionki_biale[16][2], int *szach, int *pole_x, int *pole_y)
{
	if(*szach == 0)
		return;
	if(*okno<10)
		return;

	bool tablica_pom[8][8];
	int x,y;
	x=*pole_x;
	y=*pole_y;
	bool mat;
	mat = 1;
	int pom;
	pom = *szach;

	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
			tablica_pom[i][j] = 0;
	}

	if(*kolor_ruchu == 0)
	{
		for(int i = 0; i<=15; i++)
		{
			*szach = pom;
			*pole_x = pionki_biale[i][0];
			*pole_y = pionki_biale[i][1];
			dostepne_ruchy(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,tablica_pom,pionki_biale,pionki_czarne,czy_szach,0);
		}
		for(int i = 0; i<=7; i++)
		{
			for(int j = 0; j<=7; j++)
			{
				if(tablica_pom[i][j] == 1)
					{
						mat = 0;
					}
			}
			if(mat == 0)
				break;

				
		}
	}
	else
	{
		for(int i = 0; i<=15; i++)
		{
			*szach = pom;
			*pole_x = pionki_czarne[i][0];
			*pole_y = pionki_czarne[i][1];
			dostepne_ruchy(okno,kolor_ruchu,szach,pole_x,pole_y,plansza,tablica_pom,pionki_biale,pionki_czarne,czy_szach,0);
		}
		for(int i = 0; i<=7; i++)
		{
			for(int j = 0; j<=7; j++)
			{
				if(tablica_pom[i][j] == 1)
					{
						mat = 0;
					}
			}
			if(mat == 0)
				break;				
		}
	}
	if(mat == 1)
		*szach = 20;
	else
		*szach = pom;
	*pole_x = x;
	*pole_y = y;

}
