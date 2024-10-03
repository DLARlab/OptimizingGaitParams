/**********************************************************************
 Copyright (c) 2020-2023, Unitree Robotics.Co.Ltd. All rights reserved.
***********************************************************************/
#include "interface/KeyBoard.h"
#include <iostream>

KeyBoard::KeyBoard(){
    userCmd = UserCommand::NONE;
    userValue.setZero();

    tcgetattr( fileno( stdin ), &_oldSettings );
    _newSettings = _oldSettings;
    _newSettings.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr( fileno( stdin ), TCSANOW, &_newSettings );

    pthread_create(&_tid, NULL, runKeyBoard, (void*)this);
}

KeyBoard::~KeyBoard(){
    pthread_cancel(_tid);
    pthread_join(_tid, NULL);
    tcsetattr( fileno( stdin ), TCSANOW, &_oldSettings );
}

UserCommand KeyBoard::checkCmd(){
    switch (_c){
    case '1':
        return UserCommand::L2_B;// passive
    case '2':
        return UserCommand::L2_A;// fixedStand
    case '3':
        return UserCommand::L2_X;// freeStand
    case '4':
        return UserCommand::START; // BOUNDING_COM
    case '6':
        return UserCommand::R2_A; // bounding_slip
    case '7':
        return UserCommand::L1_B; // bounding_lip
#ifdef COMPILE_WITH_MOVE_BASE
    case '5':
        return UserCommand::L2_Y;
#endif  // COMPILE_WITH_MOVE_BASE
    case '0':
        return UserCommand::L1_X;// bounding_real_lip
    case '-':
        return UserCommand::R2_B; //Bounding_Real_SLIP
    case '9':
        return UserCommand::L1_A; //swingTest
    case '8':
        return UserCommand::L1_Y;// stepTest
    case ' ':
        userValue.setZero();
        return UserCommand::NONE;
    case 't':case 'T':
        return UserCommand::R1_A;
    case 'f':case 'F':
        return UserCommand::R1_B;
    case 'g':case 'G':
        return UserCommand::R1_X;
    case 'h':case 'H':
        return UserCommand::R1_Y;
    case 'z':case 'Z':
        return UserCommand::R1_down;
    case 'x':case 'X':
        return UserCommand::R1_right;
    case 'c':case 'C':
        return UserCommand::R1_left;
    case 'v':case 'V':
        return UserCommand::R1_down;
    case 'e':case 'E':
        return UserCommand::R1_select;
    case 'r':case 'R':
        return UserCommand::R1_start;
    default:
        return UserCommand::NONE;
    }
}

void KeyBoard::changeValue(){
    switch (_c){
    case 'w':case 'W':
        userValue.ly = min<float>(userValue.ly+sensitivityLeft, 10.0);
        break;
    case 's':case 'S':
        userValue.ly = max<float>(userValue.ly-sensitivityLeft, -10.0);
        break;
    case 'd':case 'D':
        userValue.lx = min<float>(userValue.lx+sensitivityLeft, 1.0);
        break;
    case 'a':case 'A':
        userValue.lx = max<float>(userValue.lx-sensitivityLeft, -1.0);
        break;

    case 'i':case 'I':
        userValue.ry = min<float>(userValue.ry+sensitivityRight, 1.0);
        break;
    case 'k':case 'K':
        userValue.ry = max<float>(userValue.ry-sensitivityRight, -1.0);
        break;
    case 'l':case 'L':
        userValue.rx = min<float>(userValue.rx+sensitivityRight, 1.0);
        break;
    case 'j':case 'J':
        userValue.rx = max<float>(userValue.rx-sensitivityRight, -1.0);
        break;
    default:
        break;
    }
}

void* KeyBoard::runKeyBoard(void *arg){
    ((KeyBoard*)arg)->run(NULL);
    return NULL;
}

void* KeyBoard::run(void *arg){
    while(1){
        FD_ZERO(&set);
        FD_SET( fileno( stdin ), &set );

        res = select( fileno( stdin )+1, &set, NULL, NULL, NULL);

        if(res > 0){
            ret = read( fileno( stdin ), &_c, 1 );
            userCmd = checkCmd();
            if(userCmd == UserCommand::NONE)
                changeValue();
            _c = '\0';
        }
        usleep(1000);
    }
    return NULL;
}