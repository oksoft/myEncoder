/*
Р‘РёР±Р»РёРѕС‚РµРєР° РґР»СЏ СѓРїСЂР°РІР»РµРЅРёСЏ СЌРЅРєРѕРґРµСЂРѕРј.
РќР°РїРёСЃР°РЅР° 25.06.2015.
*/


#ifndef __MYENCODER_H__ 
#define __MYENCODER_H__



class CEncoder
{
  public:
    CEncoder(int pin1, int pin2, int pin3);
    int check();
    bool button_down();
  private:
    int _pin1;
    int _pin2;
    int _pin3;
    long _mySec;
    int _state; 
    int _dec;
};

#endif //__MYENCODER_H__


