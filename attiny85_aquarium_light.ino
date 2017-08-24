// řízení osvětlení akvária
// Pomocí jednoho logického signálu 0/1 řídí rozsvědcení, zhasínání akvária.
// Vždy při změně signálu 0-1 následuje rozsvědcecí sekvence a pak trvale svítí.
// Vždy pak po změně signálu 1-0 následuje zhasínací sekvence a pak trvale off.
// Priklad PWM zde : http://www.technoblogy.com/show?LE0

// HEX zkopírovat do adresáře k AVRDUDE Win a vypálit
// 24.8.2017 - první app, funguje
// opravit chzbku  sviti trvale lehce po stmivaci sekvenci

#include <EEPROM.h>

#define INPUT_PIN 4 //P4
#define PWM_LED_PIN 1 // P1

#define PWM_LIGHTUP 60
#define PWM_LIGHDOWN 60

unsigned long minuly_cas, nynejsi_cas, rozdil;
int EEsize = 512; // size in bytes of your board's EEPROM

int pinstate, pinstate_last;
unsigned char f_lighton, f_lightoff;

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
void setup()
{
  // put your setup code here, to run once:
 pinMode(INPUT_PIN, INPUT_PULLUP);
 pinMode(PWM_LED_PIN, OUTPUT);
 
 // uvodni hodnoty
 pinstate_last = LOW;
 pinstate = LOW;
 f_lighton = 0;
 f_lightoff = 0;
}

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
void loop() 
{
 pinstate = digitalRead(INPUT_PIN);

 if ((pinstate_last == LOW) && (pinstate == HIGH))
 { // detekce zmeny pro rozsviceni
  f_lighton = PWM_LIGHTUP;
  f_lightoff = 0;
 }

 if ((pinstate_last == HIGH) && (pinstate == LOW))
 { // detekce zmeny pro zhasinani
  f_lighton = 0;
  f_lightoff = PWM_LIGHDOWN;
 }

 if (f_lighton > 0)
 { // obsluha rozsvedceni
  analogWrite(PWM_LED_PIN, (PWM_LIGHTUP - f_lighton));
  f_lighton--;
 }

 if (f_lightoff > 0)
 { // obsluha rozsvedceni
  analogWrite(PWM_LED_PIN, f_lightoff);
  f_lightoff--;
 }

 pinstate_last = pinstate;
 delay(500);
}


