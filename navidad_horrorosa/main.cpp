// miniblip led matrix demo

#include "mbed.h"
#include "neopixel.h"
#include "pitches.h"

// Matrix led output pin
#define DATA_PIN P0_9
DigitalIn pushbutton(P0_23);

#define MUTE  0.0
#define END   1.0
//-- Notes and frequencies (Hz)
#define DO_4  261.626
#define MI_4  329.628 
#define SOL_4 391.995 
#define SI_4  493.883
#define DO_5  523.251

//-- Tempo
#define TEMPO 200

//-- Default volume
#define VOL 0.4


/*int jingleBells[] = { N_E5, N_E5, N_E5, N_E5, N_E5, N_E5, N_E5, N_G5, N_C5, N_D5, N_E5,
                      N_F5, N_F5, N_F5, N_F5, N_F5, N_E5, N_E5, N_E5, N_E5, N_D5, N_D5, N_E5, N_D5, N_G5,
                      N_E5, N_E5, N_E5, N_E5, N_E5, N_E5, N_E5, N_G5, N_C5, N_D5, N_E5,
                      N_F5, N_F5, N_F5, N_F5, N_F5, N_E5, N_E5, N_E5, N_G5, N_G5, N_F5, N_D5, N_C5};*/
/*int tempo[] = { 3, 4, 8, 4, 4, 8, 4, 4, 4, 4, 16,
                               4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 8,
                               4, 4, 8, 4, 4, 8, 4, 4, 4, 4, 16,
                               4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 16 };*/
int jingleBells[] = { N_E5, N_E5, N_E5, N_E5, N_E5, N_E5, N_E5, N_G5, N_C5, N_D5, N_E5,
                      N_F5, N_F5, N_F5, N_F5, N_F5, N_E5, N_E5, N_E5, N_E5, N_D5, N_D5, N_E5, N_D5, N_G5,
                      N_E5, N_E5, N_E5, N_E5, N_E5, N_E5, N_E5, N_G5, N_C5, N_D5, N_E5,
                      N_F5, N_F5, N_F5, N_F5, N_F5, N_E5, N_E5, N_E5, N_G5, N_G5, N_F5, N_D5, N_C5};
int tempo[] = { 2, 2, 4, 2, 2, 4, 2, 2, 2, 2, 8,
                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4,
                               2, 2, 4, 2, 2, 4, 2, 2, 2, 2, 8,
                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 8 };

                 
//-- Declare speaker object
PwmOut speaker(P0_8);

void play()
{
  int i=0;
  
  //-- Reproduce all the notes in the list
  while(jingleBells[i] != END) {
    
    //-- If silence, turn of the PWM
    if (jingleBells[i] == MUTE) {
      speaker = 0.0;
    }
    else {
      speaker.period(1.0/jingleBells[i]);  //-- Note
      speaker = VOL;                 //-- Set the volume
    }  
    //-- Note duration
    wait_ms(TEMPO * tempo[i]);
    
    //-- Move to the next note
    i++;
  }  
  
  //-- Turn off the speacker
  speaker = MUTE;
}

void void_matrix(neopixel::Pixel* aux, int tam=25){
    
    for(int i=0;i<tam;i++){
        aux[i].red=0;
        aux[i].green=0;
        aux[i].blue=0;
    }
}

