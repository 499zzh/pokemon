#include "my_pokemon.h"
#include "pokemon_set.h"
#include<string.h>
#include<time.h>
#include<random>
#include<QString>
#include<QTime>
#include<QCoreApplication>
#include "fight_game.h"
#include "QDebug"

pokemon::pokemon(){
    strcpy_s(m_name, "pokemon");
    m_attack = 40;
    m_defense = 20;
    m_speed = 50;
    m_HP = 200;
    m_level = 1;
    m_exp = 0;
    m_crit = 0;
    m_dodge = 0;
    m_growing_att = 0;
    m_growing_def = 0;
    m_growing_HP = 0;
}

fire_pokemon::fire_pokemon(){
    m_property = FIRE;
    m_growing_att += 15;
    m_growing_def += 10;
    m_growing_HP += 25;
}
//火属性精灵的构造函数
water_pokemon::water_pokemon() {
    m_property = WATER;
    m_growing_att += 10;
    m_growing_def += 15;
    m_growing_HP += 25;
}
//水属性精灵的构造函数
plant_pokemon::plant_pokemon() {
    m_property = PLANT;
    m_growing_att += 10;
    m_growing_def += 20;
    m_growing_HP += 30;
}
//草属性精灵的构造函数
dark_pokemon::dark_pokemon() {
    m_property = DARK;
    m_growing_att += 25;
    m_growing_def += 5;
    m_growing_HP += 20;
}
//黑暗属性精灵的构造函数
bright_pokemon::bright_pokemon() {
    m_property = BRIGHT;
    m_growing_att += 20;
    m_growing_def += 5;
    m_growing_HP += 25;
    m_crit *= 2;
}
//光属性精灵的构造函数
wind_pokemon::wind_pokemon() {
    m_property = WIND;
    m_growing_att += 15;
    m_growing_def += 10;
    m_growing_HP += 20;
    m_growing_speed += 3;

}
//风属性精灵的构造函数
earth_pokemon::earth_pokemon() {
    m_property = EARTH;
    m_growing_att += 5;
    m_growing_def += 25;
    m_growing_HP += 45;
}
//地属性精灵的构造函数
thunder_pokemon::thunder_pokemon() {
    m_property = THUNDER;
    m_growing_att += 25;
    m_growing_def += 5;
    m_growing_HP += 20;
}
//雷电属性精灵的构造函数
machinery_pokemon::machinery_pokemon() {
    m_property = MACHINERY;
    m_growing_att += 5;
    m_growing_def += 1;
    m_growing_HP += 25;
}
//机械属性精灵的构造函数

strong_type::strong_type()
{
    m_type = STRONG;
    m_speed = 12;
    m_dodge = 0.03;
    m_crit = 0.2;
    m_growing_att += 55;
    m_growing_def += 25;
    m_growing_HP += 100;
    m_growing_speed = 12;
    //设定初始化
}
//力量型构造函数
shield_type::shield_type()
{
    m_type = SHIELD;
    m_speed = 12;
    m_dodge = 0.03;
    m_crit = 0.1;
    m_growing_att += 50;
    m_growing_def += 35;
    m_growing_HP += 100;
    m_growing_speed = 12;
    //设定初始化
}
//防御型构造函数
tank_type::tank_type()
{
    m_type = TANK;
    m_speed = 8;
    m_dodge = 0.01;
    m_crit = 0.05;
    m_growing_att += 50;
    m_growing_def += 30;
    m_growing_HP += 120;
    m_growing_speed = 8;
}
//肉盾类构造函数
swift_type::swift_type()
{
    m_type = SWIFT;
    m_speed = 15;
    m_dodge = 0.06;
    m_crit = 0.2;
    m_growing_att += 45;
    m_growing_def += 20;
    m_growing_HP += 80;
    m_growing_speed = 15;
}
//敏捷类构造函数

