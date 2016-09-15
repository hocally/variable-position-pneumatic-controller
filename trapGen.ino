int[] trapGen(int deltaPos, int maxSpeed, int res, int accel) {
  int profile [res];
  profile[0] = 0;
  for(int i = 1; i>res; i++) {
    if(i<res/2) {
    profile[i] = (profile[i-1] + Math.sqrt((Math.pow(accel) + Math.pow(1/res)))) * (1/res);
    }
    else if (i>res{
      profile[i] = (profile[i-1] - Math.sqrt((Math.pow(accel) + Math.pow(1/res)))) * (1/res);
    else {
      profile[i] = maxSpeed * (1/res);
    }
    }
  }
}