//Si color = 1 --> rojo. Si color = 2 --> azul Si color = 3 --> azul
void encenderLed(neopixel::Pixel* aux,int posicion,int color){
    
    if(color == 1){
        aux[posicion].red = 0x33;
        aux[posicion].blue = 0x00;
        aux[posicion].green = 0x00;
    }else if(color == 2){
        aux[posicion].red = 0x00;
        aux[posicion].blue = 0x33;
        aux[posicion].green = 0x00;
    }else if(color == 3){
        aux[posicion].red = 0x00;
        aux[posicion].blue = 0x00;
        aux[posicion].green = 0x33;        
    }else if(color == 4){
        aux[posicion].red = 0x00;
        aux[posicion].blue = 0x00;
        aux[posicion].green = 0x00; 
    }else if(color == 5){ //morado
        aux[posicion].red = 0x22;
        aux[posicion].blue = 0x33;
        aux[posicion].green = 0x11; 
    }else if(color == 6){ //blanco
        aux[posicion].red = 0x255;
        aux[posicion].blue = 0x255;
        aux[posicion].green = 0x255; 
    }
}
//Si color = 1 --> rojo. Si color = 2 --> azul Si color = 3 --> azul
void X(neopixel::Pixel* aux){
    
    void_matrix(aux);
    encenderLed(aux,4,1);
    encenderLed(aux,8,1);    
    encenderLed(aux,16,1);    
    encenderLed(aux,20,1);
    encenderLed(aux,0,1);    
    encenderLed(aux,6,1); 
    encenderLed(aux,18,1);
    encenderLed(aux,24,1);
    
}

void M(neopixel::Pixel* aux){
    
    void_matrix(aux);
    encenderLed(aux,24,1);
    encenderLed(aux,19,1);    
    encenderLed(aux,14,1);    
    encenderLed(aux,9,1);
    encenderLed(aux,4,1);    
    encenderLed(aux,8,1); 
    encenderLed(aux,12,1);
    encenderLed(aux,6,1);
    encenderLed(aux,0,1);
    encenderLed(aux,5,1);
    encenderLed(aux,10,1);
    encenderLed(aux,15,1);
    encenderLed(aux,20,1);
    }
void A(neopixel::Pixel* aux){
    
    void_matrix(aux);
    encenderLed(aux,23,1);
    encenderLed(aux,18,1);    
    encenderLed(aux,13,1);    
    encenderLed(aux,8,1);
    encenderLed(aux,3,1);    
    encenderLed(aux,2,1); 
    encenderLed(aux,1,1);
    encenderLed(aux,6,1);
    encenderLed(aux,11,1);
    encenderLed(aux,16,1);
    encenderLed(aux,21,1);
    }
void S(neopixel::Pixel* aux){
    void_matrix(aux);
    encenderLed(aux,1,1);
    encenderLed(aux,2,1);    
    encenderLed(aux,3,1);    
    encenderLed(aux,8,1);
    encenderLed(aux,13,1);    
    encenderLed(aux,12,1);  
    encenderLed(aux,11,1);
    encenderLed(aux,16,1);
    encenderLed(aux,21,1);
    encenderLed(aux,22,1);
    encenderLed(aux,23,1);
    }
    
    void arbol(neopixel::Pixel* aux){
    
    void_matrix(aux);
    encenderLed(aux,2,6);
    encenderLed(aux,7,3);    
    encenderLed(aux,13,1);
    encenderLed(aux,12,3);
    encenderLed(aux,11,2);
    encenderLed(aux,19,1);
    encenderLed(aux,18,3);
    encenderLed(aux,17,2);
    encenderLed(aux,16,3);
    encenderLed(aux,15,2);
    encenderLed(aux,22,5);    
    
}


void acero(neopixel::Pixel* aux){
    void_matrix(aux);
    encenderLed(aux,0,4);
    }


int main() {
    int i;
    neopixel::Pixel vector[25];
    
    neopixel::PixelArray array(DATA_PIN);
    
    //int contador = 0;
    while(true){
            acero(vector);
            array.update(vector,25); 
            
            arbol(vector);
            array.update(vector,25);            
            wait(1);
            play();
        
            X(vector);
            array.update(vector,25);            
            wait(1);
                 
            M(vector);
            array.update(vector,25);
            wait(1);
            
            A(vector);
            array.update(vector,25);
            wait(1);
            
            S(vector);
            array.update(vector,25);    
            wait(1);
            
    
    
    }
 
    
}
