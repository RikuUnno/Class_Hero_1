#pragma once

class Enemy;

class Hero
{
private:
    char* name;
    int hp;
    int atk;
    int def;
public:
    Hero(const char* heroName, int heroHp, int heroAtk = 20, int heroDef = 5);
    ~Hero();
    void attack(Enemy* enemy);
    void heal(int recovery = 15);
    int HpGetter();
    int DefGetter();
    char* NameGetter();
    void TakeDamage(int damage);
};
