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

#ifndef CONTROLLER_SENSORS_HPP
#define CONTROLLER_SENSORS_HPP

#include <stdint.h>
#include <Vector.hpp>
#include <Controller.hpp>
#include <Sensor.hpp>

class ControllerSensors : public Controller {
	public:
	    ControllerSensors();
	    ~ControllerSensors();
		bool Init();
	    bool Update();
		int8_t AddSensor(Sensor *sensor);
		uint8_t GetSensorCount();
		SensorData  &GetSensorData(const uint8_t index);
	private:
		static const uint8_t _sensors_buf_size = 12;
		Sensor *_sensors_buf[_sensors_buf_size];
		Vector<Sensor*> _sensors;
};

#endif
