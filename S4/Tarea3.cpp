class Led
{
public:
    Led(int _pin)
    {
        pin = _pin;
        pinMode(pin, OUTPUT);
    }

    void encenderApagar(bool tipo)
    {
        if (tipo)
        {
            digitalWrite(pin, HIGH);
        }
        else
        {
            digitalWrite(pin, LOW);
        }
    }

private:
    int pin;
};

class Pulsador
{
public:
    Pulsador(int _pin)
    {
        pin = _pin;
        pinMode(pin, INPUT);
    }

    int GetEstado()
    {
        return digitalRead(pin);
    }

private:
    int pin;
};

byte Contador = 0;

Led bombilloRojo(3);
Led bombilloVerde(4);

Pulsador pulsadorIncrementar(5);
Pulsador pulsadorDisminuir(2);

void setup()
{
    Serial.begin(9600);
}

void loop()

{
    Serial.println(Contador);
    if (pulsadorIncrementar.GetEstado() == HIGH)
    {
        delay(200);
        Contador++;
        bombilloVerde.encenderApagar(1);
        bombilloVerde.encenderApagar(0);
    }
    if (pulsadorDisminuir.GetEstado() == HIGH)
    {
        delay(200);
        Contador--;
        bombilloRojo.encenderApagar(1);
        bombilloRojo.encenderApagar(0);
    }
}
