#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Enemy.h"
#include "Hero.h"

using namespace std;

class Hero; //‘O•ûéŒ¾

//```````````EnemyClass```````````

Enemy::Enemy(const char* enemyName, int enemyHp, int enemyAtk, int enemyDef)
{
    name = new(nothrow) char[strlen(enemyName) + 1];

    strcpy(name, enemyName);

    hp = enemyHp;

    atk = enemyAtk;

    def = enemyDef;

    cout << "name > " << name << endl
        << "Hp > " << hp << endl
        << "ak > " << atk << endl
        << "def > " << def << endl;
}

Enemy::~Enemy()
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
}

Enemy::Enemy(const Enemy& other)
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

void Enemy::operator=(const Enemy& other)
{
    hp = other.hp;
    atk = other.atk;
    def = other.def;
    char* m_mane = new char[strlen(other.name) + 1];

    if (m_mane != nullptr)
    {
        if (name != nullptr)
        {
            delete[] name;
            copy(other.name, other.name + strlen(other.name) + 1, name);
        }
    }
}

void Enemy::attack(Hero* hero)
{
    int damage = atk - hero->DefGetter();

    cout << hero->NameGetter() << "‚Ö" << damage << "‚Ìƒ_ƒ[ƒW‚ğ—^‚¦‚½" << endl;

    hero->TakeDamage(damage);
}

void Enemy::heal(int recovery)
{
    hp += recovery;
}

int Enemy::HpGetter() const
{
    return hp;
}

int Enemy::AtkGetter() const
{
    return atk;
}

int Enemy::DefGetter() const
{
    return def;
}

char* Enemy::NameGetter() const
{
    return name;
}

void Enemy::TakeDamage(int damage)
{
    hp -= damage;
    cout << name << "‚Íc‚è " << hp << endl;
}

//```````````EnemyClass```````````