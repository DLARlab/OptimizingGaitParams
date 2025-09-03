## Video

Simulation Results

https://github.com/user-attachments/assets/d8e0904b-6cea-495f-9e85-9ea55c721029

0.5m/s with stride time 0.14s

https://github.com/user-attachments/assets/3724c20b-b9d6-48ed-b955-f2f42f754727

0.5m/s with stride time 0.24s

https://github.com/user-attachments/assets/86cfa23d-1912-497c-b556-4a888edbba59

0.5m/s with stride time 0.36s

Experimental Results

https://github.com/user-attachments/assets/7b3cb65d-e146-4956-88f4-5d1279cd1a7c

0.5m/s with stride time 0.14s

https://github.com/user-attachments/assets/745990a8-eb6e-4483-9f09-3a803f3034f1

0.5m/s with stride time 0.24s

https://github.com/user-attachments/assets/6eb390ad-0c1a-4d8a-b60b-90a1b9ed0751

0.5m/s with stride time 0.36s

## Publications

Y. G. Alqaham, J. Cheng and Z. Gan, "Refining Motion for Peak Performance: Identifying Optimal Gait Parameters for Energy-Efficient Quadrupedal Bounding," 2025 American Control Conference (ACC), Denver, CO, USA, 2025, pp. 3794-3800, doi: 10.23919/ACC63710.2025.11107530.

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
