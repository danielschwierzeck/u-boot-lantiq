/*
Author : Wang Yunliang
Company : Lantqi Asia Pacific Pte. Ltd.
Release date : 2014 -10 -31

Introduciton:
This BCH encoder can generate 40 bits error correction encoder file "output.bin" from original file "sample.bin"
You can choose how many errors you want to inject and the inject positions.

All rights reserved.
*/


#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define BIN	"sample.bin"
#define WBIN	"output.bin"
#define RSBIN	"result.bin"

int             m, n, length, k, t, d;
int             p[21];
int             alpha_to[1048576], index_of[1048576], g[548576];
int             recd[1048576], data[1048576], bb[548576];
int             seed;
int             numerr, errpos[1024], decerror = 0;
int 		filesize;
uint8_t		input[8192];

static sector_bits=4096;
static Gx_num=521;


int m_value=13;
int t_value;
char *argv0;
char *input_str;
char *output_str;
char *argv3;
uint8_t		source[512];
uint8_t		source_temp2[4096];//512*8
uint8_t		destination[512];
uint8_t		output[512];
uint8_t		source_temp[4096];//512*8
uint8_t		Gx_record[3520][530];










void 
byte2bit(int len)
{
       int a, b, c;	
       c = 0;
       for (a = 0; a < len; a++) {
            for (b = 0; b < 8; b++)
	    {
	        data[c] = (input[a] >> (7 - b)) & 1; 
		c++;
	    }
	}

}

void 
bit2byte(len)
{
	int a, b;
	
	for (a = 0; a < len; a++) {
		output[a] = 0;
		for (b = 0; b < 8; b++) {
			output[a]|= (recd[(a*8)+b] << (7 - b));
		}
	}

}



