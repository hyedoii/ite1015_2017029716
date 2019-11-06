# include <iostream>
# include <string>
# include <sstream>

# include "minimal_fighter.h"

using namespace std;

MinimalFighter::MinimalFighter() {}
MinimalFighter::MinimalFighter(int _hp, int _power) {
    mHp = _hp;
    mPower = _power;
}

EFighterStatus MinimalFighter::status() const{
    if(mHp <= 0){
        return Dead;
    }
    else return Alive;
}

void MinimalFighter::setHp(int _hp) {
    if(_hp < 0) mHp = 0;
    else mHp = _hp;
}

void MinimalFighter::hit(MinimalFighter *_enemy){
    mHp = mHp - _enemy->power();
    _enemy->setHp(_enemy->hp() - mPower);
}

void MinimalFighter::attack(MinimalFighter *_target){
    _target->setHp(_target->hp() - mPower);
    mPower = 0;
}

void MinimalFighter::fight(MinimalFighter *_enemy){
    while(mStatus != Dead && _enemy->status() != Dead){
        mHp = mHp - _enemy->power();
        _enemy->setHp(_enemy->hp() - mPower);
    }
}

int MinimalFighter::hp() const {
    return mHp;
}

int MinimalFighter::power() const {
    return mPower;
}

