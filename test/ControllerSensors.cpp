//
// Spine - Spine - MCU code for robotics.
// Copyright (C) 2019-2021 Codam Robotics
//
// This file is part of Spine.
//
// Spine is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Spine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Spine.  If not, see <http://www.gnu.org/licenses/>.
//

#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include <SensorCurrent.hpp>
#include <ControllerSensors.hpp>

unittest(ControllersSensors)
{
	GodmodeState* state = GODMODE();   // get access to the state
	ControllerSensors cm;
	assertTrue(cm.Init());

	const int pin = 10;
	const int sample_count = 10;
	const unsigned long sampling_interval = 1000;
	SensorCurrent s(pin, sample_count, sampling_interval);
	int8_t s_i = cm.AddSensor(&s);
	assertEqual(0, (int)s_i);

	assertTrue(cm.Update());
	SensorData s2 = cm.GetSensorData(s_i);
}

unittest_main()
