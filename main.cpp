#include<graphics.h>
#include<math.h> 

int pencere_genislik=1000;
int pencere_yukseklik=1000;
int noktalar_arasi_mesafe=25;



void KoordinatSistemiCiz()
{    setcolor(RED);
     line(0, pencere_yukseklik/2, pencere_genislik, pencere_yukseklik/2);
     
     line(pencere_genislik/2, 0, pencere_genislik/2, pencere_yukseklik);

int i,k;
setfillstyle(1,1);
setcolor(BLUE);
     for(i=0;i<=pencere_genislik;i+=noktalar_arasi_mesafe)
        { 
        	fillellipse(i,pencere_yukseklik/2,4,4);
	 
   	    }
setcolor(BLUE);
     for(i=0;i<=pencere_yukseklik;i+=noktalar_arasi_mesafe)
        { 
		    fillellipse(pencere_genislik/2,i,4,4);
	    }	

                       
char dizi[1000];
k=0;
for(i=pencere_genislik/2;i<=pencere_genislik;i+=noktalar_arasi_mesafe)
{
	sprintf(dizi,"%d",k);
	outtextxy(i-10,pencere_yukseklik/2+2,dizi);
	k+=1;
}
k=0;
for(i=pencere_genislik/2;i>=-pencere_genislik;i-=noktalar_arasi_mesafe)
{
	sprintf(dizi,"%d",k);
	outtextxy(i-10,pencere_yukseklik/2+2,dizi); 
	k-=1;
}
k=0;
for(i=pencere_yukseklik/2;i<=pencere_yukseklik;i+=noktalar_arasi_mesafe)
{
	sprintf(dizi,"%d",k);
	outtextxy(pencere_genislik/2+2,i-10,dizi);
	k-=1;
}
k=0;
for(i=pencere_yukseklik/2;i>=-pencere_yukseklik;i-=noktalar_arasi_mesafe)
{
	sprintf(dizi,"%d",k);
	outtextxy(pencere_genislik/2+2,i-10,dizi);
	k+=1;
}

}

void NoktaCiz(double x, double y)
{

fillellipse(pencere_genislik/2+x*noktalar_arasi_mesafe,pencere_yukseklik/2-y*noktalar_arasi_mesafe,4,4);	
}

void CemberCiz(double x,double y,double r)
{ 
setcolor(WHITE);
circle(pencere_genislik/2+x*noktalar_arasi_mesafe,pencere_yukseklik/2-y*noktalar_arasi_mesafe,r*noktalar_arasi_mesafe);
}

  double d;
  double e;
	  
 double XKoordinatToplami=0,YKoordinatToplami=0;
 double iki_nokta_arasi_mesafe(double a,double b)
{ 
return sqrt((a*a+b*b));
}

void YaricapCiz(double a,double b,double r)
{   
    
    
   
    
	line(pencere_genislik/2+a*noktalar_arasi_mesafe, pencere_yukseklik/2-b*noktalar_arasi_mesafe,
	pencere_genislik/2+a*noktalar_arasi_mesafe+r*noktalar_arasi_mesafe,pencere_yukseklik/2-b*noktalar_arasi_mesafe);
}




int main(){

    int i,j;
    int nokta_sayisi=0;
    
 
  
    int x[100],y[100];
	char karakter;
    FILE *dosya;
    
        dosya=fopen("koordinatlar.txt","r");
        if((dosya=fopen("koordinatlar.txt","r"))!=NULL)
        { int i=0;
           while(!feof(dosya))
           {
           	fscanf(dosya,"%d%c%d",&x[i],&karakter,&y[i]);
               printf("%d\n",x[i]);
               printf("%d\n",y[i]);
			   XKoordinatToplami+=x[i];
               YKoordinatToplami+=y[i];
               i++;
               nokta_sayisi++;
		   }
        }
        else
        {
           printf("Dosya Bulunamadý");
        }
      
	    
        printf("nokta%d\n",nokta_sayisi);
        printf("%1f\n",XKoordinatToplami);
        printf("%1f\n",YKoordinatToplami);
        double ortalamax,ortalamay;
        ortalamax=XKoordinatToplami/nokta_sayisi;
        ortalamay=YKoordinatToplami/nokta_sayisi;
        
    
   
   
   
   
      double p=0.02;
 
	  
       
       
       for(i=0;i<30000;i++)
       { 
	     int f=0;
         d=iki_nokta_arasi_mesafe(ortalamax-x[0],ortalamay-y[0]);
        for(j=1;j<nokta_sayisi;j++)
        { 
		e=iki_nokta_arasi_mesafe(ortalamax-x[j],ortalamay-y[j]);
        if(d<e)
        { 
		  d=e;
          f=j;		}
		
       	}
		ortalamax+=(x[f]-ortalamax)*p;
		ortalamay+=(y[f]-ortalamay)*p;
		p*=0.98;
}
        printf("%1f\n%1f\n%1f\n",ortalamax,ortalamay,d);
	   
	    initwindow(pencere_genislik,pencere_yukseklik,"");
        KoordinatSistemiCiz();
        for(int i=0;i<nokta_sayisi;i++)
        { 
		setcolor(GREEN);
        setfillstyle(1,GREEN);
		NoktaCiz(x[i],y[i]);
		}
		CemberCiz(ortalamax,ortalamay,d);
	   double yaricap=d;
		 setcolor(WHITE);
         setfillstyle(1,WHITE);
        NoktaCiz(ortalamax,ortalamay);
        
        setcolor(RED);
        YaricapCiz(ortalamax,ortalamay,yaricap);
        printf("{Mx,My} -> { %1f , %1f }\n",ortalamax,ortalamay);
        printf("Yaricap = %1f ",yaricap);
        

	

	  	getch();
       
       fclose(dosya);
       return 0;
	   
}