int pokemon::fight(pokemon* opponent){
    //返回0代表自己胜利 返回1代表对手胜利
    fight_game* new_fight = new fight_game();
    new_fight->recieve_pokemon(this, opponent);
    connect(this, &pokemon::update ,new_fight, &fight_game::recieve_fight_log);
    int my_HP = m_HP;
    int opponent_HP = opponent->get_HP();
    //临时变量双方HP
    QString msg;
    //消息
    int temp_demage = 0;
    //临时变量 临时伤害，用于计算
    while(1){
        //战斗回合 可用信号！
        int fight = 0;

        //每1s自动战斗一个回合，这里是非阻塞的延时
        if(m_speed >= opponent->get_speed()){
            //如果速度相同，玩家方先出手
            temp_demage = this->attack(opponent);
            opponent_HP -= temp_demage;
            emit update(QString::fromLocal8Bit(this->get_name()) + QString::fromLocal8Bit("造成了 ") +
                        QString::number(temp_demage) + QString::fromLocal8Bit(" 点伤害\n") +
                        QString::fromLocal8Bit(opponent->get_name()) + QString::fromLocal8Bit("还有")
                        + QString::number(opponent_HP>0?opponent_HP:0) + QString::fromLocal8Bit(" 点生命值\n"));
            //msg.append(QString::fromLocal8Bit("您造成了 ") +
            //QString::number(temp_demage) + QString::fromLocal8Bit(" 点伤害\n"));

            if(opponent_HP <= 0){
                msg.append(QString::fromLocal8Bit("您击败了对手！\n"));
                int reward = m_level - opponent->get_level();
                //越级挑战奖励，相差太多减少
                int exp = 0;
                if (reward <= 0)
                    exp = m_level * m_level + pow(2, reward) + (16 - m_level) * 10;
                else
                    exp = m_level * opponent->get_level() - reward + (16 - m_level) * 10;
                msg.append(QString::fromLocal8Bit("获得了 ") +
                           QString::number(exp) + QString::fromLocal8Bit(" 点经验值\n"));
                emit update(msg);
                exp_level(exp);
                return 0;
            }

            QTime dieTime = QTime::currentTime().addMSecs(500);
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

            temp_demage = opponent->attack(this);
            my_HP -= temp_demage;
            emit update(QString::fromLocal8Bit(opponent->get_name()) + QString::fromLocal8Bit("造成了 ") +
                        QString::number(temp_demage) + QString::fromLocal8Bit(" 点伤害\n") +
                        QString::fromLocal8Bit(this->get_name()) + QString::fromLocal8Bit("还有") +
                        QString::number(my_HP>0?my_HP:0) + QString::fromLocal8Bit(" 点生命值\n"));
            //msg.append(QString::fromLocal8Bit("对手造成了 ") +
            //QString::number(temp_demage) + QString::fromLocal8Bit(" 点伤害\n"));

            if(my_HP <= 0){
                msg.append(QString::fromLocal8Bit("您失败了！\n"));
                emit update(msg);
                return 1;
            }

        }
        else{
            //否则对手先出手
            temp_demage = opponent->attack(this);
            my_HP -= temp_demage;
            emit update(QString::fromLocal8Bit(opponent->get_name()) + QString::fromLocal8Bit("造成了 ") +
                        QString::number(temp_demage) + QString::fromLocal8Bit(" 点伤害\n") +
                        QString::fromLocal8Bit(this->get_name()) + QString::fromLocal8Bit("还有")
                        + QString::number(my_HP>0?my_HP:0) + QString::fromLocal8Bit(" 点生命值\n"));
            //msg.append(QString::fromLocal8Bit("对手造成了 ") +
            //QString::number(temp_demage) + QString::fromLocal8Bit(" 点伤害\n"));

            if(my_HP <= 0){
                msg.append(QString::fromLocal8Bit("您失败了！\n"));
                emit update(msg);
                return 1;
            }

            QTime dieTime = QTime::currentTime().addMSecs(500);
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

            temp_demage = this->attack(opponent);
            opponent_HP -= temp_demage;
            emit update(QString::fromLocal8Bit(this->get_name()) + QString::fromLocal8Bit("造成了 ") +
                        QString::number(temp_demage) + QString::fromLocal8Bit(" 点伤害\n") +
                        QString::fromLocal8Bit(opponent->get_name()) + QString::fromLocal8Bit("还有")
                        + QString::number(opponent_HP>0?opponent_HP:0) + QString::fromLocal8Bit(" 点生命值\n"));
            //msg.append(QString::fromLocal8Bit("您造成了 ") +
            //QString::number(temp_demage) + QString::fromLocal8Bit(" 点伤害\n"));

            if(opponent_HP <= 0){
                msg.append(QString::fromLocal8Bit("您击败了对手！\n"));
                int reward = m_level - opponent->get_level();
                //越级挑战奖励，相差太多减少
                int exp = 0;
                if (reward <= 0)
                    exp = m_level * m_level + pow(2, reward) + (16 - m_level) * 10;
                else
                    exp = m_level * opponent->get_level() - reward + (16 - m_level) * 10;
                msg.append(QString::fromLocal8Bit("获得了 ") +
                           QString::number(exp) + QString::fromLocal8Bit(" 点经验值\n"));
                emit update(msg);
                exp_level(exp);
                return 0;
            }
        }
    }
}
//战斗函数
int pokemon::attack(pokemon* opponent) {
    double damage = 0;
    //临时变量 计算伤害
    int damage_coefficient = 1;
    //伤害系数
    damage_coefficient *= att_crit_and_dodge(opponent);
    //判断闪避、暴击等因素的影响
    if (damage_coefficient == 0)
        return 0;
    //攻击被闪避了直接返回0
    damage = damage_coefficient * (this->m_attack - opponent->get_defense() + this->get_level() - opponent->get_level());
    //计算伤害
    if (damage <= 1)
        //如果过小或没有破防 则强制为1点
        return 1;
    else
        //其余情况向上取整
        return (int)(floor(damage));
}
//一般的攻击函数
const double pokemon::property_for_damage(pokemon* opponent) {
    switch (m_property)
    {
    case FIRE:
        switch (opponent->get_property())
        {
        case FIRE:
        case WIND:
        case THUNDER:
            return 1;
        case WATER:
        case BRIGHT:
        case EARTH:
            return 0.5;
        case PLANT:
        case DARK:
        case MACHINERY:
            return 2;
        default:
            return 0;
        }
        break;
    case WATER:
        switch (opponent->get_property())
        {
        case WATER:
        case DARK:
        case BRIGHT:
        case WIND:
        case EARTH:
        case THUNDER:
            return 1;
        case PLANT:
            return 0.5;
        case FIRE:
        case MACHINERY:
            return 2;
        default:
            return 0;
        }
        break;
    case PLANT:
        switch (opponent->get_property())
        {
        case PLANT:
        case DARK:
        case BRIGHT:
        case WIND:
        case THUNDER:
            return 1;
        case MACHINERY:
        case FIRE:
            return 0.5;
        case WATER:
        case EARTH:
            return 2;
        default:
            return 0;
        }
        break;
    case DARK:
        switch (opponent->get_property())
        {
        case WATER:case PLANT:
        case DARK:
        case WIND:
        case EARTH:
            return 1;
        case MACHINERY:
        case THUNDER:
        case FIRE:
            return 0.5;
        case BRIGHT:
            return 2;
        default:
            return 0;
        }
        break;
    case BRIGHT:
        switch (opponent->get_property())
        {
        case WATER:
        case MACHINERY:
        case BRIGHT:
        case WIND:
        case EARTH:
            return 1;
        case PLANT:
        case THUNDER:
        case FIRE:
            return 0.5;
        case DARK:
            return 2;
        default:
            return 0;
        }
        break;
    case WIND:
        switch (opponent->get_property())
        {
        case WATER:
        case DARK:
        case BRIGHT:case MACHINERY:
        case WIND:
        case THUNDER:
            return 1;
        case EARTH:
        case FIRE:
            return 0.5;
        case PLANT:
            return 2;
        default:
            return 0;
        }
        break;
    case EARTH:
        switch (opponent->get_property())
        {
        case WATER:
        case DARK:
        case BRIGHT:
        case WIND:
        case EARTH:
        case THUNDER:
        case MACHINERY:
            return 1;
        case PLANT:
            return 0.5;
        case FIRE:
            return 2;
        default:
            return 0;
        }
        break;
    case THUNDER:
        switch (opponent->get_property())
        {
        case FIRE:
        case PLANT:
        case WIND:
        case THUNDER:
            return 1;
        case EARTH:
        case BRIGHT:
        case WATER:
            return 0.5;
        case DARK:
        case MACHINERY:
            return 2;
        default:
            return 0;
        }
        break;
    case MACHINERY:
        switch (opponent->get_property())
        {
        case MACHINERY:
        case DARK:
        case BRIGHT:
        case WIND:
            return 1;
        case WATER:
        case FIRE:
        case THUNDER:
            return 0.5;
        case EARTH:
        case PLANT:
            return 2;
        default:
            return 0;
        }
        break;
    default:
        return 0;
    }
}
//攻击时的属性判定
const int pokemon::att_crit_and_dodge(pokemon* opponent) {
    QTime time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int random = qrand() % 100 + 1;
    //随机数
    QString msg;
    //消息
    if (random <= opponent->get_dodge() * 100) {
        //闪避判断
        msg = QString::fromLocal8Bit(opponent->get_name()) + QString::fromLocal8Bit("闪避了") +
                QString::fromLocal8Bit(this->get_name()) + QString::fromLocal8Bit("的攻击");
        emit update(msg);
        return 0;
    }
    if (random >= 100 - this->m_crit * 100) {
        //暴击判断
        msg = QString::fromLocal8Bit(this->get_name()) + QString::fromLocal8Bit("暴击了") +
                QString::fromLocal8Bit(opponent->get_name()) + QString::fromLocal8Bit("!");
        emit update(msg);
        return 2;
        //如果暴击伤害系数*2
    }
    //其余情况返回1
    msg = QString::fromLocal8Bit(this->get_name()) + QString::fromLocal8Bit("攻击了") +
            QString::fromLocal8Bit(opponent->get_name());
    emit update(msg);
    return 1;
}
//攻击时的暴击闪避判断
void pokemon::exp_level(int new_exp) {
    QString msg;
    if (new_exp > 0) {
        if (m_level < 15) {
            m_exp += new_exp;
            int now_level_max_exp = m_level * 100 + (int)pow(2, (m_level - 1));
            while (m_exp >= (now_level_max_exp) && m_level != 15) {
                m_exp -= now_level_max_exp;
                m_level++;
                msg.append(QString::fromLocal8Bit(m_name) + QString::fromLocal8Bit(" 升级了，当前是 ") +
                           QString::number(m_level) + QString::fromLocal8Bit(" 级\n") +
                           QString::fromLocal8Bit("攻击力：") + QString::number(m_attack) +
                           QString::fromLocal8Bit("->") + QString::number(m_attack + m_growing_att) + '\n' +
                           QString::fromLocal8Bit("防御力：") + QString::number(m_defense) +
                           QString::fromLocal8Bit("->") + QString::number(m_defense + m_growing_def) + '\n' +
                           QString::fromLocal8Bit("生命值：") + QString::number(m_HP) +
                           QString::fromLocal8Bit("->") + QString::number(m_HP + m_growing_HP) + '\n' +
                           QString::fromLocal8Bit("速  度：") + QString::number(m_speed) +
                           QString::fromLocal8Bit("->") + QString::number(m_speed + m_growing_speed) + '\n');
                //发送更新消息
                m_attack = m_attack + m_growing_att;
                m_defense = m_defense + m_growing_def;
                m_HP = m_HP + m_growing_HP;
                m_speed = m_speed + m_growing_speed;
                //等级成长
            }
        }
    }
    //emit update(msg);
}
//经验升级等
const char* pokemon::format_output(int attribute, int type) {
    //格式化输出
    if (attribute == -1) {
        switch (type)
        {
        case STRONG:
            return Strong;
        case SHIELD:
            return Shield;
        case TANK:
            return Tank;
        case SWIFT:
            return Swift;
        default:
            return Error;
        }
    }
    else if (type == -1) {
        switch (attribute)
        {
        case FIRE:
            return Fire;
        case WATER:
            return Water;
        case PLANT:
            return Plant;
        case DARK:
            return Dark;
        case BRIGHT:
            return Bright;
        case WIND:
            return Wind;
        case EARTH:
            return Earth;
        case MACHINERY:
            return Machinery;
        case THUNDER:
            return Thunder;
        default:
            return Error;
        }
    }
    else
        return Error;
}
//格式化输出
int fire_pokemon::attack(pokemon* opponent) {
    //火属性的攻击效果->1.2倍攻击伤害
    double damage = 0;
    //临时变量 计算伤害
    int damage_coefficient = 1;
    //伤害系数
    damage_coefficient *= att_crit_and_dodge(opponent);
    //判断闪避、暴击等因素的影响
    if (damage_coefficient == 0)
        return 0;
    damage = damage_coefficient * 1.2 * (this->m_attack - opponent->get_defense() + this->get_level() - opponent->get_level());
    //计算伤害
    if (damage <= 1)
        //如果过小或没有破防 则强制为1点
        return 1;
    else
        //其余情况向上取整
        return (int)(floor(damage));
}
//火属性攻击
int water_pokemon::attack(pokemon* opponent) {
    double damage = 0;
    //临时变量 计算伤害
    int damage_coefficient = 1;
    //伤害系数
    damage_coefficient *= att_crit_and_dodge(opponent);
    //判断闪避、暴击等因素的影响
    if (damage_coefficient == 2) {
        damage = damage_coefficient * (this->m_attack - opponent->get_defense() + this->get_level() * 3 - opponent->get_level());
        //计算伤害
    }
    else {
        damage = (this->m_attack - opponent->get_defense() + this->get_level() - opponent->get_level());
    }

    if (damage_coefficient == 0) {
        //如果被闪避了,返回0
        return 0;
    }
    else if (damage <= 1)
        //如果过小或没有破防 则强制为1点
        return 1;
    else
        //其余情况向上取整
        return (int)(floor(damage));
}
//水属性攻击
int plant_pokemon::attack(pokemon* opponent) {
    double damage = 0;
    //临时变量 计算伤害
    int damage_coefficient = 1;
    //伤害系数
    damage_coefficient *= att_crit_and_dodge(opponent);
    //判断闪避、暴击等因素的影响
    if (damage_coefficient == 0)
        return 0;
    damage = damage_coefficient * (this->m_attack - opponent->get_defense() + this->get_level() - opponent->get_level()) + this->get_level() * 5;
    //计算伤害
    if (damage <= 1)
        //如果过小或没有破防 则强制为1点
        return 1;
    else
        //其余情况向上取整
        return (int)(floor(damage));
}
//草属性攻击
int dark_pokemon::attack(pokemon* opponent) {
    //该攻击不会被闪避
    double damage = 0;
    //临时变量 计算伤害
    int damage_coefficient = 1;
    //伤害系数
    damage_coefficient *= att_crit_and_dodge(opponent);
    //判断闪避、暴击等因素的影响
    if (damage_coefficient == 0)
        damage_coefficient = 4;
    damage = damage_coefficient * (this->m_attack - opponent->get_defense() + this->get_level() - opponent->get_level());
    //计算伤害
    if (damage <= 1)
        //如果过小或没有破防 则强制为1点
        return 1;
    else
        //其余情况向上取整
        return (int)(floor(damage));
}
//黑暗属性攻击
int machinery_pokemon::attack(pokemon* opponent) {
    double damage = 0;
    //临时变量 计算伤害
    int damage_coefficient = 1;
    //伤害系数
    damage_coefficient *= att_crit_and_dodge(opponent);
    //判断闪避、暴击等因素的影响
    if (damage_coefficient == 2) {
        damage = damage_coefficient * (this->m_attack - opponent->get_defense() + this->get_level() - opponent->get_level());
        //计算伤害
    }
    else {
        damage = (this->m_attack - opponent->get_defense() + this->get_level() - opponent->get_level());
    }

    if (damage <= 1)
        //如果过小或没有破防 则强制为1点
        return 1;
    else{
        //其余情况向上取整
        int temp = (int)(floor(damage));
        if(temp % 7 == 0)
            temp *= 2;
        return temp;
    }

}
//机械属性精灵的攻击
pokemon* pokemon::recover(int level){
    int now_level = 1;
    while(now_level < level){
        this->exp_level(now_level * 100 + (int)pow(2, (now_level - 1)));
        now_level++;
    }
    //qDebug() << "recover_success";
    return this;
}
//加载精灵
