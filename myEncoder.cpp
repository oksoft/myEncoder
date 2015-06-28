/*
���������� ��� ���������� ���������.
�������� 24.06.2015.
 
*/



#include "Arduino.h"    // ����������� ��� ����� ���������� ��� �������
#include "myEncoder.h"  // �� �������� �������� ������������ ���� ������ � ��� ������


CEncoder::CEncoder(int pin1, int pin2, int pin3){
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
  _mySec = 0;
  _state = 0;
  _dec = 0;
  pinMode(_pin1, INPUT);
  pinMode(_pin2, INPUT);
  pinMode(_pin3, INPUT);
  digitalWrite(_pin1, HIGH);
  digitalWrite(_pin2, HIGH);
  digitalWrite(_pin3, HIGH); 
};  


int CEncoder::check(){     // ���������� 1 ��� �������� �� ������� ������� ��� -1 ��� �������� ������ ������� �������
  if ((millis() - _mySec)<1) return(0);  // ������������ ����� �������� �������� 1���, ����� �� ��������� ������ ������� � �����
  int result =0;
  _mySec = millis();
  int New = digitalRead(_pin1) + 2*digitalRead(_pin2);
  switch (_state) {
        case 2:            
		{
		if(New == 3) result = 1;
		if(New == 0) result = -1;
		break;
		}
 	case 0:
		{
		if(New == 2) result = 1;
		if(New == 1) result = -1;
		break;
		}
	case 1:
		{
		if(New == 0) result = 1;
		if(New == 3) result = -1;
		break;
		}
	case 3:
		{
		if(New == 1) result = 1;
		if(New == 2) result = -1;
		break;
		} 
  }
  _state = New;
  if (result != 0) _dec++;
  if (_dec==2) {result = 0;_dec = 0;};
    
  return(result);  
};

bool CEncoder::button_down(){   // ���������� true? ���� ������ ������!!! �.�. ������ ������ � �����!!! 
  return(!digitalRead(_pin3));
};
