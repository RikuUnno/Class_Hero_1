#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Hero; //前方宣言
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

//～～～～～～～～～～～HeroClass～～～～～～～～～～～

Hero::Hero(const char* heroName, int heroHp, int heroAtk, int heroDef)
{
    name = new char[strlen(heroName) + 1];

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

void Hero::attack(Enemy* enemy)
{
    int damage = atk - enemy->DefGetter();

    cout << enemy->NameGetter() << "へ" << damage << "のダメージを与えた" << endl;

    enemy->TakeDamage(damage); 
}

void Hero::heal(int recovery)
{
    hp += recovery;
}

int Hero::HpGetter()
{
    return hp;
}

int Hero::DefGetter()
{
    return def;
}

char* Hero::NameGetter()
{
    return name;
}

void Hero::TakeDamage(int damage)
{
    hp -= damage;
    cout << name << "は残り " << hp << endl;
}

//～～～～～～～～～～～HeroClass～～～～～～～～～～～

//～～～～～～～～～～～EnemyClass～～～～～～～～～～～

Enemy::Enemy(const char* enemyName, int enemyHp, int enemyAtk, int enemyDef)
{
    name = new char[strlen(enemyName) + 1];

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

void Enemy::attack(Hero* hero)
{
    int damage = atk - hero->DefGetter();

    cout << hero->NameGetter() << "へ" << damage << "のダメージを与えた" << endl;

    hero->TakeDamage(damage);
}

void Enemy::heal(int recovery)
{
    hp += recovery;
}

int Enemy::HpGetter()
{
    return hp;
}

int Enemy::DefGetter()
{
    return def;
}

char* Enemy::NameGetter()
{
    return name;
}

void Enemy::TakeDamage(int damage)
{
    hp -= damage;
    cout << name << "は残り " << hp << endl;
}

//～～～～～～～～～～～EnemyClass～～～～～～～～～～～

int main()
{
    Hero hero1("Hero1", 200);
    Enemy enemy1("Enemy1", 200);

    cout << endl;

    while (hero1.HpGetter() > 0 && enemy1.HpGetter() > 0) {
        hero1.attack(&enemy1);
        if (enemy1.HpGetter() <= 0) {
            cout << hero1.NameGetter() << "の勝ち" << endl;
            break;
        }

        enemy1.attack(&hero1);
        if (hero1.HpGetter() <= 0) {
            cout << enemy1.NameGetter() << "の勝ち" << endl;
            break;
        }
    }
}
