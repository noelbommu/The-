#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<process.h>
#include<dos.h>
class calen
{
	public:
	int days;
	int mm;
	int k;
	int z;
	int p;
	int yy;
	int r;

	int calen[5][7];
	int i,j;
	int mon;

	public:
	void calen_call(void);
	void display(void);
};
void main()
{
	clrscr();
	calen c;
	c.calen_call();
	c.display();
	getch();
}
void calen::calen_call(void)
{
	int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	long int t;
	time_tt:
	time(&t);


	cout<<"\n\n\n\t\t\tCALANDAR FROM YEAR 2018...\n\n\n";
	//cout<<"\n\nTODAY'S DATE AND TIME:"<<time(&t);
	repeat:

	cout<<"\n\nENTER YEAR[2018...]:";
	cin>>yy;

	if(yy==2017)
	{
		cout<<"\n\nWRONG ENTRY";
		goto repeat;
	}
	if(yy%4==0)
	{
		if(yy%100==0)
		{
			if(yy%400==0)
			month[1]=29;
			else
			month[1]=28;
		}
		else
		month[1]=29;
	}
	again:
	cout<<"\nENTER MONTH[1-12]:";
	cin>>mon;

	if(mon>12||mon<1)
	{
		cout<<"\nWRONG ENTRY";
		goto again;
	}
	cout<<"\n\n\t\t\t\tYEAR"<<yy<<"\n\n";

	switch(mon)
	{
		case 1:
		cout<<"\n\n\t\t\t\tJANUARY\n\n";
		break;
		case 2:
		cout<<"\n\n\t\t\t\tFEBRUARY\n\n";
		break;
		case 3:
		cout<<"\n\n\t\t\t\tMARCH\n\n";
		break;
		case 4:
		cout<<"\n\n\t\t\t\tAPRIL\n\n";
		break;
		case 5:
		cout<<"\n\n\t\t\t\tMAY\n\n";
		break;
		case 6:
		cout<<"\n\n\t\t\t\tJUNE\n\n";
		break;
		case 7:
		cout<<"\n\n\t\t\t\tJULY\n\n";
		break;
		case 8:
		cout<<"\n\n\t\t\t\tAUGUST\n\n";
		break;
		case 9:
		cout<<"\n\n\t\t\t\tSEPTEMBER\n\n";
		break;
		case 10:
		cout<<"\n\n\t\t\t\tOCTOBER\n\n";
		break;
		case 11:
		cout<<"\n\n\\t\t\t\tNOVEMBER\n\n";
		break;
		case 12:
		cout<<"\n\n\t\t\t\tDECEMBER\n\n";
		break;
		default:
		cout<<"\n\nWRONG ENTRY";
		exit(0);
	}
	p=5;
	for(r=2017;r<yy;r++)
	{
		if(r%4==0)
		{
		if(r%100==0)
		{
			if(r%400==0)
			p=p+2;
			else
			p++;
		}
		else
		p=p+2;
		}
		else
		p++;

		if(p==7)
		p=0;
		if(p==8)
		p=1;
	}

	for(mm=0;mm<12;mm++)
	{
		days=month[mm];
		k=0;

		for(z=0;z<7;z++)
		calen[0][z]=0;

		for(i=0;i<5;i++,p=0)
		for(j=p;j<7&&k<days;j++)
		{
			calen[i][j]=k+1;
			k++;

			if(k==days&&i==4&&j<7)
			{
			for(p=j+1;p<7;p++)
			calen[i][p]=0;
			}
			if(k<days&&i==4&&j==6)
			{
				for(p=0;p<7&&k<days;p++,k++)
				calen[0][p]=k+1;
				j=p-1;
			}

		if(k==days&&i==4&&j==6)
		{
		j=-1;
		}

		if(k==days&&i==3&&j==6)
		{
			for(p=0;p<7;p++)
			calen[4][p]=0;
		}
	}
	p=j;
	if(mm+1==mon)
	return;
	}

}
void calen::display()
{
cout<<"\n\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n\n";

for(i=0;i<5;i++)
{
	for(j=0;j<7;j++)
	cout<<"\t"<<calen[i][j];
	cout<<"\n\n";
}
getch();
}




