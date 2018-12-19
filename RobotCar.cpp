#include "pch.h"
#include <iostream>

//фейковые функции, чтобы во время написания кода их вызовы не подсвечивались как ошибка

const int8_t defaultSpeed = 5;

float get_dist(int8_t nOfSonar)
{
	return 0;
}

void car_right_fi(int8_t angle)
{

}
//конец фейковых функций


class RobotCar
{
public:
	int8_t x;
	int8_t y;
	RobotCar();
	RobotCar(int8_t newSpeed);
	int8_t ReturnSideOfObstacle();
	void Drive();
	void TurnRight(int8_t angle);
private:
	int8_t speed;
	float right;
	float center;
	float left;
	void _UpdateSensors();
};
RobotCar::RobotCar()
{
	speed = defaultSpeed;
}
RobotCar::RobotCar(int8_t newspeed)
{

}
void RobotCar::_UpdateSensors()
{
	left = get_dist(1);
	center = get_dist(2);
	right = get_dist(3);
}
void RobotCar::Drive()
{
	//Insert method for moving forward here;
}
void RobotCar::TurnRight(int8_t angle)
{
	car_right_fi(angle);
}
int8_t RobotCar::ReturnSideOfObstacle()
{
	
}

//CHeck if car has arrived;
bool hasArrived(int8_t carX, int8_t carY, int8_t goalX, int8_t goalY)
{
	if ((abs(goalX - carX) < margin) & (abs(goalY - carY) < margin))
		return true;
	return false;
}

double cal_angle(double current_x, double current_y, double tar_x, double tar_y)
{
	return atan2(tar_y - current_y, tar_x - current_x);
}

public double margin = 1.0;

int main()
{
	int8_t goalX;
	int8_t goalY;

	int8_t startX;
	int8_t startY;

	RobotCar RobotCar;
	if (!hasArrived(RobotCar.x, RobotCar.y, goalX, goalY))
	{
		//TODO: Add previous angle and factor it into turning
		double angle = cal_angle(RobotCar.x, RobotCar.y, goalX, goalY);
		RobotCar.TurnRight(angle);
		RobotCar.Drive();
	}

}
