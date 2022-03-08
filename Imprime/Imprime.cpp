#include <Imprime.h>

//globais
int _nivelSerial = 0;
long _ledon = 500;
long _ledoff = 1000;
long _tempoLedOn = 500;
long _tempoLedOff = 1000;
int _pinoLed = LED_BUILTIN;
String _serial = "";
Imprime::Imprime()
{
}

void Imprime::temposLed(int tempoLigado, int tempoDesligado)
{
  _tempoLedOn = tempoLigado;
  _tempoLedOff = tempoDesligado;
}

void Imprime::ledDebug(int pino){
  _pinoLed = pino;
  pinMode(_pinoLed, OUTPUT);
} 

void Imprime::piscaLed()
{  
  if (_ledon < millis()) {
    digitalWrite(_pinoLed, HIGH);
    _ledon = millis() + _tempoLedOn;
    _ledoff =  millis() + _tempoLedOff;
  }
  if (_ledoff < millis()) {
    digitalWrite(_pinoLed, LOW);
    _ledoff =  millis() + _tempoLedOff;
  }
}

void Imprime::seta_nivel(int nivel)
{
  _nivelSerial = nivel;
}

void Imprime::pula_linha(int nivel)
{
  if (nivel == _nivelSerial)
  {
    Serial.println();
    _serial += "\n";
  }
}

String Imprime::stringSerial(){
  String serialTemp = _serial;
  _serial = "";
  return serialTemp;
}
void Imprime::separador(int nivel)
{
  if (nivel == _nivelSerial)
  {
    Serial.println("---------------------------------------------------");
    _serial += "--------------------------------------------------- \n";
  }
}

void Imprime::print(String texto, String valor, int nivel)
{
  bool podeImprimir = false;
  if (nivel == 0)
  {
    podeImprimir = true;
  }
  if (nivel == _nivelSerial)
  {
    podeImprimir = true;
  }

  if (_nivelSerial == 9)
  {
    podeImprimir = true;
  }
  //nivelSerial
  if (podeImprimir)
  {
    Serial.print(texto);
    Serial.println(valor);
    if(_serial.length() > 2300){
        _serial = "";
    }
    _serial += texto + valor + "\n";
  }
}


