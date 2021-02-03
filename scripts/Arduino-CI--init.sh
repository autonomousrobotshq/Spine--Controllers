#!/bin/sh

# stop on first error
set -e

# pull in external repositories
git clone https://github.com/autonomousrobotshq/External--Structures Structures
git clone https://github.com/autonomousrobotshq/External--TinyGPS TinyGPS
git clone https://github.com/autonomousrobotshq/External--LSM303 LSM303
git clone https://github.com/autonomousrobotshq/External--OneWire OneWire
git clone https://github.com/autonomousrobotshq/External--DallasTemperature DallasTemperature

# pull in internal repositories
git clone https://github.com/autonomousrobotshq/Spine--Sensors
git clone https://github.com/autonomousrobotshq/Spine--Actuators
git clone https://github.com/autonomousrobotshq/Spine--Filters
git clone https://github.com/autonomousrobotshq/Spine--Timers
git clone https://github.com/autonomousrobotshq/Spine--ROS-Generated