void Gx_gen()
{
/*
Author : Wang Yunliang
Company : Lantqi Asia Pacific Pte. Ltd.
Release date : 2014 -10 -31

Introduciton:
This BCH encoder can generate 40 bits error correction encoder file "output.bin" from original file "sample.bin"
You can choose how many errors you want to inject and the inject positions.

All rights reserved.
*/


int i,j,k,q;
int x[14];
int y[14];
int x_next[2];
int mx[100][14];

int temp1,temp2;

int z_value,nor_value;

int shift_times=0;

int shift_record[14];
int overlap;

int keep;
int message_temp=0;
int Gx_b=0;
int Gx_b_temp=0;
int ref_Gx;
int r=0;
int n=0;
int kk=0;


int Gx[Gx_num];
int Gx_temp[sector_bits];
int ref_Gx_byte[Gx_num];

int q_max=79;

int m_test;
int ref_m;

int error_num;
int error_pos[40];


int choose_num;

choose_num = m_value;
//printf("\n %d is choosed. \n",choose_num);

switch(choose_num)
{

case 3:
 m_test=3;
 ref_m=0x3;
break;

case 4:
 m_test=4;
 ref_m=0x3;
break;

case 5:
 m_test=5;
 ref_m=0x5;
break;

case 6:
 m_test=6;
 ref_m=0x3;
break;

case 7:
 m_test=7;
 ref_m=0x3;
break;

case 8:
 m_test=8;
 ref_m=0x71;
break;

case 9:
 m_test=9;
 ref_m=0x11;
break;

case 10:
 m_test=10;
 ref_m=0x9;
break;

case 11:
 m_test=11;
 ref_m=0x5;
break;

case 12:
 m_test=12;
 ref_m=0x99;
break;

case 13:
 m_test=13;
 ref_m=0x1b;
break;


}

//printf("\n m_test=%d  \n", m_test);
//printf("\n ref_m=0x%x  \n", ref_m);



//int message=0x1;
//int message_bits=50;


//uint8_t		source[512];
//uint8_t		source_temp[sector_bits];//512*8
//uint8_t		source_temp2[sector_bits];//512*8
uint8_t		temp_s;

//int 	source_len=3520;//440*8   , 72*8=576
int 	source_len=3520;//440*8   , 72*8=576
int 	byte_s;
int 	bit_s;


uint8_t temp_w;
int w_byte;
int w_bit;



FILE *input_file, *output_file;
int input_sz, output_sz;
int readlen;
int ii;



			
int t;   //use the global t
int d;

//////////////////////



t = t_value;
//printf("\n t = %d is choosed. \n",t);






////////////////////////

for(i=0;i<14;i++)
{
x[i]=0;
y[i]=0;

}
x_next[0]=0;
x_next[1]=0;






#if 1 

for(q=1;q<=q_max;q=q+2)//m1(x),m3(x),...

{
/////////////

for(i=0;i<14;i++)
{
x[i]=0;
y[i]=0;
shift_record[i]=0;

}


	x[0]=1;

	for(i=1;i<=q;i++)
	{

		x[0]=x[0]<<1;

		if((x[0]&(0x1<<m_test))!=0)
		{

			x[0]^=ref_m;

		}


		x[0]&=((0x1<<m_test)-1);


	}

x[1]=0x1;

/////////////////////

if(q>=(0x1<<m_test))
{
	shift_times=(q)%((0x1<<m_test)-1);
	//printf("q*(1<<(i-1)) = 0x%x \n",q*(1<<(i-1)));
	//printf("(0x1<<m_test)-1 = 0x%x \n",(0x1<<m_test)-1);
	//printf("shift_times = 0x%x \n",shift_times);

}
else
{
	shift_times=q;
	//printf("shift_times = 0x%x \n",shift_times);

}
shift_record[1]=shift_times;


/////////////////////////





for(i=2;i<=m_test;i++)
{

	//x_next[0]=1<<(3*(1<<(i-1)));
	//x_next[1]=1;

	overlap=0;

	if(q*(1<<(i-1))>=(0x1<<m_test))
	{
		shift_times=(q*(1<<(i-1)))%((0x1<<m_test)-1);
		//printf("q*(1<<(i-1)) = 0x%x \n",q*(1<<(i-1)));
		//printf("(0x1<<m_test)-1 = 0x%x \n",(0x1<<m_test)-1);
		//printf("shift_times = 0x%x \n",shift_times);

	}
	else
	{
		shift_times=q*(1<<(i-1));
		//printf("shift_times = 0x%x \n",shift_times);

	}

	for(j=1;j<=i-1;j++)
	{
		if(shift_times==shift_record[j])
			{
				overlap=1;
				//printf("overlap here.\n");
				break;
			}
		else
			{
				overlap=0;
			}
			
	}

	if(overlap==1)
		{
			//printf("skip current item. \n");
			continue;

		}





	shift_record[i]=shift_times;



	y[0]=0;
	for(j=0;j<=(m_test-1);j++)
	{
		y[j+1]=x[j];
	}


	
	for(j=1;j<=shift_times;j++)
	{
		for(k=0;k<=i-1;k++)
		{


		
		
			if((x[k]&(0x1<<(m_test-1)))!=0)
			{
				x[k]=(x[k]<<1)&((0x1<<m_test)-1);
				x[k]^=ref_m;
			}
			else
			{
				x[k]=(x[k]<<1)&((0x1<<m_test)-1);

			}

		}


		
	}
	
	for(j=0;j<=m_test;j++)
	{
		x[j]^=y[j];
	}




}

//printf("q= %d,x[j]^y[j]= ",q);

for(j=0;j<=m_test;j++)
{
//	printf("%4d ,",x[j]);
	mx[q][j]=x[j];
}

//printf("\n\n\n\n");

/////////////////
}	
#endif


////////////////////////////////////////////////////////////////////////
#if 1
for(i=0;i<Gx_num;i++)
{
	Gx_temp[i]=0;
	Gx[i]=0;
}

for(i=0;i<=m_test;i++)
{

	Gx_temp[i]=mx[1][i];
}

////////////
d=0;
q=1;
for(i=0;i<=m_test;i++)
{

	Gx[i]=mx[1][i];
	if(Gx[i]==1)
	{
		r=i;
	}
	
		
}



if(t<=1)
{
	keep=0;

}
else
{
	keep=1;
}

/////////////


if(keep ==1 )
{
for(q=3;q<=q_max;q=q+2)
{

	for(i=0;i<Gx_num;i++)
	{
		Gx[i]=0;
	}


	for(i=0;i<=m_test;i++)
	{
		if((mx[q][i]!=1)&&(mx[q][i]!=0))
		{
			printf("error on mx ! \n");
			return;
		}
		else if (mx[q][i]==1)
		{
			for(j=0;j<Gx_num;j++)
			{
				Gx[j+i]^=Gx_temp[j];
			}

		}
		
	}


	for(i=0;i<Gx_num;i++)
	{

		Gx_temp[i]=Gx[i];
		if(Gx[i]==1)
		{

			r=i;
		}
		
			
	}

	if(q>=(2*t-1))
	{
		break;
	}



}
}


if(q>=(2*t-1))
{
//	printf("q=%d >= (2*t-1)=%d , t=%d \n",q,(2*t-1),t);

}
else
{
	printf("failed,q<(2*t-1) \n");
	return;
}

d=2*t+1;

n=(1<<m_test)-1;
kk=n-r;



#if 1



for(j=0;j<3520;j++)
{
	for(ii=0;ii<530;ii++)
	{
	
		Gx_record[j][ii]=0;
	}
}







if(kk>=source_len)
{
//	printf("kk=%d  >= source_len=%d \n",kk,source_len);

	for(i=0;i<source_len;i++)
	{


			if(i==0)
			{
			
				for(j=0;j<Gx_num;j++)
				{
		
					Gx_temp[j]=Gx[j];
				}
			
			}

			else if(Gx_temp[r-1]==1)
			{
				//Gx_b_temp= (0x1<<(r+i))| (((Gx_b_temp<<1) &((0x1<<r)-1))^ref_Gx);
				Gx_temp[r+i]=1;
				Gx_temp[r+i-1]=0;
				for(j=(r-2);j>=0;j--)
				{
					Gx_temp[j+1]=Gx_temp[j];
				}					
				Gx_temp[0]=0;
				
				for(j=0;j<r;j++)
				{
		
					Gx_temp[j]^=Gx[j];
				}
					
			}
			else
			{
 					//Gx_b_temp= (0x1<<(r+i))| ((Gx_b_temp<<1) &((0x1<<r)-1));  	
 				Gx_temp[r+i]=1;
				Gx_temp[r+i-1]=0;
				for(j=(r-2);j>=0;j--)
				{
					Gx_temp[j+1]=Gx_temp[j];
				}					
				Gx_temp[0]=0;
			}

				for(j=0;j<r;j++)
				{
					Gx_record[i][j]=Gx_temp[j];
				}
				
			

	}
	
}
else
{
	printf("error! kk must >= source_len.\n");
	printf("kk=%d  , source_len=%d \n",kk,source_len);
	return;
}












input_file = fopen(input_str, "rb");
if (!input_file) {
		printf("Error opening file %s\n", input_str);
		return;
}


output_file = fopen(output_str, "wb");
if (!output_file) {
		printf("Error opening file %s\n", output_str);
		return;
}


fseek(input_file, 0L, SEEK_END);
input_sz = ftell(input_file);
fseek(input_file, 0L, SEEK_SET);





for(ii=0;ii<input_sz;ii+=440){
	//printf("i=%d\n",i);
	fseek(input_file, ii, SEEK_SET);  


	if(ii+440<=input_sz)
	{
		readlen=fread(input, 440, 1, input_file); 

	}
	else
	{
		readlen=fread(input, (input_sz-ii), 1, input_file); 
		for (j = (input_sz-ii); j < 440; j++)
		{
			input[j]=0;
		
		}

	}
	

	
	byte2bit(440);

	for (j = 0; j < 3520; j++)
	{
		source_temp[j]=data[j];

	}
/////////////////////////////////////////////////////////////////////////////////////////////////





for(j=0;j<sector_bits;j++)
	{
		Gx_temp[j]=0;
		source_temp2[j]=0;
	}


if(kk>=source_len)
{
//	printf("kk=%d  >= source_len=%d \n",kk,source_len);

	for(i=0;i<source_len;i++)
	{

			if(source_temp[i])
			{
			
				//message_temp = (message_temp ^ Gx_b_temp);
				for(j=0;j<r;j++)
				{
					source_temp2[j]^=Gx_record[i][j];
				}

				source_temp2[r+i]=1;
				
			}
			//printf("message_temp = 0x%x \n",message_temp);


	}
	
}
else
{
	printf("error! kk must >= source_len.\n");
	printf("kk=%d  , source_len=%d \n",kk,source_len);
	return;
}


error_num=0;
for(j=0;j<40;j++)
{
	error_pos[j]=0;
}


	error_num=0;


if((error_num>0)&&(error_num<=40))
{
	for(j=0;j<error_num;j++)
	{
		scanf("%d", &error_pos[j]);

	}

	for(j=0;j<error_num;j++)
	{
		source_temp2[error_pos[j]]^=1;

	}	
	
}
else if (error_num >40)
{
	printf("error number must <= 40 \n");
}





for (i = 0; i < 4096; i++) 
{
	w_byte=i/8;
	w_bit=i%8;
	if(w_bit==0)
	{
		temp_w=0;
	}
	

	temp_w|= ((source_temp2[i])&(0x1))<<(7-w_bit);	

	if(w_bit==7)
	{
		output[w_byte]=temp_w;
	}

}






/////////////////////////////////////////////////////////////////////////////////////////////////

	fwrite(&output, 512, 1, output_file);
 }		  


fclose(input_file);
fclose(output_file);



#endif



/////////////////////////////////

#endif 

}




int main(int argc, char *argv[])
{
	int  i,j;

        argv0 = argv[0];
	input_str = argv[1];
	output_str = argv[2];
	argv3 = argv[3];
	

	t_value = strtoul(argv3,NULL,10);


	Gx_gen();

        return 0;
	
}

