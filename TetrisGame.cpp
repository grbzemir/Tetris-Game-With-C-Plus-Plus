#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<ctime>
#include<stddef.h>

// Space Basarsanız oyun durur ve devam etmek için Herhangi bir  tuşa basmanız gerekir.
// Legolari Hareket ettirmek için A ve D tuşlarını kullanabilirsiniz.
// Legoları Çevirmek için W tuşunu kullanabilirsiniz.
// Emircan Gurbuz!

using namespace std;

const int R = 21 , C = 19 , B= 6;

char board[R][C] , KENAR[R][B];

int e11;
int e12;
int e21;
int e22;
int e31;
int e32;
int e41;
int e42;

int k11;
int k12;
int k21;
int k22;
int k31;
int k32;
int k41;
int k42;

int Sekil_No;
int Sekil_Sonraki;
int Talimat;
int i;
int j;
int a;
int b;
int c;


int Cevirmatik=0;
int Beepmatik=0;
int Bosluk=0;

int Puan=0;
int Evre=1;
int Temas=-1;
int OyunBitti=0;

void Acilis ( void );
void Bos_Cerceve ( void );
void Rastgele_Sekil ( void );
void Sekli_Kodla ( void );
void Grafik ( void );
void Sekli_Sil ( void );
void Sola_Git ( void );
void Saga_Git ( void );
void Cevir ( void );
void Asagi_Hareket ( void );
void Satir_Analizi ( void );
void Temas_Analizi ( void );
void Pause ( void );
void Oyun_Sonu ( void );


int main ()

