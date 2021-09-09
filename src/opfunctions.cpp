/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "main.h"

// void null;
void tankDrive()
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	leftMtr.move(master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_LEFT_X));
	rightMtr.move(master.get_analog(ANALOG_RIGHT_Y) + master.get_analog(ANALOG_RIGHT_Y));
	leftMtrR.move(master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_LEFT_X));
	rightMtrR.move(master.get_analog(ANALOG_RIGHT_Y) + master.get_analog(ANALOG_RIGHT_Y));
}

void arcadeDrive()
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	int forward_backward = master.get_analog(ANALOG_LEFT_Y);
	int left_right = master.get_analog(ANALOG_LEFT_X);
	leftMtr.move(forward_backward + left_right);
	rightMtr.move(forward_backward - left_right);
}
