#include <iostream>
#include <memory>
#include <stdlib.h>
#include <string>
using namespace std;

string Winner;
class Player {
public:
  virtual bool isWinner() = 0;
  ~Player() { cout << "\ndeleted\n"; }
  virtual int getHealth() = 0;
  virtual string getPlayerName() = 0;
  virtual int getAdditionalDamage() = 0;
  virtual int getHealing() = 0;
  virtual int getAdditionalHealing() = 0;
  virtual int takeDamage(int dmg) = 0;
  virtual int giveDamage() = 0;
  virtual bool Alive() = 0;
};
class TankPlayer : public Player {
private:
  bool isGameOver = false;
  int Health = 200;
  int BaseDamage = 10;
  int AdditionalDamage;
  int Damage;
  int minAD = 5;
  int maxAD = 15;
  int BaseHeal = 10;
  int Heal = 0;
  int AdditionalHeal;
  int minHeal = 5;
  int maxHeal = 15;
  bool isAlive = true;
  string PlayerName = "Tank Player";

public:
  TankPlayer(string Name) {
    PlayerName = Name;
    cout << PlayerName << " chose Tank Playerr\n";
    cout << "Health Points : " << Health << endl;
    cout << "Base Damage : " << BaseDamage << endl;
    cout << "Additional Damage : " << minAD << " - " << maxAD << endl;
    cout << "Base Healing Capacity : " << Heal << endl;
    cout << "Additional Healing Capacity : " << minHeal << " - " << maxHeal
         << endl;
  }
  ~TankPlayer() { cout << "/ndeleted/n"; }

  string getPlayerName() { return PlayerName; }

  int getHealth() { return Health; }

  int getAdditionalDamage() {
    AdditionalDamage = (rand() % maxAD) + minAD;
    return AdditionalDamage;
  }

  int getHealing() {
    cout << PlayerName << " Healing\n";
    Heal = BaseHeal + AdditionalHeal;
    Health = Health + Heal;
    cout << "Damage Healed " << BaseDamage << " + Additional Heal "
         << getAdditionalHealing() << endl;
    return Heal;
  }

  int getAdditionalHealing() {
    AdditionalHeal = (rand() % maxHeal) + minHeal;
    return AdditionalHeal;
  }

  int takeDamage(int dmg) {

    cout << PlayerName << " received Attack\n";
    Health = Health - dmg;
    if (Health > 0) {
      cout << PlayerName << "'s Current Health : " << Health << endl;
    } else {
      isGameOver = true;
      cout << PlayerName << " Died" << endl;
      Alive();
      isAlive = false;
    }
    return Health;
  }

  int giveDamage() {
    cout << PlayerName << " Attacked\n";
    Damage = BaseDamage + getAdditionalDamage();
    cout << "Damage Dealt " << BaseDamage << " + Additional Damage "
         << getAdditionalDamage() << endl;

    return Damage;
  }

  bool Alive() {
    if (Health <= 0) {
      isAlive = false;
    } else {
      isAlive = true;
    }

    return isAlive;
  }
  bool isWinner() { return isAlive; }
};
class DamageDealer : public Player {
private:
  bool isGameOver = false;
  int Health = 100;
  int BaseDamage = 15;
  int AdditionalDamage;
  int Damage;
  int minAD = 8;
  int maxAD = 18;
  int BaseHeal = 10;
  int Heal = 0;
  int AdditionalHeal;
  int minHeal = 5;
  int maxHeal = 15;
  bool isAlive = true;
  string PlayerName = "Tank Player";

public:
  DamageDealer(string Name) {
    PlayerName = Name;
    cout << PlayerName << " chose Damage Dealer\n";
    cout << "Health Points : " << Health << endl;
    cout << "Base Damage : " << BaseDamage << endl;
    cout << "Additional Damage : " << minAD << " - " << maxAD << endl;
    cout << "Base Healing Capacity : " << Heal << endl;
    cout << "Additional Healing Capacity : " << minHeal << " - " << maxHeal
         << endl;
  }
  ~DamageDealer() { cout << "/ndeleted/n"; }

  string getPlayerName() { return PlayerName; }

  int getHealth() { return Health; }

  int getAdditionalDamage() {
    AdditionalDamage = (rand() % maxAD) + minAD;
    return AdditionalDamage;
  }

  int getHealing() {
    cout << PlayerName << " Healing\n";
    Heal = BaseHeal + AdditionalHeal;
    Health = Health + Heal;
    cout << "Damage Healed " << BaseDamage << " + Additional Heal "
         << getAdditionalHealing() << endl;
    cout << PlayerName << "'s Current Health : " << Health << endl;
    return Heal;
  }

  int getAdditionalHealing() {
    AdditionalHeal = (rand() % maxHeal) + minHeal;
    return AdditionalHeal;
  }

  int takeDamage(int dmg) {

    cout << PlayerName << " received Attack\n";
    Health = Health - dmg;
    if (Health > 0) {
      cout << PlayerName << "'s Current Health : " << Health << endl;
    } else {
      isGameOver = true;
      cout << PlayerName << " Died" << endl;
      Alive();
      isAlive = false;
    }
    return Health;
  }

  int giveDamage() {
    cout << PlayerName << " Attacked\n";
    Damage = BaseDamage + getAdditionalDamage();
    cout << "Damage Dealt " << BaseDamage << " + Additional Damage "
         << getAdditionalDamage() << endl;

    return Damage;
  }

