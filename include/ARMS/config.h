#ifndef _ARMS_CONFIG_H_
#define _ARMS_CONFIG_H_

// clang-format off
#include "ARMS/api.h"
// clang-format on
#include "okapi/api.hpp"

namespace arms {

// debug
#define ODOM_DEBUG 0

// negative numbers mean reversed motor
#define LEFT_MOTORS 20, 19
#define RIGHT_MOTORS 12, 11
#define GEARSET 200 // rpm of chassis motors

// unit constants
#define DISTANCE_CONSTANT 64 // ticks per distance unit
#define DEGREE_CONSTANT 2.3   // ticks per degree

// slew control (autonomous only)
#define SLEW_STEP 8 // smaller number = more slew

// sensors
#define IMU_PORT 21            // port 0 for disabled
#define ENCODER_PORTS 0, 0, 0 // port 0 for disabled,
#define EXPANDER_PORT 0       // port 0 for disabled

// odometry
#define LEFT_RIGHT_DISTANCE 6.375 // only needed for non-imu setups
#define MIDDLE_DISTANCE 5.75      // only needed if using middle tracker
#define LEFT_RIGHT_TPI 41.4       // Ticks per inch
#define MIDDLE_TPI 41.4           // Ticks per inch
#define EXIT_ERROR 1              // default exit distance for movements

// default pid constants
#define LINEAR_KP .3
#define LINEAR_KI 0
#define LINEAR_KD .5
#define ANGULAR_KP .8
#define ANGULAR_KI 0
#define ANGULAR_KD 3
#define DIF_KP .5      // Keep the robot driving straight
#define FEEDFORWARD 10 // Minimum power to keep the chassis moving

// arc movements
#define ARC_KP .05
#define ARC_SLEW_STEP 2 // smaller number = slower acceleration

// Auton selector configuration constants
#define AUTONS "YLW Goal", "R WP", "L WP", "Do Nothing"
#define HUE 360 // Color of theme from 0-359(H part of HSV)
#define DEFAULT 3 // Default auton numbers

// initializer
inline void init() {
	chassis::init({LEFT_MOTORS}, {RIGHT_MOTORS}, GEARSET, DISTANCE_CONSTANT,
	              DEGREE_CONSTANT, SLEW_STEP, ARC_SLEW_STEP, IMU_PORT,
	              {ENCODER_PORTS}, EXPANDER_PORT, EXIT_ERROR);

	if (IMU_PORT != 0) {
		odom::init(ODOM_DEBUG, LEFT_RIGHT_DISTANCE, MIDDLE_DISTANCE, LEFT_RIGHT_TPI,
		           MIDDLE_TPI);
	}

	pid::init(LINEAR_KP, LINEAR_KI, LINEAR_KD, ANGULAR_KP, ANGULAR_KI, ANGULAR_KD,
	          ARC_KP, DIF_KP, FEEDFORWARD);

	const char* b[] = {AUTONS, ""};
	selector::init(HUE, DEFAULT, b);

	pros::delay(200); // delay while PID and odom initialize
}

} // namespace arms

#endif
