int oswietlenie = 0;
int pomiar = 0;
int odleglosc = 0;

void setup(){
    Serial.begin(9600);
    pinMode(A0, INPUT);
    pinMode(9, INPUT);
}

void loop(){
    oswietlenie = digitalRead(2);
    if(oswietlenie == 1){       #jeśli wartość oświetlenia jest inna niż domyśla, czyli 0, to....
        Serial.println("kolor czarny"); # to czujnik odbiera informację jako kolor czarny, czyli obiekt jest daleko czujnika
    }
    else{                                 # jeśli wartość oświetlenia jest inna niż 1 czyli 0, wówczas...
        Serial.println("kolor bialy");       # wówczas czujnik odbiera informację jako kolor biały, czyli obiekt jest blisko czujnika
    }
    pomiar = analogRead (A0); # mikrokontroler mierzy odległość dwukrotnie...
    delay(250);                       # ...w odstępie 0,25 s
    odleglosc = ((67870 / (pomiar - 3)) - 40); # mierzona odległość
    if (odleglosc > 800){
        Serial.println("Obiekt zbyt daleko czujnika!"); #informacja, że obiekt jest zbyt daleko czujnika
    }
    else{
        Serial.print (odleglosc);
        Serial.println(" mm"); # informacja o tym, jak blisko od czujnika znajduje się obiekt
    }
    delay (250);
}
