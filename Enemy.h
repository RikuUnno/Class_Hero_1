#pragma once

class Hero;

class Enemy
{
private:
    char* name;
    int hp;
    int atk;
    int def;
public:
    Enemy(const char* enemyName, int enemyHp, int enemyAtk = 20, int enemyDef = 5);
    ~Enemy();
    void attack(Hero* hero);
    void heal(int recovery = 15);
    int HpGetter();
    int DefGetter();
    char* NameGetter();
    void TakeDamage(int damage);
};