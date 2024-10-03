## Publications

This work has been submitted to the ACC 2024.

If you use this work in an academic context, please cite the following publication:

## Requirements
### Environment

We recommend that users run this project in Ubuntu 18.04 with ROS melodic or 20.04 with ROS noetic.

### Dependencies

Please place the three packages, unitree_guide, unitree_ros, and unitree_ros_msgs in our repository in a ROS workspace’s source directory.

## build

Open a terminal and switch the directory to the ros workspace containing unitree_guide, then run the following command to build the project:
```
catkin_make
```

## run

In the same terminal, run the following command step by step:
```
source ./devel/setup.bash
```
To open the gazebo simulator, run:
```
roslaunch unitree_guide gazeboSim.launch 
```

For starting the controller, open an another terminal and switch to the same directory,  then run the following command:
```
./devel/lib/unitree_guide/junior_ctrl
```

## Usage

### Simulation

After starting the controller,  the robot will lie on the ground of the simulator, then press the '2' key on the keyboard to switch the robot's finite state machine (FSM) from **Passive**(initial state) to **FixedStand**.  

hen press the ‘6’ key to switch the FSM from **FixedStand** to **Bounding_SLIP**. In this case, you don't need to press 'w' to accelerate the robot. The program will accelerate the robot by itself.

(If there is no response, you need to click on the terminal opened to start the controller and then repeat the previous operation)

### Hardware implementation

Download the code from "hardware" branch. Connect a cable to your computer with the robot or download the entire folder on your robot computer.

Assme you connect your robot with a cable, set the local IP address as 192.168.123.xxx. Then ping 192.168.123.161 to make sure your computer can communicate with robot.

In the CmakeLists.txt file, set REAL_ROBOT ON, set SIMULATION OFF, and set DEBUG OFF.

Open a terminal and switch the directory to the ros workspace containing unitree_guide,  then run the following command to build the project:
```
catkin_make
```
```
source ./devel/setup.bash
```
On the same terminal, run the following command with **root** right:
```
rosrun unitree_guide junior_ctrl
```

Use the remote controller to control the robot:

Press 'L2+B' to switch the robot's finite state machine to **Passive**.

Press 'L2+A' to switch the robot's finite state machine from **Passive** to **FixedStand**. 

Go back to **FixedStand**, then press the R2+B key to switch the FSM from **FixedStand** to **Bounding_SLIP**, which corresponds to the second control scheme in the paper. Be careful, the robot will accelerate very quickly.

The program will record the data automatically.
