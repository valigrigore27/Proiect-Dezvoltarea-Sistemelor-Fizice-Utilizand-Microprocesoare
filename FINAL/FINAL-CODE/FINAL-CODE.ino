#define do1  262
#define re  294 
#define mi  330
#define fa  349 //fa
#define fa_dz  370 //fa#
#define sol  392 
#define la  440 
#define si  494 
#define do2  523
#define re2  587 
#define mi2 659

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int numarSilabe = 0;

//Pin definitions
const int Blue = 10;
const int Yellow = 9;
const int Red = 8;
const int Button = 7;
const int Buzzer = 13;
int flag = 1;

void playNote(int note, int duration) {
  tone(13, note, duration);
  delay(duration);
  
  // Crește numarul de silabe după fiecare notă
  numarSilabe++;
  
  if(numarSilabe==1){
  // Aprinde LED-ul roșu
  digitalWrite(Red, HIGH);
  digitalWrite(Red, LOW);
  }
  else
  if(numarSilabe==2){
  // Aprinde LED-ul galben
  digitalWrite(Yellow, HIGH);
  digitalWrite(Yellow, LOW);

  }
    else
  if(numarSilabe==3){
// Aprinde LED-ul albastru
  digitalWrite(Blue, HIGH);
  digitalWrite(Blue, LOW);
  }
    
  // Verifică dacă s-a atins un număr de 4 silabe
  if (numarSilabe >=5 && flag==1) {
    //lcd.clear();
  	lcd.setCursor(0, 1);
 	flag = 0;
  }
  if (numarSilabe >=10 && flag==0) {
    lcd.clear();
  	lcd.setCursor(0, 0);
    numarSilabe=0;
 	flag=1;
  }
  
}
//pentru a doua parte a primului vers:
struct SilabaNotaDurata {
  const char *silaba;
  int nota;
  int durata;
};

//pentru prima parte a primului vers:
SilabaNotaDurata vers1[] = {
  {"De", mi, 500},
  {"stea", mi, 1000},
  {"pta", fa_dz, 250},
  {"-te ", sol, 500},
  {"ro", la, 500},
  {"ma", si, 1000},
  {"ne ", mi, 500},
  {"din ", mi, 500},
  {"som", do2, 1000},
  {"nul ", si, 250},
  {"cel ", la, 500},
  {"de ", la, 500},
  {"moa", re2, 1000},
  {"", do2, 250},
  {"rte ", si, 500},
  {"In ", si, 500},
  {"ca", mi2, 1000},
  {"re ", re2, 250},
  {"te-a", do2, 250},
  {"", si, 250},
  {"dan", la, 500},
  {"ci", si, 500},
  {"ra ", sol, 1000},
  {"bar", la, 500},
  {"ba", si, 1000},
  {"rii ", la, 250},
  {"de ", sol, 500},
  {"ti", fa_dz, 500},
  {"r", mi, 1000},
  {"", fa_dz, 500},
  {"ani ", sol, 500},
  {"bar", la, 500},
  {"ba", si, 500},
  {"ri", la, 250},
  {"i ", sol, 500},
  {"de ", fa_dz, 500},
  {"ti", sol, 500},
  {"rani ", mi, 1000}
};


//pentru a doua parte a primului vers:
SilabaNotaDurata vers2[] = {
  {"A", mi, 500},
  {"cum ", mi, 1000},
  {"ori ", mi2, 250},
  {"ni", mi2, 500},
  {"cio", mi2, 500},
  {"da", mi2, 1000},
  {"ta ", re2, 500},
  {"cro", re2, 500},
    
  {"ies", mi2, 1000},
  {"te-ti ", re2, 250},
  {"al", do2, 250},
  {"", si, 250},
  {"ta ", la, 500},
  {"soa", re2, 1000},
  {"", do2, 250},
  {"rta ", si, 500},
  {"La ", si, 500},
  {"ca", mi2, 1000},
  {"re ", re2, 250},
  {"sa ", do2, 250},
  {"", si, 250},
    
  {"se-n", la, 500},
  {"chi", si, 500},
  {"ne ", sol, 1000},
  {"si ", la, 500},
  {"cru", si, 1000},
  {"zii ", la, 250},
  {"tai ", sol, 500},
  {"dus", fa_dz, 500},
    
  {"ma", mi, 1000},
  {"", fa_dz, 250},
  {"ni ", sol, 500},
  {"si ", la, 500},
  {"cru", si, 500},
  {"zii ", la, 250},
  {"", sol, 500},
  {"tai ", fa_dz, 500},
  {"dus", sol, 500},
  {"mani", mi, 1000}
};

