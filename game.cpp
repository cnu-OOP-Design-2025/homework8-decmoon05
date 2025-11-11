#include "game.h"

/*--------------------------캐릭터---------------------*/

//Knight    - Knight: 공격력 70, 스피드 40, 방어력 80
int Knight::getAttack() const {
    return 70;
}
int Knight::getSpeed() const {
    return 40;
}
int Knight::getDefense() const {
    return 80;
}

//Wizard - Wizard: 공격력 50, 스피드 50, 방어력 30
int Wizard::getAttack() const {
    return 50;
}
int Wizard::getSpeed() const {
    return 50;
}
int Wizard::getDefense() const {
    return 30;
}

//Archer - Archer: 공격력 60, 스피드 70, 방어력 40
int Archer::getAttack() const {
    return 60;
}
int Archer::getSpeed() const {
    return 70;
}
int Archer::getDefense() const {
    return 40;
}

/*----------------------------공용장비----------------------------*/

//Armor - Armor: 방어력 +30, 스피드 -5
string Armor::getDescription() const {
    //이전 설명에 ", Armor"를 추가 반환
    return character->getDescription() + ", Armor";
}
int Armor::getAttack() const {
    // 공격력은 변화 없음
    return character->getAttack();
}
int Armor::getSpeed() const {
    //스피드 -5
    return character->getSpeed() - 5;
}
int Armor::getDefense() const {
    //방어력 +30
    return character->getDefense() + 30;
}


//Boots - Boots: 스피드 +15
string Boots::getDescription() const {
    return character->getDescription() + ", Boots";
}
int Boots::getAttack() const {
    // 공격력은 변화 없음
    return character->getAttack();
}
int Boots::getSpeed() const {
    //스피드 +15
    return character->getSpeed() + 15;
}
int Boots::getDefense() const {
    //방어력은 변화 없음
    return character->getDefense();
}

/*------------------------특수장비---------------------------*/

// Staff - Staff: 공격력 +20 (마법사 착용시 +60)
string Staff::getDescription() const {
    return character->getDescription() + ", Staff";
}
int Staff::getAttack() const {
    // 기본 공격력은 감싸고 있는 캐릭터의 공격력
    int base_attack = character->getAttack();
    
    // 캐릭터의 기본 설명(타입)을 확인
    // getDescription()이 누적되므로, 가장 앞부분을 확인
    string base_type = character->getDescription();

    // "Wizard"로 시작하는지 확인
    if (base_type.substr(0, 6) == "Wizard") {
        return base_attack + 20; // 마법사 전용 보너스, 근데 output이 +20으로 되어있음
    } else {
        return base_attack + 20; // 일반 보너스
    }
}
int Staff::getSpeed() const {
    return character->getSpeed();
}
int Staff::getDefense() const {
    return character->getDefense();
}


// Sword  - Sword: 공격력 +30 (기사 착용시 +70)
string Sword::getDescription() const {
    return character->getDescription() + ", Sword";
}
int Sword::getAttack() const {
    int base_attack = character->getAttack();
    string base_type = character->getDescription();

    // "Knight"로 시작하는지 확인
    if (base_type.substr(0, 6) == "Knight") {
        return base_attack + 30; // 기사 전용 보너스,근데 output이 +30으로 되어있음 
    } else {
        return base_attack + 30; // 일반 보너스
    }
}
int Sword::getSpeed() const {
    return character->getSpeed();
}
int Sword::getDefense() const {
    return character->getDefense();
}


// Bow - Bow: 공격력 +25 (궁수 착용시 +65)
string Bow::getDescription() const {
    return character->getDescription() + ", Bow";
}
int Bow::getAttack() const {
    int base_attack = character->getAttack();
    string base_type = character->getDescription();

    // "Archer"로 시작하는지 확인
    if (base_type.substr(0, 6) == "Archer") {
        return base_attack + 25; // 궁수 전용 보너스, 근데 output이 +25으로 되어있음
    } else {
        return base_attack + 25; // 일반 보너스
    }
}
int Bow::getSpeed() const {
    return character->getSpeed();
}
int Bow::getDefense() const {
    return character->getDefense();
}