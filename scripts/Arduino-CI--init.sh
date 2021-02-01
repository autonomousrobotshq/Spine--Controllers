#!/bin/sh

# stop on first error
set -e

# pull in external repositories
git clone https://github.com/s-t-a-n/Structures s-t-a-n--Structures

# pull in internal repositories
git clone https://github.com/autonomousrobotshq/Spine--Sensors
git clone https://github.com/autonomousrobotshq/Spine--Actuators
git clone https://github.com/autonomousrobotshq/Spine--Filters
git clone https://github.com/autonomousrobotshq/Spine--Timers
git clone https://github.com/autonomousrobotshq/Spine--ROS-Generated
git clone https://github.com/autonomousrobotshq/TinyGPS
git clone https://github.com/autonomousrobotshq/LSM303
git clone https://github.com/autonomousrobotshq/OneWire
git clone https://github.com/autonomousrobotshq/DallasTemperature