{

   system("color 0A");
   system("Emircan Gurbuz Tetris Oyunu 2023");

   Acilis();
   Bos_Cerceve();
   Rastgele_Sekil();

   Temas=0;

   for ( ;; )

   {

    if ( OyunBitti!=0 )

    {
        Oyun_Sonu();
       
    }

    if(OyunBitti ==0 )

    {

        if (kbhit())

        {

            Talimat = getch();

            if (Talimat=='a')

            {

                if (e12-1!=0 && e22-1!=0 && e32-1!=0 && e42-1!=0)

                {

                    Sola_Git();

                }

                    
                }

            if (Talimat=='d')

            {

                if (e12+1!=C-1 && e22+1!=C-1 && e32+1!=C-1 && e42+1!=C-1)

                {
                    Saga_Git();

                }

            }

            if (Talimat=='w')

            {

                Cevir();

            }

            if (Talimat ==' ')

            {
                Pause();
                cout<<" Oyun Durdu ";
                system("pause>nul");
                
            }
            
                
            }

            if(Talimat=='a' || Talimat=='d' || Talimat=='w' || Talimat==' ')

            {
                Talimat=0;
                
            }

            Sekli_Kodla();
            Grafik();
            Temas_Analizi();

            if(Temas==0)

            {
                Sekli_Sil();
                Asagi_Hareket();
                
             if (Talimat == 0)
             {

                if (Beepmatik == 0)

                {
                    Sleep(350-Evre*75);
                    
                }
                
             }

        }

        if(Temas != 0)

        {

            Sekli_Sil();
            Satir_Analizi();
            Satir_Analizi();
            Satir_Analizi();
            Satir_Analizi();

            if(Beepmatik !=0 )

            {
                Beep( 750 , 300);
                Beepmatik=0;

           }
              
              Grafik();
              Rastgele_Sekil();
              Cevirmatik=0;
              Talimat=0;
              Temas=0;

        }
    }

}
     
     system("pause");

     return 0;

}

  void Grafik (  )

  {

    system("cls");

    for ( i = 0; i < R; i++)
    {

        cout<<"\n";

        for ( j = 0; j < C; j++)
        {
                
           cout<<board[i][j];
    
            
        }

         if ( i != 9 && i != 14 && i != 0 && i != 7 && i != 12) 

        { 

        for ( j = 0 ; j < B ; j ++ ) 

        { 

            cout << KENAR [ i ] [ j ] ; 

            } 


            }
        
    

    if (i==0)

    {
      
      cout<<"Sonra";
        
    }

    if (i==7)

    {
      
      cout<<"Puan";
        
    }

    if (i==9)

    {
      
      cout<<" "<<Puan;
        
    }

    if (i==12)

    {
      
      cout<<"Evre";
        
    }

    if (i==14)

    {
      
      cout<<" "<<Evre;
        
    }


  }

  }

  void Sola_Git (  )

    {
         
        e12=e12-1;
        e22=e22-1;
        e32=e32-1;
        e42=e42-1;
        
        e11=e11-1;
        e21=e21-1;
        e31=e31-1;
        e41=e41-1;

    }

    void Saga_Git (  )
    
        {
             
            e12=e12+1;
            e22=e22+1;
            e32=e32+1;
            e42=e42+1;
            
            e11=e11+1;
            e21=e21+1;
            e31=e31+1;
            e41=e41+1;
    
        }

    void Asagi_Hareket (  )

    {
         
        e11=e11+1;
        e21=e21+1;
        e31=e31+1;
        e41=e41+1;
        

    }

    void Cevir()

    {

        Cevirmatik++;

        if (Sekil_No==1)

        {

            if (Cevirmatik%2 ==1)
            {
                e11=e11+1;
                e12=e12-1;
                e31=e31-1;
                e32=e32+1;
                e41=e41-2;
                e42=e42+2;

            }

             if (Cevirmatik%2 ==0)

             {
                    e11=e11-1;
                    e12=e12+1;
                    e31=e31+1;
                    e32=e32-1;
                    e41=e41+2;
                    e42=e42-2;
                    
                
             }
                
                
            }

        if (Sekil_No==3)

        {

      if ( Cevirmatik % 4 == 1 ) 
      
     { 
         e11 += 1; 
         e12 -= 1; 
         e21 -= 1; 
         e22 += 1; 
         e41 += 1;
         e42 -= 1; 
         
     }
        if ( Cevirmatik % 4 == 2 ) 
        
        { 
             e11 += 1; 
             e12 += 1; 
             e21 += 1; 
             e22 -= 1; 
             e41 -= 1; 
             e42 += 1;

        }

        if ( Cevirmatik % 4 == 3 ) 
        
        { 
            e11 -= 1; 
            e12 += 1; 
            e21 -= 1; 
            e22 += 1; 
            e41 += 1; 
            e42 -= 1;

        }

        if ( Cevirmatik % 4 == 0 ) 
        
        { 
            e11 -= 1; 
            e12 -= 1; 
            e21 += 1; 
            e22 -= 1; 
            e41 -= 1; 
            e42 += 1;

        }

        }


        if ( Sekil_No == 4 ) 

        {

        if ( Cevirmatik % 4 == 1 ) 

        { 

        e11 += 1; 
        e12 -= 1; 
        e31 -= 1; 
        e32 += 1; 
        e41 -= 2; 

        }

        if ( Cevirmatik % 4 == 2 ) 

        { 

        e11 += 1; 
        e12 += 2; 
        e22 += 1; 
        e31 -= 1; 
        e42 -= 1; 

        }

        if ( Cevirmatik % 4 == 3 ) 

        { 

         e11 -= 2;
         e12 += 1;
         e21 -= 1; 
         e32 -= 1;
         e41 += 1;

        }

        if ( Cevirmatik % 4 == 0 ) 
        
        { 

        e12 -= 2; 
        e21 += 1; 
        e22 -= 1; 
        e31 += 2; 
        e41 +=1; 
        e42 += 1; 
        
        }


        
        }

     
    if ( Sekil_No == 5 ) 

    {

        if ( Cevirmatik % 4 == 1 )
         {
             e11 += 1 ; 
             e12 -= 1 ; 
             e31 -= 1 ; 
             e32 += 1 ; 
             e42 += 2 ;

        }

        if ( Cevirmatik % 4 == 2 ) 
        { 

        e11 += 1 ; 
        e12 += 1 ; 
        e31 -= 1 ; 
        e32 -= 1 ; 
        e41 -= 2 ; 

        }

        if ( Cevirmatik % 4 == 3 ) 
        { 

        e11 -= 1 ;
        e12 += 1 ;
        e31 += 1 ;
        e32 -= 1 ;
        e42 -= 2 ;
             
        }

        if ( Cevirmatik % 4 == 0 ) 
        { 
            e11 -= 1 ; 
            e12 -= 1 ; 
            e31 += 1 ; 
            e32 += 1 ; 
            e41 += 2 ; 
            
            }

        }
                    
    if ( Sekil_No == 6 ) 
    {

        if ( Cevirmatik % 2 == 1 ) 
        { 

        e11 -= 1; 
        e12 += 1; 
        e31 -= 1;
        e22 -= 1; 
        e42 -= 2;

        }

        if ( Cevirmatik % 2 == 0 )

        { 
            e11 += 1;
            e12 -= 1; 
            e31 += 1; 
            e22 += 1;
            e42 += 2; 

             }

        }
                    
    if ( Sekil_No == 7 ) 

    {
        if ( Cevirmatik % 2 == 1 ) 
        { 

        e21 += 1; 
        e32 += 1; 
        e41 += 1; 
        e42 += 1; 

        }

        if ( Cevirmatik % 2 == 0 ) 
        { 

        e21 -= 1; 
        e32 -= 1;
        e41 -= 1; 
        e42 -= 1; 

         }

        }
    
    }

    void Rastgele_Sekil()

    {

        srand(time(NULL));

        if(Temas==-1)

        {

            Sekil_No=rand()%7+1;


        }

        if (Temas!=-1)

        {
        
       Sekil_No=Sekil_Sonraki;
           
        }

        if ( Sekil_No == 1 ) 

       {

         e11 = 0; e12 = ( C - 1 ) / 2; 
         e21 = 1; e22 = ( C - 1 ) / 2; 
         e31 = 2; e32 = ( C - 1 ) / 2; 
         e41 = 3; e42 = ( C - 1 ) / 2;

            }           
            
        if ( Sekil_No == 2 ) 

        {

            e11 = 0; e12 = ( C - 3 ) / 2; 
            e21 = 0; e22 = ( C - 1 ) / 2; 
            e31 = 1; e32 = ( C - 3 ) / 2; 
            e41 = 1; e42 = ( C - 1 ) / 2; 

            }
            
        if ( Sekil_No == 3 ) 

        {
            e11 = 0; e12 = ( C - 1 ) / 2;
            e21 = 1; e22 = ( C - 3 ) / 2;  
            e31 = 1; e32 = ( C - 1 ) / 2; 
            e41 = 1; e42 = ( C + 1 ) / 2; 

            }
            
        if ( Sekil_No == 4 ) 

        { 

            e11 = 0; e12 = ( C - 1 ) / 2; 
            e21 = 1; e22 = ( C - 1 ) / 2; 
            e31 = 2; e32 = ( C - 1 ) / 2; 
            e41 = 2; e42 = ( C + 1 ) / 2; 

            }
            
        if ( Sekil_No == 5 ) 

        {

            e11 = 0; e12 = ( C - 1 ) / 2; 
            e21 = 1; e22 = ( C - 1 ) / 2; 
            e31 = 2; e32 = ( C - 1 ) / 2; 
            e41 = 2; e42 = ( C - 3 ) / 2; 

            }
            
        if ( Sekil_No == 6 ) 

        {
            e11 = 0; e12 = ( C - 3 ) / 2; 
            e21 = 0; e22 = ( C - 1 ) / 2; 
            e31 = 1; e32 = ( C - 1 ) / 2; 
            e41 = 1; e42 = ( C + 1 ) / 2; 

            }
            
        if ( Sekil_No == 7 ) 

        { 
            e11 = 0; e12 = ( C - 1 ) / 2; 
            e21 = 0; e22 = ( C + 1 ) / 2;
            e31 = 1; e32 = ( C - 3 ) / 2; 
            e41 = 1; e42 = ( C - 1 ) / 2; 

            }
      
         Sekil_Sonraki = rand () % 7 + 1;

        if ( Sekil_Sonraki == 1 ) 

        { 
            k11 = 2; 
            k12 = 2; 
            k21 = 3; 
            k22 = 2; 
            k31 = 4; 
            k32 = 2; 
            k41 = 5; 
            k42 = 2; 
            
       }

        if ( Sekil_Sonraki == 2 ) 

        {

            k11 = 2;
            k12 = 2; 
            k21 = 2; 
            k22 = 3;
            k31 = 3;
            k32 = 2; 
            k41 = 3; 
            k42 = 3;

            }

        if ( Sekil_Sonraki == 3 ) 

        { 
            k11 = 2; 
            k12 = 2; 
            k21 = 3; 
            k22 = 2; 
            k31 = 4;
            k32 = 2; 
            k41 = 3; 
            k42 = 3; 

        }

        if ( Sekil_Sonraki == 4 ) 

        { 
            k11 = 2; 
            k12 = 2;
            k21 = 3; 
            k22 = 2; 
            k31 = 4; 
            k32 = 2; 
            k41 = 4;
            k42 = 3; 

        }



        if ( Sekil_Sonraki == 5 ) 

        { 
             k11 = 2;
             k12 = 3; 
             k21 = 3; 
             k22 = 3; 
             k31 = 4; 
             k32 = 3; 
             k41 = 4; 
             k42 = 2; 
             
        }

        if ( Sekil_Sonraki == 6 ) 

        { 
             k11 = 2;
             k12 = 3; 
             k21 = 3; 
             k22 = 3; 
             k31 = 3; 
             k32 = 2; 
             k41 = 4; 
             k42 = 2; 

        }

        if ( Sekil_Sonraki == 7 ) 

        { 
            k11 = 2;
            k12 = 2; 
            k21 = 3;
            k22 = 2;
            k31 = 3;
            k32 = 3; 
            k41 = 4; 
            k42 = 3; 
               
            }
 
}

        void Sekli_Sil()

        {

            if(Temas==0)

         {

            board[e11][e12] = ' '; 
            board[e21][e22] = ' ';
            board[e31][e32] = ' ';
            board[e41][e42] = ' ';

        }

       if(Temas!=0 && OyunBitti==0) 

       {

          KENAR[k11][k12]=' ';
          KENAR[k21][k22]=' ';
          KENAR[k31][k32]=' ';
          KENAR[k41][k42]=' ';

        
       }           

}

        void Sekli_Kodla()

        {

            board[e11][e12] = 'X';
            board[e21][e22] = 'X';
            board[e31][e32] = 'X';
            board[e41][e42] = 'X';

            KENAR[k11][k12] = 'X';
            KENAR[k21][k22] = 'X';
            KENAR[k31][k32] = 'X';
            KENAR[k41][k42] = 'X';

        }

      

        void Bos_Cerceve ( )