  bool Alive() {
    if (Health <= 0) {
      isAlive = false;
    } else {
      isAlive = true;
    }

    return isAlive;
  }
  bool isWinner() { return isAlive; }
};
class Healer : public Player {
private:
  bool isGameOver = false;
  int Health = 150;
  int BaseDamage = 10;
  int AdditionalDamage;
  int Damage;
  int minAD = 5;
  int maxAD = 10;
  int BaseHeal = 15;
  int Heal = 0;
  int AdditionalHeal;
  int minHeal = 8;
  int maxHeal = 18;
  bool isAlive = true;
  string PlayerName = "Tank Player";

public:
  Healer(string Name) {
    PlayerName = Name;
    cout << PlayerName << " chose Healer\n";
    cout << "Health Points : " << Health << endl;
    cout << "Base Damage : " << BaseDamage << endl;
    cout << "Additional Damage : " << minAD << " - " << maxAD << endl;
    cout << "Base Healing Capacity : " << Heal << endl;
    cout << "Additional Healing Capacity : " << minHeal << " - " << maxHeal
         << endl;
  }
  ~Healer() { cout << "/ndeleted/n"; }

  string getPlayerName() { return PlayerName; }

  int getHealth() { return Health; }

  int getAdditionalDamage() {
    AdditionalDamage = (rand() % maxAD) + minAD;
    return AdditionalDamage;
  }

  int getHealing() {
    cout << PlayerName << " Healing\n";
    Heal = BaseHeal + AdditionalHeal;
    Health = Health + Heal;
    cout << "Damage Healed " << BaseDamage << " + Additional Heal "
         << getAdditionalHealing() << endl;
    return Heal;
  }

  int getAdditionalHealing() {
    AdditionalHeal = (rand() % maxHeal) + minHeal;
    return AdditionalHeal;
  }

  int takeDamage(int dmg) {

    cout << PlayerName << " received Attack\n";
    Health = Health - dmg;
    if (Health > 0) {
      cout << PlayerName << "'s Current Health : " << Health << endl;
    } else {
      isGameOver = true;
      cout << PlayerName << " Died" << endl;
      Alive();
      isAlive = false;
    }
    return Health;
  }

  int giveDamage() {
    cout << PlayerName << " Attacked\n";
    Damage = BaseDamage + getAdditionalDamage();
    cout << "Damage Dealt " << BaseDamage << " + Additional Damage "
         << getAdditionalDamage() << endl;

    return Damage;
  }

  bool Alive() {
    if (Health <= 0) {
      isAlive = false;
    } else {
      isAlive = true;
    }

    return isAlive;
  }
  bool isWinner() { return isAlive; }
};

Player *SelectPlayer(string Name) {
  char PlayerChoice;
  string PlayerName = Name;
  Player *Player;
here:
  cin >> PlayerChoice;

  switch (PlayerChoice) {
  case '1': {
    Player = new TankPlayer(PlayerName);
    break;
  }
  case '2': {
    Player = new DamageDealer(PlayerName);
    break;
  }
  case '3': {
    Player = new Healer(PlayerName);
    break;
  }
  default: {
    cout << "Invalid choice\nChoose Again\n";
    goto here;
  }
  };
  return Player;
  delete Player;
}

void Action(Player *Player1, Player *Player2) {
  char Choice;
here:
  cout << Player1->getPlayerName() << " Your turn\nA : Attack\nH : Heal\n"
       << endl;
  cin >> Choice;
  switch (Choice) {
  case 'a':
    Player2->takeDamage(Player1->giveDamage());
    break;
  case 'A':
    Player2->takeDamage(Player1->giveDamage());
    break;
  case 'H':
    Player1->getHealing();
    break;
  case 'h':
    Player1->getHealing();
    break;
  default:
    cout << "Invalid Choice \n";
    goto here;
  };
}

void BattleLoop(Player *Player1, Player *Player2) {

  do {
    Action(Player1, Player2);
    if (Player2->Alive() == false) {
      Winner = Player1->getPlayerName();
      break;
    }
    Action(Player2, Player1);
    if (Player1->Alive() == false) {
      Winner = Player2->getPlayerName();
      break;
    }

  } while (Player1->Alive() == true && Player2->Alive() == true);
}

int main() {
  Player *Player1;
  Player *Player2;
  int Round = 1;
  char choice;
  string PlayerName;

  cout << "Chose one amongst following\n";
  cout << "1. Tank Player\n";
  cout << "2. Damage Dealer\n";
  cout << "3. Healer\n";

  cout << "Player1 incert Name :" << endl;
  cin >> PlayerName;
  cout << PlayerName << " Choose Character :" << endl;
  Player1 = SelectPlayer(PlayerName);

  cout << "Player2 incert Name :" << endl;
  cin >> PlayerName;
  cout << PlayerName << " Chooase Character :" << endl;
  Player2 = SelectPlayer(PlayerName);

  cout << "Now that both players made choice,  Lets begin" << endl;

  do {
    BattleLoop(Player1, Player2);

    cout << "Round " << Round << " Winner is " << Winner << endl;
    Round += 1;
    cout << "Do You Want To Continue (Y/N) : ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
      cout << "\nReady For Round : " << Round << endl;
    } else if (choice == 'n' || choice == 'N') {
      cout << "\nThanks For Playing\n";
    } else {
      cout << "\nInvalid choice\nBut Who Cares\nYou Are Leaving Anyway\n";
    }
  } while (choice == 'y' || choice == 'Y');
}
