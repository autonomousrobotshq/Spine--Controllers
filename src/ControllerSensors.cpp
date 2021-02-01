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

#include "ControllerSensors.hpp"

ControllerSensors::ControllerSensors()
	: _sensors(_sensors_buf)
{
}

ControllerSensors::~ControllerSensors()
{
}

bool ControllerSensors::Init()
{
	uint8_t errors;
	for (Sensor *s : _sensors)
		errors += (s->Init() == false);
	return (errors == 0);
}

bool ControllerSensors::Update()
{
	uint8_t errors;
	for (Sensor *s : _sensors)
		errors += (s->Update() == false);
	return (errors == 0);
}

int8_t ControllerSensors::AddSensor(Sensor *sensor)
{
	if (_sensors.size() < _sensors_buf_size) {
		_sensors.push_back(sensor);
		return (_sensors.size() - 1);
	}
	else {
		return (-1);
	}
}

uint8_t ControllerSensors::GetSensorCount()
{
	return (_sensors.size());
}

SensorData	&ControllerSensors::GetSensorData(const uint8_t index)
{
	return (_sensors[index]->RetreiveData());
}
