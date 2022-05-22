/*
 * Copyright (c) 2019-2022, Michael Gummere.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "main.h"

#ifndef MOTORS_H_
#define MOTORS_H_

// Declare controller
inline pros::Controller master(pros::E_CONTROLLER_MASTER);;

// Declare drive motors
inline pros::Motor leftMtr(20, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
inline pros::Motor leftMtrR(19, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
inline pros::Motor rightMtr(11, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
inline pros::Motor rightMtrR(12, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);

// Lift Motors
inline okapi::Motor rightLift(8, true, okapi::AbstractMotor::gearset::red,
                       okapi::AbstractMotor::encoderUnits::degrees);
inline okapi::Motor leftLift(9, false, okapi::AbstractMotor::gearset::red,
                      okapi::AbstractMotor::encoderUnits::degrees);
inline okapi::MotorGroup liftMotors({rightLift, leftLift});

// Ring Motor
inline okapi::Motor ringM(6, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

// Winch Motor
inline pros::Motor winchM(10, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);

// Sensors
inline pros::Imu imu_sensor(1);
inline pros::Distance distanceR(21);

// Vision
inline pros::vision_signature_s_t RED_SIG =
    pros::Vision::signature_from_utility(1, 6255, 7309, 6782, -325, 223, -52, 3.000, 0);
inline pros::vision_signature_s_t YLW_SIG =
    pros::Vision::signature_from_utility(2, 351, 1099, 724, -3479, -2631, -3054, 3.000, 0);
inline pros::vision_signature_s_t BLU_SIG =
    pros::Vision::signature_from_utility(3, -3073, -2047, -2560, 7899, 12545, 10222, 3.000, 0);
inline pros::Vision vision_sensor(7, pros::E_VISION_ZERO_CENTER);

// Pneumatics
inline pros::ADIDigitalOut clawP('A');
inline pros::ADIDigitalOut AWP('B');


#endif
