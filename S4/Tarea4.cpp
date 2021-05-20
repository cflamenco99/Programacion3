
class Led{  
public:    
  Led(int _pin){
    pin=_pin;
    pinMode(pin,OUTPUT);
  }
  
  void encenderApagar(bool tipo){
      if(tipo){
      	digitalWrite(pin, HIGH);
      }else{
      	digitalWrite(pin, LOW);
      }
  }
  
  private:
  	int pin;
};


class Pulsador{  
public:  
  Pulsador(int _pin)
  {
    pin=_pin;
    pinMode(pin,INPUT);
  }
  
  int GetEstado()
  {    
    return digitalRead(pin);
  }
  
  private:
  	int pin;
};


class Tanque
{
  public:  
  Tanque(int _NivelMinimo, int _NivelMaximo, int _NivelActual)
  {    
    NivelMinimo = _NivelMinimo;
    NivelMaximo = _NivelMaximo;
    NivelActual = _NivelActual;
  }
  
  void SetearNivelMinimo(int nivel)
  {
    NivelMinimo = nivel;
  }
  
  void SetearNivelMaximo(int nivel)
  {
    NivelMaximo = nivel;
  }
  
  int ObtenerNivelMinimo()
  {
    return NivelMinimo;
  }
  
  int ObtenerNivelMaximo()
  {
    return NivelMaximo;
  }
  
  int ObtenerNivelActual()
  {
    return NivelActual;
  }
  
  void AumentarNivelActual()
  {
    if(NivelActual >= NivelMaximo)
    {
      Serial.println("EL NIVEL MAXIMO YA HA SIDO SUPERADO!!!");
      Led bombilloRojo(3);
      bombilloRojo.encenderApagar(1);
      delay(200);
      bombilloRojo.encenderApagar(0);
    }
    else
    {
      NivelActual++;      
    }    
  }
  
  void DisminuirNivelActual()
  {
    if(NivelActual <= NivelMinimo)
    {
      Serial.println("EL NIVEL MINIMO YA HA SIDO SUPERADO!!!");
      Led bombilloRojo(3);
      bombilloRojo.encenderApagar(1);
      delay(200);
      bombilloRojo.encenderApagar(0);
    }
    else
    {
      NivelActual--;      
    }
  }
  
  private:
  int NivelMinimo = 0;
  int NivelMaximo = 0;
  int NivelActual = 0;
};



Pulsador pulsadorVerNivelActual(6);
Pulsador pulsadorDisminuir(2);
Pulsador pulsadorIncrementar(5);

Tanque TanqueAgua(1,1,1);



void setup()
{
  Serial.begin(9600);  
  TanqueAgua.SetearNivelMinimo(1);
  TanqueAgua.SetearNivelMaximo(100);
}

void loop()
{
  if(pulsadorVerNivelActual.GetEstado() == HIGH)
  {
    delay(200);
    Serial.print("NIVEL ACTUAL: ");
    Serial.println(TanqueAgua.ObtenerNivelActual());
  }
  
  if(pulsadorIncrementar.GetEstado() == HIGH)
  {
    delay(200);   
    TanqueAgua.AumentarNivelActual();
  }
  
  if(pulsadorDisminuir.GetEstado() == HIGH)
  {
    delay(200);
    TanqueAgua.DisminuirNivelActual();
  }
  
}