{

 for ( i = 0 ; i < R ; i ++ )

 {
     for ( j = 0 ; j < C ; j ++ )

     {
         board [ i ] [ j ] = ' ';
         
         if ( j < B ) 

         {
              KENAR [ i ] [ j ] = ' ';

              } 

              }

              }
                                
 for ( j = 0 ; j < C ; j ++ ) 

 {

     }
 
 for ( i = 0 ; i < R ; i ++ )

 {
     board [ i ] [ 0 ] = '|';
     board [ i ] [ C - 1 ] = '|'; 

     }
 
}

void Temas_Analizi ( )

{ 
  a = 1; b = 0;
     
  if ( board [ e11 + a ] [ e12 + b ] == 'X' || board [ e11 + a ] [ e12 + b ] == '|' ) 

  {
       if ( e11 + a != e21 || e12 + b != e22 ) 

       {
            if ( e11 + a != e31 || e12 + b != e32 )

            {
                 if ( e11 + a != e41 || e12 + b != e42 ) 

                 {
                      Temas++;

                      }

                      }

                      }

                      }
                                                                                
  if ( board [ e21 + a ] [ e22 + b ] == 'X' || board [ e21 + a ] [ e22 + b ] == '|' )

  {
       if ( e21 + a != e11 || e22 + b != e12 ) 

       {
            if ( e21 + a != e31 || e22 + b != e32 )

            {
                 if ( e21 + a != e41 || e22 + b != e42 )

                 {
                     Temas++;
                     }

                     }

                     }

                     }
                                                                                
  if ( board [ e31 + a ] [ e32 + b ] == 'X' || board [ e31 + a ] [ e32 + b ] == '|' ) 

  {
       if ( e31 + a != e21 || e32 + b != e22 ) 

       {
            if ( e31 + a != e11 || e32 + b != e12 ) 

            {
                 if ( e31 + a != e41 || e32 + b != e42 ) 

                 {
                     Temas++;
                     }

                     }

                     }

                     }
                                                                                
  if ( board [ e41 + a ] [ e42 + b ] == 'X' || board [ e41 + a ] [ e42 + b ] == '|' ) 

  {
       if ( e41 + a != e21 || e42 + b != e22 ) 

       {
            if ( e41 + a != e31 || e42 + b != e32 )

            {
                 if ( e41 + a != e11 || e42 + b != e12 )

                 {
                      Temas++;

                      }

                      }

                      }

                      }
                 
  if ( Temas != 0 ) 

  { 
       if ( e11 == 1 || e21 == 1 || e31 == 1 ||e41 == 1 ) 

       {
            OyunBitti++; 

            } 

            }
}

