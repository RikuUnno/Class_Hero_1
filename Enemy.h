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
    Enemy(const Enemy& other);
    void operator=(const Enemy& other);
    void attack(Hero* hero);
    void heal(int recovery = 15);
    int HpGetter() const;
    int AtkGetter() const;
    int DefGetter() const;
    char* NameGetter() const;
    void TakeDamage(int damage);
};