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

#include <ControllerMotor.hpp>

#define MIN_THROTTLE 0
#define MAX_THROTTLE 255

#define MOTOR_COUNT 2
#define M1_PIN_PWM 1
#define M1_PIN_A 2
#define M1_PIN_B 3

#define M2_PIN_PWM 4
#define M2_PIN_A 5
#define M2_PIN_B 6

enum e_side {
	LEFT,
	RIGHT
};

uint16_t acceleration_coef = 50;

const ControllerMotor::t_motor_pins pins[2] = {{ M1_PIN_PWM, M1_PIN_A, M1_PIN_B }, {M2_PIN_PWM, M2_PIN_A, M2_PIN_B }};

unittest(ControllerMotor)
{
	GodmodeState* state = GODMODE();   // get access to the state
	ControllerMotor cm(MOTOR_COUNT, pins, acceleration_coef);
	assertTrue(cm.Init());

	cm.SetAction(LEFT, ControllerMotor::FORWARD, MAX_THROTTLE);
	assertTrue(cm.Update());
}

unittest_main()