void Satir_Analizi ( )

{

 for ( i = R - 2; i > 0; i -- ) 

 {
     for ( j = 1; j < C - 1; j ++ ) 

     {
         if ( board [ i ] [ j ] == ' ' ) 

         {
              Bosluk ++;

              }

              }
      
     if ( Bosluk == 0 )

     {
          Puan ++;
          Evre = Puan / 10 + 1;
          Beepmatik ++;    
               
          for ( a = 0; a < i - 3; a ++ )

          {
              for ( b = 1; b < C - 1; b ++ ) 

              {
                  board [ i - a ] [ b ] = board [ i - a - 1 ] [ b ]; 

                  }

                  }

                  }
                          
     Bosluk = 0; 

     }

}

void Oyun_Sonu ( )

{
     for ( i = R / 2 - 2; i < R / 2 + 3; i ++ ) 

     {
        
         {
             board [ i ] [ j ] = ' ';

             }

             }
    
     board [ R / 2 ] [ C / 2 - 5 ] = 'O';
     board [ R / 2 ] [ C / 2 - 4 ] = 'y';
     board [ R / 2 ] [ C / 2 - 3 ] = 'u'; 
     board [ R / 2 ] [ C / 2 - 2 ] = 'n';
     board [ R / 2 ] [ C / 2 + 0 ] = 'B';
     board [ R / 2 ] [ C / 2 + 1 ] = 'i'; 
     board [ R / 2 ] [ C / 2 + 2 ] = 't'; 
     board [ R / 2 ] [ C / 2 + 3 ] = 't'; 
     board [ R / 2 ] [ C / 2 + 4 ] = 'i';
     
     Grafik ( );
     Sleep( 2500 );
     Acilis ( );
}

