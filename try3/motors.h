// MOTORS
//************************************************************************

  int HI = 3; //pin numbers
  int LI = 4;
  
  int motorValue = 0;
  int brakeValue = 0;
  double topSpeed = 10; // in ft/sec only used with Tx 
  int buffOut = 1; // for safety. larger will mess up linearity . may be in units of speed (ft/sec)

  double getVRef();

  // allow Tx input fomr channel 3 (left stick vertical)
  int REC_MOTOR = 21; // pin to read signals from reciever
  int throttleValue;
  int topDutyCycleOL = 256*.5; //max speed
  int buffTxIn = 10; // buffer for tx input . full range of tx input is 1160 to 1830
  int throttleMid = 1500;
  void getSpeedOL(); //gets input from tx, assigns it to a desired speed, determines what to give HI and LI. 

  // closed loop speed control
  double vRef;
  int SPEED1 = 9.5;
  int SPEED2 = 10;
  int SPEED3 = 10.5;
  
  double vMeas;
  double vError;
  double vValue; 

  //vRef as a function of curvature
  double bCurvature = 1.0;
  double mCurvature = 5.0/2.0;
  double threshCurvature = .4;

  int topDutyCycleCL = 256*.5; // this ramps up to maxDutyCycleCL
  double kpSpeed = 3.0;
  double kiSpeed = 0.05;
  double vErrorTotal = 0.0;
  void getSpeedCL();