//prima parte al doilea vers
SilabaNotaDurata vers3[] = {
  {"A", mi, 500},
  {"cum ", mi, 1000},
  {"ori ", fa_dz, 250},
  {"nici", sol, 500},
  {"o", la, 500},
  {"da", si, 1000},
  {"ta ", mi, 500},
  {"sa ", mi, 500},
  {"dam ", do2, 1000},
  {"do", si, 250},
  {"vezi ", la, 500},
  {"la ", la, 500},
  {"lu", re2, 1000},
  {"", do2, 250},
  {"me ", si, 500},  
  {"Ca-n ", si, 500},
  {"as", mi2, 1000},
  {"te ", re2, 250},
  {"ma", do2, 250},
  {"ini ", si, 250},
  {"mai ", la, 500},
  {"cur", si, 500},
  {"ge ", sol, 1000},
  {"un ", la, 500},
  {"san", si, 1000},
  {"ge ", la, 250},
  {"de ", sol, 500},
  {"ro", fa_dz, 500},
  {"ma", mi, 1000},
  {"",fa_dz, 500},
  {"an ", sol, 500},
  {"un ", la, 500},
  {"san", si, 500},
  {"ge ", la, 250},
  {"", sol, 500},
  {"de ", fa_dz, 500},
  {"ro", sol, 500},
  {"man", mi, 1000}
};


//a doua parte al celui de-al doilea vers.
SilabaNotaDurata vers4[] = {
  {"Si ", mi, 500},
  {"ca-n ", mi, 1000},
  {"a ", mi2, 250},
  {"noas", mi2, 500},
  {"tre ", mi2, 500},
  {"piep", mi2, 1000},
  {"turi ", re2, 500},
  {"pas", re2, 500},
    
  {"tram ", mi2, 1000},
  {"cu ", re2, 250},
  {"fa", do2, 250},
  {"", si, 250},
  {"la-un ", la, 500},
  {"nu", re2, 1000},
  {"", do2, 250},
  {"me ", si, 500},
  {"Tri", si, 500},
  {"um", mi2, 1000},
  {"fa", re2, 250},
  {"tor ", do2, 250},
  {"", si, 250},
    
  {"in ", la, 500},
  {"lup", si, 500},
  {"te ", sol, 1000},
  {"un ", la, 500},
  {"nu", si, 1000},
  {"me ", la, 250},
  {"de ", sol, 500},
  {"Tra", fa_dz, 500},
    
  {"ia", mi, 1000},
  {"", fa_dz, 250},
  {"n ", sol, 500},
  {"un ", la, 500},
  {"nu", si, 500},
  {"me ", la, 250},
  {" ", sol, 500},
  {"de ", fa_dz, 500},
  {"Tra", sol, 500},
  {"ian", mi, 1000}
  
};




void melody() {


for (int i = 0; i < sizeof(vers1) / sizeof(vers1[0]); ++i) {
    lcd.print(vers1[i].silaba);
    playNote(vers1[i].nota, vers1[i].durata);
  }
  
  lcd.clear();
for (int i = 0; i < sizeof(vers2) / sizeof(vers2[0]); ++i) {
    lcd.print(vers2[i].silaba);
    playNote(vers2[i].nota, vers2[i].durata);
  }
lcd.clear();
  for (int i = 0; i < sizeof(vers3) / sizeof(vers3[0]); ++i) {
    lcd.print(vers3[i].silaba);
    playNote(vers3[i].nota, vers3[i].durata);
  }

  
  lcd.clear();
  for (int i = 0; i < sizeof(vers4) / sizeof(vers4[0]); ++i) {
    lcd.print(vers4[i].silaba);
    playNote(vers4[i].nota, vers4[i].durata);
  }


	delay(1000);
}


void setup() {
  pinMode(13, OUTPUT);
  lcd.begin(16, 2);
  
  pinMode(Blue, OUTPUT);  //Blue
  pinMode(Yellow, OUTPUT);  //Green
  pinMode(Red, OUTPUT); //Red
  pinMode(Buzzer, OUTPUT); //Buzzer

  pinMode(Button, INPUT);   //Button
}

void loop() {
  
int btn = digitalRead(Button);
    Serial.println(btn);
  if(btn == 1)
  {
  melody();
  }
  else
  {
  delay(1);
  }
 
}