void Acilis ( )

{

 cout << "\n\n";    

 system("cls");
 
 cout << "\n                                                  \n   ";
 cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX     \n   ";
 cout << "X                                             X     \n   ";
 cout << "X XXX             XXX             X           X     \n   ";
 cout << "X XXX             XXX            XXX          X     \n   ";
 cout << "X XXX             XXX                         X     \n   ";
 cout << "X XXXXXX XXXXXXXX XXXXXX XXXXXXX XXX XXXXXXX  X     \n   ";
 cout << "X XXX    XXX  XXX XXX    XXX     XXX XXX      X     \n   ";
 cout << "X XXX    XXXXXXXX XXX    XXX     XXX XXXXXXXX X     \n   ";
 cout << "X XXX    XXX      XXX    XXX     XXX      XXX X     \n   ";
 cout << "X XXX    XXXXXXX  XXX    XXX     XXX  XXXXXXX X     \n   "; 
 cout << "X                                             X     \n   "; 
 cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX \n\n\n   "; 
 cout << "XXXXXXX TETRIS            \n   ";
 cout << "XXXXXXX Emircan Gurbuz  \n\n   "; 




 if ( OyunBitti == 0 )

  {
     Sleep ( 2000 ); 

  } 

 if ( OyunBitti != 0 ) 

 {
      cout << "XXXXXXX PUAN: " << Puan;
      
      Bos_Cerceve ( ); 
      OyunBitti = 0;
      Puan = 0;
      Evre = 1; 
      Sleep ( 5000 ); 
      getch();


      int main(); 

 } 

}


void Pause ( )

{

 while ( ! kbhit ( ) ) 

 {
       system ( "CLS" );
       
       cout << "\n\n   TETRIS\n\n\n   ";
       cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"; 
       cout << "\n\n\n\n\n\n\n\n\n\n\n   ";
       cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"; 
       
       Sleep ( 600 );
       system ( "CLS" );
       
       cout << "\n\n   TETRIS \n\n\n" ;

       cout<<"Emircan Gurbuz";
       Sleep ( 600 ) ;

 }

}

