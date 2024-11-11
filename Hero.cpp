#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Enemy.h"
#include "Hero.h"

using namespace std;

class Enemy;//‘O•ûéŒ¾

//```````````HeroClass```````````

Hero::Hero(const char* heroName, int heroHp, int heroAtk, int heroDef)
{
    name = new(nothrow) char[strlen(heroName) + 1];

    strcpy(name, heroName);

    hp = heroHp;

    atk = heroAtk;

    def = heroDef;

    cout << "name > " << name << endl
        << "Hp > " << hp << endl
        << "ak > " << atk << endl
        << "def > " << def << endl;
}

Hero::~Hero()
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
}

Hero::Hero(const Hero& other)
{
    hp = other.hp;
    atk = other.atk;
    def = other.def;
    name = name = new(nothrow) char[strlen(other.name) + 1];

    if (name != nullptr)
    {
        copy(other.name, other.name + strlen(other.name) + 1, name);
    }
}

void Hero::operator=(const Hero& other)
{
    hp = other.hp;
    atk = other.atk;
    def = other.def;
    char *m_mane = new char[strlen(other.name) + 1];

    if (m_mane != nullptr)
    {
        if (name != nullptr)
        {
            delete[] name;
            copy(other.name, other.name + strlen(other.name) + 1, name);
        }
    }
}

void Hero::attack(Enemy* enemy)
{
    int damage = atk - enemy->DefGetter();

    cout << enemy->NameGetter() << "‚Ö" << damage << "‚Ìƒ_ƒ[ƒW‚ğ—^‚¦‚½" << endl;

    enemy->TakeDamage(damage);
}

void Hero::heal(int recovery)
{
    hp += recovery;
}

int Hero::HpGetter() const
{
    return hp;
}

int Hero::AtkGetter() const
{
    return atk;
}

int Hero::DefGetter() const
{
    return def;
}

char* Hero::NameGetter() const
{
    return name;
}

void Hero::TakeDamage(int damage)
{
    hp -= damage;
    cout << name << "‚Íc‚è " << hp << endl;
}

//```````````HeroClass```````````