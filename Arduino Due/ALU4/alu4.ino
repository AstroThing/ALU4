#include <string.h>

#define WORD_SIZE 4
#define FUNC_SIZE 3

#define ADD 0
#define SUB 1
#define AND 2
#define OR 3
#define XOR 4

//Using little endian
const unsigned int a[WORD_SIZE] = { 22, 24, 26, 28 }; 
const unsigned int b[WORD_SIZE] = { 46, 48, 50, 52 };
const unsigned int _function[FUNC_SIZE] = { 23, 25, 27 };
const unsigned int result[WORD_SIZE] = { 47, 49, 51, 53 };

void setFunc(unsigned char func);
void setA(unsigned char a_data);
void setB(unsigned char b_data);
void readResult();

void setup() {
  Serial.begin(9600);
    
  for(int i = 0; i < WORD_SIZE; i++)
  {
    pinMode(a[i], OUTPUT);
    pinMode(b[i], OUTPUT);
    pinMode(result[i], INPUT);
    
    if(i < FUNC_SIZE)
      pinMode(_function[i], OUTPUT);

    digitalWrite(a[i], LOW);
    digitalWrite(b[i], LOW);
  }
}

void loop() {
  if(Serial.available())
  {
    String str = Serial.readString();
    char* token = strtok((char*)(str.c_str()), " ");
    unsigned char a_data = atoi(strtok(NULL, " "));
    unsigned char b_data = atoi(strtok(NULL, " "));

    Serial.println("Sent A: " + String(a_data));
    Serial.println("Sent B: " + String(b_data));

    if(!strcmp(token, "add"))
    {
      setA(a_data);
      setB(b_data);
      setFunc(ADD);
      readResult();
    }
    else if(!strcmp(token, "sub"))
    {
      setA(a_data);
      setB(b_data);
      setFunc(SUB);
      readResult();
    }
    else if(!strcmp(token, "and"))
    {
      setA(a_data);
      setB(b_data);
      setFunc(AND);
      readResult();
    }
    else if(!strcmp(token, "or"))
    {
      setA(a_data);
      setB(b_data);
      setFunc(OR);
      readResult();
    }
    else if(!strcmp(token, "xor"))
    {
      setA(a_data);
      setB(b_data);
      setFunc(XOR);
      readResult();
    }
    else
    {
      Serial.println("Not a valid operation");
    }
  }
}

void setFunc(unsigned char func)
{
  for(int i = 0; i < FUNC_SIZE; i++)
  {
    if(func & (1 << i))
      digitalWrite(_function[i], HIGH);
    else
      digitalWrite(_function[i], LOW);
  }
}

void setA(unsigned char a_data){
  for(int i = 0; i < WORD_SIZE; i++)
  {
    if(a_data & (1 << i))
      digitalWrite(a[i], HIGH);
    else
      digitalWrite(a[i], LOW);
  }
}

void setB(unsigned char b_data){
  for(int i = 0; i < WORD_SIZE; i++)
  {
    if(b_data & (1 << i))
      digitalWrite(b[i], HIGH);
    else
      digitalWrite(b[i], LOW);
  }
}

void readResult(){
  delay(100);
  unsigned char r = 0;
  for(int i = 0; i < WORD_SIZE; i++)
    r |= (digitalRead(result[i]) << i);
    
  Serial.println("Result: " + String((unsigned int)r));
}
