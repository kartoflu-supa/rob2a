void resetEncoder(){
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
}

void stopMotor() {
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}

void turn90(bool l_r) {
	int turn_num = BASE_DEG*80;
	resetEncoder();
	if (l_r) {
		while(abs(SensorValue[leftEncoder]) < turn_num || abs(SensorValue[rightEncoder]) < turn_num){

		if (abs(SensorValue[leftEncoder]) < turn_num){motor[leftMotor] = FULL_FORWARD;}
		if (abs(SensorValue[rightEncoder]) < turn_num){motor[rightMotor] = FULL_FORWARD * -1;}
	}}
	else {
		while(abs(SensorValue[leftEncoder]) < turn_num || abs(SensorValue[rightEncoder]) < turn_num){
		if (abs(SensorValue[leftEncoder]) < turn_num){motor[leftMotor] = FULL_FORWARD * -1;}
		if (abs(SensorValue[rightEncoder])< turn_num){motor[rightMotor] = FULL_FORWARD;}
	}}
	stopMotor();
}
task display(){
		bLCDBacklight = true;									// Turn on LCD Backlight
	string mainBattery, backupBattery;

	while(true)
	{
		clearLCDLine(0);
		clearLCDLine(1);

		displayLCDString(0, 0, "Primary: ");
		sprintf(mainBattery, "%1.2f%c",);
		displayNextLCDString(mainBattery);

		displayLCDString(1, 0, "Backup: ");
		sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');	//Build the value to be displayed
		displayNextLCDString(backupBattery);

		wait1Msec(100);
	}
}

task control(){
	bool active = true;
	while(1==1){
		if (!(vexRT[Btn8U] == 0 && SensorValue[bumber] == 0)){active = true;}
		while(active){
			hogCPU();
			motor[rightMotor]  = vexRT[Ch2];  // (y + x)/2
			motor[leftMotor] = vexRT[Ch3];

// Raise, lower or do not move arm
			if(vexRT[Btn5D] == 1){
				motor[verticleClawMotor] = 127;    	//...raise the arm.
			}
			else if(vexRT[Btn5U] == 1){
				motor[verticleClawMotor] = -127;   	//...lower the arm.
			}
			else{
				motor[verticleClawMotor] = 0;      	//...stop the arm.
			}

// Open, close or do not move claw
			if(vexRT[Btn6U] == 1){
				motor[clawMotor] = 127;}
			else if(vexRT[Btn6D] == 1){
				motor[clawMotor] = -127; 		//...open the gripper.
			}
			else{
				motor[clawMotor] = 0;    		//...stop the gripper.
				}
			if (vexRT[Btn8D] > 0){
				wait1Msec(500);
				active = false;
				releaseCPU();
	 			StartTask(display);
				}
			}
		}
	}
	void drive(int driveDistance, bool b_f){
	int dir = (b_f)? (1):(-1);
		resetEncoder();
		while (SensorValue[leftEncoder] < driveDistance && SensorValue[rightEncoder] < driveDistance){
		if (SensorValue[leftEncoder] < SensorValue[rightEncoder]){
				motor[leftMotor] = FULL_FORWARD*dir;
				motor[rightMotor] = (FULL_FORWARD-13)*dir;
		}
		if (SensorValue[leftEncoder] > SensorValue[rightEncoder]){
				motor[leftMotor] = (FULL_FORWARD-13)*dir;
				motor[rightMotor] = FULL_FORWARD*dir;
		}
		if (SensorValue[leftEncoder] == SensorValue[rightEncoder]){
				motor[leftMotor] = FULL_FORWARD*dir;
				motor[rightMotor] = FULL_FORWARD*dir;
	 }
	}
	stopMotor();
}
