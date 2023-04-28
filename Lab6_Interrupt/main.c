#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
uint8_t button = 0;

ISR (INT0_vect){
    button = !button;
    PORTB ^= (1<<PORTB1);
}

int main(void) {
    PORTD |= (1<<PORTB2);
    DDRB  &= ~(1<<DDB2); 
    DDRB  |=  (1<<DDB1);
    
    MCUCR |= (1<<ISC01);
    EIMSK |= (1<<INT0);
    sei();
  

    while(1)
    {
        if (button == 0) {
            PORTB |= (1 << DDB1);
            _delay_ms(2000);
            PORTB &= ~(1 << DDB1);
            _delay_ms(2000);
        }
        else
        {
            PORTB &= ~( 1 << DDB1);
            _delay_ms(2000);
        }
    }
}

void loop() {
    
}
