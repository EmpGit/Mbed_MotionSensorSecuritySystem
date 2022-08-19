#include "mbed.h"

DigitalOut Buzzer (D3); // defines pin for buzzer
InterruptIn PIR(D2); // defines pin for motion sensor
int PIR_Detected = 0; //initializes motion detection to not detecting anything

void irq_handler(void)
{
    PIR_Detected = 1; // Keeps motion sensor on
}

DigitalOut led[7]= {D7, D12, D8, D13, D11, D9, D10}; //pins of all segments in 7-segment display
int number[10][7]= { //array for each number for 7-segment display
    {1,1,1,0,1,1,1},          //zero
    {0,0,1,0,0,1,0},          //one
    {1,0,1,1,1,0,1},          //two
    {1,0,1,1,0,1,1},          //three
    {0,1,1,1,0,1,0},          //four
    {1,1,0,1,0,1,1},          //five
    {1,1,0,1,1,1,1},          //six
    {1,0,1,0,0,1,0},          //seven
    {1,1,1,1,1,1,1},          //eight
    {1,1,1,1,0,1,1},          //nine
};


int main()
{
    PIR.rise(&irq_handler); //runs the function for motion detector to be on
    while(1) {
        if (PIR_Detected) { // on only when something is detected.
            wait(1);
            for(int i = 0; i<7; i++) {
                led[i] = 0; //sets initial value showned on 7-segment display to Zero
            }
            for (int i=0; i<7; i++) {
                led[i] = number[9][i]; //number nine displayed on 7-segment
            }
            wait(0.5);
            for (int i=0; i<7; i++) {
                led[i] = number[8][i]; //number eight displayed on 7-segment
            }
            wait(0.5);
            for (int i=0; i<7; i++) {
                led[i] = number[7][i]; //number seven displayed on 7-segment
            }
            wait(0.5);
            for (int i=0; i<7; i++) {
                led[i] = number[6][i]; //number six displayed on 7-segment
            }
            wait(0.5);
            for (int i=0; i<7; i++) {
                led[i] = number[5][i]; //number five displayed on 7-segment
            }
            wait(0.5);
            for (int i=0; i<7; i++) {
                led[i] = number[4][i]; //number four displayed on 7-segment
            }
            wait(0.5);
            for (int i=0; i<7; i++) {
                led[i] = number[3][i]; //number three displayed on 7-segment
            }
            wait(0.5);
            for (int i=0; i<7; i++) {
                led[i] = number[2][i]; //number two displayed on 7-segment
            }
            wait(0.5);
            for (int i=0; i<7; i++) {
                led[i] = number[1][i]; //number one displayed on 7-segment
            }
            wait(0.5);
            for (int i=0; i<7; i++) {
                led[i] = number[0][i]; //number zero displayed on 7-segment
            }
            wait(0.5);
            Buzzer = true; // buzzer On
            wait (0.5);
            PIR_Detected = 0; //resets motion sensor to pick up motion again
            wait(1);
        }

        else {
            Buzzer = false;  //buzzer turned off
            wait(1);        //for warming up time
        }

    }
}
