/**********************************************************************
 Copyright (c) 2020-2023, Unitree Robotics.Co.Ltd. All rights reserved.
***********************************************************************/
#ifdef COMPILE_WITH_REAL_ROBOT

#include "interface/WirelessHandle.h"
#include "common/mathTools.h"
#include <string.h>
#include <stdio.h>

WirelessHandle::WirelessHandle(){
}

void WirelessHandle::receiveHandle(UNITREE_LEGGED_SDK::LowState *lowState){
#ifdef ROBOT_TYPE_A1
    memcpy(&_keyData, lowState->wirelessRemote, 40);  // note: available in the unitree_legged_sdk_3.2
#endif
#ifdef ROBOT_TYPE_Go1
    memcpy(&_keyData, &lowState->wirelessRemote[0], 40);
#endif  
    if(((int)_keyData.btn.components.L2 == 1) && 
       ((int)_keyData.btn.components.B  == 1)){
        userCmd = UserCommand::L2_B;
    }
    else if(((int)_keyData.btn.components.L2 == 1) && 
            ((int)_keyData.btn.components.A  == 1)){
        userCmd = UserCommand::L2_A;
    }
    else if(((int)_keyData.btn.components.L2 == 1) && 
            ((int)_keyData.btn.components.X  == 1)){
        userCmd = UserCommand::L2_X;
    }

#ifdef COMPILE_WITH_MOVE_BASE
    else if(((int)_keyData.btn.components.L2 == 1) && 
            ((int)_keyData.btn.components.Y  == 1)){
        userCmd = UserCommand::L2_Y;
    }
#endif  // COMPILE_WITH_MOVE_BASE

    else if(((int)_keyData.btn.components.L1 == 1) && 
            ((int)_keyData.btn.components.B  == 1)){
        userCmd = UserCommand::L1_B;
    }

    else if(((int)_keyData.btn.components.L1 == 1) && 
            ((int)_keyData.btn.components.X  == 1)){
        userCmd = UserCommand::L1_X;
    }
    else if(((int)_keyData.btn.components.L1 == 1) && 
            ((int)_keyData.btn.components.A  == 1)){
        userCmd = UserCommand::L1_A;
    }
    else if(((int)_keyData.btn.components.L1 == 1) && 
            ((int)_keyData.btn.components.Y  == 1)){
        userCmd = UserCommand::L1_Y;
    }
    else if((int)_keyData.btn.components.start == 1){
        userCmd = UserCommand::START;
    }
    else if(((int)_keyData.btn.components.R2 == 1) && 
            ((int)_keyData.btn.components.A  == 1)){
        userCmd = UserCommand::R2_A;
    }    
    else if(((int)_keyData.btn.components.R2 == 1) && 
            ((int)_keyData.btn.components.B  == 1)){
        userCmd = UserCommand::R2_B;
    }
     else if(((int)_keyData.btn.components.R1 == 1) && 
            ((int)_keyData.btn.components.A  == 1)){
        userCmd = UserCommand::R1_A;
    }
    else if(((int)_keyData.btn.components.R1 == 1) && 
            ((int)_keyData.btn.components.B  == 1)){
        userCmd = UserCommand::R1_B;
    }
    else if(((int)_keyData.btn.components.R1 == 1) && 
            ((int)_keyData.btn.components.X  == 1)){
        userCmd = UserCommand::R1_X;
    }
    else if(((int)_keyData.btn.components.R1 == 1) && 
            ((int)_keyData.btn.components.Y  == 1)){
        userCmd = UserCommand::R1_Y;
    }
    else if(((int)_keyData.btn.components.R1 == 1) && 
            ((int)_keyData.btn.components.down  == 1)){
        userCmd = UserCommand::R1_down;
    }
    else if(((int)_keyData.btn.components.R1 == 1) && 
            ((int)_keyData.btn.components.right  == 1)){
        userCmd = UserCommand::R1_right;
    }
    else if(((int)_keyData.btn.components.R1 == 1) && 
            ((int)_keyData.btn.components.left  == 1)){
        userCmd = UserCommand::R1_left;
    }
    else if(((int)_keyData.btn.components.R1 == 1) && 
            ((int)_keyData.btn.components.up  == 1)){
        userCmd = UserCommand::R1_up;
    }
    else if(((int)_keyData.btn.components.R1 == 1) && 
            ((int)_keyData.btn.components.select  == 1)){
        userCmd = UserCommand::R1_select;
    }
    else if(((int)_keyData.btn.components.R1 == 1) && 
            ((int)_keyData.btn.components.start  == 1)){
        userCmd = UserCommand::R1_start;
    }


    userValue.L2 = killZeroOffset(_keyData.L2, 0.08);
    userValue.lx = killZeroOffset(_keyData.lx, 0.08);
    userValue.ly = killZeroOffset(_keyData.ly, 0.08);
    userValue.rx = killZeroOffset(_keyData.rx, 0.08);
    userValue.ry = killZeroOffset(_keyData.ry, 0.08);
}


#endif  // COMPILE_WITH_REAL_ROBOT
