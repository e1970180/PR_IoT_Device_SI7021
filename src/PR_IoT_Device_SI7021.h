#ifndef PR_IoT_Device_SI7021_h
#define PR_IoT_Device_SI7021_h

    #include <arduino.h>
    #include <PR_IoT.h>

	#include <Wire.h>
	#include <SI7021.h>
	
	
class PR_IoT_SI7021 : public PR_IoT_DeviceClass {
        public:
            PR_IoT_SI7021(String name) : PR_IoT_DeviceClass(name) {}; 
			
            void 			announce();
            void 			update();
            virtual void 	inMsgCallback(); 
            virtual void 	setupHW(uint8_t pinSDA, uint8_t pinSCL);
			virtual void	loopHW()			{}
			
			float 			getTemp()			{	return _lastMeasuredTemp;	}
			uint8_t			getHumid()			{	return _lastMeasuredHumid;	}
			
        protected:
			SI7021 			sensor;
			float 			_lastMeasuredTemp;
			uint8_t			_lastMeasuredHumid;
	};
	
#endif