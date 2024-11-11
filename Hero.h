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
    Hero(const Hero& other);
    void operator=(const Hero& other);
    void attack(Enemy* enemy);
    void heal(int recovery = 15);
    int HpGetter() const;
    int AtkGetter() const;
    int DefGetter() const;
    char* NameGetter() const;
    void TakeDamage(int damage);
};
