#include "PR_IoT_Device_SI7021.h"

    #include <arduino.h>    
  
	void 	PR_IoT_SI7021::announce() {
		postMsg("temperature+humidity", "HELLO"); 
	}
	
	void 	PR_IoT_SI7021::setupHW(uint8_t pinSDA, uint8_t pinSCL) {
		sensor.begin(pinSDA , pinSCL); 
	}   
			
	void	PR_IoT_SI7021::update() {	
		
		si7021_env data = sensor.getHumidityAndTemperature();
		_lastMeasuredTemp	= data.celsiusHundredths/100;
		_lastMeasuredHumid	= data.humidityBasisPoints/100;
		
		postMsg("temperature", String(_lastMeasuredTemp, 1) );
		postMsg("humidity", String(_lastMeasuredHumid) );
	}
	
	void	PR_IoT_SI7021::inMsgCallback() {

		PR_DBGTLN("temperature+humidity: Msg got")
		PR_DBGVLN(inMsg.payload)
		
		if (inMsg.payload == "ASK")	{
			invoke();
		}
	}
	
