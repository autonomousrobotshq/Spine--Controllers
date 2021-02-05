#include <SensorCurrent.hpp>
#include <ControllerSensors.hpp>

ControllerSensors cs;

/* example sensor */
const int pin = 10;
const int sample_count = 10;
const unsigned long sampling_interval = 1000;
SensorCurrent sens_current(pin, sample_count, sampling_interval);

int sensor_index = 0;

void setup() {
	sensor_index = cs.AddSensor(&sens_current);
	cs.Init();
}

void loop() {
	if (cs.Update()) {
		SensorData sd = cs.GetSensorData(sensor_index);

		// do something with data
	} else {
		int error = cs.GetSensorData(sensor_index).GetError();

		// handle error
		(void)error;
	}
}
